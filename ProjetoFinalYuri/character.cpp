#include "character.h"
#include "attack.h"
#include <QRandomGenerator>

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


void Character::newGamePlayer(){
    life = 100;
    level = 10;
    emit lifeChanged(life);
    emit levelChanged(level);
}

void Character::newGameEnemy(){
    life = 100;
    level = 1;
    emit lifeChanged(life);
}

void Character::healPOT(){

    int rand = QRandomGenerator::global()->bounded(640, 840);
    int healPotion = rand;
    life = life + healPotion;
    if (life > 1000)
        life = 1000;
    emit lifeChanged(life);
}

void Character::healUH(){
    int rand = QRandomGenerator::global()->bounded(50, 200);
    int healPotion = rand;
    life = life + healPotion;
    if (life > 1000)
        life = 1000;
    emit lifeChanged(life);
}

void Character::manaPot(){
    int rand = QRandomGenerator::global()->bounded(50, 80);
    int manaPotion = rand;
    mana = mana + manaPotion;
    if (mana > 360)
        mana = 360;
    emit manaChanged(mana);
}

void Character::bigmanaPot(){
    int rand = QRandomGenerator::global()->bounded(100, 250);
    int manaPotion = rand;
    mana = mana + manaPotion;
    if (mana > 360)
        mana = 360;
    emit manaChanged(mana);
}

void Character::magia_Exura(){
    int rand = QRandomGenerator::global()->bounded(20, 100);
    int exura = rand;
    life = life + exura;
    if (life > 1000)
        life = 1000;
    emit lifeChanged(life);
    mana = mana - 25;
    if (mana < 0)
        mana = 0;
    emit manaChanged(mana);
}
