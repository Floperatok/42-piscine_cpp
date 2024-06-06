
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
private:
	const std::string	_name;
	int				 	_grade;
public:
    Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat(void);

	const std::string	&getName(void) const;
	int					getGrade(void) const;
	void				setGrade(const int grade);
	void				setName(const std::string name);
	void				incrementGrade(void);
	void				decrementGrade(void);

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
};

std::ostream	&operator<<(std::ostream &stream, Bureaucrat &other);

#endif
