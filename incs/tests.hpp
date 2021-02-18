#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>
# include <string>

# include <string>

# include <list>
# include <vector>
# include <map>
# include <stack>
# include <queue>

# include <stdlib.h>
# include <time.h>

# include "list.hpp"
# include "vector.hpp"
# include "map.hpp"
# include "stack.hpp"
# include "queue.hpp"

void    printTitle(std::string title);
void    printBoolColors(std::string str, int _bool);

void	list_tests(void);
void	vector_tests(void);
void	map_tests(void);
void	stack_tests(void);
void	queue_tests(void);

#endif