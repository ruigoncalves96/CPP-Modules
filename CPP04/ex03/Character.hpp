#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &copy);
		~Character();

		Character& operator=(const Character &copy);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);	
		void printSlots(void) const;

	private:
		std::string _name;
		AMateria *inventory[4];
};

#endif
