/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:54:05 by user42            #+#    #+#             */
/*   Updated: 2021/01/29 16:04:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

namespace ft
{
	template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};

	template <typename T>
	struct Node
	{
		T data;
		Node *prev;
		Node *next;
	};
	template <class T>
	class listIterator
	{
		public:
		
			typedef T value_type;
			typedef T& reference;
			typedef Node<T>* pointer;
		
		protected:

			pointer _ptr;

		public:
			
			listIterator(void)
			{};
			
			listIterator(const listIterator &other)
			{
				*this = other;
			};
			
			listIterator(pointer _pt): _ptr(_pt)
			{};
			
			~listIterator(void)
			{};
			
			pointer	node(void)
			{
				return (this->_ptr);
			};
			
			listIterator	&operator=(const listIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			listIterator	&operator++(void)
			{
				this->_ptr = this->_ptr->next;
				return (*this);
			};

			listIterator	operator++(int)
			{
				listIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			listIterator	&operator--(void)
			{
				this->_ptr = this->_ptr->prev;
				return (*this);
			};

			listIterator	operator--(int)
			{
				listIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			bool operator==(const listIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const listIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const listIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const listIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const listIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const listIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (this->_ptr->data);
			};
			
			value_type	*operator->(void)
			{
				return (this->_ptr->data);
			};
			
			listIterator &operator+=(int n)
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
			
			listIterator &operator-=(int n)
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

			listIterator operator+(int n) const
			{
				listIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			listIterator operator-(int n) const
			{
				listIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};
	};
	template <class T>
	class constListIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef Node<T>* pointer;
		
		protected:
			pointer _ptr;

		public:
			
			constListIterator(void)
			{};
			
			constListIterator(const constListIterator &other)
			{
				*this = other;
			};
			
			constListIterator(pointer _pt): _ptr(_pt)
			{};
			
			~constListIterator(void)
			{};
			
			pointer	node(void)
			{
				return (this->_ptr);
			};
			
			constListIterator	&operator=(const constListIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			constListIterator	&operator++(void)
			{
				this->_ptr = this->_ptr->next;
				return (*this);
			};

			constListIterator	operator++(int)
			{
				constListIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			constListIterator	&operator--(void)
			{
				this->_ptr = this->_ptr->prev;
				return (*this);
			};

			constListIterator	operator--(int)
			{
				constListIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			bool operator==(const constListIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const constListIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const constListIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const constListIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const constListIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const constListIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (this->_ptr->data);
			};
			
			value_type	&operator->(void)
			{
				return (this->_ptr->data);
			};
			
			constListIterator &operator+=(int n)
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
			
			constListIterator &operator-=(int n)
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

			constListIterator operator+(int n) const
			{
				constListIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			constListIterator operator-(int n) const
			{
				constListIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};
	};
	template <class T>
	class reverseListIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef Node<T>* pointer;
		
		protected:
			pointer _ptr;

		public:
			
			reverseListIterator(void)
			{};
			
			reverseListIterator(const reverseListIterator &other)
			{
				*this = other;
			};
			
			reverseListIterator(pointer _pt): _ptr(_pt)
			{};
			
			~reverseListIterator(void)
			{};
			
			reverseListIterator	&operator=(const reverseListIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			
			bool operator==(const reverseListIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const reverseListIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const reverseListIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const reverseListIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const reverseListIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const reverseListIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (this->_ptr->data);
			};
			
			value_type	&operator->(void)
			{
				return (this->_ptr->data);
			};
			
			reverseListIterator	&operator++(void)
			{
				this->_ptr = this->_ptr->prev;
				return (*this);
			};

			reverseListIterator	operator++(int)
			{
				reverseListIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			reverseListIterator	&operator--(void)
			{
				this->_ptr = this->_ptr->next;
				return (*this);
			};

			reverseListIterator	operator--(int)
			{
				reverseListIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			reverseListIterator &operator+=(int n)
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
			
			reverseListIterator &operator-=(int n)
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

			reverseListIterator operator+(int n) const
			{
				reverseListIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			reverseListIterator operator-(int n) const
			{
				reverseListIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};
	};
	template <class T>
	class constReverseListIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef Node<T>* pointer;
		
		protected:
			pointer _ptr;

		public:
			
			constReverseListIterator(void)
			{};
			
			constReverseListIterator(const constReverseListIterator &other)
			{
				*this = other;
			};
			
			constReverseListIterator(pointer _pt): _ptr(_pt)
			{};
			
			~constReverseListIterator(void)
			{};
			
			constReverseListIterator	&operator=(const constReverseListIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			
			bool operator==(const constReverseListIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const constReverseListIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const constReverseListIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const constReverseListIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const constReverseListIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const constReverseListIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (this->_ptr->data);
			};
			
			value_type	&operator->(void)
			{
				return (this->_ptr->data);
			};
			
			constReverseListIterator	&operator++(void)
			{
				this->_ptr = this->_ptr->prev;
				return (*this);
			};

			constReverseListIterator	operator++(int)
			{
				constReverseListIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			constReverseListIterator	&operator--(void)
			{
				this->_ptr = this->_ptr->next;
				return (*this);
			};

			constReverseListIterator	operator--(int)
			{
				constReverseListIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			constReverseListIterator &operator+=(int n)
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
			
			constReverseListIterator &operator-=(int n)
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

			constReverseListIterator operator+(int n) const
			{
				constReverseListIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			constReverseListIterator operator-(int n) const
			{
				constReverseListIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};
	};
}

#endif