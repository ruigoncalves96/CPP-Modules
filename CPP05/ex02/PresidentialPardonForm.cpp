# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5, "Unkown")
{
	// std::cout << "Default PresidentialPardonForm constructor called. 'Sir' created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon", 25, 5, target)
{
	// std::cout << "Default PresidentialPardonForm constructor called. '" << this->_name << "' created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
	// std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "Default PresidentialPardonForm destructor called. '" << this->_name << "' destroyed." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	// std::cout << "PresidentialPardonForm copy assignment called." << std::endl;
	(void)obj;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSign() == true)
	{
		if (executor.getGrade() <= this->getExecGrade())
			std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSigned();
}