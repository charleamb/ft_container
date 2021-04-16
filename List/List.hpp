/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:48:01 by chgilber          #+#    #+#             */
/*   Updated: 2021/04/16 17:22:34 by chgilber         ###   ########.fr       */
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
			typedef const Bidirectional_Iterator <value_type>	const_iterator;
			typedef RBI <value_type>						reverse_iterator;
			typedef const RBI <value_type>				reverse_const_iterator;
			typedef	ptrdiff_t							difference_type;
			typedef	size_t								size_type;
		
		private:
				typedef struct	l_list
				{
					value_type		value;
					l_list			*next;
					l_list			*bef;
				}				l_list;
				l_list			*_l;
				l_list			*_start;
				l_list			*_end;
				allocator_type	_alloc;
				size_type		_n;
				void		init(void)
				{
					_l = new l_list;
					_start = _l;
					_end = _l;
				}

				l_list		*find(iterator pos)
				{
					l_list	*find = _start;

					for (iterator it = begin(); it != pos && it != end(); it++)
						find = find->_next;
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
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last,
					typename InputIt::difference_type * = NULL)
			{
				clear();
				init();
				while(first != last)
				{
					push_back(*first);
					first++;
				}
			}
			void	assign(size_type n, const value_type &v)
			{
				clear();
				init();
				for (size_t i = 0; i < n; i++)
					push_back(v);
			}

			reference			back()
			{
				return _end->value;
			}
			const_reference		back() const
			{
				return _end->value;
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
				while (_start != _end)
				{
					_start = _start->next;
					delete _start->bef;
				}
				_start = NULL;
				_start->value =  0;
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
				iterator it = begin();
				while (it < position)
					it++;
				l_list	tmp = find(it);
				if (tmp != _end)
				{
					tmp->bef->next = tmp->next;
					tmp->next->bef = tmp->bef;
				}
				if (tmp == _start)
				{
					_start = tmp->next;
				}
				if (tmp == _end)
				{
					_end = tmp->bef;
				}
				delete tmp;
				_n--;
				return position;
			}
			iterator	erase(iterator first, iterator last)
			{
				iterator it = begin();
				while (it < first)
					it++;
				while (it < last)
				{
					it = erase(it);
					it++;
				}
				return it;
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
				l_list	*tmp = find(pos);
				l_list	*in = new l_list;
				in->value = val;
				in->next = tmp;
				if (tmp == _start)
					in->bef = _start;
				else
					in->before = tmp->bef;
				tmp->bef = in;
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
					pos = insert(pos, *first);
					first++;
					pos++;
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
				_start = copy._start;
				_end = copy._end;
				if (copy.size() != 0)
					assign(copy.begin(), copy.end());
				return *this;
			}

			void	pop_back()
			{
				erase(--end());
			}
			void	pop_front()
			{
				erade(begin());
			}

			void	push_back(const value_type	&val)
			{
				if (_n >= max_size())
				{
					l_list	*add = new l_list;
					add->value = val;
					add->bef = _end;
					_end->next = add;
					_end = add;
					add->next = _start;
				_n++;
				}
			}
			void	push_front(const value_type	&val)
			{
				if (_n >= max_size())
				{
					l_list	*add = new l_list;
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
