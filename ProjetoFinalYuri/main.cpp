#include "combat.h"
#include "interface.h"

#include <QApplication>
#include "character.h"
#include "weapon.h"
#include "shield.h"
#include "attack.h"


#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

//    Weapon * clava = new Weapon(20);
//    Weapon * faca = new Weapon(50);
//    Weapon * fuzil = new Weapon(200);
//    Shield * escudo = new Shield(0.95);
//    Attack * temp ;

//    Character * player = new Character(100, 10);
//    Character * enemy = new Character(200);

//    cout << "Enemy life " << enemy->getLifeLevel() << endl;

//    player->setWeapon(clava);
//    player->setShield(escudo);

//    player->attack(enemy);

//    cout << "Enemy life " << enemy->getLifeLevel() << endl;

//    enemy->setWeapon(faca);
//    enemy->attack(player);

//    cout << "Player life " << player->getLifeLevel() << endl;


    QApplication app(argc, argv);
    Interface interf;
    interf.show();

    return app.exec();
}
