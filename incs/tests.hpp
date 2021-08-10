#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>

# include <string>
# include <vector>
# include <map>
# include <stack>

# include <stdlib.h>
# include <ctime>
# include <stdio.h>

# include "vector.hpp"
# include "map.hpp"
# include "stack.hpp"

# define GREEN "\e[92m"
# define RED "\e[91m"
# define RESET "\e[0m"

std::string	printBool(bool val);
void		printTitle(std::string title);
void		printBoolColors(std::string str, int _bool);

void	vector_tests(void);
void	map_tests(void);
void	stack_tests(void);

#endif
