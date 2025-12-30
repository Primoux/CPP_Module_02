/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/30 16:03:20 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : fixed(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &original)
{
	this->fixed = original.fixed;
}

Fixed::Fixed(const int nb)
{
	this->fixed = nb << this->fracBits;
}

Fixed::Fixed(const float nb)
{
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
	Fixed result;
	result.setRawBits(this->fixed + other.fixed);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixed - other.fixed);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->fixed * other.fixed) >> fracBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->fixed << fracBits) / other.fixed);
	return (result);
}

Fixed &Fixed::operator++(void)
{
	this->fixed++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->fixed--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixed++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixed--;
	return (tmp);
}

int Fixed::getRawBits(void) const
{
	return (this->fixed);
}

void Fixed::setRawBits(int const raw)
{
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
