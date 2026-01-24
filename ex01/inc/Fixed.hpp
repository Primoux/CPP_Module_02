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
	
	// MEMBER FUNCTION
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int 	toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif // !FIXED_HPP