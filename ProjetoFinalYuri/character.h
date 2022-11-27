#ifndef CHARACTER_H
#define CHARACTER_H

class Attack;

#include "weapon.h"
#include "shield.h"

class Character
{
public:
    Character(int l, int lvl){
         life = l;
         level = lvl;
         _weapon = nullptr;
    }

    int getLifeLevel(){
        return life;
    }

    int getLevel(){
        return level;
    }

    int attackSkill(){
        return 1;
    }

    int defenseSkill(){
        return 1;
    }


    void attack(Character * opponent);
    void defend(Attack * att);
    void dmg();

    void setWeapon(Weapon * w) { _weapon = w; }
    void setShield(Shield * s) { _shield = s; }


private:
    int life;
    int atq_skill;
    int def_skill;
    int level;

    Weapon * _weapon;
    Shield * _shield;
};

#endif // CHARACTER_H
