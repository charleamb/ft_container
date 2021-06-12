/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:48:01 by chgilber          #+#    #+#             */
/*   Updated: 2021/06/12 18:00:59 by chgilber         ###   ########.fr       */
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
/*
&
&&
*/

namespace ft
{
template <class Key,                                      // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
           > class map
		{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<const Key, T>					value_type;
			typedef	Compare								key_compare;
//			typedef value_comp()						value_compare;
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
			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				public :
						bool operator()(const value_type &x, const value_type &y) const
						{
							return _comp(x.first, y.first);
						}

				private:
						Compare _comp;
						value_compare(Compare c)
						{
							_comp = c;
						}
						friend class map;
			};
		private:
			
			typedef	Mapnode<value_type>		Mapnode;
			key_compare						_key_compare;
			allocator_type					_alloc;
			size_type						_n;
			Mapnode							*_top;
			Mapnode							*_lower;
			Mapnode							*_upper;
			Mapnode							*_end;
			
			void	init()
			{
				_top = NULL;
				_lower = NULL;
				_upper = NULL;
				_end = NULL;
				_n = 0;
			}

			Mapnode		*findmn(iterator	pos)
			{
				Mapnode	*find = _lower;

					for (iterator it = begin(); it != pos && it != end(); it++)
					{
						if (find->right)
						{
							find = find->right;
							while (find->left)
								find = find->left;
						}
						else
						{
							Mapnode	*tmp = find;
							find = find->parent;
							while (find->parent && tmp == find->right)
							{
								tmp = find;
								find = find->parent;
							}
						}
					}
					return (find);
			}

			void	print()
			{
				int leaf = _lower->elem.first;
				int left = 0;
				int leftl = 0;
				int leftr = 0;
				int right = 0;
				int rightr = 0;
				int rightl = 0;
				iterator	branch = begin();
				std::cout << "--------Key print tree-------" << std::endl;
				for (int i = 0; i < (5); i++)
					std::cout << "\t";
				std::cout << "[" << (int)_top->elem.first << "]" << std::endl;
				// ligne 2
				if (_n > 1)
				{
				for (int i = 0; i < (3); i++)
					std::cout << "\t";
				std::cout << "[" << (_top->left ? _top->left->elem.first : -42)  << "]";
				left = (_top->left ? _top->left->elem.first : 0);
				for (int i = 0; i < (4); i++)
					std::cout << "\t";
				std::cout << "[" << (_top->right ? _top->right->elem.first : -42)  << "]";
				right = (_top->right ? _top->right->elem.first : 0);
				std::cout << std::endl;
				}
				//ligne 3
				if (_n > 3)
				{
				for (int i = 0; i < (2); i++)
					std::cout << "\t";
				std::cout << "[" << (left && _top->left->left ? _top->left->left->elem.first : -42)  << "]";
				leftl =  (left && _top->left->left ? _top->left->left->elem.first : 0);
				for (int i = 0; i < (2); i++)
					std::cout << "\t";
				std::cout << "[" << (left && _top->left->right ? _top->left->right->elem.first : -42)  << "]";
				leftr = (left && _top->left->right ? _top->left->right->elem.first :0);
				for (int i = 0; i < (2); i++)
					std::cout << "\t";
				std::cout << "[" << (right && _top->right->left ? _top->right->left->elem.first : -42)  << "]";
				rightl =  (right && _top->right->left ? _top->right->left->elem.first :0);
				for (int i = 0; i < (2); i++)
					std::cout << "\t";
				std::cout << "[" << (right && _top->right->right? _top->right->right->elem.first : -42)  << "]";
				rightr = (right && _top->right->right? _top->right->right->elem.first :0);
				std::cout << std::endl;
				}
				//ligne 4
				if ( _n > 7)
				{
				std::cout << "          ";
				std::cout << "[" << (leftl && _top->left->left->left ? _top->left->left->left->elem.first : -42)  << "]";
				std::cout << "      ";
				std::cout << "[" << (leftl && _top->left->left->right ? _top->left->left->right->elem.first : -42)  << "]";
				std::cout << "    ";
				std::cout << "[" << (leftr && _top->left->right->left ? _top->left->right->left->elem.first : -42)  << "]";
				std::cout << "     ";
				std::cout << "[" << (leftr && _top->left->right->right ? _top->left->right->right->elem.first : -42)  << "]";
				std::cout << "    ";
				std::cout << "[" << (rightl && _top->right->left->left ? _top->right->left->left->elem.first : -42)  << "]";
				std::cout << "     ";
				std::cout << "[" << (rightl && _top->right->left->right ? _top->right->left->right->elem.first : -42)  << "]";
				std::cout << "    ";
				std::cout << "[" << (rightr && _top->right->right->left ? _top->right->right->left->elem.first : -42)  << "]";
				std::cout << "     ";
				std::cout << "[" << (rightr && _top->right->right->right ? _top->right->right->right->elem.first : -42)  << "]";
				std::cout << std::endl;
				//ligne 5
				}
				if (_n > 15)
				{
				std::cout << "   ";
				std::cout << "[" << leaf << "]";
				std::cout << "      ";
				std::cout << "[" << leaf << "]";
				std::cout << "[" << leaf << "]";
				std::cout << "|";
				std::cout << "[" << leaf << "]";
				std::cout << "[" << leaf << "]";
				std::cout << "|";
				std::cout << "[" << leaf << "]";
				std::cout << "[" << leaf << "]";
				std::cout << "|";
				std::cout << "[" << leaf << "]";
				std::cout << "[" << leaf << "]";
				std::cout << "[" << leaf << "]";
				std::cout << "|";
				std::cout << "[" << leaf << "]";
				std::cout << "[" << leaf << "]";
				std::cout << "|";
				std::cout << "[" << leaf << "]";
				std::cout << "[" << leaf << "]";
				std::cout << "|";
				std::cout << "[" << leaf << "]";
				std::cout << "[" << leaf << "]" << std::endl;
				}
				std::cout << "lower = [" << (int)_lower->elem.first << "]"
			//	 << " lower dady  = [" << (int)_lower->parent->elem.first << "]"
			//	 << " end dady  = [" << (int)_end->parent->elem.first << "]"
						  << "upper = [" << (int)_upper->elem.first << "]" << std::endl;
				iterator it = begin();
				for (size_type i = 0; i < _n; i++)
				{
					std::cout << "lower = [" << (int)it->first << "]";
					it++;
				}
				std::cout << std::endl;

			}
		public:
			//construteur par defaut
			map(const key_compare &comp = key_compare(),
				const allocator_type &a = allocator_type()): _key_compare(comp), _alloc(a)
			{
				init();
			}
			//construteur copy
			map(const map &copy): _alloc(copy._alloc), _key_compare(copy._comp)
			{
				init();
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
					init();
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
				return (iterator(_lower));
			}
			const_iterator	begin() const
			{
				return (const_iterator(_lower));
			}

