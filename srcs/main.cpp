#include "../incs/tests.hpp"

void	printTitle(std::string title)
{
	std::cout << "\e[34m#" << std::string((36 - title.length()) / 2, ' ') << "\e[36m" << title << "\e[34m" << std::string((36 - title.length()) / 2, ' ') << "#\e[39m" << std::endl << std::endl;
}

std::string	printBool(bool val)
{
	if (val)
		return (GREEN + std::string("✔") + RESET);
	else
		return (RED + std::string("✗") + RESET);
}


int		main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string name(av[1]);

		if (name == "list")
			list_tests();
		else if (name == "vector")
			vector_tests();
		else if (name == "map")
			map_tests();
		else if (name == "stack")
			stack_tests();
		else if (name == "queue")
			queue_tests();
	}
	else if (ac == 1)
	{
		list_tests();
		vector_tests();
		map_tests();
		stack_tests();
		queue_tests();
	}
	else
		std::cout << "format: exec_tester ([container_name])" << std::endl;
}
