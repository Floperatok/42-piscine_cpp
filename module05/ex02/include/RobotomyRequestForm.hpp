
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <cstdlib>
# include <time.h>
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
    RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(void);

	void	executeFormAction(void) const;
};

#endif
