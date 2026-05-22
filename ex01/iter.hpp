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

// template function to apply one function to every element of an array
template <typename ElementType, typename FunctionType>
void	iter(ElementType *array, const unsigned int length, FunctionType function){
	unsigned int index = 0;

	while (index < length){
		function(array[index]);
		index++;
	}
}

#endif
