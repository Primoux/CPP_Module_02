/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:33:51 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/30 11:01:20 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>

using std::endl;

void	checkCalcOperator(void)
{
    std::cout << "--- " << __FUNCTION__ << " ---" << endl;
}

void	checkCompOperator(const Fixed &a, const Fixed &b)
{
    std::cout << "--- " << __FUNCTION__ << " ---" << endl;
    std::cout << "a = " << a << ", b = " << b << endl;
    std::cout << "a == b : " << (a == b ? "✓" : "✗") << endl;
    std::cout << "a != b : " << (a != b ? "✓" : "✗") << endl;
    std::cout << "a <  b : " << (a < b ? "✓" : "✗") << endl;
    std::cout << "a >  b : " << (a > b ? "✓" : "✗") << endl;
    std::cout << "a <= b : " << (a <= b ? "✓" : "✗") << endl;
    std::cout << "a >= b : " << (a >= b ? "✓" : "✗") << endl;
    std::cout << endl;
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
	return (0);
}
