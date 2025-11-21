# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main(void)
{
	std::cout << "=== ClapTrap and ScavTrap Test ===" << std::endl;

    // --- Base ClapTrap objects ---
    ClapTrap clap1("Antonio");
    ClapTrap clap2("Alfredo");

    std::cout << "\n--- ClapTrap Attacks ---" << std::endl;
    clap1.attack("Alfredo");
    clap2.attack("Antonio");

    std::cout << "\n--- Taking Damage ---" << std::endl;
    clap1.takeDamage(5);
    clap2.takeDamage(3);

    std::cout << "\n--- Repairs ---" << std::endl;
    clap1.beRepaired(2);
    clap2.beRepaired(4);

    // --- Derived ScavTrap objects ---
    std::cout << "\n=== ScavTrap Test ===" << std::endl;
    ScavTrap scav1("Joca");
    ScavTrap scav2("Xico");

    std::cout << "\n--- ScavTrap Attacks (Overridden) ---" << std::endl;
    scav1.attack("Xico");
    scav2.attack("Joca");

    std::cout << "\n--- ScavTrap Special Ability ---" << std::endl;
    scav1.guardGate();
    scav2.guardGate();

    std::cout << "\n--- ScavTrap Taking Damage ---" << std::endl;
    scav1.takeDamage(15);
    scav2.takeDamage(20);

    std::cout << "\n--- ScavTrap Repairs ---" << std::endl;
    scav1.beRepaired(10);
    scav2.beRepaired(5);

    // --- Energy Exhaustion Test ---
    std::cout << "\n--- Energy Exhaustion Test ---" << std::endl;
    for (int i = 0; i < 50; ++i)
        scav1.attack("Xico");

    // --- Copy and Assignment Tests ---
    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    ScavTrap scav3(scav1); // copy constructor

    std::cout << "\n--- Assignment Operator Test ---" << std::endl;
    scav2 = scav1;

    std::cout << "\n=== End of Simulation ===" << std::endl;
	return 0;	
}
