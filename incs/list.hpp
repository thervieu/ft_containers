#ifndef LIST_HPP
# define LIST_HPP

# include "listIterator.hpp"

# include <limits>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
		
			typedef T value_type;

			typedef Alloc allocator_type;

			typedef T& reference;
			typedef T& const_reference;
			typedef T* pointer;
			typedef T* const_pointer;

			typedef listIterator<value_type> iterator;
			typedef constListIterator<value_type> const_iterator;
			typedef reverseListIterator<value_type> reverse_iterator;
			typedef constReverseListIterator<value_type> const_reverse_iterator;

			typedef size_t size_type;

			typedef Node<T>* node;
		
		private:
			
			node			_root;
			node			_pastTheEnd;

			allocator_type	_alloc;

			size_type		_length;


			Node<value_type>	*newNode(value_type value, node _prev, node _next)
			{
				Node<value_type> *_new = new Node<value_type>;
				_new->data = value;
				_new->prev = _prev;
				_new->next = _next;
				return (_new);
			}

			void	initList(void)
			{
				_root = newNode(value_type(), NULL, NULL);
				_pastTheEnd = newNode(value_type(), _root, NULL);
				_root->next = _pastTheEnd; 
			}

			template <typename X>
			struct boolIsSmaller : std::binary_function<X, X, bool>
			{
				bool operator()(const X& a, X& b) const
				{
					return (!(a < b));
				}
			};

		public:

			explicit list (const allocator_type& alloc = allocator_type()): _root(0), _pastTheEnd(0), _alloc(alloc), _length(0)
			{
				initList();
			}

			explicit list (size_type n, const value_type& val = value_type(),
            	const allocator_type& alloc = allocator_type()): _root(0), _pastTheEnd(0), _alloc(alloc), _length(0)
			{
				initList();
				assign(n, val);
			}

			template <class InputIterator>
			list (InputIterator first, InputIterator last,
        	const allocator_type& alloc = allocator_type()): _root(0), _pastTheEnd(0), _alloc(alloc), _length(0)
			{
				initList();
				assign(first, last);
			}

			list (const list& x): _root(0), _pastTheEnd(0), _alloc(x._alloc), _length(0)
			{
				initList();
				*this = x;
			}

			~list(void)
			{
				clear();
				delete _root;
				delete _pastTheEnd;
			}

			list&	operator= (const list& x)
			{
				assign(x.begin(), x.end());
				return (*this);
			}

			iterator		begin(void)
			{
				return (iterator(_root->next));
			}

			const_iterator	begin(void) const
			{
				return (const_iterator(_root->next));
			}

			iterator		end(void)
			{
				return (iterator(_pastTheEnd));
			}

			const_iterator	end(void) const
			{
				return (const_iterator(_pastTheEnd));
			}

			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator(_root->next));
			}

			const_reverse_iterator	rbegin(void) const
			{
				return (const_reverse_iterator(_root->next));
			}

			reverse_iterator		rend(void)
			{
				return (reverse_iterator(_pastTheEnd->prev));
			}

			const_reverse_iterator	rend(void) const
			{
				return (const_reverse_iterator(_pastTheEnd->prev));
			}

			bool empty(void) const
			{
				return (_length == 0);
			}

			size_type size(void) const
			{
				return (_length);
			}

			size_type max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(Node<T>));
			}

			reference front(void)
			{
				return (_root->next->data);
			}

			const_reference front(void) const
			{
				return (_root->next->data);
			}

			reference back(void)
			{
				return (_pastTheEnd->prev->data);
			}

			const_reference back(void) const
			{
				return (_pastTheEnd->prev->data);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				while (n--)
					push_back(val);
			}

			// root	<-> beg		&& root <-  newBeg  -> beg
			// root	 -> beg		&& root <-  newBeg <-> beg
			// root	 -  beg 	&& root <-> newBeg <-> beg

			void push_front (const value_type& val)
			{
				node newBeg = newNode(val, _root, _root->next);

				_root->next->prev = newBeg;
				_root->next = newBeg;
				_length++;
			}

			// root <-> beg <-> newBeg && root  -  newBeg
			// root <-  beg <-> newBeg && root  -> newBeg
			// root <-  beg  -> newBeg && root <-> newBeg

			void pop_front(void)
			{
				node delete_me = _root->next;

				_root->next = _root->next->next;
				_root->next->prev = _root;

				delete delete_me;
				_length--;
			}

			// end	<-> _pte	&& end <-  newEnd  -> pte
			// end	<- 	_pte	&& end <-> newEnd  -> pte
			// end	 - 	_pte 	&& end <-> newEnd <-> pte

			void push_back (const value_type& val)
			{
				node newEnd = newNode(val, _pastTheEnd->prev, _pastTheEnd);

				_pastTheEnd->prev->next = newEnd;
				_pastTheEnd->prev = newEnd;
				_length++;
			}

			// newEnd <-> end <-> pte	&& newEnd  -  pte
			// newEnd <-> end -> pte	&& newEnd <-  pte
			// newEnd <- end -> pte		&& newEnd <-> pte

			void pop_back(void)
			{
				node delete_me = _pastTheEnd->prev;

				_pastTheEnd->prev = _pastTheEnd->prev->prev;
				_pastTheEnd->prev->next = _pastTheEnd;

				delete delete_me;
				_length--;
			}

			// insert val at position
			iterator insert (iterator position, const value_type& val)
			{
				if (position == _root)
				{
					push_front(val);
					return (begin());
				}
				else if (position == _pastTheEnd)
				{
					push_back(val);
					return (end());
				}
				
				node n2 = position.node();
				node n1 = n2->prev;
				
				node newPos = newNode(val, n1, n2);
				
				n1->next = newPos;
				n2->prev = newPos;
				_length++;
				
				return (position);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				while (n--)
					insert(position, val);
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(position, *first);
					first++;
				}
			}

			iterator	erase (iterator position)
			{
				if (position == _root)
				{
					pop_front();
					return (begin());
				}
				else if (position == _pastTheEnd)
				{
					pop_back();
					return (end());
				}
				
				node n2 = position.node();
				
				node n1 = n2->prev;
				node n3 = n2->next;
				
				n1->next = n3;
				n3->prev = n1;
				delete n2;
				_length--;
				
				return (position);
			}

			iterator	erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
				return (first);
			}

			void	swap (list& x)
			{
				ft::swap(_root, x._root);
				ft::swap(_pastTheEnd, x._pastTheEnd);
				ft::swap(_length, x._length);
			}

			void resize (size_type n, value_type val = value_type())
			{
				while (n < _length)
					pop_back();
				while (n > _length)
					push_back(val);
			}

			void clear(void)
			{
				node delete_me = _root->next;

				while (delete_me != _pastTheEnd)
				{
					node _next = delete_me->next;
					delete delete_me;
					delete_me = _next;
				}

				_root->next = _pastTheEnd;
				_pastTheEnd->prev = _root;
				_length = 0;
				
				return ;
			}

			void splice (iterator position, list& x)
			{
				splice(position, x, x.begin(), x.end());
			}

			void splice (iterator position, list& x, iterator i)
			{
				insert(position, *i);
				x.erase(i);
			}

			void splice (iterator position, list& x, iterator first, iterator last)
			{
				insert(position, first, last);
				x.erase(first, last);
			}

			void remove (const value_type& val)
			{
				iterator it = begin();
				while (it != end())
				{
					if (*it == val)
						erase(it);
					it++;
				}
			}

			template <class Predicate>
			void remove_if (Predicate pred)
			{
				iterator it = begin();
				while (it != end())
				{
					if (pred(*it))
						erase(it);
					it++;
				}
			}

			void unique(void)
			{
				iterator it1 = begin();
				iterator it2 = it1;
				while (++it2 != end())
				{
					if (*it1  == *it2)
					{
						erase(it2);
						it2 = it1;
					}
					else
						it1 = it2;
				}
			}

			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				iterator it1 = begin();
				iterator it2 = it1;
				while (++it2 != end())
				{
					if (binary_pred(*it1, *it2))
					{
						erase(it2);
						it2 = it1;
					}
					else
						it1 = it2;
				}
			}
			
			void	merge(list &x)
			{
				merge(x, boolIsSmaller<T>());
			}

			template <class Compare>
			void	merge(list &x, Compare comp)
			{
				insert(end(), x.begin(), x.end());
				x.clear();
				sort(comp);
			}

			void	sort(void)
			{
				sort(boolIsSmaller<T>());
			}
			
			template <class Compare>
			void	sort(Compare comp)
			{
				iterator it1 = begin();
				iterator it2;
				while (it1 + 1 != end())
				{
					it2 = it1 + 1;
					while (it2 != end())
					{
						if (comp(*it1, *it2))
							ft::swap(*it1, *it2);
						it2++;
					}
					it1++;
				}
			}
			
			void	reverse(void)
			{
				list<value_type> tmp;
				iterator it = begin();
				while (it != end())
					tmp.push_front(*(it++));
				*this = tmp;
			}
	};

	template <class T, class Alloc>
	bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::list<T>::const_iterator it1 = lhs.begin();
		typename ft::list<T>::const_iterator it2 = rhs.begin();
		while (it1 != lhs.end())
		{
			if (*it1 != *it2)
				return (false);
			it1++;
			it2++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		else if (lhs.size() > rhs.size())
			return (false);
		typename ft::list<T>::const_iterator it1 = lhs.begin();
		typename ft::list<T>::const_iterator it2 = rhs.begin();
		while (it1 != lhs.end())
		{
			if (*it1 < *it2)
				return (*it1 < *it2);
			it1++;
			it2++;
		}
		return (false);
	}

	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void	swap(list<T, Alloc> &x, list <T, Alloc> &y)
	{
		x.swap(y);
	}

}


#endif