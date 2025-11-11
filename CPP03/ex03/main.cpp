# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"


static void separator(const std::string& title) {
    std::cout << "\n========== " << title << " ==========\n";
}

int main() 
{
    separator("Basic ClapTrap");
    ClapTrap c1("CLAPPY");
    c1.attack("target");
    c1.beRepaired(3);
    for (int i = 0; i < 12; ++i) 
        c1.attack("dummy");
    c1.beRepaired(1);

    separator("ScavTrap test");
    ScavTrap s1("SCAVVY");
    s1.attack("enemy");
    s1.guardGate();
    for (int i = 0; i < 55; ++i) 
        s1.attack("drain");
    s1.guardGate(); // after energy drained

    separator("FragTrap test");
    FragTrap f1("FRAGGY");
    f1.attack("evil bot");
    f1.highFivesGuys();
    for (int i = 0; i < 5; ++i) 
        f1.beRepaired(2);

    separator("DiamondTrap construction");
    DiamondTrap d1("DIAMY");
    d1.whoAmI();
    d1.printStatus();
    d1.attack("boss");
    d1.highFivesGuys();     // from FragTrap
    d1.guardGate();         // from ScavTrap
    d1.printStatus();

    separator("DiamondTrap energy drain");
    for (int i = 0; i < 60; ++i)
        d1.attack("punching bag");
    d1.attack("after drain");
    d1.beRepaired(5);
    d1.printStatus();

    separator("Copy / Assignment");
    DiamondTrap d2(d1);      // copy ctor
    d2.whoAmI();
    DiamondTrap d3;
    d3 = d1;                 // assignment
    d3.whoAmI();
    d2.printStatus();
    d3.printStatus();

    separator("Multiple whoAmI");
    d1.whoAmI();
    d2.whoAmI();
    d3.whoAmI();

    separator("Polymorphic pointers (base part)");
    ClapTrap* poly1 = &s1;
    ClapTrap* poly2 = &f1;
    ClapTrap* poly3 = &d1;
    poly1->attack("poly target");
    poly2->attack("poly target");
    poly3->attack("poly target"); // resolves to ScavTrap::attack via using

    separator("Damage / Death simulation");
    d1.takeDamage(30);
    d1.printStatus();
    d1.takeDamage(80); // should drop to/below 0
    d1.attack("should fail");
    d1.beRepaired(10); // maybe allowed only if still alive per your canPerformAction logic
    d1.printStatus();

    separator("End");
    return 0;
}
