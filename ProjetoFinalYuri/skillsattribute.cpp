#include "skillsattribute.h"

skillsAttribute::skillsAttribute(QString name, int initial_value, bool progressBar, int max, int min, QWidget *parent) :
    QWidget(parent), _name(name)
{
    //_name.setFrameStyle(QFrame::Panel | QFrame::Sunken);
    _name.setAlignment(Qt::AlignLeft);

    //_dValue.setFrameStyle(QFrame::Panel | QFrame::Sunken);
    _dValue.setText(QString::number(initial_value));
    _dValue.setAlignment(Qt::AlignRight);

    _progressBar.setMinimum(min);
    _progressBar.setMaximum(max);
    _progressBar.setTextVisible(false);
    _progressBar.setValue(initial_value);

    _frameH.addWidget(&_name);
    _frameH.addWidget(&_dValue);

    if(progressBar){
        _frameV.addLayout(&_frameH);
        _frameV.addWidget(&_progressBar);
        this->setLayout(&_frameV);
    } else {
        this->setLayout(&_frameH);
    }

}

void skillsAttribute::updateValue(int new_value){
    _dValue.setText(QString::number(new_value));
    _progressBar.setValue(new_value);
}
