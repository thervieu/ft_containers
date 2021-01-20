#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include <iostream>
# include <string>

namespace ft
{
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
				_ptr = _ptr->next;
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
}

#endif