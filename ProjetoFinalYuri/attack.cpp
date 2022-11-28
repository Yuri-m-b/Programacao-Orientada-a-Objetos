#include "attack.h"

#include <QRandomGenerator>

int Attack::getDamage() {
    if(_weapon){
        //return _weapon->getDamage() * _player->attackSkill();
        int dano = _weapon->getDamage() * _player->attackSkill();
        int dano_half = dano/2;
        int dano_final = rand()%(dano-dano_half + 1) + dano_half;
        return dano_final;

        }
    else
        return 10;
}
