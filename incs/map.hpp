/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:21:43 by nforay            #+#    #+#             */
/*   Updated: 2021/07/28 10:43:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <limits>
# include <functional>
# include "ft_stl.hpp"
# include "mapIterator.hpp"

namespace ft
{
	/**
	 * @brief Maps are associative containers that store elements formed by a
	 * combination of a key value and a mapped value, following a specific
	 * order. In a map, the key values are generally used to sort and uniquely
	 * identify the elements, while the mapped values store the content
	 * associated to this key. The types of key and mapped value may differ, and
	 * are grouped together in member type value_type, which is a pair type
	 * combining both: typedef pair<const Key, T> value_type;
	 * @tparam Key Type of the keys. Each element in a map is uniquely
	 * identified by its key value.
	 * @tparam T Type of the mapped value. Each element in a map stores some
	 * data as its mapped value.
	 * @tparam Compare A binary predicate that takes two element keys as
	 * arguments and returns a bool.
	 * @tparam Alloc Type of the allocator object used to define the storage
	 * allocation model.
	*/
	template <class Key, class T, class Compare = std::less<Key>
	, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		struct Node
		{
			ft::pair<const Key, T>	val;
			Node*					parent;
			Node*					left;
			Node*					right;
			int						height;
		};

		public:

			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename Alloc::template
			rebind<Node>::other									Node_allocator;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef mapIterator<Key, T, Compare, Node>			iterator;
			typedef constMapIterator<Key, T, Compare, Node>	const_iterator;
			typedef reverseMapIterator<Key, T, Compare, Node>	reverse_iterator;
			typedef constReverseMapIterator<Key, T, Compare, Node>	const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:

			Node*			_root;
			Node*			_lastInsert;
			size_type		_size;
			key_compare		_comp;
			allocator_type	_alloc;

		public:

			/**
			 * @brief empty container constructor (default constructor):
			 * Constructs an empty container, with no elements.
			 * @param comp Binary predicate that, taking two element keys as
			 * argument, returns true if the first argument goes before the
			 * second argument in the strict weak ordering it defines, and false
			 * otherwise. This shall be a function pointer or a function object.
			 * @param alloc Allocator object. The container keeps and uses an
			 * internal copy of this allocator.
			*/
			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _root(NULL), _lastInsert(NULL), _size(0), _comp(comp), _alloc(alloc) {}

			/**
			 * @brief range constructor: Constructs a container with as many
			 * elements as the range [first,last), with each element constructed
			 * from its corresponding element in that range.
			 * @param first,last Input iterators to the initial and final
			 * positions in a range. The range used is [first,last), which
			 * includes all the elements between first and last, including the
			 * element pointed by first but not the element pointed by last.
			 * @param comp Binary predicate that, taking two element keys as
			 * argument, returns true if the first argument goes before the
			 * second argument in the strict weak ordering it defines, and false
			 * otherwise. This shall be a function pointer or a function object.
			 * @param alloc Allocator object. The container keeps and uses an
			 * internal copy of this allocator.
			*/
			template <class InputIterator>
			map(typename ft::enable_if<!std::numeric_limits<InputIterator>
				::is_integer, InputIterator>::type first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _root(NULL), _lastInsert(NULL), _size(0), _comp(comp), _alloc(alloc)
			{
				while (first != last)
					this->insert(*first++);
			}

			/**
			 * @brief Copy constructor: Constructs a container with a copy of
			 * each of the elements in x.
			 * @param x Another map object of the same type (with the same
			 * class template arguments Key, T, Compare and Alloc), whose
			 * contents are either copied or acquired.
			*/
			map(const map& x)
			: _root(NULL), _lastInsert(NULL), _size(0), _comp(key_compare()), _alloc(allocator_type())
			{
				const_iterator ite = x.end();
				for (const_iterator it = x.begin(); it != ite; it++)
					this->insert(*it);
			}

			/**
			 * @brief Map destructor: Destroys the container object.
			 * This destroys all container elements, and deallocates all the
			 * storage capacity allocated by the map container using its
			 * allocator.
			*/
			~map()
			{
				this->clear();
			}

			/**
			 * @brief Copies all the elements from x into the container,
			 * changing its size accordingly.
			 * @return *this
			*/
			map& operator=(const map& x)
			{
				map tmp(x);
				this->swap(tmp);
				return (*this);
			}

/*
** --------------------------------- ITERATORS ---------------------------------
*/

			/**
			 * @brief Returns an iterator referring to the first element in the
			 * map container.
			 * @return An iterator to the first element in the container.
			*/
			iterator begin()
			{
				return (iterator(this->tree_smallest(_root)));
			}

			/**
			 * @brief Returns a const iterator referring to the first element in
			 * the map container.
			 * @return A const iterator to the first element in the container.
			*/
			const_iterator begin() const
			{
				return (const_iterator(this->tree_smallest(_root)));
			}

			/**
			 * @brief Returns an iterator referring to the past-the-end element
			 * in the map container.
			 * @return An iterator to the past-the-end element in the container.
			*/
			iterator end()
			{
				if (this->empty())
					return (iterator());
				return (iterator((this->tree_biggest(_root))->right,
					this->tree_biggest(_root)));
			}

			/**
			 * @brief Returns a const iterator referring to the past-the-end
			 * element in the map container.
			 * @return A const iterator to the past-the-end element in the
			 * container.
			*/
			const_iterator end() const
			{
				if (this->empty())
					return (iterator());
				return (const_iterator((this->tree_biggest(_root))->right,
					this->tree_biggest(_root)));
			}

			/**
			 * @brief Returns a reverse iterator pointing to the last element in
			 * the container (i.e., its reverse beginning).
			 * @return A reverse iterator to the reverse beginning of the
			 * sequence container.
			*/
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->tree_biggest(_root)));
			}

			/**
			 * @brief Returns a const reverse iterator pointing to the last
			 * element in the container (i.e., its reverse beginning).
			 * @return A const reverse iterator to the reverse beginning of the
			 * sequence container.
			*/
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->tree_biggest(_root)));
			}

			/**
			 * @brief Returns a reverse iterator pointing to the theoretical
			 * element right before the first element in the map container
			 * (which is considered its reverse end).
			 * @return A reverse iterator to the reverse end of the sequence
			 * container.
			*/
			reverse_iterator rend()
			{
				if (this->empty())
					return (reverse_iterator(_root));
				return (reverse_iterator((this->tree_smallest(_root))->left,
					this->tree_smallest(_root)));
			}

			/**
			 * @brief Returns a const reverse iterator pointing to the
			 * theoretical element right before the first element in the map
			 * container (which is considered its reverse end).
			 * @return A const reverse iterator to the reverse end of the
			 * sequence container.
			*/
			const_reverse_iterator rend() const
			{
				if (this->empty())
					return (const_reverse_iterator(_root));
				return (const_reverse_iterator((this->tree_smallest(_root))->left,
					this->tree_smallest(_root)));
			}

