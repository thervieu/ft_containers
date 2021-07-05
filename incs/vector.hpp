#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "vectorIterator.hpp"

# include <limits>
# include <memory>
# include <iostream>
# include <stdio.h>

/*
** all functions implemented are those of vector (c++98)
** See: https://www.cplusplus.com/reference/vector/vector/
*/

namespace ft
{
	template <class T, class Alloc=std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;

			typedef Alloc allocator_type;

			typedef T& reference;
			typedef T& const_reference;
			typedef T* pointer;
			typedef T* const_pointer;

			typedef vectorIterator<value_type> iterator;
			typedef constVectorIterator<value_type> const_iterator;
			typedef reverseVectorIterator<value_type> reverse_iterator;
			typedef constReverseVectorIterator<value_type> const_reverse_iterator;

			typedef unsigned long size_type;

		private:

			pointer 		_elts;

			allocator_type	_alloc;

			size_type		_size;

			size_type		_capacity;

		public:

			/*
			** Constructors and destructors
			*/

			explicit vector (const allocator_type& alloc = allocator_type())
			: _elts(0), _alloc(alloc), _size(0), _capacity(0)
			{
				_elts = _alloc.allocate(_capacity);
			}

			explicit vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n)
			{
				_capacity = n;
				_elts = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_elts[i] = T(val);
			}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type())
			: _elts(0), _alloc(alloc), _size(0), _capacity(0)
			{
				_elts = _alloc.allocate(_capacity);
				assign(first, last);
			}

			vector (const vector& x)
			{
				_size = x._size;
				_capacity = x._capacity;
				_elts = _alloc.allocate(_capacity);
				
				for (size_type i = 0; i < x._size; i++)
					_elts[i] = x._elts[i];
			}

			~vector()
			{
				for (iterator it = begin(); it != end(); ++it)
                    _alloc.destroy(&(*it));
                _alloc.deallocate(_elts, _capacity);
			}

			vector& operator= (const vector& x)
			{
				if (this == &x)
					return (*this);

                _alloc.deallocate(_elts, _capacity);

				pointer tmp = _alloc.allocate(x._capacity);

				for (size_type i = 0; i < x._size; i++)
					tmp[i] = x._elts[i];
				
				_size = x._size;
				_capacity = x._capacity;
				_elts = tmp;

				return (*this);
			}

			/*
			** Iterators
			*/

			iterator begin()
			{
				return (iterator(&_elts[0]));
			}

			const_iterator begin() const
			{
				return (const_iterator(&_elts[0]));
			}

			iterator end()
			{
				return (iterator(&_elts[_size]));
			}
			
			const_iterator end() const
			{
				return (const_iterator(&_elts[_size]));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(&_elts[0]));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(&_elts[0]));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(&_elts[_size]));
			}
			
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(&_elts[_size]));
			}

			/*
			** Capacity
			*/

			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			}

			void resize (size_type n, value_type val = value_type())
			{
				while (n < _size)
					pop_back();
				while (n > _size)
					push_back(val);
			}

			size_type capacity() const
			{
				return (_capacity);
			}

			bool empty() const
			{
				return (_size == 0);
			}

			void reserve (size_type n)
			{
				if (n <= _capacity)
					return ;
				// std::cout << "call reserve after if ok\n";

				pointer tmp = _alloc.allocate(n);
				// std::cout << "allocate tmp ok size = |" << _size << "|\n";
				
				for (size_type i = 0; i < _size; i++)
				{
					// std::cout << "i = |" << i << "|\n";
					// std::cout << "elts[i] = |" << _elts[i] << "|\n";

					_alloc.construct(&tmp[i], _elts[i]);
					// std::cout << "tmp[i] = |" << tmp[i] << "|\n";
				}
				// std::cout << "tmp = elts values ok\n";
                _alloc.deallocate(_elts, _size);
				// std::cout << "deallocate elts ok\n";
				
				_capacity = n;
				_elts = tmp;
				// std::cout << "end reserve ok\n";
			}

			/*
			** Element access
			*/

			reference operator[] (size_type n)
			{
				return (_elts[n]);
			}

			const_reference operator[] (size_type n) const
			{
				return (_elts[n]);
			}

			reference at (size_type n)
			{
				if (n >= _size)
					throw(std::out_of_range("vector::out_of_range"));
				return (_elts[n]);
			}

			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw(std::out_of_range("vector::out_of_range"));
				return (_elts[n]);
			}

			reference front()
			{
				return (_elts[0]);
			}

			const_reference front() const
			{
				return (_elts[0]);
			}

			reference back()
			{
				return (_elts[_size - 1]);
			}

			const_reference back() const
			{
				return (_elts[_size - 1]);
			}

			/*
			** Modfiers
			*/

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				if (empty() == 0)
					clear();
				// std::cout << "hey\n";
				insert(begin(), first, last);
			}

			void assign (size_type n, const value_type& val)
			{
				// std::cout << "hey2\n";
				if (empty() == 0)
				{
					// std::cout << "clear\n";
					clear();
				}
				// std::cout << "hey3\n";
				insert(begin(), n, val);
			}

			void push_back (const value_type& val)
			{
				if (_size + 1 > _capacity)
					reserve(_size + 1);
				_elts[_size] = val;
				_size++;
			}

			void pop_back()
			{
				_size--;
			}

			iterator insert (iterator position, const value_type& val)
			{
				// std::cout << "begin insret val\n";
				size_type i = 0;
				iterator it = begin();

				// std::cout << "beginok\n";
				while (it + i != position && i < _size)
				{
					// std::cout << "i = " << i << "\n";
					i++;
				}
				// std::cout << "while i ok\n";
				
				if (_size + 1 > _capacity)
				{
					reserve(_size + 1);
				}
				_size++;
				// std::cout << "reserve ok\n";
				size_type r_i = _size - 1;
				while (r_i > i)
				{
					_elts[r_i] = _elts[r_i - 1];
					r_i--;
				}
				// std::cout << "while  ok\n";
				_alloc.construct(&_elts[i], val);
				// std::cout << "op=  ok val = " << _elts[i] << "\n";
				return (iterator(&_elts[i]));
			}

    		void insert (iterator position, size_type n, const value_type& val)
			{
				while (n--)
				{
					// std::cout << "n = " << n << "\n";
					position = insert(position, val);
				}
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					// std::cout << "while insert input\n";
					position = insert(position, *first) + 1;
					first++;
				}
			}

			iterator erase (iterator position)
			{
				iterator pos = position;
				while (pos + 1 != end())
				{
					*pos = *(pos + 1);
					pos++;
				}
				_size--;
				return (pos);
			}

			iterator erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					last--;
				}
				return (first);
			}

			void swap (vector& x)
			{
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
				ft::swap(_elts, x._elts);
				ft::swap(_alloc, x._alloc);
			}

			void clear()
			{
				while (_size)
					pop_back();
			}
	};

	/*
	** Relation operators and swap
	*/

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		size_t i = 0;
		while (i < lhs.size())
		{
			if (lhs[i] != rhs[i])
				return (false);
			i++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_t size;
		if (lhs.size() < rhs.size())
			size = lhs.size();
		else
			size = rhs.size();
		size_t i = 0;
		while (i < size)
		{
			if (lhs[i] != rhs[i])
				return (lhs[i] < rhs[i]);
			i++;
		}
		return (lhs.size() < rhs.size());
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif