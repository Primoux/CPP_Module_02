#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
  private:
	int _fixed;
	static const int _fracBits = 8;

  public:
	// CONSTRUCTOR
	Fixed();
	~Fixed();
	Fixed(Fixed const &original);
	Fixed(const int nb);
	Fixed(const float nb);

	// OPERATOR
	Fixed &operator=(Fixed const &other);
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	// MEMBER FUNCTION
	int 				getRawBits(void) const;
	void 				setRawBits(int const raw);
	float 				toFloat(void) const;
	int 				toInt(void) const;
	static Fixed 		&min(Fixed &a, Fixed &b);
	static const Fixed 	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed 	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);


#endif // !FIXED_HPP