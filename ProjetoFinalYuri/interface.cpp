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


    //-----------BUTTON TAB----------------------------------------------------------------------------------
    // Display é o campo onde fica o texto
    consoleTxt = new QTextEdit("Welcome to the game:");
    consoleTxt->setAlignment(Qt::AlignHCenter);
    consoleTxt->setReadOnly(true);
    endingTxt = new QLabel("");
    endingTxt->setEnabled(false);
    endingTxt->setAlignment(Qt::AlignHCenter);

    //consoleTxt->append("test");
    //display->setFixedHeight(600);

    button_atq = new QPushButton("Attack");
    QObject::connect(button_atq, SIGNAL(clicked()),
                     this, SLOT(duel()));

    button_def = new QPushButton("Defend");
    QObject::connect(button_def, SIGNAL(clicked()),
                     this, SLOT(duel()));
    //-------------------------------------------------------------------------------------------------------

    //-----------ATRIBUTOS TAB-------------------------------------------------------------------------------
    QPixmap pixmap("D:/Faculdade/2023 -1/Programacao Orientada a Objetos/ProjetoFinalYuri/Skills.png");
    QLabel *labelSkillsTab = new QLabel;
    labelSkillsTab->setPixmap(pixmap);

    // Atributos para skill table
    skillsAttribute * level = new skillsAttribute("Level:", _player->getLevel(), true);
    skillsAttribute * hitpoints = new skillsAttribute("Hitpoints:", _player->getLifeLevel(), true, 50);

    QObject::connect(_player, SIGNAL(lifeChanged(int)), hitpoints, SLOT(updateValue(int)));
    //--------------------------------------------------------------------------------------------------------

    //-----------GAMEWINDOW TAB-------------------------------------------------------------------------------
    skillsAttribute * enemy_hitpoints = new skillsAttribute("Enemy Life:", _enemy->getLifeLevel(), true, 100);
    skillsAttribute * player_hitpoints = new skillsAttribute("Player Life:", _player->getLifeLevel(), true, 50);
    QPixmap player_outfit("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Outfit/Mage_Male_Full.png");
    QPixmap enemy_outfit("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Monsters/Rat.png");
    QLabel *enemy_sprite = new QLabel("");
    enemy_sprite->setPixmap(enemy_outfit);
    enemy_sprite->setBaseSize(100,100);
    QLabel *player_sprite = new QLabel("");
    player_sprite->setPixmap(player_outfit);
    player_sprite->setBaseSize(100,100);
    QObject::connect(_enemy, SIGNAL(lifeChanged(int)), enemy_hitpoints, SLOT(updateValue(int)));
    QObject::connect(_player, SIGNAL(lifeChanged(int)), player_hitpoints, SLOT(updateValue(int)));
    //--------------------------------------------------------------------------------------------------------

    //-----------EQUIPMENT TAB-------------------------------------------------------------------------------

    btn_necklace = new QPushButton("");
  //  btn_necklace->setFixedSize(40,40);
    QPixmap necklace_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon necklace_icon(necklace_sprite);
    btn_necklace->setIcon(necklace_icon);
    btn_necklace->setIconSize(necklace_sprite.rect().size());

    btn_helmet = new QPushButton("");
   // btn_helmet->setFixedSize(40,40);
    QPixmap helmet_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon helmet_icon(helmet_sprite);
    btn_helmet->setIcon(helmet_icon);
    btn_helmet->setIconSize(helmet_sprite.rect().size());

    btn_backpack = new QPushButton("");
  //  btn_backpack->setFixedSize(40,40);
    QPixmap backpack_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon backpack_icon(backpack_sprite);
    btn_backpack->setIcon(backpack_icon);
    btn_backpack->setIconSize(helmet_sprite.rect().size());

    btn_leftHand = new QPushButton("");
  //  btn_leftHand->setFixedSize(40,40);
    QPixmap leftHand_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon leftHand_icon(leftHand_sprite);
    btn_leftHand->setIcon(leftHand_icon);
    btn_leftHand->setIconSize(leftHand_sprite.rect().size());

    btn_armor = new QPushButton("");
   // btn_armor->setFixedSize(40,40);
    QPixmap armor_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon armor_icon(armor_sprite);
    btn_armor->setIcon(armor_icon);
    btn_armor->setIconSize(armor_sprite.rect().size());

    btn_rightHand = new QPushButton("");
  //  btn_rightHand->setFixedSize(40,40);
    QPixmap rightHand_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon rightHand_icon(rightHand_sprite);
    btn_rightHand->setIcon(rightHand_icon);
    btn_rightHand->setIconSize(rightHand_sprite.rect().size());

    btn_ring = new QPushButton("");
  //  btn_ring->setFixedSize(40,40);
    QPixmap ring_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon ring_icon(ring_sprite);
    btn_ring->setIcon(ring_icon);
    btn_ring->setIconSize(ring_sprite.rect().size());

    btn_boots = new QPushButton("");
   // btn_boots->setFixedSize(40,40);
    QPixmap boots_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon boots_icon(boots_sprite);
    btn_boots->setIcon(boots_icon);
    btn_boots->setIconSize(boots_sprite.rect().size());

    btn_utility = new QPushButton("");
   // btn_utility->setFixedSize(40,40);
    QPixmap utility_sprite("C:/Users/Aluno/Downloads/ProjetoFinalYuri/Itens/aol.png");
    QIcon utility_icon(utility_sprite);
    btn_utility->setIcon(utility_icon);
    btn_utility->setIconSize(utility_sprite.rect().size());

    //--------------------------------------------------------------------------------------------------------

    // Layout para a janela principal
    mainUI = new QHBoxLayout;

    // PARA TABELA DE SKILLS
    skillsTab = new QVBoxLayout;
    skillsTab->addWidget(labelSkillsTab);
    skillsTab->addWidget(level);
    skillsTab->addWidget(hitpoints);
    skillsTab->addStretch();

    buttonBox = new QHBoxLayout;
    buttonBox->addWidget(button_atq);
    buttonBox->addWidget(button_def);

    buttonsTab = new QVBoxLayout;
    enemyHUD = new QHBoxLayout;
    enemyHUD->addWidget(enemy_hitpoints);
    enemyHUD->addWidget(enemy_sprite);
    playerHUD = new QHBoxLayout;
    playerHUD->addWidget(player_sprite);
    playerHUD->addWidget(player_hitpoints);

    buttonsTab->addLayout(enemyHUD);
    buttonsTab->addLayout(playerHUD);

    buttonsTab->addLayout(buttonBox);
    buttonsTab->addWidget(consoleTxt);
    buttonsTab->addWidget(endingTxt);

    equipmentTab = new QVBoxLayout;
    equipmentTop = new QHBoxLayout;
    equipmentMid = new QHBoxLayout;
    equipmentBot = new QHBoxLayout;

    equipmentTop->addWidget(btn_necklace);
    equipmentTop->addWidget(btn_helmet);
    equipmentTop->addWidget(btn_backpack);

    equipmentMid->addWidget(btn_leftHand);
    equipmentMid->addWidget(btn_armor);
    equipmentMid->addWidget(btn_rightHand);

    equipmentBot->addWidget(btn_ring);
    equipmentBot->addWidget(btn_boots);
    equipmentBot->addWidget(btn_utility);

    equipmentTab->addLayout(equipmentTop);
    equipmentTab->addLayout(equipmentMid);
    equipmentTab->addLayout(equipmentBot);

    mainUI->addLayout(skillsTab,Qt::AlignLeft);
    mainUI->addLayout(buttonsTab,Qt::AlignCenter);
    mainUI->addLayout(equipmentTab,Qt::AlignRight);

    setLayout(mainUI);
}

