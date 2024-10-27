/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:31:08 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/27 23:09:16 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

template<typename T>
void	ft_cout( T container ) {
	std::cout << " = { ";
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << ", ";
	std::cout << "}" << std::endl;
}

template<typename T>
void	routine( T container ) {
	for (int i = 0; i < 5; i++)
		container.push_back(i);

	ft_cout(container);

	// easyfind(container, 5);
	// easyfind(container, 2);
	std::cout << "5: " << (easyfind(container, 5) == true ? "Found" : "Not Found") << std::endl;
	std::cout << "4: " << (easyfind(container, 4) == true ? "Found" : "Not Found") << std::endl;
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
	{ // Char list test
		std::cout << std::endl << INVERT << "Char list" << RESET;
		std::list<char>	char_lst;

		for (int i = 0; i < 5; i++)
			char_lst.push_back(97 + i);

		ft_cout(char_lst);

		easyfind(char_lst, 104);
		easyfind(char_lst, 98);
	}
}