#include "../incs/tests.hpp"

static void constructors(void)
{
	std::cout << "Constructor" << std::endl;
	
	ft::queue<int> ft1;
	std::queue<int> std1;
	
	std::cout << "ft1.size() == std1.size() : " << (ft1.size() == std1.size()) << std::endl;
	std::cout << "ft1.empty() == std1.empty() : " << (ft1.empty() == std1.empty()) << std::endl;
	std::cout << std::endl;
}

static void front_back_comp(void)
{
	std::cout << "Front / Back / Push / Pop" << std::endl;
	
	ft::queue<int> ft1;
	ft::queue<int> ft2;
	std::queue<int> std1;
	std::queue<int> std2;
	
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
	
	std::cout << "ft1.size() == std1.size() : " << (ft1.size() == std1.size()) << std::endl;
	std::cout << "ft1.empty() == std1.empty() : " << (ft1.empty() == std1.empty()) << std::endl;
	std::cout << "ft1.front() == std1.front() : " << (ft1.front() == std1.front()) << std::endl;
	std::cout << "ft1.back() == std1.back() : " << (ft1.back() == std1.back()) << std::endl;
	std::cout << std::endl;
	
	ft1.pop();
	std1.pop();
	
	std::cout << "ft1.size() == std1.size() : " << (ft1.size() == std1.size()) << std::endl;
	std::cout << "ft1.front() == std1.front() : " << (ft1.front() == std1.front()) << std::endl;
	std::cout << "ft1.back() == std1.back() : " << (ft1.back() == std1.back()) << std::endl;
}

void	queue_tests(void)
{
	std::cout << "Queue" << std::endl;
	std::cout << std::endl;
	constructors();
	front_back_comp();
}
