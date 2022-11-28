#include "interface.h"
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
    _player = new Character(50, 1, 10 );
    _player->setWeapon(new Weapon(8));
    _player->setShield(new Shield(0.05));

    _enemy = new Character(100,1, 12);
    _enemy->setWeapon(new Weapon(10));
    _enemy->setShield(new Shield(0.05));

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
                     this, SLOT(duel()));

    QPixmap pixmap("D:/Faculdade/2023 -1/Programacao Orientada a Objetos/ProjetoFinalYuri/Skills.png");
    QLabel *labelSkillsTab = new QLabel;
    labelSkillsTab->setPixmap(pixmap);

    // Atributos para skill table
    skillsAttribute * level = new skillsAttribute("Level:", _player->getLevel());
    barraProgresso * levelBar = new barraProgresso(0,_player->getLevel(),0);
    skillsAttribute * hitpoints = new skillsAttribute("Hitpoints:", _player->getLifeLevel());
    barraProgresso * hpBar = new barraProgresso(0,_player->getLifeLevel(),1);

    // Layout para a janela principal
    mainUI = new QHBoxLayout;

    // PARA TABELA DE SKILLS
    skillsTab = new QVBoxLayout;
    skillsTab->addWidget(labelSkillsTab);
    skillsTab->addWidget(level);
    skillsTab->addWidget(levelBar);
    skillsTab->addWidget(hitpoints);
    skillsTab->addWidget(hpBar);
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
    QString _enemyhp = QString::number(_enemy->getLifeLevel());
    QString _playerhp = QString::number(_player->getLifeLevel());
    consoleTxt->append("Enemy Life: " );
    consoleTxt->moveCursor(QTextCursor::End); // Move o ponteiro para o final da linha, para escrever o texto de baixo na mesma linha
    consoleTxt->insertPlainText(_enemyhp);
    consoleTxt->append("Player Life: ");
    consoleTxt->moveCursor(QTextCursor::End); // Move o ponteiro para o final da linha, para escrever o texto de baixo na mesma linha
    consoleTxt->insertPlainText(_playerhp);
    int playerINT_hp = _player->getLifeLevel();
    int enemyINT_hp = _enemy->getLifeLevel();
    if(playerINT_hp <= 0){
        consoleTxt->insertPlainText("\nYOU ARE DEAD\nGame Over");

    }
    else if (enemyINT_hp <= 0){
        consoleTxt->insertPlainText("\nVocê derrotou o monstro\nParabéns");
    }
}
