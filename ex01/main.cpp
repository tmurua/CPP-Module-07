/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 22:50:40 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/22 22:50:47 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// template function to print a value without changing it (const reference)
template <typename ValueType>
void	printValue(const ValueType &value){
	std::cout << value << std::endl;
}

// template function to double a value by changing it (non-const reference) 
template <typename ValueType>
void	doubleValue(ValueType &value){
	value = value + value;
}

int	main(void){
	int			numbers[3] = {1, 2, 3};
	std::string	letters[3] = {"a", "b", "c"};
	const int	constNumbers[3] = {10, 20, 30};

	std::cout << "numbers before doubleValue:" << std::endl;
	iter(numbers, 3, printValue<int>);

	iter(numbers, 3, doubleValue<int>);

	std::cout << "numbers after doubleValue:" << std::endl;
	iter(numbers, 3, printValue<int>);

	std::cout << std::endl;

	std::cout << "letters before doubleValue:" << std::endl;
	iter(letters, 3, printValue<std::string>);

	iter(letters, 3, doubleValue<std::string>);

	std::cout << "letters after doubleValue:" << std::endl;
	iter(letters, 3, printValue<std::string>);

	std::cout << std::endl;

	std::cout << "print const numbers:" << std::endl;
	iter(constNumbers, 3, printValue<int>);

	return (0);
}
