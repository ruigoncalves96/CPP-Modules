# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(void)
{
	try
	{
		std::cout << "\t|| Build Forms ||\n";
		Form emptyForm;
		std::cout << emptyForm << '\n';
	
		Form surveyForm("Survey", 75, 50);
		std::cout << surveyForm << '\n';
	
		Form copyForm(surveyForm);
		std::cout << copyForm;
		std::cout << "\t|| ------ ||\n\n";
	
		Bureaucrat teacher("Joseph", 150);
		std::cout << teacher << '\n';
		teacher.signForm(surveyForm);
		std::cout << surveyForm << '\n';
		
		Bureaucrat director("Rui", 1);
		std::cout << director << '\n';
		director.signForm(surveyForm);
		std::cout << surveyForm << '\n';
	}
	catch (const std::exception &e) { std::cerr << e.what() << std::endl; }

	try
	{
		std::cout << "\t|| Build Error Forms ||\n";
		Form surveyForm("Survey", 151, 151);
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	try
	{
		Form surveyForm("Survey", 0, 0);
	}
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
	
	return (0);
}