			void	clear()
			{
			//	if ( _n > 0 && _end)
			//		delete _end;
				erase(begin(), end());
			}
			
			size_type	count(const key_type &k) const
			{
				if(find(k) != end())
					return 1;
				return  0;
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
			
			pair<const_iterator, const_iterator>	equal_range(const key_type &k) const
			{
				return make_pair(lower_bound(k), upper_bound(k));
			}
			pair<iterator, iterator>	equal_range(const key_type &k)
			{
				return make_pair(lower_bound(k), upper_bound(k));
			}

			iterator	erase(iterator position)
			{
				Mapnode		*delet = findmn(position);
				int check = (delet->right && delet->right != _end) ? 1 : 0;
				if (_n > 0)
				{
//	std::cout << "delet = {" << (int)delet->elem.first << "}" << std::endl;
					if (delet == _top)
					{
						if (delet->left && check )
						{
							Mapnode		*_ptr = delet->left;
							while (_ptr->right)
								_ptr = _ptr->right;
							_ptr->right = delet->right;
							_ptr->left =(delet->left != _ptr) ? delet->left: _ptr->left;
							_top = _ptr;
							_top->parent = NULL;
							delet->left->parent = _top;
							delet->right->parent = _top;
//	std::cout << "2" << std::endl;
						}
						else if (delet->left && check == 0)
						{
							_top = delet->left;
							_top->parent = NULL;
							delet->left->parent = _top;
//	std::cout << "3" << std::endl;
						}
						else if (!delet->left && check)
						{

							_top = delet->right;
							_top->parent = NULL;
							delet->right->parent = _top;
//	std::cout << "4" << std::endl;
						}
						else
						{}
//							std::cout << "5" << std::endl;
					}
					else if (delet->left)
					{
//	std::cout << "delet->left = {" << (int)delet->left->elem.first << "}" << std::endl;
//							std::cout << "6" << std::endl;
						if (delet->right)
						{
//							std::cout << "7" << std::endl;
//	std::cout << "insade delet->right = {" << (int)delet->right->elem.first << "}" << std::endl;
							delet->right->parent = delet->left;
							delet->left->right = delet->right;
						//	delet->right->parent = delet->left;
						}
						delet->left->parent = delet->parent;
				//		delet->parent->left = NULL;
						if (delet->parent)
						{
//							std::cout << "8" << std::endl;
//	std::cout << "delet = {" << (int)delet->elem.first << "}" << std::endl;
							if (delet->parent->right && delet == delet->parent->right)
								delet->parent->right = delet->right;
							else if (delet->parent->left && delet == delet->parent->left)
								delet->parent->left = delet->left;
						}
					}
					else if (delet->right)
					{
//	std::cout << "only delet->right = {" << (int)delet->right->elem.first << "}" << std::endl;
//							std::cout << "9" << std::endl;
						delet->right->parent = delet->parent;
//	std::cout << "delet->right->parent = {" << (int)delet->right->parent->elem.first << "}" << std::endl;
						if (delet->parent)
						{
		//		std::cout << "10" << std::endl;
							if (delet->parent->right && delet == delet->parent->right)
								delet->parent->right = delet->right;
							else if (delet->parent->left && delet == delet->parent->left)
								delet->parent->left = delet->left;
						}
					//	delet->parent->left = delet->right;
					//	delet->parent->right = delet->right;
//	std::cout << "delet->parent->left = {" << (int)delet->parent->left->elem.first << "}" << std::endl;
				//		delet->parent->right = NULL;
					}
					else if (delet->parent)
					{
//	std::cout << "delet = {" << (int)delet->elem.first << "}" << std::endl;
							if (delet->parent->right && delet == delet->parent->right)
								delet->parent->right = NULL;
							else if (delet->parent->left && delet == delet->parent->left)
								delet->parent->left = NULL;
					}
					if (delet == _lower)
					{
//	std::cout << "in lower = {" << (int)delet->elem.first << "}" << std::endl;
						if (delet->parent)
							delet->parent->left = (delet->right) ? delet->right : NULL;
			//std::cout << "15" << std::endl;
						if (delet->right)
						{
							Mapnode		*_ptr = delet->right;
							while (_ptr->left)
								_ptr = _ptr->left;
	//		std::cout << "16" << std::endl;
							_lower =  _ptr;
						}
						else
							_lower = ((delet == _top) ? _top : delet->parent);
	//			std::cout << "17" << std::endl;
					}
					if (delet == _upper)
					{
//	std::cout << "in upperer = {" << (int)delet->elem.first << "}" << std::endl;
						if (delet->parent)
							delet->parent->right = NULL;
						if (delet->left)
						{
							Mapnode		*_ptr = delet->left;
							while (_ptr->right)
								_ptr = _ptr->right;
							_upper =  _ptr;
						}
						else
							_upper = ((delet == _top) ? _top : delet->parent);
					}
			_end->parent = _upper;
			_upper->right = _end;
//	std::cout << "before del = {" << (int)delet->elem.first << "}" << std::endl;
					delete delet;
//	std::cout << "after del lower  = {" << (int)_lower->elem.first << "}" << std::endl;
					delet = NULL;
					_n--;
				}
				return position;
			}
			size_type	erase(const key_type &k)
			{
				iterator del = find(k);

				if (del == end())
					return _n;
				erase(del);
				return _n;
			}
			iterator	erase(iterator first, iterator last)
			{
				iterator		tmp = first;
				int i = 0;
	//				print();
		//		while (i < 8)
				while (first != last)
				{
					tmp++;
//		std::cout << "erase -> {" << (int)first->first << "} ou ["<< first->first <<"]" << std::endl;
					erase(first);
					first = tmp;
					i++;
				}
				if (_lower == findmn(first))
						delete _lower;
				return first;
			}

			iterator	find(const key_type &k)
			{
				if (_n < 1)
					return end();
				iterator findo = begin();
				while (findo->first != k && findo != end())
					findo++;
				return (findo);
			}
			const_iterator	find(const key_type &k) const
			{
				if (_n < 1)
					return end();
				iterator findo = begin();
				while (findo != end() && findo->first != k )
					findo++;
				return (findo);
			}

			allocator_type	get_allocator() const
			{
				return _alloc;
			}
			
			pair<iterator, bool>	insert(const value_type &val)
			{

				Mapnode		*node = _top;
				Mapnode		*leaf = NULL;
				if (_n == 0)
				{
					_top = new Mapnode(val);
					_upper = _top;
					_lower = _top;
					_end = new Mapnode;
					_top->right = _end;
					_upper->right = _end;
					_n++;
					return make_pair(iterator(_top), true);
				}
				else if (node->elem.first == val.first)
				{
					node->elem.second = val.second;
					return (make_pair(iterator(node), false));
				}
				else if (_top == _lower && 	value_comp()(val, node->elem))
				{
					leaf = new Mapnode(val, _top);
						_top->left = leaf;
						_lower = leaf;
				}
				else if (_top == _upper && 	!value_comp()(val, node->elem))
				{
					leaf = new Mapnode(val, _top);
						_top->right = leaf;
						_upper = leaf;
				}
				else
				{
					for (size_type i = 0; i < _n; i++)
					{
						if (node->elem.first == val.first)
						{
							node->elem.second = val.second;
							return (make_pair(iterator(node), false));
						}
						if (value_comp()(val, node->elem))
						{
							if (node->left)
								node = node->left;
							else
							{
								leaf =	new Mapnode(val, node);
								if (node == _lower)
								{
									_lower->left = leaf;
									_lower = leaf;
								}
								node->left = leaf;
								break;
							}
						}
						else
						{
							if (node->right && node->right != _end)
							{
								node = node->right;
							}
							else
							{
								leaf = new Mapnode(val, node);
								if (node == _upper)
								{
									_upper->right = leaf;
									_upper = leaf;
								}
								node->right = leaf;
								break;
							}
						}
					}
				}
					_n++;
			_end->parent = _upper;
			_upper->right = _end;
	//			print();
				return make_pair(iterator(leaf), true);
			}
			iterator		insert(iterator pos, const value_type &val)
			{
				insert(val);
				return pos;
			}
			template <class InputIt>
			void	insert(InputIt first, InputIt last,
					typename InputIt::difference_type * = NULL)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}
			
