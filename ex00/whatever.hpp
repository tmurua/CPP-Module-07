/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 21:17:47 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/22 22:09:12 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// template function to exchange 2 values (a and b) of the same type
template <typename ValueType>
void	swap(ValueType &a, ValueType &b){
	ValueType temp = a;

	a = b;
	b = temp;
}

// template function to return smaller of 2 values (a and b) of the same type
template <typename ValueType>
const ValueType	&min(const ValueType &a, const ValueType &b){
	if (a < b)
		return (a);
	return (b);
}

// template function to return greater of 2 values (a and b) of the same type
template <typename ValueType>
const ValueType	&max(const ValueType &a, const ValueType &b){
	if (a > b)
		return (a);
	return (b);
}

#endif
