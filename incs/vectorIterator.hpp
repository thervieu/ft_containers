/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:54:05 by user42            #+#    #+#             */
/*   Updated: 2021/01/29 16:04:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft
{
	template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};

	template <class T>
	class vectorIterator
	{
		public:
		
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		
		protected:

			pointer _ptr;

		public:
			
			vectorIterator(void)
			{};
			
			vectorIterator(const vectorIterator &other)
			{
				*this = other;
			};
			
			vectorIterator(pointer _pt): _ptr(_pt)
			{};
			
			~vectorIterator(void)
			{};
			
			vectorIterator	&operator=(const vectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			vectorIterator	&operator++(void)
			{
                _ptr++;
				return (*this);
			};

			vectorIterator	operator++(int)
			{
				vectorIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			vectorIterator	&operator--(void)
			{
                _ptr--;
				return (*this);
			};

			vectorIterator	operator--(int)
			{
				vectorIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			bool operator==(const vectorIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const vectorIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const vectorIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const vectorIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const vectorIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const vectorIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (*_ptr);
			};
			
			value_type	*operator->(void)
			{
				return (_ptr);
			};
			
			vectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
				return (*this);
			};
			
			vectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			};

			vectorIterator operator+(int n) const
			{
				vectorIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			vectorIterator operator-(int n) const
			{
				vectorIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};

            value_type  operator[](int n) const
            {
                return (*(this + n));
            };
    };
	template <class T>
	class constVectorIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		
		protected:
			pointer _ptr;

		public:
			
			constVectorIterator(void)
			{};
			
			constVectorIterator(const constVectorIterator &other)
			{
				*this = other;
			};
			
			constVectorIterator(pointer _pt): _ptr(_pt)
			{};
			
			~constVectorIterator(void)
			{};
			
			constVectorIterator	&operator=(const constVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			constVectorIterator	&operator++(void)
			{
                _ptr++;
				return (*this);
			};

			constVectorIterator	operator++(int)
			{
				constVectorIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			constVectorIterator	&operator--(void)
			{
                _ptr--;
				return (*this);
			};

			constVectorIterator	operator--(int)
			{
				constVectorIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			bool operator==(const constVectorIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const constVectorIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const constVectorIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const constVectorIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const constVectorIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const constVectorIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (*_ptr);
			};
			
			value_type	&operator->(void)
			{
				return (_ptr);
			};
			
			constVectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
			};
			
			constVectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
			};

			constVectorIterator operator+(int n) const
			{
				constVectorIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			constVectorIterator operator-(int n) const
			{
				constVectorIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};

            value_type  operator[](int n) const
            {
                return (*(this + n));
            };
    };
	template <class T>
	class reverseVectorIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		
		protected:
			pointer _ptr;

		public:
			
			reverseVectorIterator(void)
			{};
			
			reverseVectorIterator(const reverseVectorIterator &other)
			{
				*this = other;
			};
			
			reverseVectorIterator(pointer _pt): _ptr(_pt)
			{};
			
			~reverseVectorIterator(void)
			{};
			
			reverseVectorIterator	&operator=(const reverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			
			bool operator==(const reverseVectorIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const reverseVectorIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const reverseVectorIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const reverseVectorIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const reverseVectorIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const reverseVectorIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (*_ptr);
			};
			
			value_type	&operator->(void)
			{
				return (_ptr);
			};
			
			reverseVectorIterator	&operator++(void)
			{
                _ptr--;
				return (*this);
			};

			reverseVectorIterator	operator++(int)
			{
				reverseVectorIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			reverseVectorIterator	&operator--(void)
			{
                _ptr++;
				return (*this);
			};

			reverseVectorIterator	operator--(int)
			{
				reverseVectorIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			reverseVectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
			};
			
			reverseVectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
			};

			reverseVectorIterator operator+(int n) const
			{
				reverseVectorIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			reverseVectorIterator operator-(int n) const
			{
				reverseVectorIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};

            value_type  operator[](int n) const
            {
                return (*(this + n));
            };
    };
	template <class T>
	class constReverseVectorIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		
		protected:
			pointer _ptr;

		public:
			
			constReverseVectorIterator(void)
			{};
			
			constReverseVectorIterator(const constReverseVectorIterator &other)
			{
				*this = other;
			};
			
			constReverseVectorIterator(pointer _pt): _ptr(_pt)
			{};
			
			~constReverseVectorIterator(void)
			{};
			
			constReverseVectorIterator	&operator=(const constReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			
			bool operator==(const constReverseVectorIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const constReverseVectorIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const constReverseVectorIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const constReverseVectorIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const constReverseVectorIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const constReverseVectorIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (*_ptr);
			};
			
			value_type	&operator->(void)
			{
				return (_ptr);
			};
			
			constReverseVectorIterator	&operator++(void)
			{
                _ptr--;
				return (*this);
			};

			constReverseVectorIterator	operator++(int)
			{
				constReverseVectorIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			constReverseVectorIterator	&operator--(void)
			{
                _ptr++;
				return (*this);
			};

			constReverseVectorIterator	operator--(int)
			{
				constReverseVectorIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			constReverseVectorIterator &operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
			};
			
			constReverseVectorIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
			};

			constReverseVectorIterator operator+(int n) const
			{
				constReverseVectorIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			constReverseVectorIterator operator-(int n) const
			{
				constReverseVectorIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};

            value_type  operator[](int n) const
            {
                return (*(this + n));
            };
	};
}

#endif