/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:33:51 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/24 15:55:21 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Color.h"
#include <iostream>
#include <ostream>

using std::endl;

int	main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	
	std::cout << "\n" << CYAN << "=== Setting value ===" << RESET << endl;
	b.setRawBits(10);
	c = b;
	a.setRawBits(456);
	
	std::cout << "\n" << CYAN << "=== Raw Bits Values ===" << RESET << endl;
	std::cout << MAGENTA << "a" << RESET << " = " << YELLOW << a.getRawBits() << RESET << endl;
	std::cout << MAGENTA << "b" << RESET << " = " << YELLOW << b.getRawBits() << RESET << endl;
	std::cout << MAGENTA << "c" << RESET << " = " << YELLOW << c.getRawBits() << RESET << endl;
	return (0);
}
