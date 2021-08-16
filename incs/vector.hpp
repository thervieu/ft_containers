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
	** @brief Vectors are sequence containers representing arrays that can
	** change in size.
	** @tparam T Type of the elements.
	** @tparam Alloc Type of the allocator object used to define the storage
	** allocation model. By default, the allocator class template is used, which
	** defines the simplest memory allocation model and is value-independent.
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
			pointer			_head;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			bool			_ugly_boolean;

		public:

			/**
			** @brief empty container constructor (default constructor):
			** Constructs an empty container, with no elements.
			*/

			explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(1), _alloc(alloc)
			{
				_head = _alloc.allocate(1);
				_ugly_boolean = false;
			}

			/**
			** @brief fill constructor: Constructs a container with n elements.
			** Each element is a copy of val.
			*/

			explicit vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
				: _size(n), _capacity(n), _alloc(alloc)
			{
				this->_head = _alloc.allocate(this->_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_head[i], val);
				_ugly_boolean = true;
			}

			/**
			** @brief range constructor: Constructs a container with as many
			** elements as the range [first,last) (last is not included) in the
			** same order.
			*/

			template <class InputIterator>
			vector(typename ft::enable_if<!std::numeric_limits<InputIterator>
				::is_integer, InputIterator>::type first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(0), _alloc(alloc), _ugly_boolean(true)
			{
				this->assign(first, last);
			}

			/**
			** @brief copy constructor: Constructs a container with a copy of
			** each of the elements in x, in the same order.
			** @param x Another vector object of the same type (with the same
			** class template arguments T and Alloc), whose contents are either
			** copied or acquired.
			*/

			vector(const vector& x) : _size(x._size), _capacity(x._size),
				_alloc(x._alloc), _ugly_boolean(true)
			{
				_head = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(&_head[i], x._head[i]);
			}

			/**
			** @brief Vector destructor: Destroys the container object. This
			** destroys all container elements, and deallocates all the storage
			** capacity allocated by the vector using its allocator.
			*/

			~vector()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_head[i]);
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
			}

			/**
			** @brief Assigns new contents to the container, replacing its
			** current contents, and modifying its size accordingly. The
			** container preserves its current allocator, which is used to
			** allocate storage in case of reallocation.
			** @param x A vector object of the same type (i.e., with the same
			** template parameters, T and Alloc).
			*/
			vector& operator=(const vector& x)
			{
				_ugly_boolean = true;
				
				_size = x._size;
				if (_capacity)
					_alloc.deallocate(_head, _capacity);
				
				_head = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_head[i], x._head[i]);
				_capacity < _size ? _capacity = _size : 0;
				
				return (*this);
			}

/*
** --------------------------------- ITERATORS ---------------------------------
*/

			/**
			** @brief Returns an iterator pointing to the first element in the
			** vector.
			** @return An iterator to the beginning of the sequence container.
			** If the container is empty, the returned iterator value shall not
			** be dereferenced.
			*/
			iterator begin()
			{
				return (iterator(_head));
			}

			/**
			** @brief Returns a const_iterator pointing to the first element in
			** the vector.
			** @return An const_iterator to the beginning of the sequence
			** container. If the container is empty, the returned iterator value
			** shall not be dereferenced.
			*/
			const_iterator begin() const
			{
				return (const_iterator(_head));
			}

			/**
			** @brief Returns an iterator referring to the past-the-end element
			** in the vector container. The past-the-end element is the
			** theoretical element that would follow the last element in the
			** vector. It does not point to any element, and thus shall not be
			** dereferenced.
			** @return Returns an iterator referring to the past-the-end element
			** in the vector container.
			*/
			iterator end()
			{
				return (iterator(_head + _size));
			}

			/**
			** @brief Returns a const_iterator referring to the past-the-end
			** element in the vector container. The past-the-end element is the
			** theoretical element that would follow the last element in the
			** vector. It does not point to any element, and thus shall not be
			** dereferenced.
			** @return Returns a const_iterator referring to the past-the-end
			** element in the vector container.
			*/
			const_iterator end() const
			{
				return (const_iterator(_head + _size));
			}

			/**
			** @brief Returns a reverse_iterator pointing to the last element in
			** the vector (i.e., its reverse beginning). Reverse iterators
			** iterate backwards: increasing them moves them towards the
			** beginning of the container. rbegin points to the element right
			** before the one that would be pointed to by member end.
			** @return A reverse_iterator to the reverse beginning of the
			** sequence container.
			*/
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			/**
			** @brief Returns a const_reverse_iterator pointing to the last
			** element in the vector (i.e., its reverse beginning). Reverse
			** iterators iterate backwards: increasing them moves them towards
			** the beginning of the container. rbegin points to the element
			** right before the one that would be pointed to by member end.
			** @return A const_reverse_iterator to the reverse beginning of the
			** sequence container.
			*/
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			/**
			** @brief Returns a reverse iterator pointing to the theoretical
			** element preceding the first element in the vector (which is
			** considered its reverse end). The range between vector::rbegin and
			** vector::rend contains all the elements of the vector (in reverse
			** order).
			** @return A reverse iterator to the reverse end of the sequence
			** container.
			*/
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			/**
			** @brief Returns a const_reverse_iterator pointing to the
			** theoretical element preceding the first element in the vector
			** (which is considered its reverse end). The range between
			** vector::rbegin and vector::rend contains all the elements of the
			** vector (in reverse order).
			** @return A const_reverse_iterator to the reverse end of the
			** sequence container.
			*/
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

