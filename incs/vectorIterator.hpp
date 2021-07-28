/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:28:07 by user42            #+#    #+#             */
/*   Updated: 2021/07/28 10:42:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <stddef.h>
# include <iostream>

namespace ft
{
	template<class T> class constVectorIterator;

	template<class T>
	class vectorIterator
	{
		public:

			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef value_type*						pointer;
			typedef value_type&						reference;

		protected:

			pointer	_ptr;

		private:

			vectorIterator(const constVectorIterator<T>& ) {}

		public:

			vectorIterator(pointer ptr = NULL) : _ptr(ptr) {}
			
			vectorIterator(const vectorIterator & rhs) : _ptr(rhs._ptr) {}
			
			~vectorIterator() {}

			vectorIterator& operator=(const vectorIterator & it)
			{
				// std::cout << "op= It\n";
				if (this != &it)
					_ptr = it._ptr;
				return (*this);
			}

			bool operator==(const vectorIterator& it) const
			{
				return (_ptr == it._ptr);
			}
			
			bool operator!=(const vectorIterator& it) const
			{
				return (_ptr != it._ptr);
			}
			
			reference operator*() const
			{
				return (*_ptr);
			}
				
			reference operator[](size_t n)
			{
				return (_ptr[n]);
			}
				
			pointer operator->() const
			{
				return (_ptr);
			}

			vectorIterator& operator++()
			{
				_ptr++;
				return (*this);
			}
			
			vectorIterator operator++(int)
			{
				vectorIterator tmp(*this);
				++(*this);
				return (tmp);
			}
			
			vectorIterator& operator--()
			{
				_ptr--;
				return (*this);
			}
			
			vectorIterator operator--(int)
			{
				vectorIterator tmp(*this);
				--(*this);
				return (tmp);
			}
			
			vectorIterator operator+(difference_type n) const
			{
				return (vectorIterator(_ptr + n));
			}

			difference_type operator+(const vectorIterator& other) const
			{
				return (_ptr + other._ptr);
			}
			
			vectorIterator operator-(difference_type n) const
			{
				return (vectorIterator(_ptr - n));
			}
			
			difference_type operator-(const vectorIterator& other) const
			{
				return (_ptr - other._ptr);
			}
			
			friend vectorIterator operator+(difference_type n, const vectorIterator& other)
			{
				return (other.operator+(n));
			}
			
			vectorIterator& operator+=(int n)
			{
				_ptr += n;
				return (*this);
			}
			
			vectorIterator& operator-=(int n)
			{
				_ptr -= n;
				return (*this);
			}
			
			bool operator<(const vectorIterator& other) const
			{
				return (_ptr < other._ptr);
			}
			
			bool operator>(const vectorIterator& other) const
			{
				return (_ptr > other._ptr);
			}
			
			bool operator<=(const vectorIterator& other) const
			{
				return (_ptr <= other._ptr);
			}
			
			bool operator>=(const vectorIterator& other) const
			{
				return (_ptr >= other._ptr);
			}
	};

	template<class T>
	class constVectorIterator : public vectorIterator<T>
	{
		public:

			typedef T*			pointer;
			typedef T const &	const_reference;
			typedef T const *	const_pointer;

		private:
			
			const_reference operator[](size_t )
			{
				return (this->_ptr);
			}
		
			
		public:

			constVectorIterator(pointer ptr = NULL)
			{
				this->_ptr = ptr;
			}
			
			constVectorIterator(const vectorIterator<T>& rhs)
			{
				this->_ptr = rhs.operator->();
			}

			constVectorIterator& operator=(const constVectorIterator& it)
			{
				// std::cout << "op= constIt\n";
				if (this != &it) 
					this->_ptr = it._ptr;
				return (*this);
			}
			
			bool operator<(const constVectorIterator& other) const
			{
				return (this->_ptr < other._ptr);
			}
			
			bool operator>(const constVectorIterator& other) const
			{
				return (this->_ptr > other._ptr);
			}
			
			bool operator<=(const constVectorIterator& other) const
			{
				return (this->_ptr <= other._ptr);
			}
			
			bool operator>=(const constVectorIterator& other) const
			{
				return (this->_ptr >= other._ptr);
			}
			
			const_reference operator*() const
			{
				return (*this->_ptr);
			}
			
			const_pointer operator->() const
			{
				return (this->_ptr);
			}
			
	};
	
	template<class T> class constReverseVectorIterator;

	template<class T>
	class reverseVectorIterator
	{
		public:

			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef value_type*						pointer;
			typedef value_type&						reference;

		protected:

			vectorIterator<T>						_base;

		private:

			reverseVectorIterator(const constReverseVectorIterator<T> & ) {}

		public:

			reverseVectorIterator(pointer ptr = NULL)
			: _base(vectorIterator<T>(ptr)) {
				// std::cout << "rev(ptr) revIt\n";

			}
			
			explicit reverseVectorIterator(vectorIterator<T> rhs) : _base(--rhs)
			{
				// for (int i = 0; i < 5; i++)
				// 	std::cout << *(rhs--) << "\n";
				// std::cout << "rev(vec) revIt\n";
			}

			reverseVectorIterator(const reverseVectorIterator<T>& rev_it)
			: _base(rev_it._base) {
				// std::cout << "rev(const Rev) revIt\n";
			}

			vectorIterator<T> base() const
			{
				// std::cout << "base revIt\n";
				vectorIterator<T> tmp(_base);
				return (++tmp);
			}

			reverseVectorIterator& operator=(const reverseVectorIterator& it)
			{
				// std::cout << "op= revIt\n";
				if (this != &it)
					_base = it._base;
				return (*this);
			}
			
			bool operator==(const reverseVectorIterator& rhs) const
			{
				return this->_base.operator==(rhs._base);
			}
			
			bool operator!=(const reverseVectorIterator& rhs) const
			{
				return this->_base.operator!=(rhs._base);
			}
			
			bool operator<(const reverseVectorIterator& rhs) const
			{
				return this->_base.operator>(rhs._base);
			}
			
			bool operator<=(const reverseVectorIterator& rhs) const
			{
				return this->_base.operator>=(rhs._base);
			}
			
			bool operator>(const reverseVectorIterator& rhs) const
			{
				return this->_base.operator<(rhs._base);
			}
			
			bool operator>=(const reverseVectorIterator& rhs) const
			{
				return this->_base.operator<=(rhs._base);
			}
			
			reference operator[](size_t n)
			{
				return this->_base[-n];
			}
			
			
			reference operator*() const
			{
				return (*(vectorIterator<T>(this->_base)));
			}
			
			pointer operator->() const
			{
				return (&this->operator*());
			}
			
			friend reverseVectorIterator operator+(difference_type n, const reverseVectorIterator& other)
			{
				return (other.operator+(n));
			}
			
			reverseVectorIterator operator+(difference_type n) const
			{
				reverseVectorIterator tmp(*this);
				tmp._base.operator-=(n);
				return (tmp);
			}
			
			difference_type operator+(const reverseVectorIterator& other) const
			{
				return (other.base().operator-(this->_base + 1));
			}
			
			reverseVectorIterator operator-(difference_type n) const
			{
				reverseVectorIterator tmp(*this);
				tmp._base.operator+=(n);
				return (tmp);
			}
			
			difference_type operator-(const reverseVectorIterator& other) const
			{
				return (other.base().operator-(this->_base + 1));
			}
			reverseVectorIterator& operator+=(int n)
			{
				this->_base.operator-=(n);
				return (*this);
			}
			
			reverseVectorIterator& operator-=(int n)
			{
				this->_base.operator+=(n);
				return (*this);
			}
			
			reverseVectorIterator& operator++()
			{
				// this->_base.operator--();
				--_base;
				return (*this);
			}
			
			reverseVectorIterator operator++(int)
			{
				reverseVectorIterator tmp(*this);
				++(*this);
				return (tmp);
			}
			
			reverseVectorIterator& operator--()
			{
				this->_base.operator++();
				return (*this);
			}
			
			reverseVectorIterator operator--(int)
			{
				reverseVectorIterator tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template<class T>
	class constReverseVectorIterator : public reverseVectorIterator<T>
	{
		public:

			typedef T const &	const_reference;
			typedef T const *	const_pointer;
			typedef T*			pointer;

			explicit constReverseVectorIterator(vectorIterator<T> rhs)
			{
				vectorIterator<T> tmp(rhs);
				this->_base = --tmp;
			}
			
			constReverseVectorIterator(pointer ptr = NULL)
			{
				this->_base = vectorIterator<T>(ptr);
			}
			
			constReverseVectorIterator(constVectorIterator<T> & rhs)
			{
				pointer ptr = const_cast<pointer>(rhs.operator->());
				vectorIterator<T> tmp(ptr);
				this->_base = tmp;
			}
			
			constReverseVectorIterator(const reverseVectorIterator<T>& rhs)
			{
				this->_base = rhs.operator->();
			}

			constReverseVectorIterator& operator=(const constReverseVectorIterator& it)
			{
				if (this != &it) 
					this->_base = it._base;
				return (*this);
			}
			
			const_reference operator*() const
			{
				return (*(vectorIterator<T>(this->_base)));
			}
			
			const_pointer operator->() const
			{
				return (&this->operator*());
			}
			
	};
}

#endif