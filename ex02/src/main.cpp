/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:46:55 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/27 21:23:30 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <list>

int	main( void ) {
	{ //std::sort
		std::cout << INVERT << "std::sort" << RESET << std::endl;
		MutantStack<int> mstack;

		for (int i = 0; i < 8; i++)
			mstack.push(8 - i);

		std::cout << UNDERLINE << "Before" << RESET << "= { ";
		MutantStack<int>::iterator it = mstack.begin();
		while (it != mstack.end())
		{
			std::cout << *it << ", ";
			++it;
		}
		std::cout << "}" << std::endl << std::endl;

		std::cout << YELLOW << "Sorting..." << RESET << std::endl << std::endl;
		std::sort(mstack.begin(), mstack.end());

		std::cout << UNDERLINE << "After" << RESET << "= { ";
		it = mstack.begin();
		while (it != mstack.end())
		{
			std::cout << *it << ", ";
			++it;
		}
		std::cout << "}" << std::endl;
	}
	{ // std::count
		std::cout << std::endl << INVERT << "std::count" << RESET << std::endl;
		MutantStack<int> mstack;

		for (int i = 0; i < 8; i++)
			mstack.push(i % 2);

		std::cout << "0: " << std::count(mstack.begin(), mstack.end(), 0) << std::endl;
		std::cout << "1: " << std::count(mstack.begin(), mstack.end(), 1) << std::endl;
		std::cout << "2: " << std::count(mstack.begin(), mstack.end(), 2) << std::endl << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		std::cout << UNDERLINE << "mstack" << RESET << "= { ";
		while (it != mstack.end())
		{
			std::cout << *it << ", ";
			++it;
		}
		std::cout << "}" << std::endl;
	}
	{ // Subject test (original)
		std::cout << std::endl << INVERT << "Subject test (original)" << RESET << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{ // Subject test (list)
		std::cout << std::endl << INVERT << "Subject test (list)" << RESET << std::endl;
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}