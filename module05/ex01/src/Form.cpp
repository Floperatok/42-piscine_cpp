
#include "Form.hpp"


/* ########## Constructor ########## */

Form::Form(void) : _name("DefaultFormName"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
		throw (Form::GradeTooHighException());
	if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
}

Form::~Form(void)
{
}


/* ########## Operator overload ########## */

Form &Form::operator=(const Form &other)
{
	if (&other != this)
	{
		this->setName(other.getName());
		this->setGradeToSign(other.getGradeToSign());
		this->setGradeToExec(other.getGradeToExec());
		this->setIsSigned(other.getIsSigned());
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Form &other)
{
	stream << "Form " << other.getName() \
		<< ", form grade sign " << other.getGradeToSign() \
		<< ", form grade execution " << other.getGradeToExec() << ".";
	return (stream);
}


/* ########## Setter/Getter ########## */

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	Form::setName(const std::string name)
{
	const_cast<std::string&>(this->_name) = name;
}

void	Form::setGradeToSign(const int grade)
{
	if (grade > LOWEST_GRADE)
		throw (Form::GradeTooLowException());
	if (grade < HIGHEST_GRADE)
		throw (Form::GradeTooHighException());
	const_cast<int&>(this->_gradeToSign) = grade;
}

void	Form::setGradeToExec(const int grade)
{
	if (grade > LOWEST_GRADE)
		throw (Form::GradeTooLowException());
	if (grade < HIGHEST_GRADE)
		throw (Form::GradeTooHighException());
	const_cast<int&>(this->_gradeToExec) = grade;
}

void	Form::setIsSigned(const bool isSigned)
{
	this->_isSigned = isSigned;
}


/* ########## Member function ########## */

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned == true)
		throw (Form::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	this->_isSigned = true;
}


/* ########## Exception ########## */

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form: Exception error: Grade too high");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form: Exception error: Grade too low");
}

const char	*Form::AlreadySignedException::what(void) const throw()
{
	return ("Form: Exception error: Form's already signed");
}


/* ########## Non-member function ########## */

