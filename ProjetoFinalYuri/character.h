#ifndef CHARACTER_H
#define CHARACTER_H

class Attack;

#include "weapon.h"
#include "shield.h"

class Character
{
public:
    Character(int l, int lvl, int atk){
         life = l;
         level = lvl;
         atq_skill = atk;
         _weapon = nullptr;
    }

    int getLifeLevel(){
        return life;
    }

    int getLevel(){
        return level;
    }

    int attackSkill(){
        return atq_skill;
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
