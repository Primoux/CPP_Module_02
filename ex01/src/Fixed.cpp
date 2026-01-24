/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/24 16:04:11 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Color.h"
#include <cmath>
#include <iostream>
#include <ostream>

using std::endl;

Fixed::Fixed() : _fixed(0)
{
	std::cout << GREEN "Default constructor called" RESET << endl;
}

Fixed::~Fixed()
{
	std::cout << RED "Destructor called " << this->_fixed << RESET << endl;
}

Fixed::Fixed(Fixed const &original)
{
	std::cout << GREEN "Copy constructor called" RESET << endl;
	this->_fixed = original._fixed;
}

Fixed::Fixed(const int nb)
{
	std::cout << GREEN "Const int constructor called" RESET << endl;
	this->_fixed = nb << this->_fracBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << GREEN "Const float constructor called" RESET << endl;
	this->_fixed = roundf(nb * (1 << this->_fracBits));
}

Fixed &Fixed::operator=(Fixed const &other)
{
	this->_fixed = other._fixed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	return (o << fixed.toFloat());
}

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW "getRawBits member function called" RESET << endl;
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" RESET << endl;
	this->_fixed = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixed / (float)(1 << this->_fracBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixed >> this->_fracBits);
}
