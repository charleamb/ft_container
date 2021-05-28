/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:48:01 by chgilber          #+#    #+#             */
/*   Updated: 2021/05/28 18:57:18 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <cstddef> //ptrdiff_t
#include <climits> // sizemax
#include <stdexcept>
#include "utils.hpp"
#include "Bidirectional_iterator.hpp"
#include "Reverse_Bidirectional_iterator.hpp"
# define RBI Reverse_Bidirectional_Iterator
# define BI Bidirectional_Iterator
namespace ft
{
template <class Key,                                      // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = std::allocator<Pair<const Key,T> >    // map::allocator_type
           > class map
		{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef Pair<const Key, T>					value_type;
			typedef	Compare								key_compare;
	//		typedef value_comp()						value_compare;
			typedef Alloc								allocator_type;
			typedef T									&reference;
			typedef const T								&const_reference;
			typedef T									*pointer;
			typedef const T								*const_pointer;
			typedef Bidirectional_Iterator <value_type>	iterator;
			typedef const BI <value_type>				const_iterator;
			typedef RBI <value_type>					reverse_iterator;
			typedef const RBI <value_type>				reverse_const_iterator;
			typedef	ptrdiff_t							difference_type;
			typedef	size_t								size_type;
		private:
			
			key_compare		_key_compare;
			allocator_type	_alloc;
			size_type		_n;
			value_type		_key;
			value_type		_top;
			value_type		_bot;

			void	print()
			{
			}
		public:
			//construteur par defaut
			map(const key_compare &comp = key_compare(),
				const allocator_type &a = allocator_type()): _alloc(a), _key_compare(comp)
			{
			}
			//construteur copy
			map(const map &copy): _alloc(copy._alloc), _key_compare(copy._comp)
			{
				iterator	it = copy.begin();
				for (size_t i = 0; i < copy._n; i++)
				{
					insert(*it);
					it++;
				}
			}
			//construteur range
			template <class InputIt>
				map(InputIt first, InputIt last,
					const key_compare &comp = key_compare(),
					const allocator_type &a = allocator_type(),
					typename InputIt::difference_type * = NULL): _alloc(a), _key_compare(comp), _n(0)
				{
					while (first != last)
					{
						insert(*first);
						first++;
					}
				}
				//destructeur
			~map()
			{
				if ( _n > 0)
					clear();
			}

			//function map in alpha order
			iterator		begin()
			{
				return (iterator(_top));
			}
			const_iterator	begin() const
			{
				return (const_iterator(_top));
			}

			void	clear()
			{
					erase(begin(), end());
			}
			
			size_type	count(const key_type &k) const
			{
				(void)k;
				return ;
			}

			bool	empty() const
			{
				return _n > 0 ? false : true;
			}

			iterator		end()
			{
				return iterator(_bot);
			}
			const_iterator	end() const
			{
				return const_iterator(_bot);
			}
			
			Pair<const_iterator, const_iterator>	equal_range(const key_type &k) const
			{
				(void)k;
			}
			Pair<iterator, iterator>	equal_range(const key_type &k)
			{
				(void)k;
			}

			iterator	erase(iterator position)
			{
				return position;
			}
			size_type	erase(const key_type &k)
			{
				(void)k;
				return _n;
			}
			iterator	erase(iterator first, iterator last)
			{
				iterator		tmp = first;
				while (first != last)
				{
					tmp++;
					erase(first);
					first = tmp;
				}
				return first;
			}

			iterator	find(const key_type &k)
			{
				(void)k;
			}
			const_iterator	find(const key_type &k) const
			{
				(void)k;
			}

			allocator_type	get_allocator() const
			{
				return _alloc;
			}
			
			Pair<iterator, bool>	insert(const value_type &val)
			{
				(void)val;
			}
			iterator		insert(iterator pos, const value_type &val)
			{
				(void)val;
			return pos;
			}
			template <class InputIt>
			void	insert(iterator pos, InputIt first, InputIt last,
					typename InputIt::difference_type * = NULL)
			{
				while (first != last)
				{
					insert(pos, *first);
					first++;
				}
			}
			
			key_compare	key_comp() const
			{
				return (_key_compare);
			}

			
			iterator	lower_bound(const key_type &k)
			{
				(void)k;
			}
			const_iterator	lower_bound(const key_type &k) const
			{
				(void)k;
			}

			size_type			max_size(void) const
			{
				return (ULONG_MAX / sizeof(l_map<T>));
			}

					//constuteur = / []
			map			&operator=(const map &copy)
			{
				clear();
				if (copy.size() != 0)
					insert(begin(), copy.begin(), copy.end());
				return *this;
			}
			mapped_type	&operator[](const key_type &k)
			{
				return ((*((insert(make_Pair(k, mapped_type()))).first)).second)
			}

			reverse_iterator		rbegin()
			{
				return reverse_iterator(_bot);
			}
			reverse_const_iterator	rbegin() const
			{
				return reverse_iterator(_bot);
			}

			reverse_iterator		rend()
			{
				return reverse_iterator(_top);
			}
			reverse_const_iterator	rend() const
			{
				return reverse_iterator(_top);
			}
			
			size_type	size() const
			{
				return _n;
			}
			
			void	swap(map &x)
			{
				_n = x._n;
			}
		
			iterator		upper_bound(const key_type &k)
			{
				(void)k;
			}
			const_iterator	upper_bound(const key_type &k) const
			{
				(void)k;
			}

			value_compare	value_comp()
			{
			}

			};
/*	template <class T, class Alloc>
		bool		operator==(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			for (typename ft::map<T>::iterator l = lhs.begin(), r = rhs.begin();
					l != lhs.end() ; l++, r++)
				if (*l != *r)
					return (false);
			return (true);
		}

	template <class T, class Alloc>
		bool		operator!=(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

	template <class T, class Alloc>
		bool		operator<(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
		{
			if (lhs == rhs)
				return (false);
			for (typename ft::map<T>::iterator l = lhs.begin(), r = rhs.begin();
					l != lhs.end(); l++, r++)
			{
				if (*l < *r)
					return (true);
				if (*l > *r)
					return (false);
			}
			return (false);
		}

	template <class T, class Alloc>
		bool		operator>(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}

	template <class T, class Alloc>
		bool		operator<=(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
		{
			if (lhs == rhs)
				return (true);
			return (!(rhs < lhs));
		}

	template <class T, class Alloc>
		bool		operator>=(const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

	template <class T, class Alloc>
		void		swap(map<T,Alloc>& x, map<T,Alloc>& y)
		{
			x.swap(y);
		}
}*/
#endif
