#ifndef SKILLSATTRIBUTE_H
#define SKILLSATTRIBUTE_H

#include <QtWidgets>

class skillsAttribute : public QWidget
{
    Q_OBJECT
public:
    explicit skillsAttribute(QString name, int initial_value, QWidget *parent = nullptr);

signals:

public slots:
    void updateValue(int new_value);


private:
    QLabel _name;
    int    _value;
    QHBoxLayout _frame;
    QLabel _dValue;

};

#endif // SKILLSATTRIBUTE_H
