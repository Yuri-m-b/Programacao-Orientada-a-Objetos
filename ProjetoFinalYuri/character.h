#ifndef CHARACTER_H
#define CHARACTER_H

class Attack;

#include <QObject>
#include "weapon.h"
#include "shield.h"
using namespace std;

class Character: public QObject
{   
    Q_OBJECT

public:
    Character(int l, int m, int lvl, int atk , QString name , QString sprite){
         life = l;
         mana = m;
         level = lvl;
         atq_skill = atk;
         _weapon = nullptr;
         _shield = nullptr;
         _name = name;
         _sprite = sprite;
    }

    int getLifeLevel(){
        return life;
    }

    int getMana(){
        return mana;
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

    QString sprite(){
        return _sprite;
    }

    QString name(){
        return _name;
    }


    void attack(Character * opponent);
    void defend(Attack * att);
    void dmg();
    void newGamePlayer();
    void newGameEnemy();
    void healPOT();
    void healUH();
    void manaPot();
    void bigmanaPot();
    void magia_Exura();

    void setWeapon(Weapon * w) { _weapon = w; }
    void setShield(Shield * s) { _shield = s; }


signals:
    void levelChanged(int level);
    void lifeChanged(int life);
    void manaChanged(int mana);

private:
    int life;
    int atq_skill;
    int def_skill;
    int level;
    int mana;

    int lastDamage;

    QString _name;
    QString _sprite;

    Weapon * _weapon;
    Shield * _shield;

};



#endif // CHARACTER_H
