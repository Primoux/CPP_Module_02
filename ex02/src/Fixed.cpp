/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/24 16:03:33 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : _fixed(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &original)
{
	this->_fixed = original._fixed;
}

Fixed::Fixed(const int nb)
{
	this->_fixed = nb << this->_fracBits;
}

Fixed::Fixed(const float nb)
{
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
	Fixed result;
	result.setRawBits(this->_fixed + other._fixed);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixed - other._fixed);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->_fixed * other._fixed) >> _fracBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->_fixed << _fracBits) / other._fixed);
	return (result);
}

Fixed &Fixed::operator++(void)
{
	this->_fixed++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_fixed--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixed++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixed--;
	return (tmp);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}
