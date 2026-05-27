# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		std::cout << "|| --- Shrubbery --- ||" << "\n";
		Bureaucrat Gardener("Gardener", 145); 
		std::cout << Gardener << "\n";
		Bureaucrat ChiefGradener("ChiefGradener", 137); 
		std::cout << ChiefGradener << "\n\n";

		ShrubberyCreationForm treePlanting("Home");	
		std::cout << treePlanting << std::endl;

		// Sign Form
		Gardener.signForm(treePlanting);
		std::cout << treePlanting << std::endl;
		// Execute Form
		Gardener.executeForm(treePlanting);
		ChiefGradener.executeForm(treePlanting);
	}
	catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

	try
	{
		std::cout << "\n|| --- Robotomy --- ||" << "\n";
		Bureaucrat mechanic("Mechanic", 72); 
		std::cout << mechanic << "\n";
		Bureaucrat engineer("Engineer", 45); 
		std::cout << engineer << "\n\n";

		RobotomyRequestForm robotomy("Human");	
		std::cout << robotomy << std::endl;

		// Sign Form
		mechanic.signForm(robotomy);
		std::cout << robotomy << std::endl;
		// Execute Form
		mechanic.executeForm(robotomy);
		engineer.executeForm(robotomy);
	}
	catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

	try
	{
		std::cout << "\n|| --- Presidential Pardon --- ||" << "\n";
		Bureaucrat vicePresident("Vice-President", 25); 
		std::cout << vicePresident << "\n";
		Bureaucrat president("President", 5); 
		std::cout << president << "\n\n";

		PresidentialPardonForm pardon("Thief");	
		std::cout << pardon << std::endl;

		// Sign Form
		vicePresident.signForm(pardon);
		std::cout << pardon << std::endl;
		// Execute Form
		vicePresident.executeForm(pardon);
		president.executeForm(pardon);
	}
	catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

	return (0);
}
