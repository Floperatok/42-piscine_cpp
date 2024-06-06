
#include "RobotomyRequestForm.hpp"


/* ########## Constructor ########## */

RobotomyRequestForm::RobotomyRequestForm(void) \
	: AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) \
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}


/* ########## Operator overload ########## */

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (&other != this)
	{
		AForm::operator=(other);	
		this->_target = other._target;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	RobotomyRequestForm::executeFormAction(void) const
{
	std::cout << "DRRRRRRRRRRRRRLRLRRRRRRRRRRLRLRLRR!!" << std::endl;
	srand(time(0));
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << std::endl;
}


/* ########## Exception ########## */


/* ########## Non-member function ########## */

