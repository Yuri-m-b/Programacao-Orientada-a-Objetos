#include "barraprogresso.h"

barraProgresso::barraProgresso(int min_value, int max_value, int bar_type, QWidget *parent) : QWidget(parent)
{
    _valueMin = min_value;
    _valueMax = max_value;
    _barType = bar_type;
    barraProg.setMinimum(_valueMin);
    barraProg.setMaximum(_valueMax);

    if (bar_type == 0){
        _frameBar.addWidget(&barraProg);
        setLayout(&_frameBar);
    }

    else{
        barraProg.invertedAppearance();
        _frameBar.addWidget(&barraProg);
        setLayout(&_frameBar);
    }

}



