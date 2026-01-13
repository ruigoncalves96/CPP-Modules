# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat SubDirector("Sub-Director", 145); 
	std::cout << SubDirector << "\n";
	Bureaucrat Director("Director", 137); 
	std::cout << Director << "\n\n";

	ShrubberyCreationForm PardonForm("Citizens");	
	std::cout << PardonForm << std::endl;

	// Sign Form
	SubDirector.signForm(PardonForm);
	std::cout << PardonForm << std::endl;
	// Execute Form
	SubDirector.executeForm(PardonForm);
	Director.executeForm(PardonForm);

	return (0);
}
