/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:03:32 by user42            #+#    #+#             */
/*   Updated: 2021/07/26 17:48:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <limits>
# include <stdexcept>
# include "ft_stl.hpp"
# include "vectorIterator.hpp"

namespace ft
{
	/**
	 * @brief Vectors are sequence containers representing arrays that can
	 * change in size.
	 * @tparam T Type of the elements.
	 * @tparam Alloc Type of the allocator object used to define the storage
	 * allocation model. By default, the allocator class template is used, which
	 * defines the simplest memory allocation model and is value-independent.
	*/
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:

			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef vectorIterator<T>							iterator;
			typedef constVectorIterator<T>						const_iterator;
			typedef constReverseVectorIterator<T>				const_reverse_iterator;
			typedef reverseVectorIterator<T>					reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:

			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer			_head;

		public:

			/**
			 * @brief empty container constructor (default constructor):
			 * Constructs an empty container, with no elements.
			 * @param alloc Allocator object. The container keeps and uses an
			 * internal copy of this allocator.
			*/
			explicit vector(const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(1), _alloc(alloc)
			{
				_head = _alloc.allocate(1);
			}

			/**
			 * @brief fill constructor: Constructs a container with n elements.
			 * Each element is a copy of val.
			 * @param n Initial container size (i.e., the number of elements in
			 * the container at construction).
			 * @param val Value to fill the container with. Each of the n
			 * elements in the container will be initialized to a copy of this
			 * value.
			 * @param alloc Allocator object. The container keeps and uses an
			 * internal copy of this allocator.
			*/
			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
				: _size(n), _capacity(n), _alloc(alloc)
			{
				// std::cout << "size = |" << _size << "|\n";
				_head = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_head[i], val);
			}

			/**
			 * @brief range constructor: Constructs a container with as many
			 * elements as the range [first,last), with each element constructed
			 * from its corresponding element in that range, in the same order.
			 * @param first,last Input iterators to the initial and final
			 * positions in a range. The range used is [first,last), which
			 * includes all the elements between first and last, including the
			 * element pointed by first but not the element pointed by last.
			 * @param alloc Allocator object. The container keeps and uses an
			 * internal copy of this allocator.
			*/
			template <class InputIterator>
			vector(typename ft::enable_if<!std::numeric_limits<InputIterator>
				::is_integer, InputIterator>::type first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(0), _alloc(alloc)
			{
				this->assign(first, last);
			}

			/**
			 * @brief copy constructor: Constructs a container with a copy of
			 * each of the elements in x, in the same order.
			 * @param x Another vector object of the same type (with the same
			 * class template arguments T and Alloc), whose contents are either
			 * copied or acquired.
			*/
			vector(const vector& x) : _size(x._size), _capacity(x._capacity),
				_alloc(x._alloc)
			{
				_head = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(&_head[i], x._head[i]);
			}

			/**
			 * @brief Vector destructor: Destroys the container object. This
			 * destroys all container elements, and deallocates all the storage
			 * capacity allocated by the vector using its allocator.
			*/
			~vector()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_head[i]);
				_alloc.deallocate(_head, _capacity);
			}

			/**
			 * @brief Assigns new contents to the container, replacing its
			 * current contents, and modifying its size accordingly. The
			 * container preserves its current allocator, which is used to
			 * allocate storage in case of reallocation.
			 * @param x A vector object of the same type (i.e., with the same
			 * template parameters, T and Alloc).
			*/
			vector& operator=(const vector& x)
			{
				// std::cout << "op= vector\n";
				_size = x._size;
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
				_head = _alloc.allocate(x._size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_head[i], x._head[i]);
				if (_capacity < x._size)
					_capacity = x._size;
				return (*this);
			}