			key_compare	key_comp() const
			{
				return (_key_compare);
			}

			
			iterator	lower_bound(const key_type &k)
			{
				iterator	check = find(k);

				if (check == end())
					return check;
				return check;
			}
			const_iterator	lower_bound(const key_type &k) const
			{
				iterator	check = find(k);

				if (check == end())
					return check;
				return check;
			}

			size_type			max_size(void) const
			{
				return (ULONG_MAX / sizeof(Mapnode));
			}

					//constuteur = / []
			map			&operator=(const map &copy)
			{
				clear();
				if (copy.size() != 0)
					insert(copy.begin(), copy.end());
				return *this;
			}
			mapped_type	&operator[](const key_type &k)
			{
				iterator	check = find(k);

				if (check != end())
					return check->second;
				pair<iterator,bool> ret = insert(make_pair(k,mapped_type()));
				return ret.first->second;
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
				return reverse_iterator(_lower);
			}
			reverse_const_iterator	rend() const
			{
				return reverse_iterator(_lower);
			}
			
			size_type	size() const
			{
				return _n;
			}
			
			void	swap(map &x)
			{
				size_type tmpn;
				key_compare tmpk;
				Mapnode		*tmpm;

				tmpn = _n;
				_n = x._n;
				x._n = tmpn;
				tmpk = _key_compare;
				_key_compare = x._key_compare;
				x._key_compare = tmpk;
				tmpm = _lower;
				_lower = x._lower;
				x._lower = tmpm;
				tmpm = _upper;
				_upper = x._upper;
				x._upper = tmpm;
			}
		
