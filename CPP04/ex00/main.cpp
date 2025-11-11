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
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n[ Get type of animal ]\n";
	std::cout << j->getType() << "\n";
	std::cout << i->getType() << "\n";

	std::cout << "\n[ SPEAK! ]\n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n[ Destruction fase ]\n";
	delete meta;
	delete j;
	delete i;

	std::cout << "\n|===== Bad Polymorphism =====|\n" << std::endl;

	std::cout << "[ Construction fase ]\n";
	const WrongAnimal* _meta = new WrongAnimal();
	const WrongAnimal* _i = new WrongCat();

	std::cout << "\n[ Get type of animal ]\n";
	std::cout << _i->getType() << "\n";

	std::cout << "\n[ SPEAK! ]\n";
	_i->makeSound();
	_meta->makeSound();

	std::cout << "\n[ Destruction fase ]\n";
	delete _meta;
	delete _i;

	return 0;
}
