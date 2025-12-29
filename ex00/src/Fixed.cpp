/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/29 11:55:42 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>

Fixed::Fixed() : fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called " << this->fixed << std::endl;
}

Fixed::Fixed(Fixed const &original)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed = original.fixed;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	this->fixed = other.fixed;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed = raw;
}
