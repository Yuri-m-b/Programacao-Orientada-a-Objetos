#ifndef INTERFACE_H
#define INTERFACE_H

#include "character.h"
#include <QtWidgets>

class Interface : public QWidget
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

public slots:
    void duel();


private:
    QTextEdit *consoleTxt;
    QHBoxLayout *mainUI;

    QHBoxLayout *gameWindow;
    QHBoxLayout *buttonBox;

    QVBoxLayout *skillsTab;
    QHBoxLayout *levelSkillsTab;

    QVBoxLayout *buttonsTab;
    QVBoxLayout *equipmentTab;

    QPixmap *skills;

    Character * _player;
    Character * _enemy;
};

#endif // INTERFACE_H
