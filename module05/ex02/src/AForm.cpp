
#include "AForm.hpp"


/* ########## Constructor ########## */

AForm::AForm(void) : _name("DefaultAFormName"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExec < HIGHEST_GRADE)
		throw (AForm::GradeTooHighException());
	if (gradeToSign > LOWEST_GRADE || gradeToExec > LOWEST_GRADE)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
}

AForm::~AForm(void)
{
}


/* ########## Operator overload ########## */

AForm &AForm::operator=(const AForm &other)
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

std::ostream	&operator<<(std::ostream &stream, AForm &other)
{
	stream << "Form " << other.getName() \
		<< ", grade sign " << other.getGradeToSign() \
		<< ", grade execution " << other.getGradeToExec() << ".";
	return (stream);
}


/* ########## Setter/Getter ########## */

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	AForm::setName(const std::string name)
{
	const_cast<std::string&>(this->_name) = name;
}

void	AForm::setGradeToSign(const int grade)
{
	if (grade > LOWEST_GRADE)
		throw (AForm::GradeTooLowException());
	if (grade < HIGHEST_GRADE)
		throw (AForm::GradeTooHighException());
	const_cast<int&>(this->_gradeToSign) = grade;
}

void	AForm::setGradeToExec(const int grade)
{
	if (grade > LOWEST_GRADE)
		throw (AForm::GradeTooLowException());
	if (grade < HIGHEST_GRADE)
		throw (AForm::GradeTooHighException());
	const_cast<int&>(this->_gradeToExec) = grade;
}

void	AForm::setIsSigned(const bool isSigned)
{
	this->_isSigned = isSigned;
}


/* ########## Member function ########## */

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned == true)
		throw (AForm::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	this->_isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw(AForm::NotSignedException());
	if (executor.getGrade() > this->getGradeToExec())
		throw(AForm::GradeTooLowException());
	this->executeFormAction();
}


/* ########## Exception ########## */

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form: Exception error: Grade too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form: Exception error: Grade too low");
}

const char	*AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form: Exception error: Form's already signed");
}

const char	*AForm::NotSignedException::what(void) const throw()
{
	return ("Form: Exception error: Form's not signed");
}


/* ########## Non-member function ########## */

