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

	ft::vector<int> v5((size_t)3, 8);
	std::vector<int> v6((size_t)3, 8);
	
	std::cout << "fill : " << printBool((v5 == v6)) << std::endl;

	int a[] = {1, 2, 3, 4};

	ft::vector<int> v11(a, a + 3);
	std::vector<int> v12(a, a + 3);
	
	std::cout << "range : " << printBool((v11 == v12)) << std::endl;
	
	ft::vector<int> v3(v1);
	std::vector<int> v4(v2);
	
	std::cout << "copy : " << printBool((v3 == v4)) << std::endl;

	ft::vector<int> v9 = v1;
	std::vector<int> v10 = v2;

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

	std::cout << "test1 : " << printBool((v1 == v2)) << std::endl;

	v1.resize(2, "42");
	v2.resize(2, "42");
	
	std::cout << "test2 : " << printBool((v1 == v2)) << std::endl;
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
	std::cout << "v1.assign(10, ?);\n";
	v1.assign(10, "?");
	std::cout << "v2.assign(10, ?);\n";
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
	
	std::cout << "all : " << printBool((v1 == v2)) << std::endl;
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
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	
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

	v3.push_back(43);
	v4.push_back(43);

	std::cout << "v1 == v2 : " << printBool(((v1 == v3) == (v2 == v4))) << std::endl;
	std::cout << "v1 != v2 : " << printBool(((v1 != v3) == (v2 != v4))) << std::endl;
	std::cout << "v1 >= v2 : " << printBool(((v1 >= v3) == (v2 >= v4))) << std::endl;
	std::cout << "v1 > v2  : " << printBool(((v1 > v3) == (v2 > v4))) << std::endl;
	std::cout << "v1 <= v2 : " << printBool(((v1 <= v3) == (v2 <= v4))) << std::endl;
	std::cout << "v1 < v2  : " << printBool(((v1 < v3) == (v2 < v4))) << std::endl;
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
}
