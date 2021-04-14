/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:36:43 by chgilber          #+#    #+#             */
/*   Updated: 2021/04/14 11:55:05 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>
#include <iostream>
#include <climits>

int	main(void)
{
	ft::vector<int>		myv(15,42);
	std::vector<int>	truv(15,42);
	ft::vector<int> first (3,100);   // three ints with a value of 100
	ft::vector<int> second (15,200);  // five ints with a value of 200

	std::cout <<" ft   " << myv.size() << std::endl;
	std::cout << "true " << truv.size() << std::endl;
	std::cout << " ft  " << myv.max_size() << std::endl;
	std::cout << "true " << truv.max_size() << std::endl;
	std::cout << "true " << truv.at(12) << std::endl;
	std::cout << " ft  " << myv.at(12) << std::endl;
	ft::vector<int>::iterator	it = myv.begin();
	std::vector<int>::iterator	ite = truv.begin();
	std::cout << "true " << *truv.erase(ite) << std::endl;
	std::cout << " ft  " << *myv.erase(it) << std::endl;
	std::cout << "\nTest with swap\n\n";

	std::cout << "First BEFORE swap : ";
	for (ft::vector<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Second BEFORE swap : ";
	for (ft::vector<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	first.swap(second);

	std::cout << "first AFTER swap:";
	for (ft::vector<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << first.size();
	std::cout << '\n';

	std::cout << "second AFTER swap:";
	for (ft::vector<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << second.size();
	std::cout << '\n';
	first.swap(second);
	std::cout << "first AFTER swap:";
	for (ft::vector<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << first.size();
	std::cout << '\n';

	std::cout << "second AFTER swap:";
	for (ft::vector<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << second.size();
	std::cout << '\n';
	std::cout << "\nWith 2 empty vector\n";
	ft::vector<int> lst1;   // three ints with a value of 100
	ft::vector<int> lst2;  // five ints with a value of 200

	std::cout << "lst1 BEFORE swap : ";
	for (ft::vector<int>::iterator it=lst1.begin(); it!=lst1.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "lst2 BEFORE swap : ";
	for (ft::vector<int>::iterator it=lst2.begin(); it!=lst2.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	lst1.swap(lst2);

	std::cout << "lst1 AFTER swap:";
	for (ft::vector<int>::iterator it=lst1.begin(); it!=lst1.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << lst1.size();
	std::cout << '\n';

	std::cout << "lst2 AFTER swap:";
	for (ft::vector<int>::iterator it=lst2.begin(); it!=lst2.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << lst2.size();
	std::cout << '\n';
	std::cout << "\nTest with overload swap\n\n";

	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (15,200);   // five ints with a value of 200

	std::cout << "BEFORE swap foo contains:";
	for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "BEFORE swap bar contains:";
	for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	ft::swap(foo,bar);

	std::cout << "AFTER swap foo contains:";
	for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "AFTER swap bar contains:";
	for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}
