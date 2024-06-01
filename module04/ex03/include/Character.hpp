
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria	*_inv[4];
public:
    Character(void);
	Character(std::string name);
    Character(const Character &copy);
    Character &operator=(const Character &other);
    ~Character(void);

	void				equip(AMateria *m);
	std::string const	&getName(void) const;
	AMateria			*getInv(int idx) const;
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
};

#endif
