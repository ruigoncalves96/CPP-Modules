# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form()
	: _name("Unkown"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	// std::cout << "Default Form constructor called. 'Unkown' created." << std::endl;
}

Form::Form(const std::string &name, const int signGrade, const int execGrade)
	: _name(name), _is_signed(false),
	_sign_grade(signGrade), _exec_grade(execGrade)
{
	// std::cout << "Default Form constructor called. 'Unkown' created." << std::endl;
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw GradeTooHighException();
	if (this->_sign_grade > 150 || this->_exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &obj)
	: _name(obj._name), _is_signed(obj._is_signed),
	_sign_grade(obj._sign_grade), _exec_grade(obj._exec_grade)
{
	// std::cout << "Copy Form constructor called. 'Unkown' created." << std::endl;
}

Form::~Form()
{
	// std::cout << "Default Form destructor called. '" << this->_name << "' destroyed." << std::endl;
}

Form& Form::operator=(const Form &obj)
{
	// std::cout << "Copy assignmemt Form called. 'Unkown' created." << std::endl;
	(void)obj;
	return (*this);
}

const std::string& Form::getName() const
{
	return (this->_name);
}

bool Form::getSign() const
{
	return (this->_is_signed);
}

int Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() <= this->getSignGrade())
		this->_is_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade_too_high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade_too_low");
}

std::ostream& operator<<(std::ostream &os, const Form &obj)
{
	std::cout << "Form details:\n";
	std::cout << "\tName: " << obj.getName() << "\n";
	std::cout << "\tGrade to be signed: " << obj.getSignGrade() << "\n";
	std::cout << "\tGrade to be executed: " << obj.getExecGrade() << "\n";
	if (obj.getSign() == true)
		std::cout << "\t  x Signed" << std::endl;
	else
		std::cout << "\t  x Not Signed" << std::endl;
	return (os);
}
