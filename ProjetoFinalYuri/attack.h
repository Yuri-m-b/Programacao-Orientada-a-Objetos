#ifndef ATTACK_H
#define ATTACK_H

#include "weapon.h"
#include "character.h"

class Attack {
public:
    Attack(Character * p, Weapon * w):
        _player(p), _weapon(w) { }

    int getDamage();


private:
    Character * _player;
    Weapon * _weapon;
};

#endif // ATTACK_H

