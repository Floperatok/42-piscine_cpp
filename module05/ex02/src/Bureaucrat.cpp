
#include "Bureaucrat.hpp"


/* ########## Constructor ########## */

Bureaucrat::Bureaucrat(void) : _name("default_name"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->setName(name);
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	if (&copy != this)
		*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
}


/* ########## Operator overload ########## */

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (&other != this)
	{
		this->setName(other._name);
		this->_grade = other._grade;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Bureaucrat &other)
{
	stream << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (stream);
}


/* ########## Setter/Getter ########## */

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setName(const std::string name)
{
	const_cast<std::string&>(this->_name) = name;
}

void	Bureaucrat::setGrade(const int grade)
{
	if (grade > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade = grade;
}


/* ########## Member function ########## */

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < HIGHEST_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > LOWEST_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName() \
			<< " because \"" <<  e.what() << "\"" << std::endl;;
	}	
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() \
			<< " because \"" << e.what() << "\"" << std::endl;
	}
}


/* ########## Exception ########## */

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat: Exception error: Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat: Exception error: Grade too low");
}


/* ########## Non-member function ########## */
