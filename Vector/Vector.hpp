/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:48:01 by chgilber          #+#    #+#             */
/*   Updated: 2021/04/14 13:08:35 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cstddef> //ptrdiff_t
#include <climits> // sizemax
#include <stdexcept>
#include "Iterator.hpp"
#include "ReverseIterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
		typedef T									value_type;
		typedef Alloc								allocator_type;
		typedef T									&reference;
		typedef const T								&const_reference;
		typedef T									*pointer;
		typedef const T								*const_pointer;
		typedef Iterator<value_type>				iterator;
		typedef const Iterator<value_type>			const_iterator;
		typedef ReverseIterator<value_type>			reverse_iterator;
		typedef const ReverseIterator<value_type>	reverse_const_iterator;
		typedef	ptrdiff_t							difference_type;
		typedef	size_t								size_type;
		
		private:
				allocator_type	_alloc;
				size_type	_n;
				size_type	_ncapacity;
				pointer		_value;
	
		public:
			//construteur par defaut
			vector(const allocator_type &a = allocator_type()): _alloc(a), 
			_n(0), _ncapacity(0), _value(NULL) {}
			//construteur fill
			vector(size_type n, const value_type &v = value_type(),
				const allocator_type &a = allocator_type()):
				_alloc(a) ,_n(0), _ncapacity(0), _value(NULL)
			{
				assign(n, v);
			}
			//construteur copy
			vector(const vector &copy): 			_alloc(copy._alloc), _n(0), _ncapacity(0),
_value(NULL)
			{
				for (size_t i = 0; i < copy._n; i++)
					push_back(copy._value[i]);
			}
			//construteur range
			template <class InputIt>
				vector(InputIt first, InputIt last,
					const allocator_type &a = allocator_type(),
					typename InputIt::difference_type * = NULL): _alloc(a),
					_n(0), _ncapacity(0), _value(NULL)
				{
				assign(first, last);
				}
				//destructeur
			~vector()
			{
				clear();
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last,
					typename InputIt::difference_type * = NULL)
			{
				clear();
				while(first < last)
				{
					push_back(*first);
					first++;
				}
			}
			void	assign(size_type n, const value_type &v)
			{
				clear();
				for (size_t i = 0; i < n; i++)
					push_back(v);
			}

			reference			at(size_type n)
			{
				if (n >= _n)
					throw std::out_of_range("out_of_range");
				return _value[n];
			}
			const_reference		at(size_type n) const
			{
				if (n >= _n)
					throw std::out_of_range("out_of_range");
				return _value[n];
			}
			
			reference			back()
			{
				return _value[_n - 1];
			}
			const_reference		back() const
			{
				return _value[_n - 1];
			}

			//function vector in alpha order
			iterator		begin()
			{
				return (iterator(_value));
			}
			const_iterator	begin() const
			{
				return (iterator(_value));
			}


			size_type	capacity() const
			{
				return _ncapacity;
			}

			void	clear()
			{
				if (_value != NULL)
				{
					_alloc.destroy(_value);
					_alloc.deallocate(_value, _ncapacity);
				}
				_value = NULL;
				_n = 0;
				_ncapacity = 0;
			}

			bool	empty() const
			{
				return _n > 0 ? false : true;
			}

			iterator		end()
			{
				return iterator(_value + _n);
			}
			const_iterator	end() const
			{
				return iterator(_value + _n);
			}


			iterator	erase(iterator position)
			{
				pointer		tmp;
				int			i = 0;

				tmp = _alloc.allocate(_ncapacity);
				iterator it = begin();
				while (it < position)
					_alloc.construct(&tmp[i++], *it++);
				while (++it < end())
					_alloc.construct(&tmp[i++], *it);
				_alloc.destroy(_value);
				_alloc.deallocate(_value, _ncapacity);
				_n--;
				_value = tmp;
				return position;
			}
			iterator	erase(iterator first, iterator last)
			{
				pointer		tmp;
				int			pos, pose, i = 0;

				tmp = _alloc.allocate(_ncapacity);
				iterator it = begin();
				while (it < first)
					_alloc.construct(&tmp[i++], *it++);
				pos = i;
				pose = pos;
				while (it < last)
				{
					it++;
					pose++;
				}
				while (it < end())
					_alloc.construct(&tmp[i++], *it++);
				_alloc.destroy(_value);
				_alloc.deallocate(_value, _ncapacity);
				_n = _n + pos - pose;
				_value = tmp;
				return last;
			}

			reference		front()
			{
				return _value[0];
			}
			const_reference	front() const
			{
				return _value[0];
			}

			allocator_type	get_allocator() const
			{
				return _alloc;
			}
			
			iterator		insert(iterator pos, const value_type &val)
			{
				pointer		tmp;
				iterator	npos;
				int			nposi, i = 0;

				tmp = _alloc.allocate(_n == _ncapacity ? _n * 2 : _ncapacity);
				_ncapacity = _n == _ncapacity ? _n * 2 : _ncapacity;
				iterator it = begin();
				while (it < pos)
					_alloc.construct(&tmp[i++], *it++);
				_alloc.construct(&tmp[i++], val);
				nposi = i - 1;
				while (it < end())
					_alloc.construct(&tmp[i++], *it++);
				_alloc.destroy(_value);
				_alloc.deallocate(_value, _ncapacity);
				_n++;
				_value = tmp;
				npos = begin();
				for (int j = 0; j < nposi; j++)
					npos++;
				return npos;
			}
			void		insert(iterator pos,size_type n, const value_type &val)
			{
				pointer		tmp;
				int			i = 0;

				tmp = _alloc.allocate(_n + n > _ncapacity ? _n * 2 : _ncapacity);
				_ncapacity = _n + n  >  _ncapacity ? (_n + n) * 2 : _ncapacity;
				iterator it = begin();
				while (it < pos)
					_alloc.construct(&tmp[i++], *it++);
				for (size_type s = 0; s < n ; s++)
					_alloc.construct(&tmp[i++], val);
				while (it < end())
					_alloc.construct(&tmp[i++], *it++);
				_alloc.destroy(_value);
				_alloc.deallocate(_value, _ncapacity);
				_n = _n + n;
				_value = tmp;
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
					//constuteur =
			vector&	operator=(const vector &copy)
			{
				clear();
				_alloc = copy._alloc;
				if (copy._ncapacity != 0)
					reserve(copy._ncapacity);
				if (copy.size() != 0)
					assign(copy.begin(), copy.end());
				return *this;
			}

			reference	operator[](size_type n)
			{
				return _value[n];
			}
			const_reference	operator[](size_type n) const
			{
				return _value[n];
			}

			void	pop_back()
			{
				_alloc.destroy(&back());
				_n--;
			}

			void	push_back(const value_type	&val)
			{
				if (_n >= _ncapacity)
					reserve(((_n == 0) ? 1 : _n) * 2);
				_alloc.construct(&_value[_n], val);
				_n++;
			}

			reverse_iterator		rbegin()
			{
				return reverse_iterator(_value + _n);
			}
			reverse_const_iterator	rbegin() const
			{
				return reverse_iterator(_value + _n);
			}

			reverse_iterator		rend()
			{
				return reverse_iterator(_value);
			}
			reverse_const_iterator	rend() const
			{
				return reverse_iterator(_value);
			}

			void	reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("Reservation exceeds max size");
				if (_value == NULL)
				{
					_value = _alloc.allocate(n);
					_ncapacity = n;
					return ;
				}
				pointer		tmp;
				tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _n; i++)
					_alloc.construct(&tmp[i], _value[i]);
				_alloc.destroy(_value);
				_alloc.deallocate(_value, _ncapacity);
				_value = NULL;
				_ncapacity = n;
				_value = tmp;
			}

			void	resize(size_type n, value_type val = value_type())
			{
				while (n > _n)
					push_back(val);
				while (n < _n)
					pop_back();
			}

			size_type	size() const
			{
				return _n;
			}

			void	swap(vector &x)
			{
				vector<T>	tmp;
				tmp = x;
				x = *this;
				*this = tmp;
			}
			};
	template <class T, class Alloc>
		bool		operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			for (typename ft::vector<T>::iterator l = lhs.begin(), r = rhs.begin();
					l != lhs.end() ; l++, r++)
				if (*l != *r)
					return (false);
			return (true);
		}

	template <class T, class Alloc>
		bool		operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

	template <class T, class Alloc>
		bool		operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs == rhs)
				return (false);
			for (typename ft::vector<T>::iterator l = lhs.begin(), r = rhs.begin();
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
		bool		operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}

	template <class T, class Alloc>
		bool		operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs == rhs)
				return (true);
			return (!(rhs < lhs));
		}

	template <class T, class Alloc>
		bool		operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

	template <class T, class Alloc>
		void		swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
}
#endif
