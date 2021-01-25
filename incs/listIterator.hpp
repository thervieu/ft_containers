#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include <iostream>
# include <string>

namespace ft
{
	template <class T>
	void	swap(const T &a, const T &b)
	{
		T tmp;

		tmp = a;
		a = b;
		b = tmp;
	};
	template <class T>
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
			pointer	_ptr;
		
		public:

			listIterator(void)
			{};

			listIterator(const listIterator &rhs)
			{
				*this = rhs;
			};

			~listIterator(void)
			{};

			listIterator	&operator=(const listIterator &rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			};

			value_type		&operator&(void)
			{
				return (_ptr->data);
			};

			value_type		*operator*(void)
			{
				return (_ptr->data);
			};

			listIterator	&operator++(void)
			{
				_ptr = _ptr->next;
				return (*this);
			};

			listIterator	&operator++(int)
			{
				listIterator rtn(*this);
				operator++();
				return (*this);
			};

			listIterator	&operator--(void)
			{
				_ptr = _ptr->prev;
				return (*this);
			};

			listIterator	&operator--(int)
			{
				listIterator rtn(*this);
				operator--();
				return (*this);
			};

			bool	operator==(const listIterator &rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			bool	operator!=(const listIterator &rhs) const
			{
				return (_ptr != rhs._ptr);
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
			pointer	_ptr;
		
		public:

			constListIterator(void)
			{};

			constListIterator(const constListIterator &rhs)
			{
				*this = rhs;
			};

			~constListIterator(void)
			{};

			constListIterator	&operator=(const constListIterator &rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			};

			value_type		&operator&(void)
			{
				return (_ptr->data);
			};

			value_type		*operator*(void)
			{
				return (_ptr->data);
			};

			constListIterator	&operator++(void)
			{
				_ptr = _ptr->next;
				return (*this);
			};

			constListIterator	&operator++(int)
			{
				constListIterator rtn(*this);
				operator++();
				return (*this);
			};

			constListIterator	&operator--(void)
			{
				_ptr = _ptr->prev;
				return (*this);
			};

			constListIterator	&operator--(int)
			{
				constListIterator rtn(*this);
				operator--();
				return (*this);
			};

			bool	operator==(const constListIterator &rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			bool	operator!=(const constListIterator &rhs) const
			{
				return (_ptr != rhs._ptr);
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
			pointer	_ptr;
		
		public:

			reverseListIterator(void)
			{};

			reverseListIterator(const reverseListIterator &rhs)
			{
				*this = rhs;
			};

			~reverseListIterator(void)
			{};

			reverseListIterator	&operator=(const reverseListIterator &rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			};

			value_type		&operator&(void)
			{
				return (_ptr->data);
			};

			value_type		*operator*(void)
			{
				return (_ptr->data);
			};

			reverseListIterator	&operator++(void)
			{
				_ptr = _ptr->prev;
				return (*this);
			};

			reverseListIterator	&operator++(int)
			{
				reverseListIterator rtn(*this);
				operator++();
				return (*this);
			};

			reverseListIterator	&operator--(void)
			{
				_ptr = _ptr->next;
				return (*this);
			};

			reverseListIterator	&operator--(int)
			{
				reverseListIterator rtn(*this);
				operator--();
				return (*this);
			};

			bool	operator==(const reverseListIterator &rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			bool	operator!=(const reverseListIterator &rhs) const
			{
				return (_ptr != rhs._ptr);
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
			pointer	_ptr;
		
		public:

			constReverseListIterator(void)
			{};

			constReverseListIterator(const constReverseListIterator &rhs)
			{
				*this = rhs;
			};

			~constReverseListIterator(void)
			{};

			constReverseListIterator	&operator=(const constReverseListIterator &rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			};

			value_type		&operator&(void)
			{
				return (_ptr->data);
			};

			value_type		*operator*(void)
			{
				return (_ptr->data);
			};

			constReverseListIterator	&operator++(void)
			{
				_ptr = _ptr->prev;
				return (*this);
			};

			constReverseListIterator	&operator++(int)
			{
				constReverseListIterator rtn(*this);
				operator++();
				return (*this);
			};

			constReverseListIterator	&operator--(void)
			{
				_ptr = _ptr->next;
				return (*this);
			};

			constReverseListIterator	&operator--(int)
			{
				constReverseListIterator rtn(*this);
				operator--();
				return (*this);
			};

			bool	operator==(const constReverseListIterator &rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			bool	operator!=(const constReverseListIterator &rhs) const
			{
				return (_ptr != rhs._ptr);
			};
	};
}

#endif