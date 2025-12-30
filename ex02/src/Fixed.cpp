/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/30 11:03:12 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called " << this->toFloat() << std::endl;
}

Fixed::Fixed(Fixed const &original)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed = original.fixed;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Const int constructor called" << std::endl;
	this->fixed = nb << this->fracBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Const float constructor called" << std::endl;
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

bool Fixed::operator<(const Fixed &other) const
{
	if (this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed((this->fixed + other.fixed) >> this->fracBits);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed((this->fixed - other.fixed) >> this->fracBits);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed((this->fixed / other.fixed) >> this->fracBits);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixed = raw;
}

float Fixed::toFloat(void) const
{
	// std::cout << "toFloat member function called" << std::endl;
	return ((float)this->fixed / (float)(1 << this->fracBits));
}

int Fixed::toInt(void) const
{
	// std::cout << "toFloat member function called" << std::endl;
	return (this->fixed >> this->fracBits);
}
