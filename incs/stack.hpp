#ifndef STACK_HPP
# define STACK_HPP

# include "list.hpp"

/*
** all functions implemented are those of stack (c++98)
** See: https://www.cplusplus.com/reference/stack/stack/
** Please note that std::stack is actually implmented using the std::deque function.
** However in the pdf of the school project, implementing dequ is a bonus that I do not wish to implement.
** Besides, using list is sufficient as stated in the link above (container list has the sufficient functions)
*/

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class stack
	{
		public:

			typedef T value_type;
			typedef Container container_type;
			typedef	unsigned long size_type;

		protected:

			container_type _container;

		public:

			explicit stack (const container_type& ctnr = container_type())
			: _container(ctnr)
			{};

			bool	empty(void) const
			{
				return (_container.empty());
			};

			size_type	size(void) const
			{
				return (_container.size());
			};

			value_type& top()
			{
				return (_container.back());
			};

			const value_type& top() const
			{
				return (_container.back());
			};

			void push (const value_type& val)
			{
				_container.push_back(val);
			};

			void	pop(void)
			{
				_container.pop_back();
			};
		/*
		private:

			template <class A, class B>
			friend bool	operator==(const stack<A, B> &lhs, const stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator!=(const stack<A, B> &lhs, const stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator<(const stack<A, B> &lhs, const stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator<=(const stack<A, B> &lhs, const stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator>(const stack<A, B> &lhs, const stack<A, B> &rhs);
			template <class A, class B>
			friend bool	operator>=(const stack<A, B> &lhs, const stack<A, B> &rhs);	
		*/
	};

	/*
	** Relation operators and swap
	*/

	template <class T, class Container>
	bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._container == rhs._container);
	};
	
	template <class T, class Container>
	bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._container != rhs._container);
	};
	
	template <class T, class Container>
	bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._container > rhs._container);
	};
	
	template <class T, class Container>
	bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._container < rhs._container);
	};
	
	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._container >= rhs._container);
	};
	
	template <class T, class Container>
	bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._container <= rhs._container);
	};
}

#endif