/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:46:54 by chgilber          #+#    #+#             */
/*   Updated: 2021/05/28 18:40:11 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UTILS_HPP
# define	UTILS_HPP
template <class T>
struct less : std::binary_function <T,T,bool>
{
	bool operator() (const T& x, const T& y) const 
	{
		return (x < y);
	}
};

template <class T1, class T2>
struct Pair
{
		typedef T1		first_type;
		typedef T2		second_type;

		T1				first;
		T2				second;

		Pair(): first(), second() {}

		Pair(const T1 &f, const T2 &s): first(f), second(s) {}

	template <class U, class V>
		Pair(const Pair<U,V> &pr): first(pr.first), second(pr.second) {}

		~Pair() {}
		
	template <typename U1, typename U2>
		Pair <T1, T2> &operator=(const Pair<U1, U2> &other)
		{
			first = other.first;
			second = other.second;
			return (*this);
		}
		
		Pair <T1, T2> &operator=(const Pair<T1, T2> &other)
		{
			first = other.first;
			second = other.second;
			return (*this);
		}
};

template <class T1, class T2>
	Pair <T1, T2> make_Pair(T1 x, T2 y)
	{
		return ( Pair <T1, T2>(x, y) );
	}

template <class T1, class T2>
	bool	operator==(const Pair<T1, T2> &l, const Pair<T1, T2> &r)
	{
		return ( l.first == r.first && l.second == r.second );
	}

template <class T1, class T2>
	bool	operator!=(const Pair<T1, T2> &l, const Pair<T1, T2> &r)
	{
		return ( l.first != r.first && l.second != r.second );
	}
template <class T1, class T2>
	bool	operator<(const Pair<T1, T2> &l, const Pair<T1, T2> &r)
	{
		return ( l.first < r.first && l.second < r.second );
	}
template <class T1, class T2>
	bool	operator>(const Pair<T1, T2> &l, const Pair<T1, T2> &r)
	{
		return ( l.first > r.first && l.second > r.second );
	}
template <class T1, class T2>
	bool	operator<=(const Pair<T1, T2> &l, const Pair<T1, T2> &r)
	{
		return ( l.first <= r.first && l.second <= r.second );
	}
template <class T1, class T2>
	bool	operator>=(const Pair<T1, T2> &l, const Pair<T1, T2> &r)
	{
		return ( l.first >= r.first && l.second <= r.second );
	}

#endif
