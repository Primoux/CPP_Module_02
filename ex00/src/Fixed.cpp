/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/24 15:51:53 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Color.h"
#include <iostream>
#include <ostream>

Fixed::Fixed() : _fixed(0)
{
	std::cout << GREEN "Default constructor called" RESET << std::endl;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called for " << this->_fixed << RESET << std::endl;
}

Fixed::Fixed(Fixed const &original)
{
	std::cout << GREEN "Copy constructor called" RESET << std::endl;
	this->_fixed = original._fixed;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	this->_fixed = other._fixed;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW "getRawBits member function called" RESET << std::endl;
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << YELLOW "setRawBits member function called" RESET << std::endl;
	this->_fixed = raw;
}