			iterator		upper_bound(const key_type &k)
			{
				iterator	check = find(k);

				if (check == end())
					return check;
				check++;
				return check;
			}
			const_iterator	upper_bound(const key_type &k) const
			{
				iterator	check = find(k);

				if (check == end())
					return check;
				check++;
				return check;
			}

			value_compare	value_comp() const
			{
				return(value_compare(_key_compare));
			}

};
	template <class Key, class T, class Compare = less<Key> , class Alloc>
		bool		operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			for (typename ft::map<Key, T>::iterator l = lhs.begin(), r = rhs.begin();
					l != lhs.end() ; l++, r++)
				if (*l != *r)
					return (false);
			return (true);
		}

	template <class Key, class T, class Compare = less<Key> , class Alloc>
		bool		operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

	template <class Key, class T, class Compare = less<Key> , class Alloc>
		bool		operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
		{
			if (lhs == rhs)
				return (false);
			for (typename ft::map<Key, T>::iterator l = lhs.begin(), r = rhs.begin();
					l != lhs.end(); l++, r++)
			{
				if (*l < *r)
					return (true);
				if (*l > *r)
					return (false);
			}
			return (false);
		}

	template <class Key, class T, class Compare = less<Key> , class Alloc>
		bool		operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
		{
			return (rhs < lhs);
		}

	template <class Key, class T, class Compare = less<Key> , class Alloc>
		bool		operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
		{
			if (lhs == rhs)
				return (true);
			return (!(rhs < lhs));
		}

	template <class Key, class T, class Compare = less<Key> , class Alloc>
		bool		operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

	template <class Key, class T, class Compare = less<Key> , class Alloc>
		void		swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
		{
			x.swap(y);
		}
}
#endif