/*
** --------------------------------- CAPACITY ----------------------------------
*/

			/**
			** @brief Returns the number of elements in the vector. This is the
			** number of actual objects held in the vector, which is not
			** necessarily equal to its storage capacity.
			** @return The number of elements in the container.
			*/
			size_type size() const
			{
				return (_size);
			}

			/**
			** @brief Returns the maximum number of elements that the vector can
			** hold.
			** @return  The maximum number of elements a vector container can
			** hold as content.
			*/
			size_type max_size() const
			{
				return (_alloc.max_size());
			}

			/**
			** @brief  Resizes the container so that it contains n elements.
			*/

			void resize(size_type n, value_type val = value_type())
			{
				_ugly_boolean = true;

				if (n > _capacity)
					reallocate((n > _size * 2) ? n : _size * 2);
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			}

			/**
			** @brief Returns the size of the storage space currently allocated
			** for the vector, expressed in terms of elements. This capacity is
			** not necessarily equal to the vector size. It can be equal or
			** greater, with the extra space allowing to accommodate for growth
			** without the need to reallocate on each insertion.
			** @return The size of the currently allocated storage capacity in
			** the vector, measured in terms of the number elements it can hold.
			*/

			size_type capacity() const
			{
				return (_ugly_boolean ? _capacity : 0);
			}

			/**
			** @brief Returns whether the vector is empty (i.e. whether its size
			** is 0).
			** @return true if the container size is 0, false otherwise.
			*/

			bool empty() const
			{
				return (_size == 0);
			}

			/**
			** @brief Requests that the vector capacity be at least enough to
			** contain n elements.
			** @throw If the size requested is greater than the maximum size
			** (vector::max_size), a length_error exception is thrown.
			*/

			void reserve(size_type n)
			{
				_ugly_boolean = true;
				if (n > this->max_size())
					throw std::length_error("resized above max_size");
				if (n > _capacity)
					reallocate(n);
			}

/*
** ------------------------------ ELEMENT ACCESS -------------------------------
*/

			/**
			** @brief Returns a reference to the element at position n in the
			** vector container.
			** @return The element at the specified position in the vector.
			*/

			reference operator[](size_type n)
			{
				return (_head[n]);
			}

			/**
			** @brief Returns a const_reference to the element at position n in
			** the vector container.
			** @return The element at the specified position in the vector.
			*/

			const_reference operator[](size_type n) const
			{
				return (_head[n]);
			}

			/**
			** @brief Returns a reference to the element at position n in the
			** vector.
			** @return The element at the specified position in the container.
			*/

			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("out-of-range");
				return (_head[n]);
			}

			/**
			** @brief Returns a const_reference to the element at position n in
			** the vector.
			** @return The element at the specified position in the container.
			*/

			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("out-of-range");
				return (_head[n]);
			}

			/**
			** @brief Returns a reference to the first element in the vector.
			** @return A reference to the first element in the vector container.
			*/

			reference front()
			{
				return(_head[0]);
			}

			/**
			** @brief Returns a const_reference to the first element in the
			** vector.
			** @return A const_reference to the first element in the vector
			** container.
			*/

			const_reference front() const
			{
				return(_head[0]);
			}

			/**
			** @brief Returns a reference to the last element in the vector.
			** @return A reference to the last element in the vector.
			*/

			reference back()
			{
				return(_head[_size - 1]);
			}

			/**
			** @brief Returns a const_reference to the last element in the
			** vector.
			** @return A const_reference to the last element in the vector.
			*/

			const_reference back() const
			{
				return(_head[_size - 1]);
			}

