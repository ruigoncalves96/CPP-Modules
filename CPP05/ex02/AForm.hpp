#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, const int signGrade, const int execGrade,
			const std::string &target);
		AForm(const AForm&);
		virtual ~AForm();

		AForm& operator=(const AForm&);

		const std::string& getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		const std::string& getTarget() const;

		void beSigned(const Bureaucrat &obj);
		virtual void execute(const Bureaucrat &executor) const = 0;

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

		class FormNotSigned: public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;
		const std::string _target;

};

std::ostream& operator<<(std::ostream &os, const AForm &obj);

#endif