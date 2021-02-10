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

			
	}
}