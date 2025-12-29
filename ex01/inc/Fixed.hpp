#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
  private:
	int fixed;
	static const int fracBits = 8;

  public:
	Fixed();
	~Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(Fixed const &original);
	Fixed &operator=(Fixed const &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void);
};

#endif // !FIXED_HPP