#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "vectorIterator.hpp"

# include <limits>
# include <memory>
# include <iostream>
# include <stdio.h>

namespace ft
{
	template <class T, class Alloc=std::allocator<T> >
	class vectorIterator
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
					_elts[i] = T(value);
			}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type())
			: _elts(0), _alloc(alloc), _size(0), _capacity(0)
			{
				_elts = new T[0];
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			vector (const vector& x)
			{
				_capacity = x.capacity;
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
				if (this = &x)
					return (*this);
				if (x._size < _capacity)
				{
					for (size_type i = 0; i < x._size; i++)
						_elts[i] = x._elts[i];
					_size = x._size;
					return (*this);
				}

				delete[] _elts;

				pointer tmp = new T[x._capacity];

				for (size_type i = 0; i < x._size; i++)
					tmp[i] = x._elts[i];
				
				_size = x._size;
				_capacity = x._capacity;
				_elts = tmp;

				return (*this);
			}

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

			}

			reference operator[] (size_type n)
			{
				return (_elts[n]);
			}

			const_reference operator[] (size_type n) const
			{
				return (_elts[n]);
			}

			reference at (size_type n);
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

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{

			}

			void assign (size_type n, const value_type& val)
			{

			}

			void push_back (const value_type& val)
			{

			}
	

			void pop_back()
			{
				
			}

			iterator insert (iterator position, const value_type& val)
			{

			}

    		void insert (iterator position, size_type n, const value_type& val)
			{

			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
			{

			}

			iterator erase (iterator position)
			{

			}

			iterator erase (iterator first, iterator last)
			{

			}

			void swap (vector& x)
			{

			}

			void clear()
			{

			}
	}
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{

	}
}

#endif