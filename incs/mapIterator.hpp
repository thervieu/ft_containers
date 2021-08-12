/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:17:59 by nforay            #+#    #+#             */
/*   Updated: 2021/08/12 18:22:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <stddef.h>
# include <iostream>

# include "ft_stl.hpp"

namespace ft
{
	template<class Key, class T, class Compare, typename Node> class constMapIterator;

	template<class Key, class T, class Compare, typename Node>
	class mapIterator
	{
		public:

			typedef Key										key_type;
			typedef T										mapped_type;
			typedef Compare									key_compare;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef ptrdiff_t								difference_type;
			typedef value_type*								pointer;
			typedef value_type&								reference;
			typedef Node*									node_pointer;

		protected:

			node_pointer	_node;
			node_pointer	_endNode;

		private:

			mapIterator(const constMapIterator<Key,T,Compare,Node>& ) {}

		public:

			mapIterator(node_pointer node = NULL) : _node(node), _endNode(node)
			{
				if (_endNode != NULL)
				{
					while (_endNode->parent != NULL)
						_endNode = _endNode->parent;
					while (_endNode->right != NULL)
						_endNode = _endNode->right;
				}
			}

			mapIterator(node_pointer node, node_pointer endnode)
			: _node(node), _endNode(endnode)
			{}

			mapIterator(const mapIterator& rhs)
			: _node(rhs._node), _endNode(rhs._endNode)
			{}

			~mapIterator()
			{}

			node_pointer	getNode() const
			{
				return (_node);
			}

			mapIterator& operator=(const mapIterator& rhs)
			{
				if (this != &rhs)
				{
					_node = rhs._node;
					_endNode = rhs._endNode;
				}
				return (*this);
			}

			bool operator==(const mapIterator& rhs) const
			{
				return (_node == rhs._node);
			}

			bool operator!=(const mapIterator& rhs) const
			{
				return (_node != rhs._node);
			}

			reference operator*() const
			{
				return (_node->val);
			}

			pointer operator->() const
			{
				return (&(_node->val));
			}

			mapIterator& operator++()
			{
				if (_node == NULL)
				{
					_node = _endNode;
					_endNode = NULL;
					return (*this);
				}
				else if (_node->right != NULL)
				{
					_node = _node->right;
					while (_node->left != NULL)
						_node = _node->left;
				}
				else
				{
					Node* origin = _node;
					_node = _node->parent;
					while (_node && _node->right == origin)
					{
						origin = _node;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			mapIterator operator++(int)
			{
				mapIterator tmp(*this);
				++(*this);
				return (tmp);
			}

			mapIterator& operator--()
			{
				if (_node == NULL)
				{
					_node = _endNode;
					_endNode = NULL;
					return (*this);
				}
				else if (_node->left != NULL)
				{
					_node = _node->left;
					while (_node->right != NULL)
						_node = _node->right;
				}
				else
				{
					Node* origin = _node;
					_node = _node->parent;
					while (_node && _node->left == origin)
					{
						origin = _node;
						_node = _node->parent;
					}
				}
				return (*this);
			}

			mapIterator operator--(int)
			{
				mapIterator tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template<class Key, class T, class Compare, typename Node>
	class constMapIterator : public mapIterator<Key,T,Compare,Node>
	{
		public:

			typedef Key										key_type;
			typedef T										mapped_type;
			typedef Compare									key_compare;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef value_type const &						const_reference;
			typedef value_type const *						const_pointer;
			typedef Node*									node_pointer;

			constMapIterator(node_pointer node = NULL)
			{
				this->_node = node;
				this->_endNode = node;
				if (this->_endNode != NULL)
				{
					while (this->_endNode->parent != NULL)
						this->_endNode = this->_endNode->parent;
					while (this->_endNode->right != NULL)
						this->_endNode = this->_endNode->right;
				}
			}

			constMapIterator(node_pointer node, node_pointer endnode)
			{
				this->_node = node;
				this->_endNode = endnode;
			}

			constMapIterator(const mapIterator<Key,T,Compare,Node>& rhs)
			{
				this->_node = rhs.getNode();
			}

			constMapIterator& operator=(const constMapIterator& rhs)
			{
				if (this != &rhs) 
					this->_node = rhs._node;
				return (*this);
			}

			bool operator==(const constMapIterator& rhs) const
			{
				return (this->_node == rhs._node);
			}

			bool operator!=(const constMapIterator& rhs) const
			{
				return (this->_node != rhs._node);
			}

			const_reference operator*() const
			{
				return (this->_node->val);
			}

			const_pointer operator->() const
			{
				return (&(this->_node->val));
			}
	};
	
	template<class Key, class T, class Compare, typename Node> class constReverseMapIterator;

	template<class Key, class T, class Compare, typename Node>
	class reverseMapIterator
	{
		public:

			typedef Key										key_type;
			typedef T										mapped_type;
			typedef Compare									key_compare;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef ptrdiff_t								difference_type;
			typedef value_type*								pointer;
			typedef value_type&								reference;
			typedef Node*									node_pointer;

		protected:

			mapIterator<Key,T,Compare,Node>		_base;

		private:

			reverseMapIterator(const constReverseMapIterator<Key,T,Compare,Node> &) {}

		public:

			explicit reverseMapIterator(node_pointer node = NULL)
			: _base(mapIterator<Key,T,Compare,Node>(node))
			{}

			reverseMapIterator(node_pointer node, node_pointer endnode)
			: _base(mapIterator<Key,T,Compare,Node>(node, endnode))
			{}

			explicit reverseMapIterator(mapIterator<Key,T,Compare,Node> & rhs)
			{
				this->_base = rhs;
			}

			reverseMapIterator(const reverseMapIterator<Key,T,Compare,Node > & rhs)
			{
				this->_base = rhs._base;
			}

			node_pointer	getNode() const
			{
				return (this->_base.getNode());
			}

			mapIterator<Key,T,Compare,Node> base() const
			{
				return (this->_base);
			}

			reverseMapIterator& operator=(const reverseMapIterator & rhs)
			{
				if (this != &rhs)
				{
					this->_base = rhs._base;
				}
				return (*this);
			}

			bool operator==(const reverseMapIterator & rhs) const
			{
				return (_base == rhs._base);
			}

			bool operator!=(const reverseMapIterator & rhs) const
			{
				return (_base != rhs._base);
			}

			reference operator*() const
			{
				return (*(mapIterator<Key,T,Compare,Node>(this->_base)));
			}

			pointer operator->() const
			{
				return (&this->operator*());
			}

			reverseMapIterator& operator++()
			{
				this->_base.operator--();
				
				return (*this);
			}

			reverseMapIterator operator++(int)
			{
				reverseMapIterator tmp(*this);
				++(*this);
				return (tmp);
			}

			reverseMapIterator& operator--()
			{
				this->_base.operator++();
				return (*this);
			}

			reverseMapIterator operator--(int)
			{
				reverseMapIterator tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template<class Key, class T, class Compare, typename Node>
	class constReverseMapIterator : public reverseMapIterator<Key,T,Compare,Node>
	{
		public:

			typedef Key										key_type;
			typedef T										mapped_type;
			typedef Compare									key_compare;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef value_type const &						const_reference;
			typedef value_type const *						const_pointer;
			typedef Node*									node_pointer;

			explicit constReverseMapIterator(mapIterator<Key,T,Compare,Node> & rhs)
			{
				this->_base = rhs.getNode();
			}

			constReverseMapIterator(node_pointer node = NULL)
			{
				this->_base = mapIterator<Key,T,Compare,Node>(node);
			}

			constReverseMapIterator(node_pointer node, node_pointer endnode)
			{
				this->_base = mapIterator<Key,T,Compare,Node>(node, endnode);
			}

			constReverseMapIterator(constMapIterator<Key,T,Compare,Node> rhs)
			{
				this->_base = rhs.getNode();
			}

			constReverseMapIterator(const reverseMapIterator<Key,T,Compare,Node>& rhs)
			{
				this->_base = rhs.getNode();
			}

			constReverseMapIterator& operator=(const constReverseMapIterator& rhs)
			{
				if (this != &rhs) 
					this->_base = rhs._base;
				return (*this);
			}

			bool operator==(const constReverseMapIterator& rhs) const
			{
				return (this->_base == rhs._base);
			}

			bool operator!=(const constReverseMapIterator& rhs) const
			{
				return (this->_base != rhs._base);
			}

			const_reference operator*() const
			{
				return (*(mapIterator<Key,T,Compare,Node>(this->_base)));
			}

			const_pointer operator->() const
			{
				return (&this->operator*());
			}
	};
}

#endif
