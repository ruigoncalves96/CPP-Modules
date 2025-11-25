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
		void setIdea(int idx, const std::string &idea);
		const std::string getIdea(int idx) const;

	private :
		Brain *_brain;
};

#endif
