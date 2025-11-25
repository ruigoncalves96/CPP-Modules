# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main(void)
{
	std::cout << "|===== Good Polymorphism =====|\n" << std::endl;

	std::cout << "[ Construction fase ]\n";
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\n[ Get type of animal ]\n";
	std::cout << dog->getType() << "\n";
	std::cout << cat->getType() << "\n";

	std::cout << "\n[ SPEAK! ]\n";
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	std::cout << "\n[ Destruction fase ]\n";
	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n|===== Bad Polymorphism =====|\n" << std::endl;

	std::cout << "[ Construction fase ]\n";
	const WrongAnimal* _meta = new WrongAnimal();
	const WrongAnimal* _wrongCat = new WrongCat();

	std::cout << "\n[ Get type of animal ]\n";
	std::cout << _wrongCat->getType() << "\n";

	std::cout << "\n[ SPEAK! ]\n";
	_wrongCat->makeSound();
	_meta->makeSound();

	std::cout << "\n[ Destruction fase ]\n";
	delete _meta;
	delete _wrongCat;

	return 0;
}
