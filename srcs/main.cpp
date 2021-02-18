#include "../incs/tests.hpp"

void	printTitle(std::string title)
{
	int		margin = (40 - title.length()) / 2;
	int		width = (margin * 2) + title.length() + 2;

	std::cout << "\e[34m" << std::string(width, '#') << std::endl;
	std::cout << "#" << std::string(margin, ' ') << "\e[36m" << title << "\e[34m" << std::string(margin, ' ') << "#" << std::endl;
	std::cout << std::string(width, '#') << "\e[39m" << std::endl << std::endl;
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
