#include "../incs/tests.hpp"

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.capacity() != b.capacity())
		return (false);
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
}

static void constructors(void)
{
	printTitle("Constructors");
	
	ft::vector<int> v1;
	std::vector<int> v2;
	
	std::cout << "default : " << printBool((v1 == v2)) << std::endl;
	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	
	ft::vector<int> v3(v1);
	std::vector<int> v4(v2);
	
	std::cout << "copy : " << printBool((v3 == v4)) << std::endl;

	ft::vector<int> v5((size_t)3, 8);
	std::vector<int> v6((size_t)3, 8);
	
	std::cout << "fill : " << printBool((v5 == v6)) << std::endl;


	int a[] = {1, 2, 3, 4};

	ft::vector<int> v11(a, a + 3);
	std::vector<int> v12(a, a + 3);
	
	std::cout << "range : " << printBool((v11 == v12)) << std::endl;


	ft::vector<int> v9;
	std::vector<int> v10;

	v9 = v1;
	v10 = v2;
	std::cout << "operator= : " << printBool((v9 == v10)) << std::endl;
	std::cout << std::endl;
}

static void max_size(void)
{
	printTitle("Max_size");
	
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	
	ft::vector<int> v3;
	std::vector<int> v4;
	
	std::cout << "string without anything : " << printBool((v1.max_size() == v2.max_size())) << std::endl;
	std::cout << "int without anything : " << printBool((v3.max_size() == v4.max_size())) << std::endl;
	
	v1.push_back("test");
	v3.push_back(123);
	v2.push_back("test");
	v4.push_back(123);
	
	std::cout << "string : " << printBool((v1.max_size() == v2.max_size())) << std::endl;
	std::cout << "int : " << printBool((v3.max_size() == v4.max_size())) << std::endl;
	std::cout << std::endl;
}

static void resize(void)
{
	printTitle("Resize");
	
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	
	v1.resize(10, "test");
	v2.resize(10, "test");

	std::cout << "resize from empty vector : " << printBool((v1 == v2)) << std::endl;

	v1.resize(2, "42");
	v2.resize(2, "42");
	
	std::cout << "resize from already existing vector : " << printBool((v1 == v2)) << std::endl;
	std::cout << std::endl;
}

static void access_operator(void)
{
	printTitle("operator[] and at");
	
	ft::vector<int> v1;
	std::vector<int> v2;
	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	
	std::cout << "v1[0] == v2[0] : " << printBool((v1[0] == v2[0])) << std::endl;
	std::cout << "v1[1] == v2[1] : " << printBool((v1[1] == v2[1])) << std::endl;
	std::cout << "v1[2] == v2[2] : " << printBool((v1[2] == v2[2])) << std::endl;
	
	try
	{
		std::cout << "v1.at(100): " << v1.at(100) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(7, ' ') << std::endl;
	}
	
	try
	{
		std::cout << "v2.at(100): " << v2.at(100) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(20, ' ') << std::endl;
	}
	
	try
	{
		std::cout << "v1.at(-1): " << v1.at(-1) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(8, ' ') << std::endl;
	}
	
	try
	{
		std::cout << "v2.at(-1): " << v2.at(-1) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(21, ' ') << std::endl;
	}
	std::cout << std::endl;
}

static void front_back(void)
{
	printTitle("Front and Back");
	
	ft::vector<int> v1;
	std::vector<int> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	std::cout << "push_back 1 2 and 3 in both vectors:" << std::endl;
	std::cout << "v1.front() == v2.front() : " << printBool((v1.front() == v2.front())) << std::endl;
	std::cout << "v1.back() == v2.back() : " << printBool((v1.front() == v2.front())) << std::endl;
	std::cout << std::endl;
}

static void assign(void)
{
	printTitle("Assign");
	
	std::string test[] = {"Hey", "what's", "up", "?"};
	
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	
	std::cout << "range : " << printBool((v1 == v2)) << std::endl;
	
	v1.assign(10, "?");
	v2.assign(10, "?");
	
	std::cout << "fill : " << printBool((v1 == v2)) << std::endl;
	std::cout << std::endl;
}

static void insert(void)
{
	printTitle("Insert");
	
	int test[] = {1, 2, 3};
	
	ft::vector<int> v1;
	std::vector<int> v2;
	
	v1.insert(v1.begin(), 42);
	v1.insert(v1.end(), 21);
	v1.insert(v1.begin(), 10);
	v1.insert(v1.begin() + 1, 11);
	v1.insert(v1.begin() + 2, (size_t)3, 0);
	v1.insert(v1.begin() + 1, test, test + 3);
	
	v2.insert(v2.begin(), 42);
	v2.insert(v2.end(), 21);
	v2.insert(v2.begin(), 10);
	v2.insert(v2.begin() + 1, 11);
	v2.insert(v2.begin() + 2, (size_t)3, 0);
	v2.insert(v2.begin() + 1, test, test + 3);
	
	std::cout << "all insert : " << printBool((v1 == v2)) << std::endl;
	std::cout << std::endl;
}

