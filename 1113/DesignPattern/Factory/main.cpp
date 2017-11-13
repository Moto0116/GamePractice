#include <stdio.h>

class Weapon
{

};
class Bomb
{

};

class AbstractWeapons
{
public:
	virtual Weapon* CreateWeapon() = 0;
	virtual Bomb* CreateBomb() = 0;
};


class AbstractWeaponsType1 : public AbstractWeapons
{
public:
	virtual Weapon* CreateWeapon() {
		return new Weapon;
	}
	virtual Bomb* CreateBomb() {
		return new Bomb;
	}
};


class Type1Macine
{
private:
	Weapon *m_Weapon;   // �E�F�|���I�u�W�F�N�g�ւ̃|�C���^
	Bomb *m_Bomb;      // �{���I�u�W�F�N�g�ւ̃|�C���^

public:
	void Create(AbstractWeapons *AbsWep)
	{
		m_Weapon = AbsWep->CreateWeapon();
		m_Bomb = AbsWep->CreateBomb();
	}
};


void main()
{
	Type1Macine MyshipT1;
	AbstractWeaponsType1 AbsWepT1;

	MyshipT1.Create(&AbsWepT1);
}