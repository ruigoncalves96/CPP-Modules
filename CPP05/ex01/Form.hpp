
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string &name, const int signGrade, const int execGrade);
		Form(const Form&);
		~Form();

		Form& operator=(const Form&);

		const std::string& getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &obj);

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
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

};

std::ostream& operator<<(std::ostream &os, const Form &obj);

#endif