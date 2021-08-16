#include "../incs/tests.hpp"

static void constructors(void)
{
	printTitle("Constructor");

	ft::stack<int> ft1;
	std::stack<int> std1;
	
	printf("Default\n");
	std::cout << "ft1.size() == std1.size() : " << printBool((ft1.size() == std1.size())) << std::endl;
	std::cout << "ft1.empty() == std1.empty() : " << printBool((ft1.empty() == std1.empty())) << std::endl;
	std::cout << std::endl;
}

static void top(void)
{
	printTitle("Top");

	ft::stack<int> ft1;

	std::stack<int> std1;

	ft1.push(0);
	ft1.push(1);
	ft1.push(2);

	std1.push(0);
	std1.push(1);
	std1.push(2);

	printf("Pushed 3 numbers (0, 1, 2) in both\n");
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
	std::cout << std::endl;
}
