/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 22:40:23 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/22 22:40:42 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

// template function to apply a function to every element of an array
// ElementType keeps the whole element type, including const if the array is const
// FunctionType lets iter accept functions with const ref or non-const ref parameter
template <typename ElementType, typename FunctionType>
void	iter(ElementType *array, const unsigned int length, FunctionType function){
	unsigned int i = 0;

	while (i < length){
		function(array[i]);
		i++;
	}
}

#endif
