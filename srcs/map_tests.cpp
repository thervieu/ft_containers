#include "../incs/tests.hpp"


template <typename T, typename S>
bool operator==(ft::map<T, S> &a, std::map<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

template <typename T, typename S>
static void	printMap(ft::map<T, S> &lhs)
{
	typename ft::map<T, S>::iterator it = lhs.begin();
	std::cout << "ft :  ";
	while (it != lhs.end())
	{
		std::cout << "lhs(" << it->first << ") = " << it->second << " - ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T, typename S>
static void	printTrueMap(std::map<T, S> &lhs)
{
	typename std::map<T, S>::iterator it = lhs.begin();
	std::cout << "std : ";
	while (it != lhs.end())
	{
		std::cout << "lhs(" << it->first << ") = " << it->second << " - ";
		++it;
	}
	std::cout << std::endl;
}

static void constructors(void)
{
	std::cout << "Constructors / Copy" << std::endl;
	
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	
	ft::map<int, int> m1;
	std::map<int, int> m2;
	
	std::cout << "(default) m1 == m2 : " << (m1 == m2) << std::endl;
	
	ft::map<int, int> m3(a, a + 3);
	std::map<int, int> m4(a, a + 3);
	
	std::cout << "(range) : m3 == m4 : " << (m3 == m4) << std::endl;
	
	ft::map<int, int> m5(m3);
	std::map<int, int> m6(m4);
	
	std::cout << "(copy) m5 == m6 : " << (m5 == m6) << std::endl;
	
	ft::map<int, int> m7;
	std::map<int, int> m8;
	
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	
	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	
	std::cout << "(copy) m7 == m8 : " << (m7 == m8) << std::endl;
	
	ft::map<int, int> m9;
	std::map<int, int> m10;
	
	m9 = m7;
	m10 = m8;
	
	std::cout << "(copy) m9 == m10 : " << (m9 == m10) << std::endl;
	std::cout << std::endl;
}

static void max_size(void)
{
	std::cout << "Max_Size" << std::endl;
	
	ft::map<int, int> m1;
	std::map<int, int> m2;
	
	std::cout << "m1.max_size() == m2.max_size() : " << (m1.max_size() == m2.max_size()) << std::endl;
	
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	
	std::cout << "m3.max_size() == m4.max_size() : " << (m3.max_size() == m4.max_size()) << std::endl;
	std::cout << std::endl;
}

static void access_operator(void)
{
	std::cout << "[] operator" << std::endl;
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 0;
	m1["c"] = 42;
	m1["d"] = -5;
	m1["d"] = 11;
	m1["test"] = 100;
	
	m2["a"] = 1;
	m2["b"] = 0;
	m2["c"] = 42;
	m2["d"] = -5;
	m2["d"] = 11;
	m2["test"] = 100;
	
	std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;
	
	std::cout << "m1['a'] == m2['a'] : " << (m1["a"] == m2["a"]) << std::endl;
	std::cout << "m1['d'] == m2['d'] : " << (m1["d"] == m2["d"]) << std::endl;
	std::cout << "m1['test] == m2['test'] : " << (m1["test"] == m2["test"]) << std::endl;
	std::cout << "m1['z'] == m2['z'] : " << (m1["z"] == m2["z"]) << std::endl;
	std::cout << std::endl;
}

static void insert(void)
{
	std::cout << "Insert" << std::endl;

	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};

	ft::map<int, int> m1(a, a + 3);
	std::map<int, int> m2(a, a + 3);

	m1.insert(++m1.begin(), std::make_pair(5, 5));
	m2.insert(++m2.begin(), std::make_pair(5, 5));

	std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;

	m1.insert(std::make_pair(5, 0));
	m2.insert(std::make_pair(5, 0));
	m1.insert(std::make_pair(10, 54));
	m2.insert(std::make_pair(10, 54));

	std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;
	std::cout << std::endl;
}

static void erase(void)
{
	std::cout << "Erase" << std::endl;

	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;

	m1["test"] = 1;
	m1["a"] = 2;
	m1["b"] = 3;
	m1["c"] = 4;
	m1["d"] = 6;
	m1["e"] = 8;

	m2["test"] = 1;
	m2["a"] = 2;
	m2["b"] = 3;
	m2["c"] = 4;
	m2["d"] = 6;
	m2["e"] = 8;

	m1.erase(m1.begin());
	m2.erase(m2.begin());

	std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;

	m1.erase("d");
	m2.erase("d");

	std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;

	m1.erase(m1.begin(), m1.end());
	m2.erase(m2.begin(), m2.end());

	std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;
	std::cout << std::endl;
}

static void swap(void)
{
	std::cout << "Swap" << std::endl;

	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;

	m1["a"] = 1;
	m1["b"] = 2;
	m1["c"] = 3;

	m2["a"] = 1;
	m2["b"] = 2;
	m2["c"] = 3;

	m3["a"] = 42;
	m3["b"] = 21;

	m4["a"] = 42;
	m4["b"] = 21;

	m1.swap(m3);
	m2.swap(m4);

	std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;
	std::cout << "m3 == m4 : " << (m3 == m4) << std::endl;
	std::cout << std::endl;
}

static void clear(void)
{
	std::cout << "Clear" << std::endl;
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 42;
	
	m2["a"] = 1;
	m2["b"] = 42;
	
	m1.clear();
	m2.clear();
	
	std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;
	std::cout << std::endl;
}

static void find(void)
{
	std::cout << "Find" << std::endl;
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 42;
	
	m2["a"] = 1;
	m2["b"] = 42;
	
	std::cout << "m1.find('a')->second == m2.find('a')->second : " << (m1.find("a")->second == m2.find("a")->second) << std::endl;
	std::cout << "m1.find('z')->second == m2.find('z')->second : " << (m1.find("z")->second == m2.find("z")->second) << std::endl;
	std::cout << std::endl;
}

static void count(void)
{
	std::cout << "Count" << std::endl;
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 42;
	m1["b"] = 21;
	
	m2["a"] = 1;
	m2["b"] = 42;
	m2["b"] = 21;
	
	std::cout << "m1.count('a') == m2.count('a') : " << (m1.count("a") == m2.count("a")) << std::endl;
	std::cout << "m1.count('b') == m2.count('b') : " << (m1.count("b") == m2.count("b")) << std::endl;
	std::cout << "m1.count('z') == m2.count('z') : " << (m1.count("z") == m2.count("z")) << std::endl;
	std::cout << std::endl;
}

static void bounds()
{
	std::cout << "Bounds" << std::endl;
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	
	std::cout << "m1.lower_bound('a') == m2.lower_bound('a') : " << (m1.lower_bound("a")->first == m2.lower_bound("a")->first) << std::endl;
	std::cout << "m1.lower_bound('c') == m2.lower_bound('c') : " << (m1.lower_bound("c")->first == m2.lower_bound("c")->first) << std::endl;
	std::cout << "m1.upper_bound('a') == m2.upper_bound('a') : " << (m1.upper_bound("a")->first == m2.upper_bound("a")->first) << std::endl;
	std::cout << "m1.upper_bound('c') == m2.upper_bound('c') : " << (m1.upper_bound("c")->first == m2.upper_bound("c")->first) << std::endl;
	std::cout << std::endl;
}

static void range(void)
{
	std::cout << "Equal range" << std::endl;
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	
	std::pair<ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> a = m1.equal_range("a");
	std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> b = m2.equal_range("a");
	
	std::cout << "a.first->first == b.first->first : " << (a.first->first == b.first->first) << std::endl;
	std::cout << "a.first->second == b.first->second : " << (a.first->second == b.first->second) << std::endl;
	std::cout << "a.second->first == b.second->first : " << (a.second->first == b.second->first) << std::endl;
	std::cout << "a.second->second == b.second->second : " << (a.second->second == b.second->second) << std::endl;
	std::cout << std::endl;
}

static void operators_comp(void)
{
	std::cout << "Operators" << std::endl;
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	
	m3 = m1;
	m4 = m2;
	
	std::cout << "m1 == m2 : " << (m1 == m3) << " " << (m2 == m4) << std::endl;
	std::cout << "m1 != m2 : " << (m1 != m3) << " " << (m2 != m4) << std::endl;
	std::cout << "m1 > m2 : " << (m1 > m3) << " " << (m2 > m4) << std::endl;
	std::cout << "m1 < m2 : " << (m1 < m3) << " " << (m2 < m4) << std::endl;
	std::cout << "m1 >= m2 : " << (m1 >= m3) << " " << (m2 >= m4) << std::endl;
	std::cout << "m1 <= m2 : " << (m1 <= m3) << " " << (m2 <= m4) << std::endl;
	
	m1["e"] = 1;
	m2["e"] = 1;
	
	std::cout << "m1 == m2 : " << (m1 == m3) << " " << (m2 == m4) << std::endl;
	std::cout << "m1 != m2 : " << (m1 != m3) << " " << (m2 != m4) << std::endl;
	std::cout << "m1 > m2 : " << (m1 > m3) << " " << (m2 > m4) << std::endl;
	std::cout << "m1 < m2 : " << (m1 < m3) << " " << (m2 < m4) << std::endl;
	std::cout << "m1 >= m2 : " << (m1 >= m3) << " " << (m2 >= m4) << std::endl;
	std::cout << "m1 <= m2 : " << (m1 <= m3) << " " << (m2 <= m4) << std::endl;
	
	m3["e"] = 3;
	m4["e"] = 3;
	
	std::cout << "m1 == m2 : " << (m1 == m3) << " " << (m2 == m4) << std::endl;
	std::cout << "m1 != m2 : " << (m1 != m3) << " " << (m2 != m4) << std::endl;
	std::cout << "m1 > m2 : " << (m1 > m3) << " " << (m2 > m4) << std::endl;
	std::cout << "m1 < m2 : " << (m1 < m3) << " " << (m2 < m4) << std::endl;
	std::cout << "m1 >= m2 : " << (m1 >= m3) << " " << (m2 >= m4) << std::endl;
	std::cout << "m1 <= m2 : " << (m1 <= m3) << " " << (m2 <= m4) << std::endl;
	std::cout << std::endl;
}

void map_tests(void)
{
	std::cout << "MAP" << std::endl;
	constructors();
	max_size();
	access_operator();
	insert();
	erase();
	swap();
	clear();
	find();
	count();
	bounds();
	range();
	operators_comp();
}
