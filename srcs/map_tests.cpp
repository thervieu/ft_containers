#include "../incs/tests.hpp"
#include "../incs/ft_stl.hpp"


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

	typename ft::map<T, S>::reverse_iterator rev = a.rbegin();
	typename std::map<T, S>::reverse_iterator rev2 = b.rbegin();
	while (rev != a.rend())
	{
		if (rev->first != rev2->first || rev->second != rev2->second)
			return (false);
		++rev;
		++rev2;
	}
	return (true);
};

static void constructors(void)
{
	printTitle("Constructors");
	
	std::pair<int, int> a[] = {std::make_pair(0, 3), std::make_pair(2, 0), std::make_pair(2, 1)};
	ft::pair<int, int> b[] = {ft::make_pair(0, 3), ft::make_pair(2, 0), ft::make_pair(2, 1)};

	ft::map<int, int> m1;
	std::map<int, int> m2;
	
	std::cout << "default : " << printBool((m1 == m2)) << std::endl;
	
	ft::map<int, int> m3(b, b + 2);
	std::map<int, int> m4(a, a + 2);
	
	std::cout << "range : " << printBool((m3 == m4)) << std::endl;
	
	ft::map<int, int> m5(m3);
	std::map<int, int> m6(m4);
	
	std::cout << "copy : " << printBool((m5 == m6)) << std::endl;
	
	ft::map<int, int> m7;
	std::map<int, int> m8;
	
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	
	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	
	ft::map<int, int> m9;
	std::map<int, int> m10;
	
	m9 = m7;
	m10 = m8;
	
	std::cout << "operator= : " << printBool((m9 == m10)) << std::endl;
	std::cout << std::endl;
}

static void max_size(void)
{
	printTitle("Max_Size");
	
	ft::map<int, int> m1;
	std::map<int, int> m2;
	
	std::cout << "int : " << printBool((m1.max_size() == m2.max_size())) << std::endl;
	
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	
	std::cout << "string : " << printBool((m3.max_size() == m4.max_size())) << std::endl;
	std::cout << std::endl;
}

static void access_operator(void)
{
	printTitle("operator[]");
	
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
	
	std::cout << "m1 == m2 : " << printBool((m1 == m2)) << std::endl;
	
	std::cout << "m1['a'] == m2['a'] : " << printBool((m1["a"] == m2["a"])) << std::endl;
	std::cout << "m1['d'] == m2['d'] : " << printBool((m1["d"] == m2["d"])) << std::endl;
	std::cout << "m1['test] == m2['test'] : " << printBool((m1["test"] == m2["test"])) << std::endl;
	std::cout << "m1['z'] == m2['z'] : " << printBool((m1["z"] == m2["z"])) << std::endl;
	std::cout << std::endl;
}

static void insert(void)
{
	printTitle("Insert");

	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::pair<int, int> b[] = {ft::make_pair(0, 1), ft::make_pair(1, 0), ft::make_pair(2, 1)};

	ft::map<int, int> m1(b, b + 3);
	std::map<int, int> m2(a, a + 3);


	m1.insert(ft::make_pair(5, 0));
	m2.insert(std::make_pair(5, 0));
	m1.insert(ft::make_pair(10, 54));
	m2.insert(std::make_pair(10, 54));

	std::cout << "single element : " << printBool((m1 == m2)) << std::endl;

	m1.insert(++m1.begin(), ft::make_pair(5, 5));
	m2.insert(++m2.begin(), std::make_pair(5, 5));

	std::cout << "hint : " << printBool((m1 == m2)) << std::endl;

	m1.insert(b, b + 2);
	m2.insert(a, a + 2);
	
	std::cout << "range : " << printBool((m1 == m2)) << std::endl;

	std::cout << std::endl;
}

static void erase(void)
{
	printTitle("Erase");

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

	m1.erase(++m1.begin());
	m2.erase(++m2.begin());

	std::cout << "position : " << printBool((m1 == m2)) << std::endl;

	m1.erase("d");
	m2.erase("d");

	std::cout << "key_type : " << printBool((m1 == m2)) << std::endl;

	m1.erase((++m1.begin()), (--m1.end()));
	m2.erase(++m2.begin(), --m2.end());

	std::cout << "range : " << printBool((m1 == m2)) << std::endl;
	std::cout << std::endl;
}