/*
** -------------------------------- MODIFIERS ----------------------------------
*/

			/**
			** @brief Assigns new contents to the vector, replacing its current
			** contents, and modifying its size accordingly.
			*/

			template <class InputIterator>
			void assign(typename ft::enable_if<!std::numeric_limits<InputIterator>
				::is_integer, InputIterator>::type first, InputIterator last)
			{
				_ugly_boolean = true;

				difference_type n = 0;

				InputIterator tmp(first);
				while (tmp != last)
				{
					++tmp;
					++n;
				}
				
				this->clear();
				this->reserve(n);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			/**
			** @brief Assigns new contents to the vector, replacing its current
			** contents, and modifying its size accordingly.
			*/

			void assign(size_type n, const value_type& val)
			{
				_ugly_boolean = true;
				
				this->clear();
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}

			/**
			** @brief Adds a new element at the end of the vector, after its
			** current last element. The content of val is copied (or moved) to
			** the new element.
			*/

			void push_back(const value_type& val)
			{
				_ugly_boolean = true;
				
				if (_size ==_capacity)
					reallocate(grow(_size + 1));
				_alloc.construct(&_head[_size++], val);
			}

			/**
			** @brief  Removes the last element in the vector, effectively
			** reducing the container size by one. This destroys the removed
			** element.
			*/

			void pop_back()
			{
				_ugly_boolean = true;
				_alloc.destroy(&_head[--_size]);
			}

			/**
			** @brief The vector is extended by inserting a new element before
			** the element at the specified position, effectively increasing the
			** container size by 1.
			** @return An iterator that points to the first of the newly
			** inserted elements.
			*/

			iterator insert(iterator position, const value_type& val)
			{
				_ugly_boolean = true;
				
				difference_type shift = (position - this->begin());
				if (_size + 1 > _capacity)
					reallocate(grow(_size + 1));
				
				this->insert(iterator(this->begin() + shift), 1, val);
				return (iterator(this->begin() + shift));
			}

			/**
			** @brief The vector is extended by inserting new elements before
			** the element at the specified position, effectively increasing the
			** container size by the number of elements inserted.
			*/

			void insert(iterator position, size_type n, const value_type& val)
			{
				_ugly_boolean = true;
				
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
			** @brief The vector is extended by inserting new elements before
			** the element at the specified position, effectively increasing the
			** container size by the number of elements inserted.
			*/

			template <class InputIterator>
			void insert(iterator position, typename ft::enable_if
				<!std::numeric_limits<InputIterator>::is_integer, InputIterator>
				::type first, InputIterator last)
			{
				_ugly_boolean = true;
				
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
			** @brief Removes a single element from the vector. This effectively
			** reduces the container size by 1 and destroy the element.
			** @return An iterator pointing to the new location of the element
			** that followed the last element erased by the function call.
			*/

			iterator erase(iterator position)
			{
				return (this->erase(position, position + 1));
			}

			/**
			** @brief Removes from the vector a range of elements
			** ([first,last)). This effectively reduces the container size by
			** the number of elements removed, which are destroyed.
			** @return An iterator pointing to the new location of the element
			** that followed the last element erased by the function call.
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
			** @brief Exchanges the content of the container by the content of
			** x, which is another vector object of the same type.
			*/

			void swap(vector& x)
			{
				swap(_size, x._size);
				swap(_capacity, x._capacity);
				swap(_alloc, x._alloc);
				swap(_head, x._head);
			}

			/**
			** @brief Removes all elements from the vector (which are
			** destroyed), leaving the container with a size of 0.
			*/

			void clear()
			{
				for (size_t i = 0; i < _size; ++i)
					_alloc.destroy(&_head[i]);
				_size = 0;
			}

			/**
			** @brief Returns a copy of the allocator object associated with the
			** vector.
			** @return The allocator.
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
			** @brief Returns a unsigned int that corresponds to the new size of
			** the allocated array.
			**@return the new size to allocate.
			*/

			size_type grow(size_type new_size)
			{
				size_type	new_capacity = (_capacity > 0 ? _capacity : 1);
				
				while (new_capacity < new_size)
					new_capacity *= 2;
				return (new_capacity);
			}

			/**
			** @brief Allocates the capacity given to the array and copies the values
			** stored
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

#endif