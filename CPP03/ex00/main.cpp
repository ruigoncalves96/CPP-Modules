# include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== ClapTrap Battle Arena ===" << std::endl;

	std::string nameA = "Clappy";
	std::string nameB = "Trappy";

	ClapTrap a(nameA);
	ClapTrap b(nameB);
	ClapTrap c(a); // copy constructor

	std::cout << "\n--- Initial State ---" << std::endl;
	a.attack("Trappy");
	b.attack("Clappy");
	c.attack("Clappy");

	std::cout << "\n--- Taking Damage ---" << std::endl;
	a.takeDamage(5);
	b.takeDamage(3);
	c.takeDamage(8);

	std::cout << "\n--- Repairing ---" << std::endl;
	a.beRepaired(3);
	b.beRepaired(10);
	c.beRepaired(1);

	std::cout << "\n--- Energy Exhaustion Test ---" << std::endl;
	for (int i = 0; i < 12; i++)
		a.attack("Trappy"); // should stop after energy runs out

	std::cout << "\n--- Assignment Operator Test ---" << std::endl;
	b = a;
	b.attack("Someone Else");

	std::cout << "\n=== End of Simulation ===" << std::endl;
	return 0;	
}