static void swap(void)
{
	printTitle("Swap");

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

	std::cout << "m1 == m2 : " << printBool((m1 == m2)) << std::endl;
	std::cout << "m3 == m4 : " << printBool((m3 == m4)) << std::endl;
	std::cout << std::endl;
}

static void clear(void)
{
	printTitle("Clear");
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 42;
	
	m2["a"] = 1;
	m2["b"] = 42;
	
	m1.clear();
	m2.clear();
	
	std::cout << "m1 == m2 : " << printBool((m1 == m2)) << std::endl;
	std::cout << std::endl;
}

static void find(void)
{
	printTitle("Find");
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;

	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 123;
	
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 123;

	std::cout << "m1.find('a')->second == m2.find('a')->second : " << printBool((m1.find("a")->second == m2.find("a")->second)) << std::endl;
	std::cout << "m1.find('b')->second == m2.find('b')->second : " << printBool((m1.find("b")->second == m2.find("b")->second)) << std::endl;
	std::cout << std::endl;
}

static void count(void)
{
	printTitle("Count");
	
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	
	m1["a"] = 1;
	m1["b"] = 42;
	m1["b"] = 21;
	
	m2["a"] = 1;
	m2["b"] = 42;
	m2["b"] = 21;
	
	std::cout << "m1.count('a') == m2.count('a') : " << printBool((m1.count("a") == m2.count("a"))) << std::endl;
	std::cout << "m1.count('b') == m2.count('b') : " << printBool((m1.count("b") == m2.count("b"))) << std::endl;
	std::cout << "m1.count('z') == m2.count('z') : " << printBool((m1.count("z") == m2.count("z"))) << std::endl;
	std::cout << std::endl;
}

static void bounds()
{
	printTitle("Bounds");
	
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
	
	std::cout << "m1.lower_bound('a') == m2.lower_bound('a') : " << printBool((m1.lower_bound("a")->first == m2.lower_bound("a")->first)) << std::endl;
	std::cout << "m1.lower_bound('c') == m2.lower_bound('c') : " << printBool((m1.lower_bound("c")->first == m2.lower_bound("c")->first)) << std::endl;
	std::cout << "m1.upper_bound('a') == m2.upper_bound('a') : " << printBool((m1.upper_bound("a")->first == m2.upper_bound("a")->first)) << std::endl;
	std::cout << "m1.upper_bound('c') == m2.upper_bound('c') : " << printBool((m1.upper_bound("c")->first == m2.upper_bound("c")->first)) << std::endl;
	std::cout << std::endl;
}

static void range(void)
{
	printTitle("Equal_range");

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
	
	ft::pair<ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> a = m1.equal_range("a");
	std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> b = m2.equal_range("a");
	
	std::cout << "a.first->first == b.first->first : " << printBool((a.first->first == b.first->first)) << std::endl;
	std::cout << "a.first->second == b.first->second : " << printBool((a.first->second == b.first->second)) << std::endl;
	std::cout << "a.second->first == b.second->first : " << printBool((a.second->first == b.second->first)) << std::endl;
	std::cout << "a.second->second == b.second->second : " << printBool((a.second->second == b.second->second)) << std::endl;
	std::cout << std::endl;
}

