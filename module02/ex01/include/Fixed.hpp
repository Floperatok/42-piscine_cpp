
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_rawBits;
	static const int	_nb_bits = 8;
public:
    Fixed(void);
	Fixed(const int rawBits);
	Fixed(const float rawBits);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &other);
    ~Fixed(void);

	int	getRawBits(void) const;
	void	setRawBits(int const raw);

	int		toInt(void) const;
	float	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &other);

#endif
