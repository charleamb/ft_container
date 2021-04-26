/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:02:17 by chgilber          #+#    #+#             */
/*   Updated: 2021/04/26 14:44:07 by chgilber         ###   ########.fr       */
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
	MODE::list<int>	lst(4, 12);

//	MODE::list<int>	lst2(4, 12);
//	lst.push_back(16);
//	lst.push_back(150);
//	lst.push_back(-1);
	MODE::list<int>::iterator		ite = lst.begin();

	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;
}

