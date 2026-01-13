# include "Bureaucrat.hpp"
# include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Sir"), _grade(150)
{
	// std::cout << "Default Bureaucrat constructor called. 'Sir' created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade)
{
	// std::cout << "Default Bureaucrat constructor called. '" << this->_name << "' created." << std::endl;
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)	
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	// std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Default Bureaucrat destructor called. '" << this->_name << "' destroyed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	// std::cout << "Bureaucrat copy assignment called." << std::endl;
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat temp = *this;
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
	return (temp);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat temp = *this;
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
	return (temp);
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->_name << " couldn’t sign " << form.getName()
								<< " because "<< e.what() << '\n';
	}
}
void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->_name << " couldn’t execute " << form.getName()
								<< " because "<< e.what() << '\n';
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade_too_high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade_too_low");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() + ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}
