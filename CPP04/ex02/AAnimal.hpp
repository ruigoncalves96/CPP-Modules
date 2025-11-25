#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		AAnimal& operator=(const AAnimal &copy);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0; 

	protected:
		std::string type;
};

#endif