static void erase(void)
{
	printTitle("Erase and Clear");
	
	std::string test[] = {"Hey", "what's", "up", "?"};
	
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	std::cout << "v1.erase(v1.begin() + 2);\n";
	v1.erase(v1.begin() + 2);
	std::cout << "v2.erase(v2.begin() + 2);\n";
	v2.erase(v2.begin() + 2);
	
	std::cout << "erase : " << printBool((v1 == v2)) << std::endl;
	
	v1.clear();
	v2.clear();
	
	std::cout << "clear : " << printBool((v1 == v2)) << std::endl;
	std::cout << std::endl;
}

static void swap(void)
{
	printTitle("Swap");
	
	ft::vector<int> v1;
	std::vector<int> v2;
	
	ft::vector<int> v3;
	std::vector<int> v4;
	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3.push_back(42);
	v3.push_back(43);
	v4.push_back(42);
	v4.push_back(43);
	v1.swap(v3);
	v2.swap(v4);
	
	std::cout << "v1 == v2 : " << printBool((v1 == v2)) << std::endl;
	std::cout << "v3 == v4 : " << printBool((v3 == v4)) << std::endl;
	std::cout << std::endl;
}

static void operators(void)
{
	printTitle("Operators");
	
	ft::vector<int> v1;
	std::vector<int> v2;
	
	ft::vector<int> v3;
	std::vector<int> v4;
	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(50);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(50);
	
	v3 = v1;
	v4 = v2;

	std::cout << "v1 == v2 : " << printBool(((v1 == v3) == (v2 == v4))) << std::endl;
	std::cout << "v1 != v2 : " << printBool(((v1 != v3) == (v2 != v4))) << std::endl;
	std::cout << "v1 >= v2 : " << printBool(((v1 >= v3) == (v2 >= v4))) << std::endl;
	std::cout << "v1 > v2  : " << printBool(((v1 > v3) == (v2 > v4))) << std::endl;
	std::cout << "v1 <= v2 : " << printBool(((v1 <= v3) == (v2 <= v4))) << std::endl;
	std::cout << "v1 < v2  : " << printBool(((v1 < v3) == (v2 < v4))) << std::endl;
	std::cout << std::endl;

	v1.push_back(42);
	v2.push_back(42);

	std::cout << "v1 == v2 : " << printBool(((v1 == v3) == (v2 == v4))) << std::endl;
	std::cout << "v1 != v2 : " << printBool(((v1 != v3) == (v2 != v4))) << std::endl;
	std::cout << "v1 >= v2 : " << printBool(((v1 >= v3) == (v2 >= v4))) << std::endl;
	std::cout << "v1 > v2  : " << printBool(((v1 > v3) == (v2 > v4))) << std::endl;
	std::cout << "v1 <= v2 : " << printBool(((v1 <= v3) == (v2 <= v4))) << std::endl;
	std::cout << "v1 < v2  : " << printBool(((v1 < v3) == (v2 < v4))) << std::endl;
	std::cout << std::endl;

	v3.push_back(41);
	v4.push_back(41);

	std::cout << "v1 == v2 : " << printBool(((v1 == v3) == (v2 == v4))) << std::endl;
	std::cout << "v1 != v2 : " << printBool(((v1 != v3) == (v2 != v4))) << std::endl;
	std::cout << "v1 >= v2 : " << printBool(((v1 >= v3) == (v2 >= v4))) << std::endl;
	std::cout << "v1 > v2  : " << printBool(((v1 > v3) == (v2 > v4))) << std::endl;
	std::cout << "v1 <= v2 : " << printBool(((v1 <= v3) == (v2 <= v4))) << std::endl;
	std::cout << "v1 < v2  : " << printBool(((v1 < v3) == (v2 < v4))) << std::endl << std::endl;
}

