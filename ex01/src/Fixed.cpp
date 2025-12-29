/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:37:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/29 11:54:18 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

Fixed::Fixed() : fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called " << this->fixed << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Const int constructor called" << std::endl;
	this->fixed = nb << this->fracBits;
	
}

Fixed::Fixed(const float nb)
{
	std::cout << "Const float constructor called" << std::endl;
	this->fixed = roundf(nb) * (1 << this->fracBits);
	this->fixed += (nb - roundf(nb)) * (1 << this->fracBits);
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

float Fixed::toFloat(void)
{
	std::cout << "toFloat member function called" << std::endl;

	float f;

	f = this->fixed << this->fracBits;
	return (f);
}
