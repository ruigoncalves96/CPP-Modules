# include "Intern.hpp"
# include "AForm.hpp"

int main(void)
{
	Intern poorIntern;
	AForm *form;

	form = poorIntern.makeForm("presidential pardon", "rui");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = poorIntern.makeForm("robotomy request", "rui");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = poorIntern.makeForm("shrubbery creation", "rui");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = poorIntern.makeForm("some random form", "rui");
	if (form)
		std::cout << *form << std::endl;
	delete form;

	return (0);
}
