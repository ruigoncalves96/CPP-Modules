# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137, "Unkown")
{
	// std::cout << "Default ShrubberyCreationForm constructor called. 'Sir' created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137, target)
{
	// std::cout << "Default ShrubberyCreationForm constructor called. '" << this->_name << "' created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
	// std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "Default ShrubberyCreationForm destructor called. '" << this->_name << "' destroyed." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	// std::cout << "ShrubberyCreationForm copy assignment called." << std::endl;
	(void)obj;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getSign() == true)
	{
		if (executor.getGrade() <= this->getExecGrade())
			shrubberyExec();
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSigned();
}

void ShrubberyCreationForm::shrubberyExec() const
{
	std::string file_name = this->getTarget() + "_shrubbery";
	std::ofstream file(file_name.c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to open file!");
	for (int i = 0; i < 3; i++)
	{
		file << "   *\n";
		file << "  ***\n";
		file << " *****\n";
		file << "   |\n";
		file << "\n";
	}
	file.close();
}