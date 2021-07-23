/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:06:20 by user42            #+#    #+#             */
/*   Updated: 2021/07/12 23:08:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/tests.hpp"
#include <list>

template <typename T>
bool	operator==(std::list<T> &l1, ft::list<T> &l2)
{
	if (l1.size() != l2.size())
		return (false);
	if (l1.empty() != l2.empty())
		return (false);
	typename std::list<T>::iterator it1 = l1.begin();
	typename ft::list<T>::iterator it2 = l2.begin();
	while (it1 != l1.end())
	{
		if (*it1 != *it2)
			return (false);
		it1++;
		it2++;
	}
	return (true);
}

static void	constructors_and_copy(void)
{
	printTitle("Constructors");
	
	std::list<int> l1;
	ft::list<int> l2;
	
	std::cout << "default : "  << printBool((l1 == l2)) << std::endl;
	
	std::list<int> l3((size_t)6);
	ft::list<int> l4((size_t)6);
	std::cout << "fill with 0 : " << printBool((l3 == l4)) << std::endl;
	
	std::list<int> l5((size_t)5, 123);
	ft::list<int> l6((size_t)5, 123);
	std::cout << "fill with specified int :  " << printBool((l5 == l6)) << std::endl;

	int array[] = {1, 2, 3, 4, 5};
	std::list<int> l7(array, array + 4);
	ft::list<int> l8(array, array + 4);
	std::cout << "fill with range : " << printBool((l7 == l8)) << std::endl;

	std::list<int> l9(l5);
	ft::list<int> l10(l6);
	std::cout << "copy: " << printBool((l9 == l10)) << std::endl;

	std::list<int> l11 = l5;
	ft::list<int> l12 = l6;
	std::cout << "operator= :" << printBool((l11 == l12)) << std::endl << std::endl;
}

static void	max_size(void)
{
	printTitle("Max_size");
	
	std::list<int> l1;
	ft::list<int> l2;

	std::list<std::string> l3;
	ft::list<std::string> l4;
	std::cout << "int size : " << printBool((l1.max_size() == l2.max_size())) << std::endl;
	std::cout << "string size : " << printBool((l3.max_size() == l4.max_size())) << std::endl << std::endl;
}

static void	front_back(void)
{
	printTitle("Front and Back");
	
	std::list<int> l1;
	ft::list<int> l2;

	std::cout << "l1.front() == l1.back() at init : " << printBool((l1.front() == l1.back())) << std::endl;
	std::cout << "l1.front() == l2.back() at init : " << printBool((l1.front() == l2.back())) << std::endl;
	std::cout << "l2.front() == l2.back() at init : " << printBool((l2.front() == l2.back())) << std::endl << std::endl;
	
	l1.push_back(0);
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	l2.push_back(0);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);

	std::cout << "push_back(0, 1, 2, 3, 4) on l1, l2\n";
	std::cout << "l1.front() == l2.front() : " << printBool((l1.front() == l2.front())) << std::endl;
	std::cout << "l1.back() == l2.back() : " << printBool((l1.back() == l2.back())) << std::endl << std::endl;

	l1.pop_back();
	l2.pop_back();
	l1.pop_front();
	l2.pop_front();

	std::cout << "pop front and back on l1, l2\n";
	std::cout << "l1.front() : " << (l1.front()) << std::endl;
	std::cout << "l2.front() : " << (l2.front()) << std::endl;
	std::cout << "l1.back() : " << (l1.back()) << std::endl;
	std::cout << "l2.back() : " << (l2.back()) << std::endl;
	std::cout << "l1.front() == l2.front() : " << printBool((l1.front() == l2.front())) << std::endl;
	std::cout << "l1.back() == l2.back() : " << printBool((l1.back() == l2.back())) << std::endl << std::endl;
}

static void	assign(void)
{
	printTitle("Assign");
	
	std::list<int> l1;
	ft::list<int> l2;
	
	l1.assign((size_t)6, 13);
	l2.assign((size_t)6, 13);

	std::cout << "fill : " << printBool((l1 == l2))  << std::endl;
	int assign[] = {0, 1, 2, 3, 4, 6, 7, 8};

	l1.assign(assign, assign + 6);
	l2.assign(assign, assign + 6);
	
	std::cout << "range :  " << printBool((l1 == l2)) << std::endl << std::endl;
}

static void	push_pop(void)
{
	printTitle("Push and Pop");
	
	std::list<int> l1;
	ft::list<int> l2;

	for (int i = 0; i < 300; i++)
	{
		int n = rand() % 300;
		if (i % 2 == 0)
		{
			l1.push_back(n);
			l2.push_back(n);
		}
		else
		{
			l1.push_front(n);
			l2.push_front(n);
		}
	}

	std::cout << "push_front and back 300 nb : " << printBool((l1 == l2)) << std::endl << std::endl;

	for (int j = 0; j < 300; j++)
	{
		if (j % 2 == 0)
		{
			l1.pop_back();
			l2.pop_back();
		}
		else
		{
			l1.pop_front();
			l2.pop_front();
		}
	}
	std::cout << "pop_front and back 150 fois chacun : " << printBool((l1 == l2)) << std::endl << std::endl;
}

static void	erase(void)
{
	printTitle("Erase");
	
	std::list<int> std1;
	ft::list<int> ft1;

	for (int i = 0; i < 18; i++)
	{
		if (i % 2)
		{
			std1.push_back(i);
			ft1.push_back(i);
		}
		else
		{
			std1.push_front(i);
			ft1.push_front(i);
		}
	}

	std1.erase(std1.begin());
	ft1.erase(ft1.begin());

	std1.erase(--std1.end());
	ft1.erase(--ft1.end());

	std1.erase(++std1.begin());
	ft1.erase(++ft1.begin());
	
	std1.erase(++++std1.begin(), --std1.end());
	ft1.erase(++++ft1.begin(), --ft1.end());

	std::cout << "position and range : " << printBool((std1 == ft1)) << std::endl << std::endl;
}

static void	swap(void)
{
	printTitle("Swap");
	
	std::list<int> std1;
	std::list<int> std2;
	
	ft::list<int> ft1;
	ft::list<int> ft2;

	std1.push_back(0);
	ft1.push_back(0);
	
	std1.push_back(1);
	ft1.push_back(1);
	
	std1.push_back(2);
	ft1.push_back(2);

	std2.push_back(123);
	ft2.push_back(123);

	std2.push_back(321);
	ft2.push_back(321);

	std1.swap(std2);
	ft1.swap(ft2);

	std::cout << "std1 == ft1 : " << printBool((std1 == ft1)) << std::endl;
	std::cout << "std2 == ft2 : " << printBool((std2 == ft2)) << std::endl << std::endl;
}

static void	resize(void)
{
	printTitle("Resize");
	
	std::list<int> std1;
	ft::list<int> ft1;
	
	std1.resize(5, 10);
	ft1.resize(5, 10);
	std::cout << "std1 == ft1 : " << printBool((std1 == ft1)) << std::endl;

	std1.resize(2, 11);
	ft1.resize(2, 11);
	std::cout << "std1 == ft1 : " << printBool((std1 == ft1)) << std::endl;

	std1.resize(0, 0);
	ft1.resize(0, 0);
	std::cout << "std1 == ft1 : " << printBool((std1 == ft1)) << std::endl << std::endl;
}

static void	splice(void)
{
	printTitle("Splice");
	
	std::list<int> std1((size_t)15, 10);
	ft::list<int> ft1((size_t)15, 10);
	std::list<int> std2((size_t)6, 1);
	ft::list<int> ft2((size_t)6, 1);
	
	std1.splice(std1.begin(), std2);
	ft1.splice(ft1.begin(), ft2);

	std::cout << "entire list:" << std::endl;
	std::cout << "std1 == ft1 : " << printBool((std1 == ft1)) << std::endl;
	std::cout << "std2 == ft2 : " << printBool((std2 == ft2)) << std::endl << std::endl;

	std1.assign((size_t)15, 10);
	ft1.assign((size_t)15, 10);
	std2.assign((size_t)6, 1);
	ft2.assign((size_t)6, 1);

	std1.splice(std1.begin(), std2, ++++std2.begin());
	ft1.splice(ft1.begin(), ft2, ++++ft2.begin());

	std::cout << "single element:" << std::endl;
	std::cout << "std1 == ft1 : " << printBool((std1 == ft1)) << std::endl;
	std::cout << "std2 == ft2 : " << printBool((std2 == ft2)) << std::endl << std::endl;

	std1.assign((size_t)15, 10);
	ft1.assign((size_t)15, 10);
	std2.assign((size_t)6, 1);
	ft2.assign((size_t)6, 1);

	std::cout << "element range:" << std::endl;
	std1.splice(std1.begin(), std2, ++++std2.begin(), ----std2.end());
	ft1.splice(ft1.begin(), ft2, ++++ft2.begin(), ----ft2.end());

	std::cout << "std1 == ft1 : " << printBool((std1 == ft1)) << std::endl;
	std::cout << "std2 == ft2 : " << printBool((std2 == ft2)) << std::endl << std::endl;

}

bool	pair(const int &value)
{
	return (!(value % 2));
}

static void	remove()
{
	printTitle("Remove / Remove_if");
	
	int array[] = {0, 1, 2, 3, 5, 6, 4, 5, 6, 7, 8, 9};
	ft::list<int> ft1(array, array + 12);
	ft::list<int> std1(array, array + 12);

	ft1.remove(5);
	std1.remove(5);

	ft1.remove(6);
	std1.remove(6);
	std::cout << "remove : " << printBool((std1 == ft1)) << std::endl;

	ft1.remove_if(pair);
	std1.remove_if(pair);
	std::cout << "remove_if : " << printBool((std1 == ft1)) << std::endl << std::endl;
}

bool	strictly_greater(int a, int b)
{
	return (a > b);
}

static void	unique()
{
	printTitle("Unique");
	
	int array[] = {0, 3, 8, 10, 1, 1, 1, 5, 6, 7, 5, 1, 7, 8, 9};
	ft::list<int> ft1(array, array + 16);
	ft::list<int> std1(array, array + 16);

	ft1.unique();
	std1.unique();
	
	std::cout << "default : " << printBool((std1 == ft1)) << std::endl;

	ft1.unique(strictly_greater);
	std1.unique(strictly_greater);
	std::cout << "with binary predicate : " << printBool((std1 == ft1)) << std::endl << std::endl;
}


bool	greater_than(int a, int b)
{
	return (a >= b);
}

static void	merge()
{
	printTitle("Merge");
	
	int array1[] = {0, 3, 7, 10};
	ft::list<int> ft1(array1, array1 + 4);
	std::list<int> std1(array1, array1 + 4);

	int array2[] = {1, 2, 7, 12};
	ft::list<int> ft2(array2, array2 + 4);
	std::list<int> std2(array2, array2 + 4);

	ft1.merge(ft2);
	std1.merge(std2);

	std::cout << "default : " << printBool((std1 == ft1)) << std::endl;

	ft1.merge(ft2, greater_than);
	std1.merge(std2, greater_than);
	
	std::cout << "compare : " << printBool((std1 == ft1)) << std::endl << std::endl;
}

static void	reverse()
{
	printTitle("Reverse");
	
	int array[] = {0, 3, 8, 10, 1, 1, 1, 5, 6, 7, 5, 1, 7, 8, 9};
	ft::list<int> ft1(array, array + 16);
	ft::list<int> std1(array, array + 16);

	ft1.reverse();
	std1.reverse();
	
	std::cout << "std1 == ft1 : " << printBool((std1 == ft1)) << std::endl << std::endl;
}

static void	operators()
{
	printTitle("Operators");
	
	int array1[] = {0, 8, -4, 2, 14, 10};

	std::list<int> std1(array1, array1 + 6);
	std::list<int> std2(std1);

	ft::list<int> ft1(array1, array1 + 6);
	ft::list<int> ft2(ft1);

	std::cout << "l1 == l2 : " << printBool(((std1 == std2) == (ft1 == ft2))) << std::endl;
	std::cout << "l1 != l2 : " << printBool(((std1 != std2) == (ft1 != ft2))) << std::endl;
	std::cout << "l1 >= l2 : " << printBool(((std1 >= std2) == (ft1 >= ft2))) << std::endl;
	std::cout << "l1 > l2  : " << printBool(((std1 > std2) == (ft1 > ft2))) << std::endl;
	std::cout << "l1 <= l2 : " << printBool(((std1 <= std2) == (ft1 <= ft2))) << std::endl;
	std::cout << "l1 < l2  : " << printBool(((std1 < std2) == (ft1 < ft2))) << std::endl;
	std::cout << std::endl;

	std1.push_back(3);
	ft1.push_back(3);

	std::cout << "l1 == l2 : " << printBool(((std1 == std2) == (ft1 == ft2))) << std::endl;
	std::cout << "l1 != l2 : " << printBool(((std1 != std2) == (ft1 != ft2))) << std::endl;
	std::cout << "l1 >= l2 : " << printBool(((std1 >= std2) == (ft1 >= ft2))) << std::endl;
	std::cout << "l1 > l2  : " << printBool(((std1 > std2) == (ft1 > ft2))) << std::endl;
	std::cout << "l1 <= l2 : " << printBool(((std1 <= std2) == (ft1 <= ft2))) << std::endl;
	std::cout << "l1 < l2  : " << printBool(((std1 < std2) == (ft1 < ft2))) << std::endl;
	std::cout << std::endl;

	std2.push_back(8);
	ft2.push_back(8);

	std::cout << "l1 == l2 : " << printBool(((std1 == std2) == (ft1 == ft2))) << std::endl;
	std::cout << "l1 != l2 : " << printBool(((std1 != std2) == (ft1 != ft2))) << std::endl;
	std::cout << "l1 >= l2 : " << printBool(((std1 >= std2) == (ft1 >= ft2))) << std::endl;
	std::cout << "l1 > l2  : " << printBool(((std1 > std2) == (ft1 > ft2))) << std::endl;
	std::cout << "l1 <= l2 : " << printBool(((std1 <= std2) == (ft1 <= ft2))) << std::endl;
	std::cout << "l1 < l2  : " << printBool(((std1 < std2) == (ft1 < ft2))) << std::endl;
	std::cout << std::endl;

}

void		list_tests(void)
{	
	printTitle("LIST_TESTER");
	
	constructors_and_copy();	
	max_size();	
	front_back();	
	assign();	
	push_pop();	
	erase();	
	swap();	
	resize();	
	splice();	
	remove();	
	unique();	
	merge();	
	reverse();	
	operators();
}
