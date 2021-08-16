#include "../incs/tests.hpp"

void	printTitle(std::string title)
{
	std::cout << "\e[34m#" << std::string((34 - title.length()) / 2, ' ') << "\e[36m" << title << "\e[34m" << std::string((34 - title.length()) / 2, ' ') << "#\e[39m" << std::endl << std::endl;
}

std::string	printBool(bool val)
{
	if (val)
		return (GREEN + std::string("✔") + RESET);
	else
		return (RED + std::string("✗") + RESET);
}


template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};


#define MAX_RAM 200000000

#define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

static void school(void)
{
	const int seed = 11111111;
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::map<int, int> map_int;
	std::cout << "COUNT = |" << COUNT << "|\n";
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
}

int		main(int ac, char **av)
{
	std::srand(time(0));
	if (ac == 2)
	{
		std::string name(av[1]);

		if (name == "vector")
			vector_tests();
		else if (name == "map")
			map_tests();
		else if (name == "stack")
			stack_tests();
		else if (name == "school")
			school();
	}
	else if (ac == 1)
	{
		vector_tests();
		map_tests();
		stack_tests();
	}
	else
		std::cout << "format: exec_tester ([container_name])" << std::endl;
}
