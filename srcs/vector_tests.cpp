#include "../incs/tests.hpp"

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
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

static void default_constructor(void)
{
	printTitle("Default constructor");
	
	ft::vector<int> v1;
	std::vector<int> v2;
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
	
	ft::vector<int> v3;
	ft::vector<std::string> v4;
	
	std::string str = "test";
	v4.push_back(str);

	std::cout << std::endl;
}

static void copy_constructor(void)
{
	printTitle("Copy constructor");
	
	ft::vector<int> v1;
	std::vector<int> v2;
	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	
	ft::vector<int> v3(v1);
	std::vector<int> v4(v2);
	
	v1.push_back(42);
	v2.push_back(42);
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
	std::cout << "v3 == v4 : " << (v3 == v4) << std::endl;
	std::cout << "v1 != v3 : " << (v1 != v3) << std::endl;
	std::cout << "v2 != v4 : " << (v2 != v4) << std::endl;
	std::cout << std::endl;
}

static void max_size(void)
{
	printTitle("Max_size");
	
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	
	ft::vector<int> v3;
	std::vector<int> v4;
	
	std::cout << "string without anything : " << (v1.max_size() == v2.max_size()) << std::endl;
	std::cout << "int without anything : " << (v3.max_size() == v4.max_size()) << std::endl;
	
	v1.push_back("test");
	v3.push_back(123);
	v2.push_back("test");
	v4.push_back(123);
	
	std::cout << "string without anything : " << (v1.max_size() == v2.max_size()) << std::endl;
	std::cout << "int without anything : " << (v3.max_size() == v4.max_size()) << std::endl;
	std::cout << std::endl;
}

static void resize(void)
{
	printTitle("Resize");
	
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	
	v1.resize(10, "test");
	v2.resize(10, "test");

	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
	
	v1.resize(2, "42");
	v2.resize(2, "42");
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
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
	
	std::cout << "v1[0] == v2[0] : " << (v1[0] == v2[0]) << std::endl;
	std::cout << "v1[1] == v2[1] : " << (v1[1] == v2[1]) << std::endl;
	std::cout << "v1[2] == v2[2] : " << (v1[2] == v2[2]) << std::endl;
	
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
	
	std::cout << "v1.front() == v2.front() : " << (v1.front() == v2.front()) << std::endl;
	std::cout << "v1.back() == v2.back() : " << (v1.front() == v2.front()) << std::endl;
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
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
	
	v1.assign(10, "?");
	v2.assign(10, "?");
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
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
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
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
	v1.erase(v1.begin() + 2);
	v2.erase(v2.begin() + 2);
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
	
	v1.clear();
	v2.clear();
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
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
	
	std::cout << "v1 == v2 : " << (v1 == v2) << std::endl;
	std::cout << "v3 == v4 : " << (v3 == v4) << std::endl;
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
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	
	v3 = v1;
	v4 = v2;
	
	std::cout << "v1 == v2 : " << (v1 == v3) << " " << (v2 == v4) << std::endl;
	std::cout << "v1 != v2 : " << (v1 != v3) << " " << (v2 != v4) << std::endl;
	std::cout << "v1 > v2 : " << (v1 > v3) << " " << (v2 > v4) << std::endl;
	std::cout << "v1 < v2 : " << (v1 < v3) << " " << (v2 < v4) << std::endl;
	std::cout << "v1 >= v2 : " << (v1 >= v3) << " " << (v2 >= v4) << std::endl;
	std::cout << "v1 <= v2 : " << (v1 <= v3) << " " << (v2 <= v4) << std::endl;
	std::cout << std::endl;

	v1.push_back(42);
	v2.push_back(42);
	
	std::cout << "v1 == v2 : " << (v1 == v3) << " " << (v2 == v4) << std::endl;
	std::cout << "v1 != v2 : " << (v1 != v3) << " " << (v2 != v4) << std::endl;
	std::cout << "v1 > v2 : " << (v1 > v3) << " " << (v2 > v4) << std::endl;
	std::cout << "v1 < v2 : " << (v1 < v3) << " " << (v2 < v4) << std::endl;
	std::cout << "v1 >= v2 : " << (v1 >= v3) << " " << (v2 >= v4) << std::endl;
	std::cout << "v1 <= v2 : " << (v1 <= v3) << " " << (v2 <= v4) << std::endl;
	std::cout << std::endl;

	v3.push_back(43);
	v4.push_back(43);

	std::cout << "v1 == v2 : " << (v1 == v3) << " " << (v2 == v4) << std::endl;
	std::cout << "v1 != v2 : " << (v1 != v3) << " " << (v2 != v4) << std::endl;
	std::cout << "v1 > v2 : " << (v1 > v3) << " " << (v2 > v4) << std::endl;
	std::cout << "v1 < v2 : " << (v1 < v3) << " " << (v2 < v4) << std::endl;
	std::cout << "v1 >= v2 : " << (v1 >= v3) << " " << (v2 >= v4) << std::endl;
	std::cout << "v1 <= v2 : " << (v1 <= v3) << " " << (v2 <= v4) << std::endl;
}

void	vector_tests(void)
{
	printTitle("VECTOR_TESTER");
	default_constructor();
	copy_constructor();
	max_size();
	resize();
	access_operator();
	front_back();
	assign();
	insert();
	erase();
	swap();
	operators();
}