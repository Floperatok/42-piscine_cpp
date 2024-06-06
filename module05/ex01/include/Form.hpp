
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;
public:
    Form(void);
	Form(std::string name, int gradeToSign, int gradeToExec);
    Form(const Form &copy);
    Form &operator=(const Form &other);
    ~Form(void);

	const std::string	&getName(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;
	bool				getIsSigned(void) const;
	void				setName(const std::string name);
	void				setGradeToSign(const int grade);
	void				setGradeToExec(const int grade);
	void				setIsSigned(const bool isSigned);

	void	beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, Form &other);

#endif
