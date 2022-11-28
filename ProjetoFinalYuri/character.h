#ifndef CHARACTER_H
#define CHARACTER_H

class Attack;

#include <QObject>
#include "weapon.h"
#include "shield.h"

class Character: public QObject
{   
    Q_OBJECT

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

    int getLastDamage(){
        return lastDamage;
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

signals:
    void levelChanged(int level);
    void lifeChanged(int life);

private:
    int life;
    int atq_skill;
    int def_skill;
    int level;

    int lastDamage;

    Weapon * _weapon;
    Shield * _shield;
};

#endif // CHARACTER_H
