
#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExec;
public:
    AForm(void);
	AForm(std::string name, int gradeToSign, int gradeToExec);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &other);
    virtual ~AForm(void);

	const std::string	&getName(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;
	bool				getIsSigned(void) const;
	void				setName(const std::string name);
	void				setGradeToSign(const int grade);
	void				setGradeToExec(const int grade);
	void				setIsSigned(const bool isSigned);

	void			beSigned(const Bureaucrat &bureaucrat);
	void			execute(Bureaucrat const &executor) const;
	virtual void	executeFormAction(void) const = 0;

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
	class NotSignedException : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, AForm &other);

#endif
