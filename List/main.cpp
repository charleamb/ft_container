/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:02:17 by chgilber          #+#    #+#             */
/*   Updated: 2021/05/07 09:40:38 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bidirectional_iterator.hpp"
# include "Reverse_Bidirectional_iterator.hpp"
# include "List.hpp"
# include <list>
# include <cmath>
#include <iostream>
#ifndef MODE
# define MODE ft
#endif


int main(int argc, const char *argv[])
{
	(void)argv;
	(void)argc;
	MODE::list<int>	lst(4, 17);
	MODE::list<int>	lst2;

	lst.insert(lst.begin(), 3, 150);
	lst2.push_back(777);
//	int i = 0;

//	MODE::list<int>::iterator		ite = lst.begin();

	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

