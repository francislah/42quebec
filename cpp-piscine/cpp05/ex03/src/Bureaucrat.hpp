#ifndef	CPP05_EX00_BUREAUCRAT_HPP
# define	CPP05_EX00_BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat{
public:
//Default constructor (Required)
	Bureaucrat(void);
//Copy constructor (Required)
	Bureaucrat (const Bureaucrat &copy );
//Constructors
	Bureaucrat(const std::string& name, int grade);
//Default Destructor (Required)
	virtual ~Bureaucrat();
//Destructors
//Copy assignment operator (Required)
	Bureaucrat & operator = (const Bureaucrat &copy);
//Operators
//Swap function
//Setters & Getters
	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				setGrade(int grade);
//Other functions
	void	incrementGrade(void);
	void	decrementGrade(void);
	void	signForm(Form& form);
	void	executeForm(Form const& form);

	friend	std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

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
	int				_grade;
};

#endif