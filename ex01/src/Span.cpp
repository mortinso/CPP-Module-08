/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:10:37 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/27 00:05:37 by mortins-         ###   ########.fr       */
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

int Span::operator [] ( unsigned int index ) const{
	if (cap == 0 || index >= vect.max_size())
		throw (OutOfRange());
	return (vect[index]);
}

std::ostream& operator << (std::ostream &out, const Span &span)
{
	out << "Span = { ";
	for (size_t i = 0; i < span.getSize(); i++)
		std::cout << span[i] << ", ";
	out << "}";
	return out;
}

// -----------------------------------Getters-----------------------------------

size_t	Span::getCap( void ) const {
	return (cap);
}

size_t	Span::getSize( void ) const {
	return (vect.size());
}

// -----------------------------------Methods-----------------------------------
void	Span::addNumber( int num ) {
	if (vect.size() == cap)
		throw (FullContainer());

	std::cout << "Adding " << num << std::endl;
	vect.push_back(num);
}

void	Span::addMany( size_t n ) {
	if (n > (cap - vect.size()))
		throw(TooMany());

	srand(time(0));

	std::vector<int>	tmp(n);
	std::generate(tmp.begin(), tmp.end(), rand);

	std::cout << "Adding " << n << " random numbers" << std::endl;

	vect.insert(vect.end(), tmp.begin(), tmp.end());
}

void	Span::addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {
	if (vect.size() == cap || (std::distance(begin, end)) > (long)(cap - vect.size()))
		throw(TooMany());

	vect.insert(vect.end(), begin, end);
}

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
	return ("Can't add more");
}

const char *Span::NoSpan::what( void ) const throw() {
	return ("Not enough numbers to calculate span (min: 2)");
}

const char *Span::TooMany::what( void ) const throw() {
	return ("Span does not have enough space to add that many");
}