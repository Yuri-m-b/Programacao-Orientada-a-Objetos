//============================================================================
// Name        : Jogo_Yuri.cpp
// Author      : Yuri
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// https://www.tibiawiki.com.br/wiki/F%C3%B3rmula#Corpo_a_corpo
// https://tibia.fandom.com/wiki/Formulae#Melee
// L = Level ... W = Weapon attack ... S = Skill
// Formula min = (L/5) + [W * (S+4)/4 ]
// min = -(level*0.25) + -(skill*0.4) + -(darma*0.5)
// max = -(level*0.35) + -(skill*0.8) + -(darma*0.6)


class Game{
	public:
		virtual double vida_p();
		virtual double vida_m();
		virtual ~Game() { }
};


class Player : public Game{
	public:
		float player_life = 1000;
		int player_level = 10;
		int player_weapon = 16;
		int player_skill = 20;

	double vida_p(){
		return player_life;
	}
};

class Monster : public Game{
	public:
		float monster_life = 1000;
		int monster_attack = 15;
		int monster_level = 20;

		double vida_m(){
			return monster_life;
		}
};


class Combat1: public Player {
	private:
		int dano_max;
		int dano_min;
		float dano;

	public:
		void fight_playerside(int player_level, int player_weapon, int player_skill ){
			dano_max = (player_level*0.35) + (player_weapon * 0.6) + (player_skill * 0.8);
			dano_min = (player_level*0.25) + (player_weapon * 0.5) + (player_skill * 0.4);
			dano = rand()%(dano_max-dano_min + 1) + dano_min;
		}

		void reducing_life_p(int player_life){
			player_life = player_life - dano;
		}
};

class Combat2: public Monster {
	private:
		int dano_max;
		int dano_min;
		float dano;

	public:
		void fight_monsterside(float monster_attack , int monster_level){
			dano_max = (monster_level*0.35) + (monster_attack * 0.6);
			dano_min = (monster_level*0.25) + (monster_attack * 0.5);
			dano = rand() % dano_min + dano_max;
		}

		void reducing_life_m(int player_life){
			monster_life = player_life - dano;
		}
};


int main() {
	cout << "Iniciando jogo" << endl;

	Player vida_p;

	cout << vida_p()  << endl;


	return 0;
}
