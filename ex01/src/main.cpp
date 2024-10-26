/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:10:32 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/26 22:47:39 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int	main( void ) {
	{ // 10K test

	}
	{ // 100K test

	}
	{ // Overflow test
		std::cout << std::endl << INVERT << "Overflow test" << RESET << std::endl;
		try {
			Span	overflow(3);

			overflow.addNumber(5);
			overflow.addNumber(4);
			overflow.addNumber(3);
			overflow.addNumber(2);
		}
		catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }
	}
	{ // Empty Test
		std::cout << std::endl << INVERT << "Empty test" << RESET << std::endl;
		Span	empty;

		try {
			empty.addNumber(6);
		}
		catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

		try {
			std::cout << empty[0] << std::endl;
		}
		catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

		try {
			std::cout << empty.shortestSpan() << std::endl;
		}
		catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

		try {
			std::cout << empty.longestSpan() << std::endl;
		}
		catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }
	}
	{ // Subject Test
		std::cout << std::endl << INVERT << "Subject test" << RESET << std::endl;
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl << YELLOW << "Add addRange()" << RESET << std::endl;
}

// Add addRange()