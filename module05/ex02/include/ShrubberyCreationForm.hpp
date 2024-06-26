
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
    ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm(void);

	void	executeFormAction(void) const;
};

#endif
