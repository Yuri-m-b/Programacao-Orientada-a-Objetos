#ifndef SHIELD_H
#define SHIELD_H


class Shield {
public:
    Shield(double _factor) {  _protection_factor = _factor; }
    int protect(int damage) {
        return static_cast<int>(damage * _protection_factor);
    }

private:
    double _protection_factor;
};

#endif // SHIELD_H
