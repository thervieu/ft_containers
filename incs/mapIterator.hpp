/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:54:05 by user42            #+#    #+#             */
/*   Updated: 2021/01/29 16:04:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include "listIterator.hpp"
# include "ft_stl.hpp"

namespace ft
{

	/*
	** Linked list base node
	** Boolean is used to identify the past-the-end element and
	** is needed to get the right value for max_size
	*/

	template <class Key, class T>
	struct BinaryNode
	{
		ft::pair<Key, T> pair;
		BinaryNode *parent;
		BinaryNode *left;
		BinaryNode *right;
		bool		_bool;
	};

	template <class K, class T>
	class mapIterator
	{
		public:
		
			typedef	ft::pair<K, T> value_type;
			typedef	ft::pair<K, T>& reference;
			typedef	BinaryNode<K, T>* pointer;
		
		protected:

			pointer _ptr;

		private:

			pointer	predecessor(pointer _ptr)
			{
				pointer _pred;

				if (_ptr->left)
				{
					_pred = _ptr->left;
					while (_pred->right)
						_pred = _pred->right;
				}
				else
				{
					_pred = _ptr;
					while (_pred->parent && _pred->parent->left == _pred)
						_pred = _pred->parent;
					if (_pred->parent)
						_pred = _pred->parent;
				}
				return (_pred);
			};

			pointer	successor(pointer _ptr)
			{
				pointer _succesor;
				
				if (_ptr->right)
				{
					_succesor = _ptr->right;
					while (_succesor->left)
						_succesor = _succesor->left;
				}
				else
				{
					_succesor = _ptr;
					while (_succesor->parent && _succesor->parent->right == _succesor)
						_succesor = _succesor->parent;
					if (_succesor->parent)
						_succesor = _succesor->parent;
				}
				return (_succesor);
			};

		public:
			
			mapIterator(void): _ptr(0)
			{};
			
			mapIterator(const mapIterator &other)
			{
				*this = other;
			};
			
			mapIterator(pointer _pt): _ptr(_pt)
			{};
			
			~mapIterator(void)
			{};

			pointer	binaryNode(void)
			{
				return (_ptr);
			};
			
			mapIterator	&operator=(const mapIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			mapIterator	&operator++(void)
			{
                _ptr = successor(_ptr);
				return (*this);
			};

			mapIterator	operator++(int)
			{
				mapIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			mapIterator	&operator--(void)
			{
                _ptr = predecessor(_ptr);
				return (*this);
			};

			mapIterator	operator--(int)
			{
				mapIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			bool operator==(const mapIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const mapIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const mapIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const mapIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const mapIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const mapIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (_ptr->pair);
			};
			
			value_type	*operator->(void)
			{
				return (&_ptr->pair);
			};
			
			mapIterator &operator+=(int n)
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
			
			mapIterator &operator-=(int n)
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

			mapIterator operator+(int n) const
			{
				mapIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			mapIterator operator-(int n) const
			{
				mapIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};

            value_type  operator[](int n) const
            {
                return (*(this + n));
            };
    };
	template <class K, class T>
	class constMapIterator
	{
		public:
		
			typedef	ft::pair<K, T> value_type;
			typedef	ft::pair<K, T>& reference;
			typedef	BinaryNode<K, T>* pointer;
		
		protected:

			pointer _ptr;

		private:

			pointer	predecessor(pointer _ptr)
			{
				pointer _pred;

				if (_ptr->left)
				{
					_pred = _ptr->left;
					while (_pred->right)
						_pred = _pred->right;
				}
				else
				{
					_pred = _ptr;
					while (_pred->parent && _pred->parent->left == _pred)
						_pred = _pred->parent;
					if (_pred->parent)
						_pred = _pred->parent;
				}
				return (_pred);
			};

			pointer	successor(pointer _ptr)
			{
				pointer _succesor;
				
				if (_ptr->right)
				{
					_succesor = _ptr->right;
					while (_succesor->left)
						_succesor = _succesor->left;
				}
				else
				{
					_succesor = _ptr;
					while (_succesor->parent && _succesor->parent->right == _succesor)
						_succesor = _succesor->parent;
					if (_succesor->parent)
						_succesor = _succesor->parent;
				}
				return (_succesor);
			};

		public:
			
			constMapIterator(void)
			{};
			
			constMapIterator(const constMapIterator &other)
			{
				*this = other;
			};
			
			constMapIterator(pointer _pt): _ptr(_pt)
			{};
			
			~constMapIterator(void)
			{};

			pointer	binaryNode(void)
			{
				return (_ptr);
			};
			
			constMapIterator	&operator=(const constMapIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			constMapIterator	&operator++(void)
			{
                _ptr = successor(_ptr);
				return (*this);
			};

			constMapIterator	operator++(int)
			{
				constMapIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			constMapIterator	&operator--(void)
			{
                _ptr = predecessor(_ptr);
				return (*this);
			};

			constMapIterator	operator--(int)
			{
				constMapIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			bool operator==(const constMapIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const constMapIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const constMapIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const constMapIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const constMapIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const constMapIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (_ptr->pair);
			};
			
			value_type	*operator->(void)
			{
				return (&_ptr->pair);
			};
			
			constMapIterator &operator+=(int n)
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
			
			constMapIterator &operator-=(int n)
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

			constMapIterator operator+(int n) const
			{
				constMapIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			constMapIterator operator-(int n) const
			{
				constMapIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};

            value_type  operator[](int n) const
            {
                return (*(this + n));
            };
    };
	template <class K, class T>
	class reverseMapIterator
	{
		public:
		
			typedef	ft::pair<K, T> value_type;
			typedef	ft::pair<K, T>& reference;
			typedef	BinaryNode<K, T>* pointer;
		
		protected:

			pointer _ptr;

		private:

			pointer	predecessor(pointer _ptr)
			{
				pointer _pred;

				if (_ptr->left)
				{
					_pred = _ptr->left;
					while (_pred->right)
						_pred = _pred->right;
				}
				else
				{
					_pred = _ptr;
					while (_pred->parent && _pred->parent->left == _pred)
						_pred = _pred->parent;
					if (_pred->parent)
						_pred = _pred->parent;
				}
				return (_pred);
			};

			pointer	successor(pointer _ptr)
			{
				pointer _succesor;
				
				if (_ptr->right)
				{
					_succesor = _ptr->right;
					while (_succesor->left)
						_succesor = _succesor->left;
				}
				else
				{
					_succesor = _ptr;
					while (_succesor->parent && _succesor->parent->right == _succesor)
						_succesor = _succesor->parent;
					if (_succesor->parent)
						_succesor = _succesor->parent;
				}
				return (_succesor);
			};

		public:
			
			reverseMapIterator(void)
			{};
			
			reverseMapIterator(const reverseMapIterator &other)
			{
				*this = other;
			};
			
			reverseMapIterator(pointer _pt): _ptr(_pt)
			{};
			
			~reverseMapIterator(void)
			{};

			pointer	binaryNode(void)
			{
				return (_ptr);
			};
			
			reverseMapIterator	&operator=(const reverseMapIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			reverseMapIterator	&operator++(void)
			{
                _ptr = successor(_ptr);
				return (*this);
			};

			reverseMapIterator	operator++(int)
			{
				reverseMapIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			reverseMapIterator	&operator--(void)
			{
                _ptr = predecessor(_ptr);
				return (*this);
			};

			reverseMapIterator	operator--(int)
			{
				reverseMapIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			bool operator==(const reverseMapIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const reverseMapIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const reverseMapIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const reverseMapIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const reverseMapIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const reverseMapIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (_ptr->pair);
			};
			
			value_type	*operator->(void)
			{
				return (&_ptr->pair);
			};
			
			reverseMapIterator &operator+=(int n)
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
			
			reverseMapIterator &operator-=(int n)
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

			reverseMapIterator operator+(int n) const
			{
				reverseMapIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			reverseMapIterator operator-(int n) const
			{
				reverseMapIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};

            value_type  operator[](int n) const
            {
                return (*(this + n));
            };
    };
	template <class K, class T>
	class constReverseMapIterator
	{
		public:
		
			typedef	ft::pair<K, T> value_type;
			typedef	ft::pair<K, T>& reference;
			typedef	BinaryNode<K, T>* pointer;
		
		protected:

			pointer _ptr;

		private:

			pointer	predecessor(pointer _ptr)
			{
				pointer _pred;

				if (_ptr->left)
				{
					_pred = _ptr->left;
					while (_pred->right)
						_pred = _pred->right;
				}
				else
				{
					_pred = _ptr;
					while (_pred->parent && _pred->parent->left == _pred)
						_pred = _pred->parent;
					if (_pred->parent)
						_pred = _pred->parent;
				}
				return (_pred);
			};

			pointer	successor(pointer _ptr)
			{
				pointer _succesor;
				
				if (_ptr->right)
				{
					_succesor = _ptr->right;
					while (_succesor->left)
						_succesor = _succesor->left;
				}
				else
				{
					_succesor = _ptr;
					while (_succesor->parent && _succesor->parent->right == _succesor)
						_succesor = _succesor->parent;
					if (_succesor->parent)
						_succesor = _succesor->parent;
				}
				return (_succesor);
			};

		public:
			
			constReverseMapIterator(void)
			{};
			
			constReverseMapIterator(const constReverseMapIterator &other)
			{
				*this = other;
			};
			
			constReverseMapIterator(pointer _pt): _ptr(_pt)
			{};
			
			~constReverseMapIterator(void)
			{};

			pointer	binaryNode(void)
			{
				return (_ptr);
			};
			
			constReverseMapIterator	&operator=(const constReverseMapIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};

			constReverseMapIterator	&operator++(void)
			{
                _ptr = successor(_ptr);
				return (*this);
			};

			constReverseMapIterator	operator++(int)
			{
				constReverseMapIterator rtn(*this);
				this->operator++();
				return (rtn);
			};
			
			constReverseMapIterator	&operator--(void)
			{
                _ptr = predecessor(_ptr);
				return (*this);
			};

			constReverseMapIterator	operator--(int)
			{
				constReverseMapIterator rtn(*this);
				this->operator--();
				return (rtn);
			};
			
			bool operator==(const constReverseMapIterator &rhs) const
			{
				return (this->_ptr == rhs._ptr);
			};
			
			bool operator!=(const constReverseMapIterator &rhs) const
			{
				return (this->_ptr != rhs._ptr);
			};
			
			bool operator>=(const constReverseMapIterator &rhs) const
			{
				return (this->_ptr >= rhs._ptr);
			};
			
			bool operator>(const constReverseMapIterator &rhs) const
			{
				return (this->_ptr > rhs._ptr);
			};
			
			bool operator<=(const constReverseMapIterator &rhs) const
			{
				return (this->_ptr <= rhs._ptr);
			};
			
			bool operator<(const constReverseMapIterator &rhs) const
			{
				return (this->_ptr < rhs._ptr);
			};
			
			value_type	&operator*(void)
			{
				return (_ptr->pair);
			};
			
			value_type	*operator->(void)
			{
				return (&_ptr->pair);
			};
			
			constReverseMapIterator &operator+=(int n)
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
			
			constReverseMapIterator &operator-=(int n)
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

			constReverseMapIterator operator+(int n) const
			{
				constReverseMapIterator rtn(*this);
				rtn += n;
				return (rtn);
			};
			
			constReverseMapIterator operator-(int n) const
			{
				constReverseMapIterator rtn(*this);
				rtn -= n;
				return (rtn);
			};

            value_type  operator[](int n) const
            {
                return (*(this + n));
            };
	};
}

#endif