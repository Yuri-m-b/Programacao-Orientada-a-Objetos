#include "skillsattribute.h"

skillsAttribute::skillsAttribute(QString name, int initial_value, QWidget *parent) :
    QWidget(parent), _name(name)
{
    //_name.setFrameStyle(QFrame::Panel | QFrame::Sunken);
    _name.setAlignment(Qt::AlignLeft);

    //_dValue.setFrameStyle(QFrame::Panel | QFrame::Sunken);
    _dValue.setText(QString::number(initial_value));
    _dValue.setAlignment(Qt::AlignRight);

    _frame.addWidget(&_name);
    _frame.addWidget(&_dValue);


    this->setLayout(&_frame);
}

void skillsAttribute::updateValue(int new_value){
    _dValue.setText(QString::number(new_value));
}
