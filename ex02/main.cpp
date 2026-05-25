/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:11:23 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/25 20:53:32 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "Array.hpp"

int main(void){
    try{
		std::cout << "--- Create Array<int> a(3) ---" << std::endl;
        Array<int> a(3);
        std::cout << "a.size(): " << a.size() << std::endl;

        std::cout << "\n--- Write and read values with operator[] ---" << std::endl;
        a[0] = 10;
        a[1] = 20;
        a[2] = 30;
        std::cout << "a[0]: " << a[0] << std::endl;
        std::cout << "a[1]: " << a[1] << std::endl;
        std::cout << "a[2]: " << a[2] << std::endl;

        std::cout << "\n--- Read from const Array ---" << std::endl;
        const Array<int> constA(a);
        std::cout << "constA[2]: " << constA[2] << std::endl;
        // constA[2] = 99; // ERROR: const Array gives read-only access

        std::cout << "\n--- Copy constructor: Array<int> copy(a) ---" << std::endl;
        Array<int> copy(a);
        std::cout << "a[0]:      " << a[0] << std::endl;
		std::cout << "copy[0]:   " << copy[0] << std::endl;
        copy[0] = 100;
		std::cout << "copy[0] = 100;" << std::endl;
        std::cout << "a[0]:      " << a[0] << std::endl;
        std::cout << "copy[0]:  " << copy[0] << std::endl;

        std::cout << "\n--- Assignment operator: assigned = a ---" << std::endl;
        Array<int> assigned;
        assigned = a;
		std::cout << "a[1]:          " << a[1] << std::endl;
		std::cout << "assigned[1]:   " << assigned[1] << std::endl;
        assigned[1] = 200;
		std::cout << "assigned[1] = 200;" << std::endl;
        std::cout << "a[1]:          " << a[1] << std::endl;
        std::cout << "assigned[1]:  " << assigned[1] << std::endl;

        std::cout << "\n--- Out of bounds exception: a[3] ---" << std::endl;
        std::cout << a[3] << std::endl;

    }
    catch (const std::exception& e){
        std::cout << "Exception caught: index is out of bounds" << std::endl;
    }
	
	try{
		std::cout << "\n--- Create Array<std::string> a(3) ---" << std::endl;
        Array<std::string> a(3);
        std::cout << "a.size(): " << a.size() << std::endl;
        std::cout << "\n--- Write and read values with operator[] ---" << std::endl;
        a[0] = "apple";
        a[1] = "banana";
        a[2] = "cherry";
        std::cout << "a[0]: " << a[0] << std::endl;
        std::cout << "a[1]: " << a[1] << std::endl;
        std::cout << "a[2]: " << a[2] << std::endl;
        
		std::cout << "\n--- Out of bounds exception: a[3] ---" << std::endl;
        std::cout << a[3] << std::endl;
	}
    catch (const std::exception& e){
        std::cout << "Exception caught: index is out of bounds" << std::endl;
    }
}
