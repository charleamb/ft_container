/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:58:54 by chgilber          #+#    #+#             */
/*   Updated: 2021/04/05 15:14:36 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>

namespace ft
{
	template <class T, class Alloc = allocator<T> >
	class list
	{
		typedef T							value_ty;
		typedef Alloc						allocator_type;
		typedef T							&reference;
		typedef	size_t						size_type;
	//	typedef allocator_type::const_reference	const_reference;
	//	typedef allocator_type::pointer			pointer;
	//	typedef allocator_type::const_pointer	const_pointer;
//		typedef 		iterator;
//		typedef
	private:
		value_type		lvalue
		allocator_type	lalloc
		list			*lnext
		list			*lprevious
			public:
			list()
			{
			};
			list(
