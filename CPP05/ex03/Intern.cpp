# include "Intern.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

const std::string Intern::_formsName[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

Intern::Intern()
{
	// std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	// std::cout << "Intern copy constructor called" << std::endl;
	(void)obj;
}

Intern::~Intern()
{
	// std::cout << "Intern Default destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

int Intern::getFormIndex(const std::string &form)
{
	for (int i = 0; i < 3; i++)
	{
		if (form == _formsName[i])
			return (i + 1);
	}
	return (0);
}

AForm* Intern::makeForm(const std::string &form, const std::string &target)
{
	int form_index = getFormIndex(form);
	switch (form_index) {
		case 1 : // Presidential Pardon
			std::cout << "Intern creates 'Presidential Pardon' Form" << std::endl;
			return (new PresidentialPardonForm(target));
		case 2 : // Robotomy Request
			std::cout << "Intern creates 'Robotomy Request' Form" << std::endl;
			return (new RobotomyRequestForm(target));
		case 3 : // Shrubbery Creation
			std::cout << "Intern creates 'Shrubbery Creation' Form" << std::endl;
			return (new ShrubberyCreationForm(target));
		default :
			std::cerr << "Error: '" << form << "' doesnt exist! Intern is not able to create the Form" << std::endl;
			return (NULL);
	}
}