static void operators_comp(void)
{
	printTitle("Operators");
	
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
	
	std::cout << "m1 == m2 : " << printBool(((m1 == m3) == (m2 == m4))) << std::endl;
	std::cout << "m1 != m2 : " << printBool(((m1 != m3) == (m2 != m4))) << std::endl;
	std::cout << "m1 >= m2 : " << printBool(((m1 >= m3) == (m2 >= m4))) << std::endl;
	std::cout << "m1 > m2  : " << printBool(((m1 > m3) == (m2 > m4))) << std::endl;
	std::cout << "m1 <= m2 : " << printBool(((m1 <= m3) == (m2 <= m4))) << std::endl;
	std::cout << "m1 < m2  : " << printBool(((m1 < m3) == (m2 < m4))) << std::endl;
	std::cout << std::endl;
	
	m1["e"] = 1;
	m2["e"] = 1;
	
	std::cout << "m1 == m2 : " << printBool(((m1 == m3) == (m2 == m4))) << std::endl;
	std::cout << "m1 != m2 : " << printBool(((m1 != m3) == (m2 != m4))) << std::endl;
	std::cout << "m1 >= m2 : " << printBool(((m1 >= m3) == (m2 >= m4))) << std::endl;
	std::cout << "m1 > m2  : " << printBool(((m1 > m3) == (m2 > m4))) << std::endl;
	std::cout << "m1 <= m2 : " << printBool(((m1 <= m3) == (m2 <= m4))) << std::endl;
	std::cout << "m1 < m2  : " << printBool(((m1 < m3) == (m2 < m4))) << std::endl;
	std::cout << std::endl;
	
	m3["e"] = 3;
	m4["e"] = 3;

	std::cout << "m1 == m2 : " << printBool(((m1 == m3) == (m2 == m4))) << std::endl;
	std::cout << "m1 != m2 : " << printBool(((m1 != m3) == (m2 != m4))) << std::endl;
	std::cout << "m1 >= m2 : " << printBool(((m1 >= m3) == (m2 >= m4))) << std::endl;
	std::cout << "m1 > m2  : " << printBool(((m1 > m3) == (m2 > m4))) << std::endl;
	std::cout << "m1 <= m2 : " << printBool(((m1 <= m3) == (m2 <= m4))) << std::endl;
	std::cout << "m1 < m2  : " << printBool(((m1 < m3) == (m2 < m4))) << std::endl << std::endl;
}

template <typename T, typename S>
bool operator==(ft::pair<T, S> &a, std::pair<T, S> &b)
{
	if (a.first != b.first || a.second != b.second)
		return (false);
	return (true);
};


template <typename T, typename S>
bool operator==(ft::pair<T, S> &a, const std::pair<T, S> &b)
{
	if (a.first != b.first || a.second != b.second)
		return (false);
	return (true);
};

