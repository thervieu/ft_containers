#ifndef FT_STL_HPP
# define FT_STL_HPP

namespace ft
{
	template <bool B, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class Iterator1, class Iterato2>
	static bool	equal(Iterator1 begin1, Iterator1 end1, Iterato2 begin2)
	{
		while (begin1 != end1)
		{
			if (*begin1 != *begin2)
				return (false);
			begin1++;
			begin2++;
		}
		return (true);
	}

	template <class Iterator1, class Iterato2>
	static bool	lexicographical_compare(Iterator1 begin1, Iterator1 end1,
		Iterato2 begin2, Iterato2 end2)
	{
		while (begin1 != end1)
		{
			if (begin2 == end2 || *begin2 < *begin1)
				return (false);
			else if (*begin1 < *begin2)
				return (true);
			begin1++;
			begin2++;
		}
		return (begin2 != end2);
	}

	template<class T1, class T2>
	struct pair
	{
			typedef T1		first_type;
			typedef T2		second_type;

			first_type		first;
			second_type		second;

			pair() : first(first_type()), second(second_type()) {}
			pair(const first_type& x, const second_type& y)
			: first(x), second(y) {}
			template<class U, class V>
			pair(const pair<U,V>& src) : first(src.first), second(src.second) {}
			~pair() {}

			pair& operator=(const pair& rhs)
			{
				if (this != &rhs)
				{
					first = rhs.first;
					second = rhs.second;
				}
				return (*this);
			}
	};

	template<class T1, class T2>
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template<class T1, class T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T1, class T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		if (lhs.first < rhs.first || lhs.second < rhs.second)
			return (true);
		return (false);
	}

	template<class T1, class T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		if (lhs.first <= rhs.first || lhs.second <= rhs.second)
			return (true);
		return (false);
	}

	template<class T1, class T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (!(lhs <= rhs));
	}

	template<class T1, class T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 t, T2 u)
	{
		return (ft::pair<T1, T2>(t, u));
	}
}

#endif