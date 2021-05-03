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
				_elts = new T[0];
			}

			explicit vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n)
			{
				_capacity = n;
				_elts = new T[n];
				for (size_type i = 0; i < _size; i++)
					_elts[i] = T(val);
			}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type())
			: _elts(0), _alloc(alloc), _size(0), _capacity(0)
			{
				_elts = new T[0];
				assign(first, last);
			}

			vector (const vector& x)
			{
				_size = x._size;
				_capacity = x._capacity;
				_elts = new T[x._capacity];
				
				for (size_type i = 0; i < x._size; i++)
					_elts[i] = x._elts[i];
			}

			~vector()
			{
				delete[] _elts;
			}

			vector& operator= (const vector& x)
			{
				if (this == &x)
					return (*this);

				delete[] _elts;

				pointer tmp = new T[x._capacity];

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

				pointer tmp = new T[n];
				
				for (size_type i = 0; i < _size; i++)
					tmp[i] = _elts[i];
				delete[] _elts;
				
				_capacity = n;
				_elts = tmp;
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
				insert(begin(), first, last);
			}

			void assign (size_type n, const value_type& val)
			{
				if (empty() == 0)
					clear();
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
				size_type i = 0;
				iterator it = begin();

				while (it + i != position && i < _size)
					i++;
				
				if (_size + 1 > _capacity)
					reserve(_size + 1);
				_size++;

				size_type r_i = _size - 1;
				while (r_i > i)
				{
					_elts[r_i] = _elts[r_i - 1];
					r_i--;
				}
				_elts[i] = val;
				return (iterator(&_elts[i]));
			}

    		void insert (iterator position, size_type n, const value_type& val)
			{
				while (n--)
					position = insert(position, val);
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *first) + 1;
					first++;
				}
			}

			iterator erase (iterator position)
			{
				iterator pos = position;
				while (pos != end())
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
			}

			void clear()
			{
				erase(begin(), end());
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