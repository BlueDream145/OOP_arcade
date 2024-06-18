//
// EPITECH PROJECT, 2019
// pacman
// File description:
// pacman
//

#ifndef PACMAN_H_
#define PACMAN_H_

#include "IGame.hpp"
#include "SE.hpp"

typedef enum dir { Left, Right, Up, Down, Other} dir;

class pacman : public IGame
{
public:
	pacman();
	void get_map(std::string str);
    bool InitMap(void);
    bool DestroyMap(void);
	void fill_map();
	void display();
	bool is_at_pos(int i, int j, std::pair<int, int> value);
	void move_player_left();
	void move_player_right();
	void move_player_up();
	void move_player_down();
	void move_defaut();
	void move_player(std::string move);
	void move_ghost_1(std::string move);
	void move_ghost_2(std::string move);
	void move_ghost_3(std::string move);
	void move_ghost_4(std::string move);
	void move_ghost(std::string move, int nb);
	void move_ghosts();
	void is_angry();
	void reset();
	bool game_won();
	void reset_the_ghost();
	int game_over();
	std::vector<SE *> updateMap(std::string);
	virtual std::vector<SE *> updateTxt();
	~pacman();
private:
	std::vector<std::string> map;
	std::pair <int, int> ghost1;
	std::pair <int, int> ghost2;
	std::pair <int, int> ghost3;
	std::pair <int, int> ghost4;
	std::pair <int, int> player;
	std::pair <int, int> defaut_player_pos;
	std::pair <int, int> defaut_ghost1_pos;
	std::pair <int, int> defaut_ghost2_pos;
	std::pair <int, int> defaut_ghost3_pos;
	std::pair <int, int> defaut_ghost4_pos;
	std::pair <int, int> life_pos;
	std::pair <int, int> score_pos;
	bool angry;
	bool img;
	int a;
	int life;
	int score;
	dir defaut;
	std::vector <SE *> game;
	std::vector <SE *> game_txt;
};

#endif /* !PACMAN_H_ */