/*
** --------------------------------- CAPACITY ----------------------------------
*/

			/**
			 * @brief Returns whether the map container is empty (i.e. whether
			 * its size is 0).
			 * @return true if the container size is 0, false otherwise.
			*/
			bool empty() const
			{
				return (_size == 0);
			}

			/**
			 * @brief Returns the number of elements in the map container.
			 * @return The number of elements in the container.
			*/
			size_type size() const
			{
				return (_size);
			}

			/**
			 * @brief Returns the maximum number of elements that the map
			 * container can hold.
			 * @return The maximum number of elements a map container can hold
			 * as content.
			*/
			size_type max_size() const
			{
				return (Node_allocator(_alloc).max_size());
			}

/*
** ------------------------------ ELEMENT ACCESS -------------------------------
*/

			/**
			 * @brief If k matches the key of an element in the container, the
			 * function returns a reference to its mapped value. If k does not
			 * match the key of any element in the container, the function
			 * inserts a new element with that key and returns a reference to
			 * its mapped value.
			*/
			mapped_type& operator[](const key_type& k)
			{
				_root = this->insertNode(_root, NULL, ft::make_pair(k, mapped_type()));
				_root = balanceTree(_root);
				Node* element = _lastInsert;
				_lastInsert = NULL;
				return (element->val.second);
			}

