/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/24 15:39:08 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Color.h"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : fixed(0)
{
	std::cout << GREEN "Default constructor called" RESET << std::endl;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called " << this->fixed << RESET << std::endl;
}

Fixed::Fixed(Fixed const &original)
{
	std::cout << GREEN "Copy constructor called" RESET << std::endl;
	this->fixed = original.fixed;
}

Fixed::Fixed(const int nb)
{
	std::cout << GREEN "Const int constructor called" RESET << std::endl;
	this->fixed = nb << this->fracBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << GREEN "Const float constructor called" RESET << std::endl;
	this->fixed = roundf(nb * (1 << this->fracBits));
}

Fixed &Fixed::operator=(Fixed const &other)
{
	this->fixed = other.fixed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	return (o << fixed.toFloat());
}

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW "getRawBits member function called" RESET << std::endl;
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" RESET<< std::endl;
	this->fixed = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixed / (float)(1 << this->fracBits));
}

int Fixed::toInt(void) const
{
	return (this->fixed >> this->fracBits);
}
