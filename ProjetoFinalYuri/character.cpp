#include "character.h"
#include "attack.h"

void Character::attack(Character * opponent){
    Attack att(this, _weapon);
    opponent->defend(&att);
}

void Character::defend(Attack * att) {
    int damage = att->getDamage();
    if(_shield){
        damage = _shield->protect(damage);
    }

    life -= damage;
}

