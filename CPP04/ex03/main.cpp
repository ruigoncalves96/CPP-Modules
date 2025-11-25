# include "MateriaSource.hpp"
# include "Character.hpp"

int main(void)
{
	IMateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

    std::cout << "\n=== Test 1: Basic Functionality ===" << std::endl;
    {
    	AMateria* spell_1 = source->createMateria("ice");
   		AMateria* spell_2 = source->createMateria("cure");

        ICharacter* hero = new Character("Hero");
        
        hero->equip(spell_1);
        hero->equip(spell_2);
        
        ICharacter* enemy = new Character("Enemy");
        
        hero->use(0, *enemy);
        hero->use(1, *enemy);

        hero->use(-2, *enemy);
        hero->use(4, *enemy);
        
        delete enemy;
        delete hero;
    }
	std::cout << "\n=== Test 2: Full Inventory ===" << std::endl;
    {
		AMateria* spell_1 = source->createMateria("ice");
		AMateria* spell_2 = source->createMateria("cure");
    	AMateria* spell_3 = source->createMateria("ice");
		AMateria* spell_4 = source->createMateria("cure");
    	AMateria* spell_5 = source->createMateria("ice");

        ICharacter* mage = new Character("Mage");
        
        mage->equip(spell_1);
        mage->equip(spell_2);
        mage->equip(spell_3);
        mage->equip(spell_4);

        mage->equip(spell_5);

		mage->printSlots();

		delete spell_5;
        delete mage;
    }

    std::cout << "\n=== Test 3: Unequip ===" << std::endl;
    {
    	AMateria* spell_1 = source->createMateria("ice");
   		AMateria* spell_2 = source->createMateria("cure");

        ICharacter* player = new Character("Player");

        player->equip(spell_1);
        player->equip(spell_2);

		player->printSlots();
        
        player->unequip(0);
        player->unequip(1);

		player->printSlots();
        
        player->use(0, *player); // Should do nothing (empty slot)
        
        delete spell_1;
        delete spell_2;
        delete player;
    }

    std::cout << "\n=== Test 4: Unknown Materia Type ===" << std::endl;
    {
        IMateriaSource* lib = new MateriaSource();
        lib->learnMateria(new Ice());
        
        AMateria* unknown = lib->createMateria("fire"); // Should return NULL
        if (!unknown)
            std::cout << "Unknown materia type correctly handled" << std::endl;
        
        delete lib;
    }

	std::cout << "\n=== Test 5: Deep Copy ===" << std::endl;
    {
    	AMateria* spell_1 = source->createMateria("ice");

        Character* original = new Character("Original");
        original->equip(spell_1);
        
        Character* copy = new Character(*original);
        
        ICharacter* target = new Character("Target");
        
        std::cout << "Original -> ";
        original->use(0, *target);
        std::cout << "Copy -> ";
        copy->use(0, *target);
        
        delete target;
        delete copy;
        delete original;
    }

    std::cout << "\n=== Test 6: MateriaSource Limits ===" << std::endl;
    {
        IMateriaSource* vault = new MateriaSource();
        
        vault->learnMateria(new Ice());
        vault->learnMateria(new Cure());
        vault->learnMateria(new Ice());
        vault->learnMateria(new Cure());
        vault->learnMateria(new Ice()); // Should be deleted (limit is 4)
        
        delete vault;
    }

	delete source;

	return 0;
}
