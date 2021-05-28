/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_Bidirectional_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:29:35 by chgilber          #+#    #+#             */
/*   Updated: 2021/04/16 18:02:32 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_BIDIRECTIONAL_ITERATOR_HPP
# define REVERSE_BIDIRECTIONAL_ITERATOR_HPP

#include <iostream>
#include <cstddef> //ptrdiff_t
#include "Bidirectional_iterator.hpp"

namespace ft
{
	template <typename T>
	class Reverse_Bidirectional_Iterator
	{
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef	T									&reference;
			typedef const T								&const_reference;
			typedef T									*pointer;
			typedef	ptrdiff_t							difference_type;
			typedef size_t								size_type;

		private:
			l_list<T>										*_ptr;
			typedef Reverse_Bidirectional_Iterator			self;

		public:
			Reverse_Bidirectional_Iterator() {}

			Reverse_Bidirectional_Iterator(l_list<T> *other): _ptr(other) {}

			Reverse_Bidirectional_Iterator(Reverse_Bidirectional_Iterator *other)
			{
				this->_ptr = other->_ptr;
			}

			~Reverse_Bidirectional_Iterator() {}

			Reverse_Bidirectional_Iterator		&operator=(self const &it)
			{
				_ptr = it._ptr;
				return (*this);
			}
			//crementation
			self	operator++()
			{
				_ptr = _ptr->bef;
				return *this;
			}
			self	operator++(int)
			{
				self	tmp = *this;
				_ptr = _ptr->bef;
				return tmp;
			}

			self	operator--()
			{
				_ptr = _ptr->next;
				return *this;
			}
			self	operator--(int)
			{
				self	tmp = *this;
				_ptr = _ptr->next;
				return tmp;
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
			//reference and pointer
			reference	operator*()
			{
				return _ptr->value;
			}

			const_reference	operator*()const
			{
				return _ptr->value;
			}

			reference	operator->()
			{
				return &_ptr->value;
			}
	};
}

#endif
