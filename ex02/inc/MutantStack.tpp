/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:46:22 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/27 20:47:20 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Default constructor
template <typename T>
MutantStack<T>::MutantStack( void ) {
}

// Copy constructor
template <typename T>
MutantStack<T>::MutantStack( const MutantStack &_mutantstack ) {
	*this = _mutantstack;
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack( void ) {
}

// -----------------------------------Operators---------------------------------
// Copy assignment operator overload
template <typename T>
MutantStack<T> &MutantStack<T>::operator = ( const MutantStack<T> &_mutantstack ) {
	if (*this != _mutantstack)
		*this = _mutantstack;
	return (*this);
}

// -----------------------------------Methods-----------------------------------
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void ) {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( void ) {
	return (this->c.end());
}