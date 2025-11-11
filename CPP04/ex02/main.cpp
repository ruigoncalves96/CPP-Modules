# include "AAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

int main(void)
{
	AAnimal *animals[10] = {NULL};
	/* 	AAnimal A; 	-----\ 
		AAnimal A(); ------\ -> incorrect declarations (Abstarct default classes - cant instantiate it) */

	std::cout << "| ===== Constructors ===== |\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ":\n";
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n| ===== Speaking ===== |\n";
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	std::cout << "\n| ===== Destruction ===== |\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ":\n";
		delete animals[i];
	}

	std::cout << "\n| ===== Dog Deep Copy ===== |\n";
	Dog Nala;

	std::cout << "| ----- ----- |\n";
    Nala.getBrain().setIdea(0, "Tenis Baaaaalls!");
    Nala.getBrain().setIdea(1, "Foooood!");
	std::cout << "| ----- ----- |\n";

    Dog Scraps = Nala;              // copy constructor

	std::cout << "| ----- ----- |\n";
    Scraps.getBrain().setIdea(0, "Booone!");
	std::cout << "| ----- ----- |\n";
    std::cout << "Nala 1: " << Nala.getBrain().getIdea(0) << " / "
				<< "Nala 2: " << Nala.getBrain().getIdea(1) << std::endl;
    std::cout << "Scraps 1: " << Scraps.getBrain().getIdea(0) << " / "
				<< "Scraps 2: " << Scraps.getBrain().getIdea(1) << std::endl;
	std::cout << "| ----- ----- |\n";


	std::cout << "\n| ===== Cat Deep Copy ===== |\n";
	Cat Sol;

	std::cout << "| ----- ----- |\n";
    Sol.getBrain().setIdea(0, "Sleeep!");
    Sol.getBrain().setIdea(1, "Sunbatheeee!");
	std::cout << "| ----- ----- |\n";

    Cat Lua = Sol;              // copy constructor

	std::cout << "| ----- ----- |\n";
    Lua.getBrain().setIdea(0, "Fooooooood!");
	std::cout << "| ----- ----- |\n";
    std::cout << "Sol 1: " << Sol.getBrain().getIdea(0) << " / "
				<< "Sol 2: " << Sol.getBrain().getIdea(1) << std::endl;
    std::cout << "Lua 1: " << Lua.getBrain().getIdea(0) << " / "
				<< "Lua 2: " << Lua.getBrain().getIdea(1) << std::endl;
	std::cout << "| ----- ----- |\n";

	std::cout << "\n| ===== Brain Addresses ===== |\n";
    std::cout << "Nala Brain: " << &Nala.getBrain() << "\n";
    std::cout << "Scraps Brain: " << &Scraps.getBrain() << "\n";
    std::cout << "Sol Brain: " << &Sol.getBrain() << "\n";
    std::cout << "Lua Brain: " << &Lua.getBrain() << "\n";
	std::cout << "| ----- ----- |\n";
	
	std::cout << "\n| ===== Destructores ===== |\n";

	return 0;
}
