/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:39:25 by chgilber          #+#    #+#             */
/*   Updated: 2021/06/08 15:43:07 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.hpp"

int	main(void)
{
	std::cout << std::endl;
	ft::map<char, int> mym;
	ft::map<char, int> mam;

	mym.insert(ft::pair<char,int>( 98, 100));
	mym.insert(ft::pair<char,int>(80, 15));
	mym.insert(ft::pair<char,int>(77, 12));
	mym.insert(ft::pair<char,int>(85, 30));
	mym.insert(ft::pair<char,int>(115, 150));
	mym.insert(ft::pair<char,int>(125, 400));
	mym.insert(ft::pair<char,int>(110, 140));
	mym.insert(ft::pair<char,int>(1, 1));
	std::cout << "destru" << std::endl;
	return 1;
}
