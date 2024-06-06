
#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
private:
	std::string _data;
public:
    Data(void);
	Data(std::string str);
    Data(const Data &copy);
    Data &operator=(const Data &other);
    ~Data(void);

	const std::string	&getData(void) const;
};

#endif
