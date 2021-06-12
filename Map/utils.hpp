/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:46:54 by chgilber          #+#    #+#             */
/*   Updated: 2021/06/12 07:09:11 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UTILS_HPP
# define	UTILS_HPP

#include <iostream>
/*
&
&&
*/
//namespace ft
//{
	template <class T>
		class Mapnode
		{
			public :
				typedef T		value_type;

				Mapnode			*parent;
				Mapnode			*right;
				Mapnode			*left;
				value_type		elem;

				Mapnode(value_type const &val = value_type()) : elem(val)
				{
					parent = NULL;
					right = NULL;
					left = NULL;
				}
				Mapnode(value_type const &val, Mapnode *dad) : elem(val)
				{
					parent = dad;
					right = NULL;
					left = NULL;
				}
				Mapnode(Mapnode const &o)
				{
					elem = o.elem;
					parent = o.parent;
					right = o.right;
					left = o.left;
				}
				Mapnode	&operator=(Mapnode const &o)
				{
					elem = o.elem;
					parent = o.parent;
					right = o.right;
					left = o.left;
					return (*this);
				}

				~Mapnode() {}

				value_type	operator->()
				{
					return (elem);
				}
		};
	template <class T>
		struct less : std::binary_function <T,T,bool>
	{
		bool operator() (const T& x, const T& y) const 
		{
			return (x < y);
		}
	};
	template <class T1, class T2>
		struct pair
		{
			typedef T1		first_type;
			typedef T2		second_type;

			T1				first;
			T2				second;

			pair(): first(), second() {}

			pair(const T1 &f, const T2 &s): first(f), second(s) {}

			template <class U, class V>
				pair(const pair<U,V> &pr): first(pr.first), second(pr.second) {}

			~pair() {}

			template <typename U1, typename U2>
				pair &operator=(const pair<U1, U2> &other)
				{
					first = other.first;
					second = other.second;
					return (*this);
				}

			pair &operator=(const pair &other)//: first(other.first), second(other.second)
			{
				first = other.first;
				second = other.second;
				return (*this);
			}
		};
		template <class T1, class T2>
	pair <T1, T2> make_pair(T1 x, T2 y)
	{
		return ( pair <T1, T2>(x, y) );
	}

template <class T1, class T2>
	bool	operator==(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return ( l.first == r.first && l.second == r.second );
	}

template <class T1, class T2>
	bool	operator!=(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return ( l.first != r.first && l.second != r.second );
	}
template <class T1, class T2>
	bool	operator<(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return ( l.first < r.first && l.second < r.second );
	}
template <class T1, class T2>
	bool	operator>(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return ( l.first > r.first && l.second > r.second );
	}
template <class T1, class T2>
	bool	operator<=(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return ( l.first <= r.first && l.second <= r.second );
	}
template <class T1, class T2>
	bool	operator>=(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return ( l.first >= r.first && l.second <= r.second );
	}


//};
#endif
