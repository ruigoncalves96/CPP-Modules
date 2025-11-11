#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();

		Cat& operator=(const Cat &copy);

		void makeSound(void) const;
		Brain& getBrain(void);
		const Brain& getBrain(void) const;

	private :
		Brain *_brain;
};

#endif
