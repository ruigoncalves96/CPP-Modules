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
	{
		Dog temp = Nala;
	}
	std::cout << "| ----- ----- |\n";
	{
		Dog temp(Nala);
	}

	std::cout << "| ----- ----- |\n";
    Nala.setIdea(0, "Tenis Baaaaalls!");
    Nala.setIdea(1, "Foooood!");
	std::cout << "| ----- ----- |\n";

    Dog Scraps = Nala;              // copy constructor

	std::cout << "| ----- ----- |\n";
    Scraps.setIdea(0, "Booone!");
	std::cout << "| ----- ----- |\n";
    std::cout << "Nala 1: " << Nala.getIdea(0) << " / "
				<< "Nala 2: " << Nala.getIdea(1) << std::endl;
    std::cout << "Scraps 1: " << Scraps.getIdea(0) << " / "
				<< "Scraps 2: " << Scraps.getIdea(1) << std::endl;
	std::cout << "| ----- ----- |\n";


	std::cout << "\n| ===== Cat Deep Copy ===== |\n";
	Cat Sol;
	std::cout << "| ----- ----- |\n";
	{
		Cat temp = Sol;
	}
	std::cout << "| ----- ----- |\n";
	{
		Cat temp(Sol);
	}

	std::cout << "| ----- ----- |\n";
    Sol.setIdea(0, "Sleeep!");
    Sol.setIdea(1, "Sunbatheeee!");
	std::cout << "| ----- ----- |\n";

    Cat Lua = Sol;              // copy constructor

	std::cout << "| ----- ----- |\n";
    Lua.setIdea(0, "Fooooooood!");
	std::cout << "| ----- ----- |\n";
    std::cout << "Sol 1: " << Sol.getIdea(0) << " / "
				<< "Sol 2: " << Sol.getIdea(1) << std::endl;
    std::cout << "Lua 1: " << Lua.getIdea(0) << " / "
				<< "Lua 2: " << Lua.getIdea(1) << std::endl;
	std::cout << "| ----- ----- |\n";
	
	std::cout << "\n| ===== Destructores ===== |\n";

	return 0;
}
