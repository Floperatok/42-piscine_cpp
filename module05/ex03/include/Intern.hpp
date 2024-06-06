
#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include <exception>
# include <string>

class Intern
{
private:
public:
    Intern(void);
    Intern(const Intern &copy);
    Intern &operator=(const Intern &other);
    ~Intern(void);

	AForm	*makeForm(const std::string formName, const std::string formTarget) const;

	class NotExistingForm : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
};

#endif
