#ifndef MAP_HPP
# define MAP_HPP

# include <limits>
# include <memory>

# include "listIterator.hpp"
# include "mapIterator.hpp"

# include <iostream>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map
	{
		public:

			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;

			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
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

			typedef BinaryNode<key_type, mapped_type>* node;

			typedef mapIterator<key_type, mapped_type> iterator;
			typedef constMapIterator<key_type, mapped_type> const_iterator;
			typedef reverseMapIterator<key_type, mapped_type> reverse_iterator;
			typedef constReverseMapIterator<key_type, mapped_type> const_reverse_iterator;

			typedef unsigned long size_type;

		private:

			allocator_type	_allocator;

			key_compare		_compare;

			node			_root;

			size_type		_size;

			node		newNode(key_type _key, mapped_type _mapped, node parent)
			{
				node _node = new BinaryNode<key_type, mapped_type>;
				
				_node->pair = std::make_pair(_key, _mapped);
				
				_node->parent = parent;
				_node->left = 0;
				_node->right = 0;
				
				return (_node);
			};

			void	initTree(void)
			{
				_root = newNode(key_type(), mapped_type(), 0);
				_size = 0;
			};

			node	addNode(node node, key_type key, mapped_type mapped)
			{
				if (key < node->pair.first)
				{
					if (!node->left)
					{
						node->left = newNode(key, mapped, node);
						return (node->left);
					}
					return (addNode(node->left, key, mapped));
				}
				else
				{
					if (!node->right)
					{
						node->right = newNode(key, mapped, node);
						return (node->right);
					}
					return (addNode(node->right, key, mapped));
				}
			};

			void	deleteNode(node _node)
			{
				if (!_node->left && !_node->right)
				{
					if (_node->parent->left == _node)
						_node->parent->left = 0;
					if (_node->parent->right == _node)
						_node->parent->right = 0;
					delete _node;
					return ;
				}
				else if (_node->left && !_node->right)
				{
					if (_node->parent->left == _node)
						_node->parent->left = _node->left;
					if (_node->parent->right == _node)
						_node->parent->right = _node->left;
					_node->left->parent = _node->parent;
					delete _node;
					return ;
				}
				else if (!_node->left && _node->right)
				{
					if (_node->parent->right == _node)
						_node->parent->right = _node->right;
					if (_node->parent->left == _node)
						_node->parent->left = _node->right;
					_node->right->parent = _node->parent;
					delete _node;
					return ;
				}
				node successor = (++iterator(_node)).binaryNode();
				ft::swap(successor->pair, _node->pair);
				deleteNode(successor);
				return ;
			};

			node	findNode(node node, key_type key)
			{
				if (node->parent && node->pair.first == key) // CHECK
					return (node);
				if (node->left)
					return (findNode(node->left, key));
				if (node->right)
					return (findNode(node->right, key));
				return (0);
			};

			void	freeTree(node node)
			{
				if (!node)
					return ;
				freeTree(node->left);
				freeTree(node->right);
				delete node;
			};

		public:

			explicit map (const key_compare& comp = key_compare(),
            	const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _compare(comp)
			{
				_size = 0; 
				initTree();
			}

			template <class InputIterator>
 			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
    			const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _compare(comp)
			{
				_size = 0; 
				initTree();
				insert(first, last);
			}

			map (const map& x)
			: _allocator(x._allocator), _root(x._root), _size(x._size)
			{
			}

			~map(void)
			{
				freeTree(_root);
			}

			map	&operator=(const map<key_type, mapped_type>& x)
			{
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

			iterator begin(void)
			{
				node _node = _root;

				if (!_node->left && !_node->right)
					return (_root);
				if (!_node->left && _node->right)
					_node =_node->right;
				while (_node->left)
					_node = _node->left;
				return (iterator(_node));
			}

			const_iterator begin() const
			{
				node _node = _root;

				if (!_node->left && !_node->right)
					return (_root);
				if (!_node->left && _node->right)
					_node =_node->right;
				while (_node->left)
					_node = _node->left;
				return (const_iterator(_node));
			}

			iterator end()
			{
				return (iterator(_root));
			}

			const_iterator end() const
			{
				return (const_iterator(_root));
			}

			reverse_iterator rbegin()
			{
				iterator	it = end();

				it--;
				return (reverse_iterator(it.binaryNode()));
			}

			const_reverse_iterator rbegin() const
			{
				iterator	it = end();

				it--;
				return (const_reverse_iterator(it.binaryNode()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(_root));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_root));
			}

			bool	empty(void)
			{
				return (_size == 0);
			}

			size_type size(void) const
			{
				return (_size);
			}

			size_type max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(BinaryNode<key_type, mapped_type>));
			}

			mapped_type& operator[] (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
					return (it->second);
				return (insert(std::make_pair(k, mapped_type())).first->second);
			}

			//https://stackoverflow.com/questions/23421639/return-false-or-value-c
			std::pair<iterator,bool> insert (const value_type& val)
			{
				iterator	it;

				if ((it = find(val.first)) != end())
					return (std::make_pair(it, false));
				_size++;
				return (std::make_pair(iterator(addNode(_root, val.first, val.second)), true));
			}

			iterator insert (iterator position, const value_type& val)
			{
				iterator	it;
				if ((it = find(val.first)) != end())
					return (it);
				_size++;
				return (iterator(addNode(position.binaryNode(), val.first, val.second)));
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void erase (iterator position)
			{
				deleteNode(position.binaryNode());
				_size--;
			}

			size_type erase (const key_type& k)
			{
				size_type	rtn = 0;
				iterator	it;

				while ((it = find(k)) != end())
				{
					erase(it);
					rtn++;
				}
				return (rtn);
			}

			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
			}

			void swap (map<key_type, mapped_type>& x)
			{
				ft::swap(_root, x._root);
				ft::swap(_size, x._size);
			}

			void clear()
			{
				erase(begin(), end());
			}

			key_compare key_comp() const
			{
				return (_compare);
			}

			value_compare value_comp() const
			{
				return (value_compare());
			}

			iterator find (const key_type& k)
			{
				if (empty())
					return (end());
				node _node = findNode(_root, k);
				if (_node)
					return (iterator(_node));
				return (end());
			}

			const_iterator find (const key_type& k) const
			{
				if (empty())
					return (end());
				node _node = findNode(_root, k);
				if (_node)
					return (const_iterator(_node));
				return (end());
			}

			size_type count (const key_type& k) const
			{
				size_type rtn = 0;
				const_iterator it = begin();

				while (it != end())
				{
					if (it->first == k)
						rtn++;
					it++;
				}
				return (rtn);
			}

			iterator lower_bound(const key_type &key)
			{
				iterator it = begin();
				while (it != end())
				{
					if (this->_compare(it->first, key) <= 0)
						return (it);
					++it;
				}
				return (end());
			}

			const_iterator lower_bound(const key_type &key) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (this->_compare(it->first, key) <= 0)
						return (it);
					++it;
				}
				return (end());
			}

			iterator upper_bound(const key_type &key)
			{
				iterator it = begin();
				while (it != end())
				{
					if (it->first != key && this->_compare(it->first, key) <= 0)
						return (it);
					++it;
				};
				return (end());
			};
			const_iterator upper_bound(const key_type &key) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (it->first != key && this->_compare(it->first, key) <= 0)
						return (it);
					++it;
				};
				return (end());
			}

			std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

			std::pair<iterator, iterator> equal_range(const key_type &k)
			{
				return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

	};

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it = rhs.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = lhs.begin();
		while (it != rhs.end())
		{
			if (*it != *it2)
				return (false);
			++it2;
			++it;
		}
		return (true);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return (true);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
		while (it != lhs.end() && it2 != rhs.end())
		{
			if (*it > *it2)
				return (true);
			++it2;
			++it;
		}
		return (false);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs) && !(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs));
	};
}

#endif