/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:33:51 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/30 16:20:55 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Fixed.hpp"
#include <iostream>
#include <ostream>

using std::endl;
using std::string;

void	printIncDec(void)
{
	Fixed a(1.2f);
	std::cout << CYAN << "--- " << __FUNCTION__ << " ---" << RESET << endl
				<< RED << "-----BEFORE-----" << YELLOW << "-----INSIDE-----"<< GREEN <<"-----AFTER-----" << RESET << endl
				<< "a = " << a << "\t ++a = " << ++a << "\t a = " << a << endl
				<< "a = " << a << "\t --a = " << --a << "\t a = " << a << endl
				<< "a = " << a << "\t a++ = " << a++ << "\t a = " << a << endl
				<< "a = " << a << "\t a-- = " << a-- << "\t a = " << a << endl
				<< endl;
}

void	printOperation(float res, Fixed a, Fixed b, Fixed c, string sign)
{
	std::cout   << a.toFloat() << sign << b.toFloat()
				<< (res == c.toFloat() ? GREEN " ✓ " : RED " ✗ ")
				<< GREEN "res = " << res << (res == c.toFloat() ? GREEN : RED)
				<< " c = " << c
				<< RESET << endl << endl;
}

void	checkCalcOperator(void)
{
	std::cout << MAGENTA << "--- " << __FUNCTION__ << " ---" << RESET << endl;
	Fixed a(55.6541f), b(5.1f), c(a + b);
	float res = a.toFloat() + b.toFloat();
	printOperation(res, a, b, c, " + ");
	res = a.toFloat() - b.toFloat();
	c = a - b;
	printOperation(res, a, b, c, " - ");
	res = a.toFloat() * b.toFloat();
	c = a * b;
	printOperation(res, a, b, c, " * ");
	res = a.toFloat() / b.toFloat();
	c = a / b;
	printOperation(res, a, b, c, " / ");
}

void	checkCompOperator(const Fixed &a, const Fixed &b)
{
	std::cout << BLUE << "--- " << __FUNCTION__ << " ---" << RESET << endl
				<< "a = " << a << ", b = " << b << endl
				<< "a == b : " << (a == b ? GREEN "✓" : RED "✗") << RESET << endl
				<< "a != b : " << (a != b ? GREEN "✓" : RED "✗") << RESET << endl
				<< "a <  b : " << (a < b ? GREEN "✓" : RED "✗") << RESET << endl
				<< "a >  b : " << (a > b ? GREEN "✓" : RED "✗") << RESET << endl
				<< "a <= b : " << (a <= b ? GREEN "✓" : RED "✗") << RESET << endl
				<< "a >= b : " << (a >= b ? GREEN "✓" : RED "✗") << RESET << endl << endl;
}

int	main(void)
{
	Fixed a(0);
	Fixed b(0);
	checkCompOperator(a, b);
	a = 1.1f + 50.0f;
	checkCompOperator(a, b);
	a = a - 500.0f;
	checkCompOperator(a, b);
	checkCalcOperator();
	printIncDec();
	{
		std::cout << "--- Basic test main ---" << endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << endl;
		std::cout << ++a << endl;
		std::cout << a << endl;
		std::cout << a++ << endl;
		std::cout << a << endl;
		std::cout << b << endl;
		std::cout << Fixed::max( a, b ) << endl;
	}
	return (0);
}
