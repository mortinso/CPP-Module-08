/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:46:52 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/27 19:51:11 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>

# define BOLD "\e[1m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define RED "\e[91m"
# define GREEN "\e[92m"
# define YELLOW "\e[93m"
# define BLUE "\e[94m"
# define PURPLE "\e[95m"
# define CYAN "\e[96m"
# define INVERT "\e[90m\e[107m"
# define RESET "\e[0m"

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		// Constructors
		MutantStack<T>( void );
		MutantStack<T>( const MutantStack &_mutantstack );

		// Destructor
		~MutantStack<T>( void );

		// Operator overloads
		MutantStack<T> &operator = ( const MutantStack<T> &_mutantstack );

		typedef typename std::deque<T>::iterator iterator;

		// Methods
		iterator begin( void );
		iterator end( void );

		// Exceptions
};

# include "MutantStack.tpp"

#endif
