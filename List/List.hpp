/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:48:01 by chgilber          #+#    #+#             */
/*   Updated: 2021/05/20 17:35:43 by chgilber         ###   ########.fr       */
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
					_n = 0;
				}

				l_list<T>		*find(iterator pos)
				{
					l_list<T>	*find = _start;

					for (iterator it = begin(); it != pos && it != end(); it++)
						find = find->next;
					return (find);
				}

				void	connected(l_list<T> *in, l_list<T> *tmp)
				{
			//	std::cout << "in bef = " << in->bef->value;
			//		std::cout << " / in bef next = " << in->bef->next->value;
			//		std::cout << " / in next bef = " << in->next->bef->value;
			//		std::cout << " / in  next = " << in->next->value;
			//	std::cout << " / in bef nextnext = " << in->bef->next->next->value << std::endl;
			//		std::cout << "tmp bef insade= " << tmp->bef << std::endl;
			//		std::cout << "tmp next insade= " << tmp->next << std::endl;
	//				std::cout << "tmp next next insade= " << tmp->next->next->value << std::endl;
			//		std::cout << "end= " << _end << std::endl;
	//					std::cout << "start next = " << _start->next->value << std::endl;
	//					std::cout << "start = " << _start->value << std::endl;
	//					std::cout << "tmp = " << tmp->value << std::endl;
			//			std::cout << "tmp = " << tmp << std::endl;
			//			std::cout << "start = " << _start << std::endl;
					if (_n == 0)
					{
						_end->bef = in;
					}
					in->next = tmp;
					in->bef = tmp->bef;
					tmp->bef->next = in;
					tmp->bef->next->next = tmp;
					tmp->next->bef = in;
					tmp->bef = in;
					//	in->next->bef = in->bef;
					if (_start == tmp)
					{
						in->bef = _end;
					}
					else
					{
						in->bef->next = in;
						in->next->bef = in;
					}
				//	std::cout << "in  next = " << in->next->value << std::endl;
				//	std::cout << "in  bef = " << in->bef->value << std::endl;
					if (_start == tmp)
					{
						_start = in;
					}
						//			std::cout << "sstatrt bef val = " << _start->bef->value << std::endl;
	//			std::cout << "start val = " << _start->value << std::endl;
	//			std::cout << "start  next val = " << _start->next->value << std::endl;

				}
				void	printer(iterator pos)
				{
				l_list<T>	*tmpi = find(pos);
	//			std::cout << "start val = " << _start->value << std::endl;
	//			std::cout << "start bef val = " << _start->bef->value << std::endl;
	//			std::cout << "end  val = " << _end->value << std::endl;
	//			std::cout << "end bef val = " << _end->bef->value << std::endl;
	//			std::cout << "end next val = " << _end->next->value << std::endl;
				std::cout << "tmpi bef val = " << tmpi->bef->value << std::endl;
				std::cout << "tmpi  val = " << tmpi->value << std::endl;
				std::cout << "tmpi next val = " << tmpi->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmpi next nxt val = " << tmpi->next->next->next->next->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "size = " << _n << std::endl;
		//		for (iterator it = begin(); it != end(); it++)
		//			std::cout << "it  = " << *it << std::endl;
				}
				void	printer(iterator pos, list &x)
				{
				std::cout << "start val = " << x._start->value << std::endl;
				std::cout << "start val next = " << x._start->next->value << std::endl;
				l_list<T>	*tmp = x.find(pos);
				std::cout << "tmp bef val = " << tmp->bef->value << std::endl;
				std::cout << "tmp  val = " << tmp->value << std::endl;
				std::cout << "tmp next val = " << tmp->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->next->next->next->next->next->next->next->value << std::endl;
				std::cout << "tmp next nxt val = " << tmp->next->next->next->next->next->next->next->next->next->next->next->next->value << std::endl;
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
				for (size_t i = 0; i < n; i++)
					push_back(v);
			}
			//construteur copy
			list(const list &copy): _alloc(copy._alloc), _n(0)
			{
				init();
				iterator	it = copy.begin();
				for (size_t i = 0; i < copy._n; i++)
				{
					push_back(*it);
					it++;
				}
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
				if ( _n > 0)
					clear();
				else if (begin() != end())
					delete _start;
				delete _end;
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last,
					typename InputIt::difference_type * = NULL)
			{
				if ( _n > 0)
					clear();
				else if (begin() != end())
					delete _start;
				delete _end;
				init();
				while(first != last)
				{
					push_back(*first);
					first++;
				}
			}
			void	assign(size_type n, const value_type &v)
			{
				if ( _n > 0)
					clear();
				else if (begin() != end())
					delete _start;
				delete _end;
				init();
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
				return (const_iterator(_start));
			}

			void	clear()
			{
					erase(begin(), end());
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
				return const_iterator(_end);
			}

			iterator	erase(iterator position)
			{
				if (_n == 0)
					return position;
				l_list<T>	*tmp = find(position);
				if (tmp == _start)
					_start = tmp->next;
				else if (tmp != _end->bef)
				{
					tmp->bef->next = tmp->next;
					tmp->next->bef = tmp->bef;
				}
				else if (tmp == _end->bef)
				{
					_end->bef = tmp->bef;
					_end->bef->next = _end;
					_end->value = _n - 1;
	//		std::cout << "here = "<< tmp->value << std::endl;
				}
				if (tmp != _start && tmp != _end)
				{
					delete tmp;
	//		std::cout << "delete = "<< tmp->value << std::endl;
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
				if ( _n == 0)
				{
					_start->value = val;
					_n++;
					return pos;
				}
				l_list<T>	*tmp = find(pos);
				l_list<T>	*in = new l_list<T>;
				in->bef = tmp->bef;
				in->value = val;
				in->next = tmp;
				tmp->bef = in;
				if (begin() == pos)
					_end->next = in;
				else
					in->bef->next = in;
				if (tmp == _start)
					_start = in;
				_end->value = _n + 1;
				_n++;
				return pos;
			}
			void		insert(iterator pos,size_type n, const value_type &val)
			{
				for (size_type s = 0; s < n ; s++)
					insert(pos, (val));
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

			size_type			max_size(void) const
			{
				return (ULONG_MAX / sizeof(l_list<T>));
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
					sort();
				}
			}

		template <class Compare>
			void				merge(list &x, Compare comp)
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
					sort(comp);
				}
			}


			
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
				if ( _n == 0)
				{
					if (_start == _end)
					{
						l_list<T>	*start = new l_list<T>;
						_start = start;
					}
					_start->value = val;
					_start->next = _end;
					_start->bef = _end;
					_end->value = _n + 1;
					_n++;
					return ;
			//		return (void)insert(begin(), val);
				}
				if (_n <= max_size())
				{
					l_list<T>	*add = new l_list<T>;
					_end->value = val;
					_end->next = add;
					add->bef = _end;
					_end = add;
					_end->value = _n + 1;
					_end->next = _start;
					_start->bef = _end;
					_n++;
				}
			}
			void	push_front(const value_type	&val)
			{
				if ( _n == 0)
					return push_back(val);
				if (_n <= max_size())
				{
					l_list<T>	*add = new l_list<T>;
					_end->value = _n + 1;
					add->value = _start->value;
					add->next =  _start->next;
					_start->value = val;
					_start->next = add;
					_start->bef = _end;
					add->bef =  _start;
				/*
					std::cout << "start val = " << _start->value << std::endl;
					std::cout << "start next val = " << _start->next->value << std::endl;
					std::cout << "start next next val = " << _start->next->next->value << std::endl;
					std::cout << "start bef val = " << _start->bef->value << std::endl;
					std::cout << "start bef bef val = " << _start->bef->bef->value << std::endl;
					std::cout << "add bef val = " << add->bef->value << std::endl;
					std::cout << "end val = " << _end->value << std::endl;
					std::cout << "end next val = " << _end->next->value << std::endl;
					std::cout << std::endl;
			*/	_n++;
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
				iterator	start = begin();
				iterator	endi = end();
				value_type	tmp;

				endi--;
				for (size_type i = 0; i < _n / 2; i++)
				{
					tmp = *start;
					*start = *endi;
					*endi = tmp;
					start++;
					endi--;
				}
			}

			size_type	size() const
			{
				return _n;
			}
			
			void		sort()
			{
				value_type	tmp;
				for (size_type i = 0; i < _n; i++)
				{
					iterator	it = begin();
					iterator	ite = begin();
					ite++;
					for (size_type j = 0; j < _n && ite != end(); j++)
					{
						if (*it > *ite)
						{
							tmp = *it;
							*it = *ite;
							*ite = tmp;
						}
						it++;
						ite++;
					}
				}
			}
			template <class Compare>
			void		sort(Compare comp)
			{
				value_type	tmp;
				for (size_type i = 0; i < _n; i++)
				{
					iterator	it = begin();
					iterator	ite = begin();
					ite++;
					for (size_type j = 0; j < _n && ite != end(); j++)
					{
						if (!comp(*it, *ite))
						{
							tmp = *it;
							*it = *ite;
							*ite = tmp;
						}
						it++;
						ite++;
					}
				}
			}
			void		splice(iterator pos, list &x)
			{
				iterator it = x.begin();
				while (it != x.end())
				{
					it = x.begin();
					splice(pos, x, it);
					if (it == x.end())
						return;
				}
			}
			void		splice(iterator pos, list &x, iterator i)
			{
				l_list<T>	*tmp = find(pos);
				l_list<T>	*add =	x.find(i);

		//		std::cout << "add  val = " << add->value << std::endl;
		//			std::cout << "tmp bef bef = " << tmp->bef->bef->value;
		//		std::cout << " / tmp bef = " << tmp->bef->value;
		//		std::cout << " / tmp = " << tmp->value;
		//			std::cout << " / tmp next = " << tmp->next->value << std::endl;
				if (i == x.begin())
				{
					x._start = add->next;
					x._start->next = add->next->next;
			//		std::cout << "i = xbegin add next next " << add->next->next->value << std::endl;
		//			std::cout << "i = xbegin start next " << x._start->next->value << std::endl;
					if (i == x.end())
					{
						x._start = x._end;
				//		x._end = x._start;
			//			std::cout << "start" << x._start->value << std::endl;
				//		std::cout << "endt" << x._end << std::endl;
				//		std::cout << "start" << x._start << std::endl;
				//		std::cout << "endt" << x._end->value << std::endl;
				// 		std::cout << "endt bef" << x._end->bef->value << std::endl;
						return ;
					}
				}
				else
				{
		//		std::cout << "in bef  = " << add->bef->value << std::endl;
		//		std::cout << "in bef next = " << add->bef->next->value << std::endl;
		//			std::cout << "in next bef = " << add->next->bef->value << std::endl;
					add->next->bef = add->bef;
					add->bef->next = add->next;
		//		std::cout << "in bef = " << add->bef->value << std::endl;
		//			std::cout << "in bef next = " << add->bef->next->value << std::endl;
		//		std::cout << "in bef next x 2 = " << add->bef->next->next->value << std::endl;
		//			std::cout << "in next bef = " << add->next->bef->value << std::endl;
				}
			//	std::cout << "2 start next " << x._start->next->value << std::endl;
		//		std::cout << "CONECTED  ---  add next " << add->next->value << std::endl;
				connected(add,tmp);
								_n++;
				x._n--;
				_end->value = _n;
				x._end->value = x._n;
			//	printer(i);

		//		std::cout << "FINNNN  ---  add next " << add->next->value << std::endl;
		//		std::cout << "in bef = " << add->bef->value;
		//			std::cout << " / in bef next = " << add->bef->next->value;
		//			std::cout << " / in next bef = " << add->next->bef->value;
		//		std::cout << " / in bef next x 2 = " << add->bef->next->next->value << std::endl;
		//		std::cout << " x end bef   = " << x._end->bef->value << std::endl;

			}
			void		splice(iterator pos, list &x, iterator first, iterator last)
			{
				int size = 1;

				for (iterator	ite = first; ite != last; ite++)
					size++;
				iterator	t = first;
				for (int i = 0; i  < size; i++)
				{
					splice(pos, x, t);
					t++;
				}
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
