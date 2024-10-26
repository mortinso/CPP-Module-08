/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:10:27 by mortins-          #+#    #+#             */
/*   Updated: 2024/10/26 22:36:42 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

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

class Span {
	private:
		size_t				cap;
		std::vector<int>	vect;

	public:
		// Constructors
		Span( void );
		Span( size_t _cap );
		Span( const Span &_span );

		// Destructor
		~Span( void );

		// Operator overloads
		Span &operator = ( const Span &_span );
		int operator [] ( unsigned int n );

		// Getters
		size_t	getCap( void ) const;

		// Methods
		void			addNumber(int num);
		//void			addRange(iterator begin, iterator end);
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;

		// Exceptions
		class OutOfRange : public std::exception {
			public:
				const char *what( void ) const throw();
		};

		class FullContainer : public std::exception {
			public:
				const char *what( void ) const throw();
		};

		class NoSpan : public std::exception {
			public:
				const char *what( void ) const throw();
		};
};

#endif
