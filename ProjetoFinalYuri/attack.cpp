#include "attack.h"

int Attack::getDamage() {
    if(_weapon){
        return _weapon->getDamage() * _player->attackSkill();
        }
    else
        return 10;
}
