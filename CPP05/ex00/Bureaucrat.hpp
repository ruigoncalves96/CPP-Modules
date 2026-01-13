#ifndef BUREAUCRAFT_HPP
# define BUREAUCRAFT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const int);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat&);
		Bureaucrat operator++(int);
		Bureaucrat operator--(int);

		const std::string& getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj);

#endif