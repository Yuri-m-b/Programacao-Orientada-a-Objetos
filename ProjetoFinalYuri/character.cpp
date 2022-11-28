#include "character.h"
#include "attack.h"

void Character::attack(Character * opponent){
    Attack att(this, _weapon);
    opponent->defend(&att);
}

void Character::defend(Attack * att) {
    lastDamage = att->getDamage();
    if(_shield){
        lastDamage = _shield->protect(lastDamage);
    }

    life -= lastDamage;
    if(life < 0) life = 0;
    emit lifeChanged(life);
}


