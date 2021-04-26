/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:48:01 by chgilber          #+#    #+#             */
/*   Updated: 2021/04/26 14:53:35 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include <cstddef> //ptrdiff_t
#include <climits> // sizemax
#include <stdexcept>
#include "Bidirectional_iterator.hpp"
#include "Reverse_Bidirectional_iterator.hpp"
# define RBI Reverse_Bidirectional_Iterator
# define BI Bidirectional_Iterator
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T									value_type;
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
				l_list<T>			*_start;
				l_list<T>			*_end;
				allocator_type	_alloc;
				size_type		_n;
				void		init(void)
				{
					_start = new l_list<T>;
					_end = new l_list<T>;

					_start->next = _end;
					_start->bef = _end;
					_end->bef = _start;
					_end->next = _start;
				}

				l_list<T>		*find(iterator pos)
				{
					l_list<T>	*find = _start;

					for (iterator it = begin(); it != pos && it != end(); it++)
						find = find->next;
					return (find);
				}

			public:
			//construteur par defaut
			list(const allocator_type &a = allocator_type()): _alloc(a), _n(0)
			{
				init();
			}
			//construteur fill
			list(size_type n, const value_type &v = value_type(),
				const allocator_type &a = allocator_type()):
				_alloc(a) ,_n(0)
			{
				init();
				assign(n, v);
			}
			//construteur copy
			list(const list &copy): _alloc(copy._alloc), _n(0)
			{
				init();
				_start = copy._start;
				iterator	it = copy.begin();
				for (size_t i = 0; i < copy._n; i++)
				{
					push_back(*it);
					it++;
				}
				_end = copy._end;
				copy.clear();
			}
			//construteur range
			template <class InputIt>
				list(InputIt first, InputIt last,
					const allocator_type &a = allocator_type(),
					typename InputIt::difference_type * = NULL): _alloc(a),
					_n(0)
				{
				init();
				assign(first, last);
				}
				//destructeur
			~list()
			{
				clear();
				delete _start;
				delete _end;
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last,
					typename InputIt::difference_type * = NULL)
			{
				clear();
				_start = _end;
				while(first != last)
				{
					push_back(*first);
					first++;
				}
			}
			void	assign(size_type n, const value_type &v)
			{
				clear();
				_start = _end;
				for (size_t i = 0; i < n; i++)
					push_back(v);
			}

			reference			back()
			{
				return _end->bef->value;
			}
			const_reference		back() const
			{
				return _end->bef->value;
			}

			//function list in alpha order
			iterator		begin()
			{
				return (iterator(_start));
			}
			const_iterator	begin() const
			{
				return (iterator(_start));
			}

			void	clear()
			{
				erase(begin(), end());
				_n = 0;
			}

			bool	empty() const
			{
				return _n > 0 ? false : true;
			}

			iterator		end()
			{
				return iterator(_end);
			}
			const_iterator	end() const
			{
				return iterator(_end);
			}

			iterator	erase(iterator position)
			{
				if (_n == 0)
					return position;
				l_list<T>	*tmp = find(position);
				if (tmp == _start)
					_start = tmp->next;
				else if (_start != _end->bef)
				{
					tmp->bef->next = tmp->next;
					tmp->next->bef = tmp->bef;
				}
				else if (tmp == _end->bef)
					_end->bef = tmp->bef;
				if (tmp != _start && tmp != _end)
				{
					delete tmp;
				std::cout << "erase" << std::endl;
				}
				_n--;
				return position;
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

			reference		front()
			{
				return _start->value;
			}
			const_reference	front() const
			{
				return _start->value;
			}

			allocator_type	get_allocator() const
			{
				return _alloc;
			}
			
			iterator		insert(iterator pos, const value_type &val)
			{
				l_list<T>	*tmp = find(pos);
				l_list<T>	*in = new l_list<T>;
				
				in->value = val;
				if (_n == 0)
					_start = in;
				else
					tmp->bef = in;
				in->next = tmp;
				in->bef = tmp->bef;
				_n++;
				return pos;
			}
			void		insert(iterator pos,size_type n, const value_type &val)
			{
				for (size_type s = 0; s < n ; s++)
					insert(pos, val);
			}
			template <class InputIt>
			void	insert(iterator pos, InputIt first, InputIt last,
					typename InputIt::difference_type * = NULL)
			{
				while (first != last)
				{
					std::cout << *first << std::endl;
					insert(pos, *first);
					first++;
				}
			}

			size_type			max_size(void) const
			{
				return (ULONG_MAX / sizeof(value_type));
			}

			void				merge(list &x)
			{
				if ( &x != this)
				{
				//	bool		is_sort = 0;
					iterator	it = x.begin();

					it++;
					for (iterator cmp = x.begin(); cmp != x.end(); it++, cmp++)
					{
				//		if (*cmp > *it)
				//			is_sort = 1;
						push_back(*cmp);
					}
					x.clear();
				//	sort();
				}
			}

	//	template <class Compare>
	//		void				merde(list &x, Compare comp)
	//		{



			
					//constuteur =
			list&	operator=(const list &copy)
			{
				clear();
				if (copy.size() != 0)
					insert(begin(), copy.begin(), copy.end());
				return *this;
			}

			void	pop_back()
			{
				erase(--end());
			}
			void	pop_front()
			{
				erase(begin());
			}

			void	push_back(const value_type	&val)
			{
				if (_n <= max_size())
				{
					l_list<T>	*add = new l_list<T>;
					_end->value = val;
					_end->next = add;
					add->bef = _end;
					_end = add;
					_end->next = _start;
					_n++;
				}
			}
			void	push_front(const value_type	&val)
			{
				if (_n >= max_size())
				{
					l_list<T>	*add = new l_list<T>;
					add->value = val;
					add->bef = _end;
					_end->next = add;
					add->next = _start;
					_start = add;
				_n++;
				}
			}


			reverse_iterator		rbegin()
			{
				return reverse_iterator(_end);
			}
			reverse_const_iterator	rbegin() const
			{
				return reverse_iterator(_end);
			}

			reverse_iterator		rend()
			{
				return reverse_iterator(_start);
			}
			reverse_const_iterator	rend() const
			{
				return reverse_iterator(_start);
			}
			
			void	remove(const value_type &val)
			{
				iterator	it = begin();

				while (it != end())
				{
					if (find(it)->value == val)
						it = erase(it);
					it++;
				}
			}
		template <class Predicate>
			void	remove_if(Predicate pred)
			{
				iterator	it = begin();

				while (it != end())
				{
					if (pred(find(it)->value) == true)
						it = erase(it);
					it++;
				}
			}
			
			
			void	resize(size_type n, value_type val = value_type())
			{
				while (n > _n)
					push_back(val);
				while (n < _n)
					pop_back();
			}

			void	reverse()
			{


			}

			size_type	size() const
			{
				return _n;
			}

			void	swap(list &x)
			{
				list<T>	tmp;
				tmp = x;
				x = *this;
				*this = tmp;
			}
			};
	template <class T, class Alloc>
		bool		operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			for (typename ft::list<T>::iterator l = lhs.begin(), r = rhs.begin();
					l != lhs.end() ; l++, r++)
				if (*l != *r)
					return (false);
			return (true);
		}

	template <class T, class Alloc>
		bool		operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

	template <class T, class Alloc>
		bool		operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if (lhs == rhs)
				return (false);
			for (typename ft::list<T>::iterator l = lhs.begin(), r = rhs.begin();
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
		bool		operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}

	template <class T, class Alloc>
		bool		operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			if (lhs == rhs)
				return (true);
			return (!(rhs < lhs));
		}

	template <class T, class Alloc>
		bool		operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

	template <class T, class Alloc>
		void		swap(list<T,Alloc>& x, list<T,Alloc>& y)
		{
			x.swap(y);
		}
}
#endif