/*
** --------------------------------- ITERATORS ---------------------------------
*/

			/**
			 * @brief Returns an iterator pointing to the first element in the
			 * vector.
			 * @return An iterator to the beginning of the sequence container.
			 * If the container is empty, the returned iterator value shall not
			 * be dereferenced.
			*/
			iterator begin()
			{
				return (iterator(_head));
			}

			/**
			 * @brief Returns a const_iterator pointing to the first element in
			 * the vector.
			 * @return An const_iterator to the beginning of the sequence
			 * container. If the container is empty, the returned iterator value
			 * shall not be dereferenced.
			*/
			const_iterator begin() const
			{
				return (const_iterator(_head));
			}

			/**
			 * @brief Returns an iterator referring to the past-the-end element
			 * in the vector container. The past-the-end element is the
			 * theoretical element that would follow the last element in the
			 * vector. It does not point to any element, and thus shall not be
			 * dereferenced.
			 * @return Returns an iterator referring to the past-the-end element
			 * in the vector container.
			*/
			iterator end()
			{
				// std::cout << "end values: size = |" << _size << "|\n";
				// for (int i = 0; i < 5; i++)
					// std::cout << *(_head + i) << "\n";
				// std::cout << "end values\n\n";
				return (iterator(_head + _size));
			}

			/**
			 * @brief Returns a const_iterator referring to the past-the-end
			 * element in the vector container. The past-the-end element is the
			 * theoretical element that would follow the last element in the
			 * vector. It does not point to any element, and thus shall not be
			 * dereferenced.
			 * @return Returns a const_iterator referring to the past-the-end
			 * element in the vector container.
			*/
			const_iterator end() const
			{
				return (const_iterator(_head + _size));
			}

			/**
			 * @brief Returns a reverse_iterator pointing to the last element in
			 * the vector (i.e., its reverse beginning). Reverse iterators
			 * iterate backwards: increasing them moves them towards the
			 * beginning of the container. rbegin points to the element right
			 * before the one that would be pointed to by member end.
			 * @return A reverse_iterator to the reverse beginning of the
			 * sequence container.
			*/
			reverse_iterator rbegin()
			{
				// std::cout << "rbegin\n";
				// for (int i = 0; i < (int)_size; ++i)
				// 	std::cout << "it[" << i << "] = |" << *(_head + i) << "|\n";
				// std::cout << "\n\n";
				return (reverse_iterator(end()));
			}

			/**
			 * @brief Returns a const_reverse_iterator pointing to the last
			 * element in the vector (i.e., its reverse beginning). Reverse
			 * iterators iterate backwards: increasing them moves them towards
			 * the beginning of the container. rbegin points to the element
			 * right before the one that would be pointed to by member end.
			 * @return A const_reverse_iterator to the reverse beginning of the
			 * sequence container.
			*/
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			/**
			 * @brief Returns a reverse iterator pointing to the theoretical
			 * element preceding the first element in the vector (which is
			 * considered its reverse end). The range between vector::rbegin and
			 * vector::rend contains all the elements of the vector (in reverse
			 * order).
			 * @return A reverse iterator to the reverse end of the sequence
			 * container.
			*/
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			/**
			 * @brief Returns a const_reverse_iterator pointing to the
			 * theoretical element preceding the first element in the vector
			 * (which is considered its reverse end). The range between
			 * vector::rbegin and vector::rend contains all the elements of the
			 * vector (in reverse order).
			 * @return A const_reverse_iterator to the reverse end of the
			 * sequence container.
			*/
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

/*
** --------------------------------- CAPACITY ----------------------------------
*/

			/**
			 * @brief Returns the number of elements in the vector. This is the
			 * number of actual objects held in the vector, which is not
			 * necessarily equal to its storage capacity.
			 * @return The number of elements in the container.
			*/
			size_type size() const
			{
				return (_size);
			}

			/**
			 * @brief Returns the maximum number of elements that the vector can
			 * hold. This is the maximum potential size the container can reach
			 * due to known system or library implementation limitations, but
			 * the container is by no means guaranteed to be able to reach that
			 * size: it can still fail to allocate storage at any point before
			 * that size is reached.
			 * @return  The maximum number of elements a vector container can
			 * hold as content.
			*/
			size_type max_size() const
			{
				return (_alloc.max_size());
			}

			/**
			 * @brief  Resizes the container so that it contains n elements.
			 * If n is smaller than the current container size, the content is
			 * reduced to its first n elements, removing those beyond (and
			 * destroying them). If n is greater than the current container
			 * size, the content is expanded by inserting at the end as many
			 * elements as needed to reach a size of n. If val is specified,
			 * the new elements are initialized as copies of val, otherwise,
			 * they are value-initialized. If n is also greater than the current
			 * container capacity, an automatic reallocation of the allocated
			 * storage space takes place.
			 * @param n New container size, expressed in number of elements.
			 * @param val Object whose content is copied to the added elements
			 * in case that n is greater than the current container size. If not
			 * specified, the default constructor is used instead.
			*/
			void resize(size_type n, value_type val = value_type())
			{
				if (n > _capacity)
					reallocate((n > _size * 2) ? n : _size * 2);
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			}

			/**
			 * @brief Returns the size of the storage space currently allocated
			 * for the vector, expressed in terms of elements. This capacity is
			 * not necessarily equal to the vector size. It can be equal or
			 * greater, with the extra space allowing to accommodate for growth
			 * without the need to reallocate on each insertion.
			 * @return The size of the currently allocated storage capacity in
			 * the vector, measured in terms of the number elements it can hold.
			*/
			size_type capacity() const
			{
				return (_capacity);
			}

			/**
			 * @brief Returns whether the vector is empty (i.e. whether its size
			 * is 0).
			 * @return true if the container size is 0, false otherwise.
			*/
			bool empty() const
			{
				return (_size == 0);
			}

			/**
			 * @brief Requests that the vector capacity be at least enough to
			 * contain n elements. If n is greater than the current vector
			 * capacity, the function causes the container to reallocate its
			 * storage increasing its capacity to n (or greater). In all other
			 * cases, the function call does not cause a reallocation and the
			 * vector capacity is not affected. This function has no effect on
			 * the vector size and cannot alter its elements.
			 * @param n Minimum capacity for the vector. Note that the resulting
			 * vector capacity may be equal or greater than n.
			 * @throw If the size requested is greater than the maximum size
			 * (vector::max_size), a length_error exception is thrown.
			*/
			void reserve(size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("resized above max_size");
				if (n > _capacity)
					reallocate(n);
			}

