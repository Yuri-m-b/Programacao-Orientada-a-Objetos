#include "barraprogresso.h"

barraProgresso::barraProgresso(int min_value, int max_value, QWidget *parent) : QWidget(parent)
{
    _valueMin = min_value;
    _valueMax = max_value;
    barraProg.setMinimum(_valueMin);
    barraProg.setMaximum(_valueMax);

    _frameBar.addWidget(&barraProg);
    setLayout(&_frameBar);
}


