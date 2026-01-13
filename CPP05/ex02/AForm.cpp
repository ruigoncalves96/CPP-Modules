# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Unkown"), _is_signed(false), _sign_grade(150), _exec_grade(150), _target("Unkown")
{
	// std::cout << "Default AForm constructor called. 'Unkown' created." << std::endl;
}

AForm::AForm(const std::string &name, const int signGrade, const int execGrade, const std::string &target)
	: _name(name), _is_signed(false),
	_sign_grade(signGrade), _exec_grade(execGrade), _target(target)
{
	// std::cout << "Default AForm constructor called. 'Unkown' created." << std::endl;
	if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw GradeTooHighException();
	if (this->_sign_grade > 150 || this->_exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &obj)
	: _name(obj._name), _is_signed(obj._is_signed),
	_sign_grade(obj._sign_grade), _exec_grade(obj._exec_grade), _target(obj._target)
{
	// std::cout << "Copy AForm constructor called. 'Unkown' created." << std::endl;
}

AForm::~AForm()
{
	// std::cout << "Default AForm destructor called. '" << this->_name << "' destroyed." << std::endl;
}

AForm& AForm::operator=(const AForm &obj)
{
	// std::cout << "Copy assignmemt AForm called. 'Unkown' created." << std::endl;
	(void)obj;
	return (*this);
}

const std::string& AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSign() const
{
	return (this->_is_signed);
}

int AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

const std::string& AForm::getTarget() const
{
	return (this->_target);
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() <= this->getSignGrade())
		this->_is_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("'Grade_too_high'");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("'Grade_too_low'");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("'Form_not_signed'");
}

std::ostream& operator<<(std::ostream &os, const AForm &obj)
{
	std::cout << "Form details:\n";
	std::cout << "\tName: " << obj.getName() << "\n";
	std::cout << "\tGrade to be signed: " << obj.getSignGrade() << "\n";
	std::cout << "\tGrade to be executed: " << obj.getExecGrade() << "\n";
	std::cout << "\tTarget: " << obj.getTarget() << "\n";
	if (obj.getSign() == true)
		std::cout << "\t  x Signed" << std::endl;
	else
		std::cout << "\t  x Not Signed" << std::endl;
	return (os);
}