/*
** ------------------------------ ELEMENT ACCESS -------------------------------
*/

			/**
			 * @brief Returns a reference to the element at position n in the
			 * vector container.
			 * @param n Position of an element in the container. Notice that the
			 * first element has a position of 0 (not 1).
			 * @return The element at the specified position in the vector.
			*/
			reference operator[](size_type n)
			{
				return (_head[n]);
			}

			/**
			 * @brief Returns a const_reference to the element at position n in
			 * the vector container.
			 * @param n Position of an element in the container. Notice that the
			 * first element has a position of 0 (not 1).
			 * @return The element at the specified position in the vector.
			*/
			const_reference operator[](size_type n) const
			{
				return (_head[n]);
			}

			/**
			 * @brief Returns a reference to the element at position n in the
			 * vector. The function automatically checks whether n is within the
			 * bounds of valid elements in the vector, throwing an out_of_range
			 * exception if it is not (i.e., if n is greater than, or equal to,
			 * its size). This is in contrast with member operator[], that does
			 * not check against bounds.
			 * @param n Position of an element in the container.
			 * @return The element at the specified position in the container.
			*/
			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("out-of-range");
				return (_head[n]);
			}

			/**
			 * @brief Returns a const_reference to the element at position n in
			 * the vector. The function automatically checks whether n is within
			 * the bounds of valid elements in the vector, throwing an
			 * out_of_range exception if it is not (i.e., if n is greater than,
			 * or equal to, its size). This is in contrast with member
			 * operator[], that does not check against bounds.
			 * @param n Position of an element in the container.
			 * @return The element at the specified position in the container.
			*/
			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("out-of-range");
				return (_head[n]);
			}

			/**
			 * @brief Returns a reference to the first element in the vector.
			 * Unlike member vector::begin, which returns an iterator to this
			 * same element, this function returns a direct reference. Calling
			 * this function on an empty container causes undefined behavior.
			 * @return A reference to the first element in the vector container.
			*/
			reference front()
			{
				return(_head[0]);
			}

			/**
			 * @brief Returns a const_reference to the first element in the
			 * vector. Unlike member vector::begin, which returns an iterator to
			 * this same element, this function returns a direct reference.
			 * Calling this function on an empty container causes undefined
			 * behavior.
			 * @return A const_reference to the first element in the vector
			 * container.
			*/
			const_reference front() const
			{
				return(_head[0]);
			}

			/**
			 * @brief Returns a reference to the last element in the vector.
			 * Unlike member vector::end, which returns an iterator just past
			 * this element, this function returns a direct reference. Calling
			 * this function on an empty container causes undefined behavior.
			 * @return A reference to the last element in the vector.
			*/
			reference back()
			{
				return(_head[_size - 1]);
			}

			/**
			 * @brief Returns a const_reference to the last element in the
			 * vector. Unlike member vector::end, which returns an iterator just
			 * past this element, this function returns a direct reference.
			 * Calling this function on an empty container causes undefined
			 * behavior.
			 * @return A const_reference to the last element in the vector.
			*/
			const_reference back() const
			{
				return(_head[_size - 1]);
			}

