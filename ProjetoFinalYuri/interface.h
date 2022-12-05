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
    QPushButton *button_atq;
    QPushButton *button_def;

    QTextEdit *consoleTxt;
    QLabel *endingTxt;
    QHBoxLayout *mainUI;

    QHBoxLayout *gameWindow;
    QHBoxLayout *enemyHUD;
    QHBoxLayout *playerHUD;

    QVBoxLayout *skillsTab;
    QHBoxLayout *levelSkillsTab;

    QVBoxLayout *buttonsTab;
    QHBoxLayout *buttonBox;

    QVBoxLayout *equipmentTab;
    QHBoxLayout *equipmentTop;
    QHBoxLayout *equipmentMid;
    QHBoxLayout *equipmentBot;
    QPushButton *btn_necklace;
    QPushButton *btn_helmet;
    QPushButton *btn_backpack;
    QPushButton *btn_leftHand;
    QPushButton *btn_armor;
    QPushButton *btn_rightHand;
    QPushButton *btn_ring;
    QPushButton *btn_boots;
    QPushButton *btn_utility;

    QHBoxLayout *backpackTab;
    QHBoxLayout *backpackLine2;
    QPushButton *backpackSlot1;
    QPushButton *backpackSlot2;
    QPushButton *backpackSlot3;
    QPushButton *backpackSlot4;
    QPushButton *backpackSlot5;
    QPushButton *backpackSlot6;
    QPushButton *backpackSlot7;
    QPushButton *backpackSlot8;

    QPixmap *skills;

    Character * _player;
    Character * _enemy;
    string _enemySprite;

    int monster_id;

    vector<Character*> _monster;


};

#endif // INTERFACE_H
