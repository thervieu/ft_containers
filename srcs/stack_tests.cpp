#include "../incs/tests.hpp"

static void constructors(void)
{
	printTitle("Constructor");

	ft::stack<int> ft1;
	std::stack<int> std1;
	
	std::cout << "ft1.size() == std1.size() : " << printBool((ft1.size() == std1.size())) << std::endl;
	std::cout << "ft1.empty() == std1.empty() : " << printBool((ft1.empty() == std1.empty())) << std::endl;
	std::cout << std::endl;
}

static void top(void)
{
	printTitle("Top");

	ft::stack<int> ft1;
	ft::stack<int> ft2;

	std::stack<int> std1;
	std::stack<int> std2;

	ft1.push(0);
	ft1.push(1);
	ft1.push(2);
	ft2.push(0);
	ft2.push(1);
	ft2.push(2);

	std1.push(0);
	std1.push(1);
	std1.push(2);
	std2.push(0);
	std2.push(1);
	std2.push(2);

	std::cout << "ft1.size() == std1.size() : " << printBool((ft1.size() == std1.size())) << std::endl;
	std::cout << "ft1.empty() == std1.empty() : " << printBool((ft1.empty() == std1.empty())) << std::endl;
	std::cout << "ft1.top() == std1.top() : " << printBool((ft1.top() == std1.top())) << std::endl;
	std::cout << std::endl;

	ft1.pop();
	std1.pop();
	
	std::cout << "ft1.size() == std1.size() : " << printBool((ft1.size() == std1.size())) << std::endl;
	std::cout << "ft1.top() == std1.top() : " << printBool((ft1.top() == std1.top())) << std::endl;
}

void	stack_tests(void)
{
	printTitle("STACK");
	constructors();
	top();
}