/*
** -------------------------------- MODIFIERS ----------------------------------
*/

			/**
			 * @brief Assigns new contents to the vector, replacing its current
			 * contents, and modifying its size accordingly. Any elements held
			 * in the container before the call are destroyed and replaced by
			 * newly constructed elements (no assignments of elements take
			 * place). The new contents are elements constructed from each of
			 * the elements in the range between first and last, in the same
			 * order.
			 * @param first,last Input iterators to the initial and final
			 * positions in a sequence. The range used is [first,last), which
			 * includes all the elements between first and last, including the
			 * element pointed by first but not the element pointed by last.
			*/
			template <class InputIterator>
			void assign(typename ft::enable_if<!std::numeric_limits<InputIterator>
				::is_integer, InputIterator>::type first, InputIterator last)
			{
				difference_type n = 0;
				InputIterator tmp(first);
				while (tmp != last)
				{
					++tmp;
					++n;
				}
				this->clear();
				this->reserve(n);
				for (; first != last; first++)
					push_back(*first);
			}

			/**
			 * @brief Assigns new contents to the vector, replacing its current
			 * contents, and modifying its size accordingly. Any elements held
			 * in the container before the call are destroyed and replaced by
			 * newly constructed elements (no assignments of elements take
			 * place). The new contents are n elements, each initialized to a
			 * copy of val.
			 * @param n New size for the container.
			 * @param val Value to fill the container with. Each of the n
			 * elements in the container will be initialized to a copy of this
			 * value.
			*/
			void assign(size_type n, const value_type& val)
			{
				this->clear();
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}

			/**
			 * @brief Adds a new element at the end of the vector, after its
			 * current last element. The content of val is copied (or moved) to
			 * the new element.
			 * @param val Value to be copied (or moved) to the new element.
			*/
			void push_back(const value_type& val)
			{
				if (_size ==_capacity)
					reallocate(grow(_size + 1));
				_alloc.construct(&_head[_size++], val);
			}

			/**
			 * @brief  Removes the last element in the vector, effectively
			 * reducing the container size by one. This destroys the removed
			 * element.
			*/
			void pop_back()
			{
				_alloc.destroy(&_head[--_size]);
			}

			/**
			 * @brief The vector is extended by inserting a new element before
			 * the element at the specified position, effectively increasing the
			 * container size by 1.
			 * @param position Position in the vector where the new elements are
			 * inserted.
			 * @param val Value to be copied (or moved) to the inserted
			 * elements.
			 * @return An iterator that points to the first of the newly
			 * inserted elements.
			*/
			iterator insert(iterator position, const value_type& val)
			{
				difference_type shift = (position - this->begin());
				if (_size + 1 > _capacity)
					reallocate(grow(_size + 1));
				this->insert(iterator(this->begin() + shift), 1, val);
				return (iterator(this->begin() + shift));
			}

			/**
			 * @brief The vector is extended by inserting new elements before
			 * the element at the specified position, effectively increasing the
			 * container size by the number of elements inserted.
			 * @param position Position in the vector where the new elements are
			 * inserted.
			 * @param n Number of elements to insert. Each element is
			 * initialized to a copy of val.
			 * @param val Value to be copied (or moved) to the inserted
			 * elements.
			*/
			void insert(iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return;
				difference_type shift = position - this->begin();
				difference_type tmp = this->end() - this->begin();

				this->resize(this->_size + n);
				iterator end = this->end();
				position = this->begin() + shift;
				iterator tmp_end = this->begin() + tmp;
				while (tmp_end != position)
				{
					--end;
					--tmp_end;
					*end = *tmp_end;
				}
				while (n--)
					*position++ = val;
			}

			/**
			 * @brief The vector is extended by inserting new elements before
			 * the element at the specified position, effectively increasing the
			 * container size by the number of elements inserted.
			 * @param position Position in the vector where the new elements are
			 * inserted.
			 * @param first,last Iterators specifying a range of elements.
			 * Copies of the elements in the range [first,last) are inserted at
			 * position (in the same order).
			*/
			template <class InputIterator>
			void insert(iterator position, typename ft::enable_if
				<!std::numeric_limits<InputIterator>::is_integer, InputIterator>
				::type first, InputIterator last)
			{
				difference_type shift = (position - this->begin());
				size_type n = 0;
				InputIterator tmp(first);
				while (tmp != last)
				{
					++tmp;
					++n;
				}
				if (_size == 0)
					reallocate(_size + n);
				if ((_size + n) > _capacity)
					reallocate((_size + n > _size * 2) ? _size + n : _size * 2);
				_size += n;
				iterator it(&_head[_size - n]);
				iterator insert_pos(&_head[shift]);
				iterator it_end = this->end();
				while (it >= insert_pos)
					*--it_end = *--it;
				while (first != last)
					_alloc.construct(&(*insert_pos++), *first++);
			}

			/**
			 * @brief Removes a single element from the vector. This effectively
			 * reduces the container size by 1 and destroy the element.
			 * @param iterator Iterator pointing to a single element to be
			 * removed from the vector.
			 * @return An iterator pointing to the new location of the element
			 * that followed the last element erased by the function call.
			 * This is the container end if the operation erased the last
			 * element in the sequence.
			*/
			iterator erase(iterator position)
			{
				return (this->erase(position, position + 1));
			}

			/**
			 * @brief Removes from the vector a range of elements
			 * ([first,last)). This effectively reduces the container size by
			 * the number of elements removed, which are destroyed.
			 * @param first,last Iterators specifying a range within the vector]
			 * to be removed: [first,last). i.e., the range includes all the
			 * elements between first and last, including the element pointed by
			 * first but not the one pointed by last.
			 * @return An iterator pointing to the new location of the element
			 * that followed the last element erased by the function call.
			 * This is the container end if the operation erased the last
			 * element in the sequence.
			*/
			iterator erase(iterator first, iterator last)
			{
				if (this->empty())
					return (last);
				size_type n = last - first;
				iterator ret(first);

				while (last != this->end())
					*(first++) = *(last++);
				while (n--)
					_alloc.destroy(&_head[--_size]);
				return (ret);
			}

			/**
			 * @brief Exchanges the content of the container by the content of
			 * x, which is another vector object of the same type. Sizes may
			 * differ. After the call to this member function, the elements in
			 * this container are those which were in x before the call, and the
			 * elements of x are those which were in this. All iterators,
			 * references and pointers remain valid for the swapped objects.
			 * @param x Another vector container of the same type (i.e.,
			 * instantiated with the same template parameters, T and Alloc)
			 * whose content is swapped with that of this container.
			*/
			void swap(vector& x)
			{
				swap(_size, x._size);
				swap(_capacity, x._capacity);
				swap(_alloc, x._alloc);
				swap(_head, x._head);
			}

			/**
			 * @brief Removes all elements from the vector (which are
			 * destroyed), leaving the container with a size of 0.
			*/
			void clear()
			{
				for (size_t i = 0; i < _size; ++i)
					_alloc.destroy(&_head[i]);
				_size = 0;
			}

