# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
    std::cout << "=== FragTrap Tests ===\n";

    // Construction
    FragTrap f1("Joca");
    FragTrap f2("Xico");

    std::cout << "\n--- Basic Actions ---\n";
    f1.attack("dummy target");
    f1.takeDamage(30);
    f1.beRepaired(20);   

    std::cout << "\n--- High Fives ---\n";
    f1.highFivesGuys();
    f2.highFivesGuys();

    std::cout << "\n--- Energy Exhaustion ---\n";
    // Drain all energy by attacking
    for (int i = 0; i < 105; ++i)
        f2.attack("training dummy");
    // Attempt actions with 0 energy
    f2.attack("still trying");
    f2.beRepaired(10);

    std::cout << "\n--- Lethal Damage + Actions ---\n";
    f1.takeDamage(200);    // kill
    f1.attack("post-mortem attack");
    f1.beRepaired(10);
    f1.highFivesGuys();  

    std::cout << "\n--- Copy and Assignment ---\n";
    FragTrap f3("CopyBot");
    f3 = f2;               // copy assignment (CopyBot becomes a copy of Xico)
    FragTrap f4(f1);       // copy constructor (f4 is a clone of Joca)
    
    std::cout << "\nTesting copied objects:\n";
    f3.attack("clone target");
    f3.highFivesGuys();
    f4.attack("another target");

    std::cout << "\n=== Mixed Inheritance Sanity Checks ===\n";
    // Ensure ScavTrap and ClapTrap still work alongside FragTrap
    ScavTrap s1("Tim");
    s1.guardGate();
    s1.attack("Joca");
    s1.beRepaired(5);

    ClapTrap c1("Joe");
    c1.attack("Joca");
    c1.beRepaired(3);

    std::cout << "\n=== End (watch destruction order - LIFO) ===\n";
    return 0;
}
