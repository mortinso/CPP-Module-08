/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:31:08 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/26 17:57:08 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

template<typename T>
void	routine( T container ) {
	for (int i = 0; i < 5; i++)
		container.push_back(i);

	std::cout << " = { ";
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << ", ";
	std::cout << "}" << std::endl;

	easyfind(container, 5);
	easyfind(container, 2);
}

int	main( void ) {
	{ // Vector test
		std::cout << INVERT << "Vector" << RESET;
		std::vector<int>	vect;
		routine(vect);
	}
	{ // Deque Test
		std::cout << std::endl << INVERT << "Deque" << RESET;
		std::deque<int>	dq;
		routine(dq);
	}
	{ // List Test
		std::cout << std::endl << INVERT << "List" << RESET;
		std::list<int> 	lst;
		routine(lst);
	}
}