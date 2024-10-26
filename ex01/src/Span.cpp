/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:10:37 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/26 22:46:05 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

// Default constructor
Span::Span( void ) : cap(0) {
	// std::cout << "Span default constructor called" <<std::endl;
}

// Constructor
Span::Span( size_t _cap ) : cap(_cap){
	// std::cout << "Span default constructor called" <<std::endl;
}

// Copy constructor
Span::Span( const Span &_span ) {
	// std::cout << "Span copy constructor called" << std::endl;
	cap = _span.cap;

	if (!_span.vect.empty())
	{
		for (size_t i = 0; i < _span.vect.size(); i++)
			this->vect.push_back(_span.vect[i]);
	}
}

// Destructor
Span::~Span( void ) {
	// std::cout << "Span destructor called" <<std::endl;
}

// -----------------------------------Operators---------------------------------
// Copy assignment operator overload
Span& Span::operator = ( const Span &_span ) {
	// std::cout << "Span copy assignment operator called" << std::endl;
	vect.clear();

	cap = _span.cap;

	if (!_span.vect.empty()) {
		for (size_t i = 0; i < _span.vect.size(); i++)
			this->vect.push_back(_span.vect[i]);
	}
	return (*this);
}

int Span::operator [] ( unsigned int index ) {
	if (cap == 0 || index >= vect.max_size())
		throw (OutOfRange());
	return (vect[index]);
}

// -----------------------------------Getters-----------------------------------

size_t	Span::getCap( void ) const {
	return (cap);
}

// -----------------------------------Methods-----------------------------------
void	Span::addNumber(int num) {
	if (vect.size() == cap)
		throw (FullContainer());

	std::cout << "Adding " << num << std::endl;
	vect.push_back(num);
}

//void	addRange(iterator begin, iterator end);

unsigned int	Span::shortestSpan( void ) const {
	if (vect.size() <= 1)
		throw (NoSpan());
	std::vector<int> copy = vect;
	sort(copy.begin(), copy.end());

	// accept repeated numbers in span?
	// if not use unique()

	int	tmp = copy[1] - copy[0];
	for (size_t i = 0; i < (copy.size() - 1); i++) {
		if ((copy[i + 1] - copy[i]) < tmp)
			tmp = copy[i + 1] - copy[i];
	}
	return (tmp);
}

unsigned int	Span::longestSpan( void ) const {
	if (vect.size() <= 1)
		throw (NoSpan());
	std::vector<int> copy = vect;
	sort(copy.begin(), copy.end());

	return (copy.back() - copy.front());
}

// -----------------------------------Exceptions--------------------------------
const char *Span::OutOfRange::what( void ) const throw() {
	return ("Index out of range");
}

const char *Span::FullContainer::what( void ) const throw() {
	return ("Object is already full");
}

const char *Span::NoSpan::what( void ) const throw() {
	return ("Not enough numbers to calculate span (min: 2)");
}