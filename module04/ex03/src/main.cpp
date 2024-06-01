
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	AMateria *onGround;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");	
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	me->use(0, *bob);
	me->use(1, *bob);
	onGround = me->getInv(0);
	me->unequip(0);
	me->use(0, *bob); // shouldn't do anything

	Cure cure;
	cure.use(*me);

	std::cout << std::endl;

	Character niko("niko");
	niko.equip(new Cure());
	Character nikoClone = niko;
	nikoClone.use(0, nikoClone);
	
	delete bob;
	delete me;
	delete src;
	delete onGround;
	return 0;
}