static void iterators(void)
{
	printTitle("Iterators");


	ft::map<std::string, bool> ft2;
	std::map<std::string, bool> std2;

	for (unsigned int i = 1; i < 10; ++i)
	{
		std::string str;
		for (int j = 0; j < (int)i; j++)
			str += "a";
		
		ft2.insert(ft::make_pair(str, i % 2 == 0 ? true : false));
		std2.insert(std::make_pair(str, i % 2 == 0 ? true : false));
	}
	std::cout << printBool(ft2 == std2) << std::endl;

	ft::map<std::string, bool>::reverse_iterator it(ft2.rbegin());
	ft::map<std::string, bool>::const_reverse_iterator ite(ft2.rbegin());

	std::map<std::string, bool>::reverse_iterator it_std(std2.rbegin());
	std::map<std::string, bool>::const_reverse_iterator ite_std(std2.rbegin());
	std::cout << "Verify that the values are equal : " << printBool((it)->first == (it_std)->first) << std::endl;

	std::cout << "First Test is about verifying the use of operators ++, -- (pre and post), * and -> on reverse_iterator\n";
	std::cout << "Operator++ :\n";
	std::cout << printBool(*(++it) == (*(++it_std))) << std::endl;
	std::cout << printBool(*(it++) == *(it_std++)) << std::endl;
	std::cout << printBool(*it++ == *it_std++) << std::endl;
	std::cout << printBool(*++it == *++it_std) << std::endl;


	std::cout << "Operator-- :\n";
	std::cout << printBool(*(--it) == (*(--it_std))) << std::endl;
	std::cout << printBool(*(it--) == *(it_std--)) << std::endl;
	std::cout << printBool(*it-- == *it_std--) << std::endl;
	std::cout << printBool(*--it == *--it_std) << std::endl;

	std::cout << "Operator* :\n";
	std::cout << printBool((*it).first.capacity() == (*it_std).first.capacity()) << std::endl;
	std::cout << printBool((*ite).first.capacity() == (*ite_std).first.capacity()) << std::endl;

	std::cout << "Operator-> :\n";
	std::cout << printBool(it->first.capacity() == it_std->first.capacity()) << std::endl;
	std::cout << printBool(ite->first.capacity() == ite_std->first.capacity()) << std::endl;


	ft::map<std::string, bool>::iterator it_(ft2.begin());
	ft::map<std::string, bool>::const_iterator ite_(ft2.begin());

	std::map<std::string, bool>::iterator it__std(std2.begin());
	std::map<std::string, bool>::const_iterator ite__std(std2.begin());

	std::cout << "\nSecond test is about using operator++ and -- on iterator and const_iterator\n";
	std::cout << "\nIterator :\n";
	std::cout << "Operator++ :\n";
	std::cout << printBool(*(++it_) == (*(++it__std))) << std::endl;
	std::cout << printBool(*(it_++) == *(it__std++)) << std::endl;
	std::cout << printBool(*it_++ == *it__std++) << std::endl;
	std::cout << printBool(*++it_ == *++it__std) << std::endl;


	std::cout << "Operator-- :\n";
	std::cout << printBool(*(--it_) == (*(--it__std))) << std::endl;
	std::cout << printBool(*(it_--) == *(it__std--)) << std::endl;
	std::cout << printBool(*it_-- == *it__std--) << std::endl;
	std::cout << printBool(*--it_ == *--it__std) << std::endl;

	std::cout << "\nConst_iterator :\n";
	std::cout << "Operator++ :\n";
	std::cout << printBool(*(++ite_) == (*(++ite__std))) << std::endl;
	std::cout << printBool(*(ite_++) == *(ite__std++)) << std::endl;
	std::cout << printBool(*ite_++ == *ite__std++) << std::endl;
	std::cout << printBool(*++ite_ == *++ite__std) << std::endl;


	std::cout << "Operator-- :\n";
	std::cout << printBool(*(--ite_) == (*(--ite__std))) << std::endl;
	std::cout << printBool(*(ite_--) == *(ite__std--)) << std::endl;
	std::cout << printBool(*ite_-- == *ite__std--) << std::endl;
	std::cout << printBool(*--ite_ == *--ite__std) << std::endl;
	
	it_ = ft2.begin();
	ft::map<std::string, bool>::reverse_iterator rev_it_ft(it_);

	it__std = std2.begin();
	std::map<std::string, bool>::reverse_iterator rev_it_std(it__std);
	
	std::cout << "\nThird Test is about using reverse_iterator and verifying that base() and operators work :\n";
	std::cout << "\nVerify that rev_it.base() is the iterator we created it with : " << printBool((it_ == rev_it_ft.base()) == (it__std == rev_it_std.base())) << std::endl;
	std::cout << "Even if we move through the reverse iterator : " << printBool((it_ == (rev_it_ft--).base()) == (it__std == (rev_it_std--).base())) << std::endl;

	std::cout << "Verify that the values are equal : " << printBool((rev_it_ft).base()->first == (rev_it_std).base()->first) << std::endl;
	std::cout << "Same but moving through iterator : " << printBool(*(rev_it_ft------).base() == *(rev_it_std------).base()) << std::endl;
	std::cout << "Same but moving through base iterator and calling it  : " << printBool(*(rev_it_ft.base()++) == *(rev_it_std.base()++)) << std::endl;
	rev_it_ft------;
	rev_it_std------;
	std::cout << "Verify that base gets iterated through (-= 3 on rev iterator does += 3 on base iterator) : " << printBool(*rev_it_ft.base() == *rev_it_std.base()) << std::endl;
	std::cout << std::endl;
}

static void timing(void)
{
	printTitle("Timing");

	ft::map<int, bool> ft1;
	std::map<int, bool> std1;

	clock_t t;
	clock_t dt;

	// TESTING TIMING FOR 1M ELEMENTS INSERT AND BALANCE
	printf("Insert w/ balance 100k elements\n");
	printf("Worst Case : Each element added is greater than the previous one\n");
	t = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		std1[i * 10] = true;
	}
	t = clock() - t;
	printf("\nstd: this took |%10ld| ticks\n", t);
	
	dt = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		ft1[i * 10] = true;
	}
	dt = clock() - dt;
	printf("ft:  this took |%10ld| ticks\n", dt);
	printf("Are the two maps equal ? -> %s\n", printBool(ft1 == std1).c_str());
	printf("ft / std = |%f|\n\n", (float)dt / (float)t);

	// TESTING FOR 1M ELEMENTS
	printf("Find 100k elements\n");
	t = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		std1.find(i * 10);
	}
	t = clock() - t;
	printf("\nstd: this took |%10ld| ticks\n", t);
	
	dt = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		ft1.find(i * 10);
	}
	dt = clock() - dt;
	printf("ft:  this took |%10ld| ticks\n", dt);
	printf("ft / std = |%f|\n", (float)dt / (float)t);
}

void map_tests(void)
{
	printTitle("MAP_TESTER");

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
	iterators();
	timing();
}
