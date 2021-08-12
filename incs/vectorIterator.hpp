/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:28:07 by user42            #+#    #+#             */
/*   Updated: 2021/08/12 16:17:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

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

			vectorIterator(const constVectorIterator<T>& )
			{}

		public:

			vectorIterator(pointer ptr = NULL) : _ptr(ptr)
			{}

			vectorIterator(const vectorIterator & rhs) : _ptr(rhs._ptr)
			{}

			~vectorIterator()
			{}

			vectorIterator& operator=(const vectorIterator & it)
			{
				if (this != &it)
					this->_ptr = it._ptr;
				return (*this);
			}

			bool operator==(const vectorIterator& it) const
			{
				return (this->_ptr == it._ptr);
			}

			bool operator!=(const vectorIterator& it) const
			{
				return (this->_ptr != it._ptr);
			}

			reference operator*() const
			{
				return (*this->_ptr);
			}
	
			reference operator[](size_t n)
			{
				return (this->_ptr[n]);
			}
	
			pointer operator->() const
			{
				return (this->_ptr);
			}

			vectorIterator& operator++()
			{
				this->_ptr++;
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
				this->_ptr--;
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
				return (vectorIterator(this->_ptr + n));
			}

			difference_type operator+(const vectorIterator& rhs) const
			{
				return (this->_ptr + rhs._ptr);
			}

			vectorIterator operator-(difference_type n) const
			{
				return (vectorIterator(this->_ptr - n));
			}

			difference_type operator-(const vectorIterator& rhs) const
			{
				return (this->_ptr - rhs._ptr);
			}

			friend vectorIterator operator+(difference_type n, const vectorIterator& rhs)
			{
				return (rhs.operator+(n));
			}

			vectorIterator& operator+=(int n)
			{
				this->_ptr += n;
				return (*this);
			}

			vectorIterator& operator-=(int n)
			{
				this->_ptr -= n;
				return (*this);
			}

			bool operator<(const vectorIterator& rhs) const
			{
				return (this->_ptr < rhs._ptr);
			}

			bool operator>(const vectorIterator& rhs) const
			{
				return (this->_ptr > rhs._ptr);
			}

			bool operator<=(const vectorIterator& rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			}

			bool operator>=(const vectorIterator& rhs) const
			{
				return (this->_ptr >= rhs._ptr);
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
			
			const_reference operator[](size_t)
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

			constVectorIterator& operator=(const constVectorIterator& rhs)
			{
				if (this != &rhs) 
					this->_ptr = rhs._ptr;
				return (*this);
			}

			bool operator<(const constVectorIterator& rhs) const
			{
				return (this->_ptr < rhs._ptr);
			}

			bool operator>(const constVectorIterator& rhs) const
			{
				return (this->_ptr > rhs._ptr);
			}

			bool operator<=(const constVectorIterator& rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			}

			bool operator>=(const constVectorIterator& rhs) const
			{
				return (this->_ptr >= rhs._ptr);
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

			reverseVectorIterator(const constReverseVectorIterator<T> &)
			{}

		public:

			reverseVectorIterator(pointer ptr = NULL)
			: _base(vectorIterator<T>(ptr))
			{}

			explicit reverseVectorIterator(vectorIterator<T> rhs) : _base(--rhs)
			{}

			reverseVectorIterator(const reverseVectorIterator<T>& rhs)
			: _base(rhs._base)
			{}

			vectorIterator<T> base() const
			{
				vectorIterator<T> tmp(_base);
				return (++tmp);
			}

			reverseVectorIterator& operator=(const reverseVectorIterator& rhs)
			{
				if (this != &rhs)
					_base = rhs._base;
				return (*this);
			}

			bool operator==(const reverseVectorIterator& rhs) const
			{
				return _base.operator==(rhs._base);
			}

			bool operator!=(const reverseVectorIterator& rhs) const
			{
				return _base.operator!=(rhs._base);
			}

			bool operator<(const reverseVectorIterator& rhs) const
			{
				return _base.operator>(rhs._base);
			}

			bool operator<=(const reverseVectorIterator& rhs) const
			{
				return _base.operator>=(rhs._base);
			}

			bool operator>(const reverseVectorIterator& rhs) const
			{
				return _base.operator<(rhs._base);
			}

			bool operator>=(const reverseVectorIterator& rhs) const
			{
				return _base.operator<=(rhs._base);
			}

			reference operator[](size_t n)
			{
				return _base[-n];
			}

			
			reference operator*() const
			{
				return (*(vectorIterator<T>(_base)));
			}

			pointer operator->() const
			{
				return (&this->operator*());
			}

			friend reverseVectorIterator operator+(difference_type n, const reverseVectorIterator& rhs)
			{
				return (rhs.operator+(n));
			}

			reverseVectorIterator operator+(difference_type n) const
			{
				reverseVectorIterator tmp(*this);
				tmp._base.operator-=(n);
				return (tmp);
			}

			difference_type operator+(const reverseVectorIterator& rhs) const
			{
				return (rhs.base().operator-(_base + 1));
			}

			reverseVectorIterator operator-(difference_type n) const
			{
				reverseVectorIterator tmp(*this);
				tmp._base.operator+=(n);
				return (tmp);
			}

			difference_type operator-(const reverseVectorIterator& rhs) const
			{
				return (rhs.base().operator-(_base + 1));
			}

			reverseVectorIterator& operator+=(int n)
			{
				_base.operator-=(n);
				return (*this);
			}

			reverseVectorIterator& operator-=(int n)
			{
				_base.operator+=(n);
				return (*this);
			}

			reverseVectorIterator& operator++()
			{
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
				_base.operator++();
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
			typedef T*			pointer;
			typedef T const &	const_reference;
			typedef T const *	const_pointer;

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

			constReverseVectorIterator& operator=(const constReverseVectorIterator& rhs)
			{
				if (this != &rhs) 
					this->_base = rhs._base;
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