/*
** -------------------------------- ALLOCATOR ----------------------------------
*/

			/**
			 * @brief Returns a copy of the allocator object associated with the
			 * vector.
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

			/**
			 * @brief 
			*/
			size_type grow(size_type new_size)
			{
				size_type	new_capacity = (_capacity > 0 ? _capacity : 1);
				while (new_capacity < new_size)
					new_capacity *= 2;
				return (new_capacity);
			}

			/**
			 * @brief 
			*/
			void reallocate(size_type new_capacity)
			{
				pointer new_vector = _alloc.allocate(new_capacity);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(&_head[i]);
					_alloc.construct(&new_vector[i], _head[i]);
				}
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
				_head = new_vector;
				_capacity = new_capacity;
			}

			template<class U>
			void swap(U& u1, U& u2)
			{
				U tmp = u2;
				u2 = u1;
				u1 = tmp;
			}
	};

/*
** -------------------------------- OVERLOADS ----------------------------------
*/

		template <class T, class Alloc>
		bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
		template <class T, class Alloc>
		bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs == rhs);
		}
		template <class T, class Alloc>
		bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
				rhs.begin(), rhs.end()));
		}
		template <class T, class Alloc>
		bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(rhs < lhs);
		}
		template <class T, class Alloc>
		bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}
		template <class T, class Alloc>
		bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs < rhs);
		}

		template <class T, class Alloc>
		void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
}

#endif /* ******************************************************** VECTOR_HPP */