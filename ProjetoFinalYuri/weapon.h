#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon(int d) { _damage = d; }
    int getDamage() { return _damage; }

private:
    int _damage;
};

#endif // WEAPON_H
