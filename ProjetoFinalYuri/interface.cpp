#include "interface.h"
#include "combat.h"
#include "character.h"
#include "skillsattribute.h"
#include "barraprogresso.h"

#include <QtWidgets>
#include <QGridLayout>
#include <QLineEdit>
#include <QtMath>
#include <QApplication>
#include <QStyle>


Interface::Interface(QWidget *parent) : QWidget(parent)
{
    //Titulo da Janela
    this->setWindowTitle("Jogo");
    setFixedSize(600,600); // Tamanho da Janela

    //--------INICIALIZAÇÃO DO PERSONAGEM---------
    _player = new Character(50, 1);
    _player->setWeapon(new Weapon(8));
    _player->setShield(new Shield(0.05));

    _enemy = new Character(10,1);
    _enemy->setWeapon(new Weapon(10));

    //-------FIM DA CRIAÇÃO DO PERSONAGEM----------

    // Display é o campo onde fica o texto
    consoleTxt = new QTextEdit("Welcome to the game:");
    consoleTxt->setReadOnly(true);
    consoleTxt->setAlignment(Qt::AlignHCenter);
    //consoleTxt->append("test");
    //display->setFixedHeight(600);

    QPushButton *button_atq = new QPushButton("Attack");
    QObject::connect(button_atq, SIGNAL(clicked()),
                     this, SLOT(duel()));

    QPushButton *button_def = new QPushButton("Defend");
    QObject::connect(button_def, SIGNAL(clicked()),
                     this, SLOT());

    QPixmap pixmap("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Skills.png");
    QIcon ButtonIcon(pixmap);
    QPushButton *botaoSkillsTab = new QPushButton;
    botaoSkillsTab->setIcon(ButtonIcon);
    botaoSkillsTab->setIconSize(pixmap.rect().size());


    // Atributos para skill table
    skillsAttribute * level = new skillsAttribute("Level:", _player->getLevel());
    barraProgresso * levelBar = new barraProgresso(0,_player->getLevel());
    skillsAttribute * hitpoints = new skillsAttribute("Hitpoints:", _player->getLifeLevel());

    // Layout para a janela principal
    mainUI = new QHBoxLayout;

    // PARA TABELA DE SKILLS
    skillsTab = new QVBoxLayout;
    skillsTab->addWidget(level);
    skillsTab->addWidget(levelBar);
    skillsTab->addWidget(hitpoints);
    skillsTab->addStretch();

    gameWindow = new QHBoxLayout;

    buttonBox = new QHBoxLayout;
    buttonBox->addWidget(button_atq);
    buttonBox->addWidget(button_def);

    buttonsTab = new QVBoxLayout;
    buttonsTab->addLayout(buttonBox);
    buttonsTab->addWidget(consoleTxt);

    equipmentTab = new QVBoxLayout;

    mainUI->addLayout(skillsTab);
    mainUI->addLayout(gameWindow);
    mainUI->addLayout(buttonsTab);
    mainUI->addLayout(equipmentTab);

    setLayout(mainUI);
}

Interface::~Interface(){

}

void Interface::duel(){
    _player->attack(_enemy);
    _enemy->attack(_player);
}
