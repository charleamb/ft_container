/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:29:35 by chgilber          #+#    #+#             */
/*   Updated: 2021/04/12 17:30:27 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>

namespace ft
{
	template <typename T>
	class Iterator
	{
		public:
			typedef std::random_access_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	T									&reference;
			typedef const T								&const_reference;
			typedef T									*pointer;
			typedef	ptrdiff_t							difference_type;
			typedef size_t								size_type;

		private:
			pointer						_ptr;
			typedef Iterator			self;

		public:
			Iterator() {}

			Iterator(pointer other): _ptr(other) {}

			Iterator(Iterator *other)
			{
				this->_ptr = other->_ptr;
			}

			~Iterator() {}

			Iterator		&operator=(self const &it)
			{
				_ptr = it._ptr;
				return (*this);
			}
			//crementation
			self	operator++()
			{
				++_ptr;
				return *this;
			}
			self	operator++(int)
			{
				self	tmp = *this;
				++_ptr;
				return tmp;
			}
			self	operator+=(size_type nb)
			{
				_ptr += nb;
				return *this;
			}

			self	operator--()
			{
				--_ptr;
				return *this;
			}
			self	operator--(int)
			{
				self	tmp = *this;
				--_ptr;
				return tmp;
			}
			self	operator-=(size_type n)
			{
				_ptr -= n;
				return *this;
			}
			//arithmetique
			self	operator-(difference_type n)
			{
				return _ptr - n;
			}

			self	operator+(difference_type n)
			{
				return _ptr + n;
			}

			self	operator-(self &other)
			{
				return _ptr - other._ptr;
			}

			self	operator+(self &other)
			{
				return (_ptr + other._ptr);
			}
			//bool
			bool	operator==(self const &other)
			{
				return (_ptr == other._ptr);
			}
			bool	operator!=(self const &other)
			{
				return (_ptr != other._ptr);
			}
			bool	operator<(self const &other)
			{
				return (_ptr < other._ptr);
			}
			bool	operator>(self const &other)
			{
				return (_ptr > other._ptr);
			}
			bool	operator>=(self const &other)
			{
				return (_ptr >= other._ptr);
			}
			bool	operator<=(self const &other)
			{
				return (_ptr <= other._ptr);
			}
			//reference and pointer
			reference	operator*()
			{
				return *_ptr;
			}

			const_reference	operator*()const
			{
				return *_ptr;
			}

			reference	operator->()
			{
				return _ptr;
			}

			reference	operator[](size_type n)
			{
				return *(_ptr + n);
			}
			const_reference operator[](size_type n) const
			{
				return *(_ptr + n);
			}
	};
}

#endif
