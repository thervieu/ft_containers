#ifndef MAP_HPP
# define MAP_HPP

# include <limits>
# include <memory>

# include "mapIterator.hpp"

# include <iostream>

namespace ft
{
	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<std::pair<const Key,T> > >
	class map
	{
		public:

			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;

			class map<Key,T,Compare,Alloc>::value_compare
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;

				protected:
				
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				
				public:
				
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					};
			};

			typedef Alloc allocator_type;

			typedef T& reference;
			typedef T& const_reference;
			typedef T* pointer;
			typedef T* const_pointer;

			typedef BinaryNode<key_type, mapped_type> node;

			typedef mapIterator<key_type, mapped_type> iterator;
			typedef constMapIterator<key_type, mapped_type> const_iterator;
			typedef reverseMapIterator<key_type, mapped_type> reverse_iterator;
			typedef constReverseMapIterator<key_type, mapped_type> const_reverse_iterator;

			typedef unsigned long size_type;

		private:

			allocator_type	_allocator;

			key_compare		_compare;

			node			_root;

			size_type		_length;

			//NEWNODE, INITTREE, ADD, FIND, DELETE, FREE

		public:

			explicit map (const key_compare& comp = key_compare(),
            	const allocator_type& alloc = allocator_type())
			{

			}

			template <class InputIterator>
 			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
    			const allocator_type& alloc = allocator_type())
			{

			}

			map (const map& x)
			{

			}

			~map(void)
			{
				//free
			}

			map	&operator=(const map<key_type, mapped_type>& x)
			{

			}

			iterator begin()
			{

			}

			const_iterator begin() const
			{

			}

			iterator end()
			{

			}

			const_iterator end() const
			{
				
			}

			reverse_iterator rbegin()
			{

			}

			const_reverse_iterator rbegin() const
			{

			}

			reverse_iterator rend()
			{

			}

			const_reverse_iterator rend() const
			{
				
			}

			bool	empty(void)
			{

			}

			size_type size(void) const
			{

			}

			size_type max_size(void) const
			{

			}

			mapped_type& operator[] (const key_type& k)
			{

			}

			std::pair<iterator,bool> insert (const value_type& val)
			{

			}

			iterator insert (iterator position, const value_type& val)
			{

			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)\
			{

			}

			void erase (iterator position)
			{

			}

			size_type erase (const key_type& k)
			{

			}

			void erase (iterator first, iterator last)
			{

			}

			void swap (map<key_type, mapped_type>& x)
			{

			}

			void clear()
			{

			}

			key_compare key_comp() const
			{

			}

			value_compare value_comp() const
			{

			}

			iterator find (const key_type& k)
			{

			}

			const_iterator find (const key_type& k) const
			{

			}

			size_type count (const key_type& k) const
			{

			}

			iterator lower_bound (const key_type& k)
			{

			}

			const_iterator lower_bound (const key_type& k) const
			{

			}

			iterator upper_bound (const key_type& k)
			{

			}

			const_iterator upper_bound (const key_type& k) const
			{
				
			}

			std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{

			}

			std::pair<iterator,iterator>             equal_range (const key_type& k)
	};

	
}

#endif