/*
** -------------------------------- MODIFIERS ----------------------------------
*/

			/**
			 * @brief Extends the container by inserting new elements,
			 * effectively increasing the container size by one.
			 * @param val Value to be copied to (or moved as) the inserted
			 * element.
			 * @return Return a pair with its member pair::first set to an
			 * iterator pointing to either the newly inserted element or to the
			 * element with an equivalent key in the map. The pair::second
			 * element in the pair is set to true if a new element was inserted
			 * or false if an equivalent key already existed.
			*/
			pair<iterator,bool> insert(const value_type& val)
			{
				size_type size_before = this->size();
				_root = this->insertNode(_root, NULL, val);
				Node* newnode = _lastInsert;
				_lastInsert = NULL;
				return (ft::pair<iterator, bool>(iterator(newnode),
					(this->size() > size_before)));
			}

			/**
			 * @brief Extends the container by inserting new elements,
			 * effectively increasing the container size by one.
			 * @param position Hint for the position where the element can be
			 * inserted. Notice that this is just a hint and does not force the
			 * new element to be inserted at that position within the map
			 * container.
			 * @param val Value to be copied to (or moved as) the inserted
			 * element.
			*/
			iterator insert(iterator position, const value_type& val)
			{
				if (this->size() < 3)
					return ((this->insert(val)).first);
				while (position->first > val.first && position != this->begin())
					position--;
				iterator	tmp(position);
				tmp++;
				while (position->first < val.first && tmp != this->end())
				{
					tmp++;
					position++;
				}
				if (position->first == val.first)
					return (position);
				Node* parent = position.getNode()->parent;
				if (!parent)
					_root = this->insertNode(_root, NULL, val);
				else
				{
					insertNode(position.getNode()->parent, NULL, val);
					while (_root->parent != NULL)
						_root = _root->parent;
					_root = this->balanceTree(_root);
				}
				Node*	new_node = _lastInsert;
				_lastInsert = NULL;
				return (iterator(new_node));
			}

			/**
			 * @brief Extends the container by inserting new elements,
			 * effectively increasing the container size by the number of
			 * elements inserted.
			 * @param first,last Iterators specifying a range of elements.
			 * Copies of the elements in the range [first,last) are inserted in
			 * the container.
			*/
			template <class InputIterator>
			void insert(typename ft::enable_if<!std::numeric_limits<InputIterator>
				::is_integer, InputIterator>::type first, InputIterator last)
			{
				while (first != last)
					this->insert(*first++);
			}

			/**
			 * @brief Removes a single element from the map container.
			 * This effectively reduces the container size by one and destroy
			 * the element.
			 * @param position Iterator pointing to a single element to be
			 * removed from the map.
			*/
			void erase(iterator position)
			{
				_root = this->deleteNode(_root, position->first);
			}

			/**
			 * @brief Removes a single element from the map container.
			 * This effectively reduces the container size by one and destroy
			 * the element.
			 * @param k Key of the element to be removed from the map.
			*/
			size_type erase(const key_type& k)
			{
				size_type tmp = this->size();
				_root = this->deleteNode(_root, k);
				return ((this->size() == tmp) ? 0 : 1);
			}

			/**
			 * @brief Removes from the map container a range of elements
			 * ([first,last)). This effectively reduces the container size by
			 * the number of elements removed, which are destroyed.
			 * @param first,last Iterators specifying a range within the map
			 * container to be removed: [first,last). i.e., the range includes
			 * all the elements between first and last, including the element
			 * pointed by first but not the one pointed by last.
			*/
			void erase(iterator first, iterator last)
			{
				map tmp(first, last);
				for (reverse_iterator it = tmp.rbegin(); it != tmp.rend(); ++it)
					this->erase(it->first);
			}

			/**
			 * @brief Exchanges the content of the container by the content of
			 * x, which is another map of the same type. Sizes may differ.
			 * @param x  Another map container of the same type as this (i.e.,
			 * with the same template parameters, Key, T, Compare and Alloc)
			 * whose content is swapped with that of this container.
			*/
			void swap(map& x)
			{
				swap(_root, x._root);
				swap(_size, x._size);
				swap(_comp, x._comp);
				swap(_alloc, x._alloc);
			}

			/**
			 * @brief Removes all elements from the map container (which are
			 * destroyed), leaving the container with a size of 0.
			*/
			void clear()
			{
				_root = this->tree_clear(_root);
			}

/*
** -------------------------------- OBSERVERS ----------------------------------
*/

			/**
			 * @brief Returns a copy of the comparison object used by the
			 * container to compare keys.
			 * @return The comparison object.
			*/
			key_compare key_comp() const
			{
				return (_comp);
			}

			class value_compare
			{
				// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;

				public:

					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

				bool operator()(const value_type &x, const value_type &y) const
				{
					return comp(x.first, y.first);
				}

				protected:

					key_compare		comp;

					value_compare(Compare c) : comp(c) {}
			};

			/**
			 * @brief Returns a comparison object that can be used to compare
			 * two elements to get whether the key of the first one goes before
			 * the second.
			 * @return The comparison object for element values.
			*/
			value_compare value_comp() const
			{
				return (value_compare(_comp));
			}

