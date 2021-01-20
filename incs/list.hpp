#ifndef LIST_HPP
# define LIST_HPP

# include "listIterator.hpp"

namespace ft
{
	template < class T, class Alloc = allocator<T> >
	class list;
	{
		public:
		
			typedef T value_type;

			typedef Alloc allocator_type;

			typedef T& reference;
			typedef T& const_reference;
			typedef T* pointer;
			typedef T* const_pointer;
			typedef T value_type;

			typedef listIterator<value_type> iterator;
			typedef listIterator<value_type> const_iterator;
			typedef listIterator<value_type> reverse_iterator;
			typedef listIterator<value_type> const_reverse_iterator;

			typedef size_t size_type;

			typedef Node<T>* node;
		
		private:
			
			pointer			_root;
			pointer			_pastTheEnd;

			allocator_type _alloc;

			size_type		_length;
		
		public:

			list(void)
			{};

			list(const list &rhs)
			{
				*this = rhs;
			};

			~list(void)
			{};

			list	&operator=(const list &rhs)
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

			list	&operator++(void)
			{
				_ptr = _ptr->next;
				return (*this);
			};

			list	&operator++(int)
			{
				list rtn(*this);
				operator++();
				return (*this);
			};

			list	&operator--(void)
			{
				_ptr = _ptr->next;
				return (*this);
			};

			list	&operator--(int)
			{
				list rtn(*this);
				operator--();
				return (*this);
			};

			bool	operator==(const list &rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			bool	operator!=(const list &rhs) const
			{
				return (_ptr != rhs._ptr);
			};
	};
}

#endif