#ifndef	CPP05_EX01_FORM_HPP
# define	CPP05_EX01_FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
public:
//Default constructor (Required)
	Form(void);
//Copy constructor (Required)
	Form (const Form &copy );
//Constructors
	Form(const std::string& name, int grade_sign, int grade_exec);
//Default Destructor (Required)
	virtual ~Form(void);
//Destructors
//Copy assignment operator (Required)
	Form & operator = (const Form &copy);
//Operators
//Swap function
//Setters & Getters
	const std::string	getName(void) const;
	int			getGradeSign(void) const;		
	int			getGradeExec(void) const;
	bool				getSigned(void) const;

//Other functions
	int		setGrade(int grade);
	void	beSigned(Bureaucrat& bureaucrat);

	friend	std::ostream& operator<<(std::ostream& out, const Form& form);

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(int grade) : _grade(grade) {};
		const char* what() const throw() {return ("Grade too high!");};
		int	getGrade(void) const {return (this->_grade);};
	private:
		int	_grade;
	};

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(int grade) : _grade(grade) {};
		const char* what() const throw() {return ("Grade too low!");};
		int	getGrade(void) const {return (this->_grade);};
	private:
		int	_grade;
	};

protected:
private:
	const std::string	_name;
	bool				_signature;
	const int			_grade_sign;
	const int			_grade_exec;
};

#endif