/*
** -------------------------------- OPERATIONS ---------------------------------
*/

			/**
			 * @brief Searches the container for an element with a key
			 * equivalent to k and returns an iterator to it if found,
			 * otherwise it returns an iterator to map::end.
			 * @param k Key to search for.
			 * @return An iterator to the element, if an element with specified
			 * key is found, or map::end otherwise.
			*/
			iterator find(const key_type& k)
			{
				Node* found = this->tree_search(_root, k);

				if (found)
					return (iterator(found));
				return (this->end());
			}

			/**
			 * @brief Searches the container for an element with a key
			 * equivalent to k and returns a const iterator to it if found,
			 * otherwise it returns a const iterator to map::end.
			 * @param k Key to search for.
			 * @return A const iterator to the element, if an element with
			 * specified key is found, or map::end otherwise.
			*/
			const_iterator find(const key_type& k) const
			{
				Node* found = this->tree_search(_root, k);

				if (found)
					return (const_iterator(found));
				return (this->end());
			}

			/**
			 * @brief Searches the container for elements with a key equivalent
			 * to k and returns the number of matches.
			 * @param k Key to search for.
			 * @return 1 if the container contains an element whose key is
			 * equivalent to k, or zero otherwise.
			*/
			size_type count(const key_type& k) const
			{
				Node* found = this->tree_search(_root, k);

				if (found)
					return (1);
				return (0);
			}

			/**
			 * @brief Returns an iterator pointing to the first element in the
			 * container whose key is not considered to go before k (i.e.,
			 * either it is equivalent or goes after).
			 * @param k Key to search for.
			 * @return An iterator to the the first element in the container
			 * whose key is not considered to go before k, or map::end if all
			 * keys are considered to go before k.
			*/
			iterator lower_bound(const key_type& k)
			{
				iterator lower = this->begin();
				iterator end = this->end();
				while (lower != end && _comp(lower->first, k))
					lower++;
				return (lower);
			}

			/**
			 * @brief Returns a const iterator pointing to the first element in
			 * the container whose key is not considered to go before k (i.e.,
			 * either it is equivalent or goes after).
			 * @param k Key to search for.
			 * @return A const iterator to the the first element in the
			 * container whose key is not considered to go before k, or map::end
			 * if all keys are considered to go before k.
			*/
			const_iterator lower_bound(const key_type& k) const
			{
				const_iterator lower = this->begin();
				const_iterator end = this->end();
				while (lower != end && _comp(lower->first, k))
					lower++;
				return (lower);
			}

			/**
			 * @brief Returns an iterator pointing to the first element in the
			 * container whose key is considered to go after k.
			 * @param k Key to search for.
			 * @return An iterator to the the first element in the container
			 * whose key is considered to go after k, or map::end if no keys are
			 * considered to go after k.
			*/
			iterator upper_bound(const key_type& k)
			{
				iterator upper = this->begin();
				iterator end = this->end();
				while (upper != end && !_comp(k, upper->first))
					upper++;
				return (upper);
			}

			/**
			 * Returns a const iterator pointing to the first element in the
			 * container whose key is considered to go after k.
			 * @param k Key to search for.
			 * @return A const iterator to the the first element in the
			 * container whose key is considered to go after k, or map::end if
			 * no keys are considered to go after k.
			*/
			const_iterator upper_bound(const key_type& k) const
			{
				const_iterator upper = this->begin();
				const_iterator end = this->end();
				while (upper != end && !_comp(k, upper->first))
					upper++;
				return (upper);
			}

			/**
			 * @brief Returns the bounds of a range that includes all the
			 * elements in the container which have a key equivalent to k.
			 * Because the elements in a map container have unique keys, the
			 * range returned will contain a single element at most.
			 * @param k Key to search for.
			 * @return The function returns a pair, whose member pair::first is
			 * the lower bound of the range (the same as lower_bound),
			 * and pair::second is the upper bound (the same as upper_bound).
			*/
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const
			{
				pair<const_iterator, const_iterator> range;

				range.first = this->lower_bound(k);
				range.second = this->upper_bound(k);
				return (range);
			}

			/**
			 * @brief Returns the bounds of a range that includes all the
			 * elements in the container which have a key equivalent to k.
			 * Because the elements in a map container have unique keys, the
			 * range returned will contain a single element at most.
			 * @param k Key to search for.
			 * @return The function returns a pair, whose member pair::first is
			 * the lower bound of the range (the same as lower_bound),
			 * and pair::second is the upper bound (the same as upper_bound).
			*/
			pair<iterator,iterator> equal_range(const key_type& k)
			{
				pair<iterator, iterator> range;

				range.first = this->lower_bound(k);
				range.second = this->upper_bound(k);
				return (range);
			}