Interface::~Interface(){

}

void Interface::duel(){
    _player->attack(_enemy);
    _enemy->attack(_player);
    QString _enemyhp = QString::number(_enemy->getLastDamage());
    QString _playerhp = QString::number(_player->getLastDamage());
    consoleTxt->append("\nEnemy lost "+ _enemyhp +" due to your attack." );
    consoleTxt->moveCursor(QTextCursor::End); // Move o ponteiro para o final da linha, para escrever o texto de baixo na mesma linha
    consoleTxt->append("You lost "+ _playerhp +" due to enemy attack.");
    consoleTxt->moveCursor(QTextCursor::End); // Move o ponteiro para o final da linha, para escrever o texto de baixo na mesma linha
    int playerINT_hp = _player->getLifeLevel();
    int enemyINT_hp = _enemy->getLifeLevel();
    if(playerINT_hp <= 0){
        consoleTxt->setEnabled(false);
        endingTxt->setEnabled(true);
        endingTxt->setText("<h2><font color = red>\nYOU ARE DEAD\nGame Over</font></h2>");
        button_atq->setEnabled(false);
        button_def->setEnabled(false);
    }
    else if (enemyINT_hp <= 0){
        consoleTxt->setEnabled(false);
        endingTxt->setEnabled(true);
        endingTxt->setText("<h2><font color = green>\nYOU WON\nContinue?</font></h2>");
        button_atq->setEnabled(false);
        button_def->setEnabled(false);
    }
}
