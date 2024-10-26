/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:10:32 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/27 00:05:32 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int	main( void ) {
	{ // Overflow test
		std::cout << std::endl << INVERT << "Overflow" << RESET << std::endl;
		try {
			Span	overflow(3);

			overflow.addNumber(5);
			overflow.addNumber(4);
			overflow.addNumber(3);
			std::cout << overflow << std::endl;
			overflow.addNumber(2);
		}
		catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }
	}
	{ // Empty Test
		std::cout << std::endl << INVERT << "Empty" << RESET << std::endl;
		Span	empty;

		std::cout << empty << std::endl;
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
	{ // Add too many test
		std::cout << std::endl << INVERT << "Adding too many" << RESET << std::endl;
		try {
			std::cout << "Adding more than cap: ";
			Span notenough(5);

			notenough.addMany(6);
		}
		catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }
		try {
			Span almostfull(5);

			std::cout << YELLOW;
			almostfull.addNumber(1);
			std::cout << RESET << "Adding more than there's left: ";
			almostfull.addMany(5);
		}
		catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }
	}
	{ // 20 test
		std::cout << std::endl << INVERT << "20 test" << RESET << std::endl;
		std::vector<int>	vect;
		Span				spa(20);

		for (size_t i = 0; i < 20; i++)
			vect.push_back(rand() % 20);

		spa.addRange(vect.begin(), vect.end());

		std::cout << spa << std::endl;
		std::cout << "Size = " << spa.getSize() << std::endl;
		std::cout << "ShortestSpan = " << spa.shortestSpan() << std::endl;
		std::cout << "LongestSpan = " << spa.longestSpan() << std::endl;
	}
	{ // 10K test
		std::cout << std::endl << INVERT << "10k test (AddMany)" << RESET << std::endl;
		Span	spa(10000);

		spa.addMany(10000);

		std::cout << "Size = " << spa.getSize() << std::endl;
		std::cout << "ShortestSpan = " << spa.shortestSpan() << std::endl;
		std::cout << "LongestSpan = " << spa.longestSpan() << std::endl;
	}
	{ // 50K test
		std::cout << std::endl << INVERT << "50k test(AddRange)" << RESET << std::endl;
		std::vector<int>	vect(50000);
		Span				spa(50000);

		srand(time(0));

		std::generate(vect.begin(), vect.end(), rand);
		spa.addRange(vect.begin(), vect.end());

		std::cout << "Size = " << spa.getSize() << std::endl;
		std::cout << "ShortestSpan = " << spa.shortestSpan() << std::endl;
		std::cout << "LongestSpan = " << spa.longestSpan() << std::endl;
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
}