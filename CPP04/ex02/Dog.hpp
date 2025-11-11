#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();

		Dog& operator=(const Dog &copy);

		void makeSound(void) const;
		Brain& getBrain(void);
		const Brain& getBrain(void) const;

	private :
		Brain *_brain;
};

#endif
