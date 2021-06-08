/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_Bidirectional_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:29:35 by chgilber          #+#    #+#             */
/*   Updated: 2021/06/04 17:01:25 by chgilber         ###   ########.fr       */
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
			typedef	Mapnode<T>						node;
			node										*_ptr;
			typedef Reverse_Bidirectional_Iterator			self;

		public:
			Reverse_Bidirectional_Iterator(): _ptr(NULL) {}

			Reverse_Bidirectional_Iterator(node *other): _ptr(other) {}

			Reverse_Bidirectional_Iterator(self *other) :_ptr(other->_ptr) {}

			~Reverse_Bidirectional_Iterator() {}

			Reverse_Bidirectional_Iterator		&operator=(self const &it)
			{
				_ptr = it._ptr;
				return (*this);
			}
			//crementation
			self	operator++()
			{
				if (_ptr->left)
				{
					_ptr = _ptr->left;
					while (_ptr->right)
						_ptr = _ptr->right;
				}
				else if (_ptr->parent)
						_ptr = _ptr->parent;
				return *this;
			}
			self	operator++(int)
			{
				self	tmp = *this;
				if (_ptr->left)
				{
					_ptr = _ptr->left;
					while (_ptr->right)
						_ptr = _ptr->right;
				}
				else if (_ptr->parent)
						_ptr = _ptr->parent;
				return tmp;
			}

			self	operator--()
			{
				if (_ptr->right)
				{
					_ptr = _ptr->right;
					while (_ptr->left)
						_ptr = _ptr->left;
				}
				else
				{
					node	*tmp = _ptr;
					_ptr = _ptr->parent;
					while (_ptr->parent && tmp == _ptr->right)
					{
						tmp = _ptr;
						_ptr = _ptr->parent;
					}
				}
				return *this;
			}
			self	operator--(int)
			{
				self	tmp = *this;
				if (_ptr->right)
				{
					_ptr = _ptr->right;
					while (_ptr->left)
						_ptr = _ptr->left;
				}
				else
				{
					node	*tmp = _ptr;
					_ptr = _ptr->parent;
					while (_ptr->parent && tmp == _ptr->right)
					{
						tmp = _ptr;
						_ptr = _ptr->parent;
					}
				}
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
			value_type	operator*()
			{
				return _ptr->elem;
			}

			pointer	operator->()
			{
				return &_ptr->elem;
			}
	};
}

#endif
