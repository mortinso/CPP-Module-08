/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:29:06 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/27 23:07:42 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template<typename T>
bool	easyfind( T container, int obj ) {
	typename T::iterator it;
	try {
		it = find(container.begin(), container.end(), obj);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return false;
	}

	if (it == container.end()) {
		// std::cout << obj << ": " << RED << "NOT found" << RESET << std::endl;
		return false;
	}

	// std::cout << obj << ": " << GREEN << "Found" << RESET << std::endl;
	return true;
}

#endif