#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
  private:
	int fixed;
	static const int fracBits = 8;

  public:
	// CONSTRUCTOR
	Fixed();
	~Fixed();
	Fixed(Fixed const &original);
	Fixed(const int nb);
	Fixed(const float nb);

	// OPERATOR
	Fixed &operator=(Fixed const &other);
	friend std::ostream &operator<<(std::ostream &o, const Fixed &fixed);
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// MEMBER FUNCTION
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int 	toInt(void) const;
};

#endif // !FIXED_HPP