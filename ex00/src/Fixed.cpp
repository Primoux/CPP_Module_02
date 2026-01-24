/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/24 14:18:15 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Color.h"
#include <iostream>
#include <ostream>

Fixed::Fixed() : fixed(0)
{
	std::cout << GREEN "Default constructor called" RESET << std::endl;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called for " << this->fixed << RESET << std::endl;
}

Fixed::Fixed(Fixed const &original)
{
	std::cout << GREEN "Copy constructor called" RESET << std::endl;
	this->fixed = original.fixed;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	this->fixed = other.fixed;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW "getRawBits member function called" RESET << std::endl;
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << YELLOW "setRawBits member function called" RESET << std::endl;
	this->fixed = raw;
}