/*
** -------------------------------- ALLOCATOR ----------------------------------
*/

			/**
			 * @brief Returns a copy of the allocator object associated with the
			 * map.
			 * @return The allocator.
			*/
			allocator_type get_allocator() const
			{
				return (_alloc);
			}

/*
** ---------------------------- PRIVATE FUNCTIONS ------------------------------
*/

		private:

			template<class U>
			void swap(U& u1, U& u2)
			{
				U tmp = u2;
				u2 = u1;
				u1 = tmp;
			}

			/**
			 * @brief Calculate the height of the given AVL Tree
			 * @param node Pointer to the starting node for the depth calculation
			 * @return An int representing the height of the given node
			*/
			int		getHeight(Node* node) const
			{
				if (node != NULL)
					return (node->height);
				return (0);
			}

			/**
			 * @brief Calculate the balance factor of the given node
			 * @param node Pointer to the node to be balanced
			 * @return An int representing te balance factor. The value –1
			 * indicates that the left sub-tree contains one extra, the value +1
			 * indicates that the left sub-tree contains one extra and value 0
			 * shows that the tree includes equal nodes on each side.
			*/
			int		getBalance(Node* node) const
			{
				if (node == NULL)
					return (0);
				return (getHeight(node->left) - getHeight(node->right));
			}

			/**
			 * @brief Performs a Right-Right rotation of the given node.
			 * This rotation is performed when a new node is inserted at the
			 * right child of the right subtree.
			 * @return The root of the new subtree.
			*/
			Node*	tree_rr_rotate(Node* node)
			{
				Node*	new_parent;

				new_parent = node->right;
				new_parent->parent = node->parent;
				node->parent = new_parent;
				node->right = new_parent->left;
				if (new_parent->left)
					new_parent->left->parent = node;
				new_parent->left = node;
				node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
				new_parent->height = 1 + std::max(getHeight(new_parent->left), getHeight(new_parent->right));
				return (new_parent);
			}

			/**
			 * @brief Performs a Left-Left rotation of the given node.
			 * This rotation is performed when a new node is inserted at the
			 * left child of the left subtree.
			 * @return The root of the new subtree.
			*/
			Node*	tree_ll_rotate(Node* node)
			{
				Node*	new_parent;

				new_parent = node->left;
				new_parent->parent = node->parent;
				node->parent = new_parent;
				node->left = new_parent->right;
				if (new_parent->right)
					new_parent->right->parent = node;
				new_parent->right = node;
				node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
				new_parent->height = 1 + std::max(getHeight(new_parent->left), getHeight(new_parent->right));
				return (new_parent);
			}

			/**
			 * @brief Performs a Left-Right rotation of the given node.
			 * This rotation is performed when a new node is inserted at the
			 * right child of the left subtree.
			 * @return The root of the new subtree.
			*/
			Node*	tree_lr_rotate(Node* node)
			{
				node->left = this->tree_rr_rotate(node->left);
				return (this->tree_ll_rotate(node));
			}

			/**
			 * @brief Performs a Right-Left rotation of the given node.
			 * This rotation is performed when a new node is inserted at the
			 * left child of the right subtree.
			 * @return The root of the new subtree.
			*/
			Node*	tree_rl_rotate(Node* node)
			{
				node->right = this->tree_ll_rotate(node->right);
				return (this->tree_rr_rotate(node));
			}

			/**
			 * @brief Balance the given Tree
			 * @param node The node where you want to start balancing.
			 * @return The root of the AVL Tree
			*/
			Node*	balanceTree(Node* node)
			{
				int	factor = getBalance(node);

				if (factor >= 2)
				{
					if (getBalance(node->left) >= 1)
						return (this->tree_ll_rotate(node));
					else
						return (this->tree_lr_rotate(node));
				}
				else if (factor <= -2)
				{
					if (getBalance(node->right) <= -1)						
						return (this->tree_rr_rotate(node));
					else
						return (this->tree_rl_rotate(node));
				}
				return (node);
			}

			Node*	createNode(const value_type& val, Node* parent)
			{
				Node*	new_node = Node_allocator(_alloc).allocate(1);
				new_node->right = NULL;
				new_node->left = NULL;
				new_node->height = 1;
				new_node->parent = parent;
				_alloc.construct(&new_node->val, val);
				_size++;
				_lastInsert = new_node;
				return (new_node);
			}

			/**
			 * @brief Insert a new node in the given subtree.
			 * @return The new root of the tree
			*/
			Node*	insertNode(Node* node, Node* parent, const value_type& val)
			{
				if (node == NULL)
					return (createNode(val, parent));
				if (_comp(val.first, node->val.first))
					node->left = insertNode(node->left, node, val);
				else if (_comp(node->val.first, val.first))
					node->right = insertNode(node->right, node, val);
				else
					return (_lastInsert = node);
				node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
				int	factor = getBalance(node);
				if (factor >= 2)
				{
					if (getBalance(node->left) >= 0)
						return (tree_ll_rotate(node));
					else
						return (tree_lr_rotate(node));
				}
				else if (factor <= -2)
				{
					if (getBalance(node->right) <= 0)
						return (tree_rr_rotate(node));
					else
						return (tree_rl_rotate(node));
				}
				return (node);
			}

			/**
			 * @brief Delete the node with the corresponding key in the given
			 * subtree.
			 * @return The root of the subtree
			*/
			Node*	deleteNode(Node* node, const key_type& key)
			{
				if (node == NULL)
					return (NULL);
				if (_comp(key, node->val.first))
					node->left = deleteNode(node->left, key);
				else if (_comp(node->val.first, key))
					node->right = deleteNode(node->right, key);
				else
				{
					if ((node->left == NULL) || (node->right == NULL))
					{
						Node* tmp = node->left ? node->left : node->right;
						if (tmp == NULL)
							swap(tmp, node);
						else
						{
							_alloc.destroy(&node->val);
							_alloc.construct(&node->val, tmp->val);
							node->right = node->left = NULL;
						}
						_alloc.destroy(&tmp->val);
						Node_allocator(_alloc).deallocate(tmp, 1);
						_size--;
					}
					else
					{
						Node* tmp = this->tree_smallest(node->right);
						_alloc.destroy(&node->val);
						_alloc.construct(&node->val, tmp->val);
						node->right = deleteNode(node->right, tmp->val.first);
					}
				}
				if (node == NULL)
					return (node);
				int	factor = getBalance(node);
				if (factor >= 2)
				{
					if (getBalance(node->left) >= 0)
						return (tree_ll_rotate(node));
					else
						return (tree_lr_rotate(node));
				}
				else if (factor <= -2)
				{
					if (getBalance(node->right) <= 0)
						return (tree_rr_rotate(node));
					else
						return (tree_rl_rotate(node));
				}
				return (node);
			}

			/**
			 * @brief Removes every node from the tree.
			*/
			Node*	tree_clear(Node* node)
			{
				if (!node)
					return (NULL);
				if (node->left)
					tree_clear(node->left);
				if (node->right)
					tree_clear(node->right);
				_alloc.destroy(&node->val);
				Node_allocator(_alloc).deallocate(node, 1);
				_size--;
				return (NULL);
			}

			/**
			 * @brief Find a node in the tree using the given key starting from
			 * the given root
			*/
			Node*	tree_search(Node* node, const key_type& key) const
			{
				if (node == NULL)
					return (NULL);
				if (!_comp(node->val.first, key) && !_comp(key, node->val.first))
					return (node);
				if (_comp(key, node->val.first))
					return (tree_search(node->left, key));
				else if (_comp(node->val.first, key))
					return (tree_search(node->right, key));
				return (NULL);
			}

			/**
			 * @brief Returns the smallest node in the tree, it's the farthest
			 * node on the left from the root.
			*/
			Node*	tree_smallest(Node* node) const
			{
				while (node && node->left != NULL)
					node = node->left;
				return (node);
			}

			/**
			 * @brief Returns the biggest node in the tree, it's the farthest
			 * node on the right from the root.
			*/
			Node*	tree_biggest(Node* node) const
			{
				while (node && node->right != NULL)
					node = node->right;
				return (node);
			}
	};

/*
** -------------------------------- OVERLOADS ----------------------------------
*/

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs,
		const map<Key,T,Compare,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs,
		const map<Key,T,Compare,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs,
		const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs,
		const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs,
		const map<Key,T,Compare,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs,
		const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	/**
	 * @brief The contents of container x are exchanged with those of y.
	 * Both container objects must be of the same type (same template
	 * parameters), although sizes may differ.
	 * @param x,y list containers of the same type (i.e., having both
	 * the same template parameters, Key, T, Compare and Alloc).
	*/
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif /* *********************************************************** MAP_HPP */