void	iterators(void)
{
	printTitle("Iterators");


	ft::vector<std::string> ft2(5);
	std::vector<std::string> std2(5);

	ft::vector<std::string>::reverse_iterator it2_ft(ft2.rbegin());
	ft::vector<std::string>::const_reverse_iterator it_const2_ft(ft2.rend());

	std::vector<std::string>::reverse_iterator it2_std(std2.rbegin());
	std::vector<std::string>::const_reverse_iterator it_const2_std(std2.rend());

	for (int i = 1; it2_ft != it_const2_ft; ++i)
	{
		*it2_ft++ = (i * 7);
		*it2_std++ = (i * 7);
	}

	it2_ft = ft2.rbegin();
	it_const2_ft = ft2.rbegin();


	it2_std = std2.rbegin();
	it_const2_std = std2.rbegin();
	
	std::cout << "First Test is about verifying the use of operators *, -> and [] on reverse_iterator\n";
	std::cout << "Operator* :\n";
	std::cout << printBool((*it2_ft).capacity() == (*it2_std).capacity()) << std::endl;
	std::cout << printBool((*it_const2_ft).capacity() == (*it_const2_std).capacity()) << std::endl;

	std::cout << "Operator-> :\n";
	std::cout << printBool(it2_ft->capacity() == it2_std->capacity()) << std::endl;
	std::cout << printBool(it_const2_ft->capacity() == it_const2_std->capacity()) << std::endl;

	std::cout << "Operator[] :\n";
	std::cout << printBool(it2_ft[2] == it2_std[2]) << std::endl;
	std::cout << printBool(it_const2_ft[2] == it_const2_std[2]) << std::endl;

	std::cout << "\nSecond test is about using operator++ and -- on iterator and const_iterator\n";
	std::cout << "\nIterator :\n";
	std::cout << printBool(*(++it2_ft) == (*(++it2_std))) << std::endl;
	std::cout << printBool(*(it2_ft++) == *(it2_std++)) << std::endl;
	std::cout << printBool(*it2_ft++ == *it2_std++) << std::endl;
	std::cout << printBool(*++it2_ft == *++it2_std) << std::endl;

	std::cout << printBool(*(--it2_ft) == (*(--it2_std))) << std::endl;
	std::cout << printBool(*(it2_ft--) == *(it2_std--)) << std::endl;
	std::cout << printBool(*it2_ft-- == *it2_std--) << std::endl;
	std::cout << printBool(*--it2_ft == *--it2_std) << std::endl;

	std::cout << "\nConst_iterator :\n";
	std::cout << printBool(*(++it_const2_ft) == (*(++it_const2_std))) << std::endl;
	std::cout << printBool(*(it_const2_ft++) == *(it_const2_std++)) << std::endl;
	std::cout << printBool(*it_const2_ft++ == *it_const2_std++) << std::endl;
	std::cout << printBool(*++it_const2_ft == *++it_const2_std) << std::endl;

	std::cout << printBool(*(--it_const2_ft) == (*(--it_const2_std))) << std::endl;
	std::cout << printBool(*(it_const2_ft--) == *(it_const2_std--)) << std::endl;
	std::cout << printBool(*it_const2_ft-- == *it_const2_std--) << std::endl;
	std::cout << printBool(*--it_const2_ft == *--it_const2_std) << std::endl;
	
	ft::vector<int> ft1(5);
	ft::vector<int>::iterator it_ft = ft1.begin();
	ft::vector<int>::reverse_iterator rev_it_ft(it_ft);


	std::vector<int> std1(5);
	std::vector<int>::iterator it_std = std1.begin();
	std::vector<int>::reverse_iterator rev_it_std(it_std);


	for (int i = 0; i < 5; ++i)
	{
		ft1[i] = 14 * i;
		std1[i] = ft1[i];
	}


	std::cout << "\nThird Test is about using reverse_iterator and verifying that base() and operators work :\n";
	std::cout << "\nVerify that rev_it.base() is the iterator we created it with : " << printBool((it_ft == rev_it_ft.base()) == (it_std == rev_it_std.base())) << std::endl;
	std::cout << "Even if we move through the reverse iterator : " << printBool((it_ft == (rev_it_ft + 3).base()) == (it_std == (rev_it_std + 3).base())) << std::endl;

	std::cout << "Verify that the values are equal : " << printBool(*(rev_it_ft) == *(rev_it_std)) << std::endl;
	std::cout << "Same but moving through iterator : " << printBool(*(rev_it_ft - 3).base() == *(rev_it_std - 3).base()) << std::endl;
	std::cout << "Same but moving through base iterator and calling it  : " << printBool(*(rev_it_ft.base() + 1) == *(rev_it_std.base() + 1)) << std::endl;
	rev_it_ft -= 3;
	rev_it_std -= 3;
	std::cout << "Verify that base gets iterated through (-= 3 on rev iterator does += 3 on base iterator) : " << printBool(*rev_it_ft.base() == *rev_it_std.base()) << std::endl;
}

static void timing(void)
{
	printTitle("Timing");

	ft::vector<int> ft1;
	std::vector<int> std1;

	clock_t t;
	clock_t dt;

	// TESTING TIMING FOR 1M ELEMENTS INSERT
	printf("Push_back 1M elements\n");
	t = clock();
	for (size_t i = 0; i < 1000000; i++)
	{
		std1.push_back(i * 10);
	}
	t = clock() - t;
	printf("\nstd: this took |%10ld| ticks\n", t);
	
	dt = clock();
	for (size_t i = 0; i < 1000000; i++)
	{
		ft1.push_back(i * 10);
	}
	dt = clock() - dt;
	printf("ft:  this took |%10ld| ticks\n", dt);
	printf("Are the two vectors equal ? -> %s\n", printBool(ft1 == std1).c_str());
	printf("ft / std = |%f|\n", (float)dt / (float)t);
}
void	vector_tests(void)
{
	printTitle("VECTOR_TESTER");

	constructors();
	max_size();
	resize();
	access_operator();
	front_back();
	assign();
	insert();
	erase();
	swap();
	operators();
	iterators();
	timing();

	std::cout << std::endl;
}
