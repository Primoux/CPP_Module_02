/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:33:51 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/24 15:42:08 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Color.h"
#include <iostream>
#include <ostream>

using std::endl;

int	main(void)
{

	Fixed const b(10);
	Fixed c(42.42f);
	Fixed const d(b);
	Fixed a = Fixed(1234.4321550000001f);
	
	std::cout << "\n" << CYAN << "=== Float Values ===" << RESET << endl;
	std::cout << MAGENTA << "a" << RESET << " = " << YELLOW << a << RESET << endl;
	std::cout << MAGENTA << "b" << RESET << " = " << YELLOW << b << RESET << endl;
	std::cout << MAGENTA << "c" << RESET << " = " << YELLOW << c << RESET << endl;
	std::cout << MAGENTA << "d" << RESET << " = " << YELLOW << d << RESET << endl;
	
	std::cout << "\n" << CYAN << "=== Integer Values ===" << RESET << endl;
	std::cout << MAGENTA << "a" << RESET << " = " << YELLOW << a.toInt() << RESET << endl;
	std::cout << MAGENTA << "b" << RESET << " = " << YELLOW << b.toInt() << RESET << endl;
	std::cout << MAGENTA << "c" << RESET << " = " << YELLOW << c.toInt() << RESET << endl;
	std::cout << MAGENTA << "d" << RESET << " = " << YELLOW << d.toInt() << RESET << endl;
	std::cout << endl;
	return (0);
}
