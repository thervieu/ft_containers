#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

/*
** all functions implemented are those of stack cpp++98
** See: https://www.cplusplus.com/reference/stack/stack/
** Please note that std::stack is actually implmented using the std::deque function.
** However in the pdf of the school project,they specifically ask us to use vector (which is enough as it has the right functions)
*/

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			typedef T				value_type;
			typedef Container		container_type;
			typedef	unsigned long size_type;

		protected:

			container_type c;

		public:

			explicit stack (const container_type& ctnr = container_type())
			: c(ctnr)
			{};

			bool	empty(void) const
			{
				return (c.empty());
			};

			size_type	size(void) const
			{
				return (c.size());
			};

			value_type& top()
			{
				return (c.back());
			};

			const value_type& top() const
			{
				return (c.back());
			};

			void push (const value_type& val)
			{
				c.push_back(val);
			};

			void	pop(void)
			{
				c.pop_back();
			};
		
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
		
	};

	/*
	** Relation operators and swap
	*/

	template <class T, class Container>
	bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	};
	
	template <class T, class Container>
	bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	};
	
	template <class T, class Container>
	bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	};
	
	template <class T, class Container>
	bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	};
	
	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	};
	
	template <class T, class Container>
	bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	};
}

#endif