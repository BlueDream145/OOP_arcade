//
// EPITECH PROJECT, 2019
// snake
// File description:
// snake
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../../include/pacman.hpp"

extern "C" IGame *createObj(void) 
{
    return new pacman();
}

extern "C" void destroyObj(IGame *gam) 
{
    delete gam;
}

bool pacman::InitMap()
{ return (true); }

bool pacman::DestroyMap()
{ return (true); }

void pacman::get_map(std::string str)
{
	std::string line;
	std::ifstream file;
	file.open(str.c_str());
	if (!file.is_open())
	{
		std::cerr << str << " No such file or directory"
			  << std::endl;
		return ;
	}
	while ((getline(file, line)))
		this->map.push_back(line);
	return ;
}

void pacman::fill_map()
{
	int i = 0, j = 0, G = 0;
	while (i != map.size())
	{
		while (this->map[i][j])
		{
			if (this->map[i][j] == ' ' && j > 0 && (j < this->map[i].size() - 1))
				this->map[i][j] = '.';
			else  if (this->map[i][j] == 'G')
			{
				if (G == 0)
				{
					this->ghost1.first = i;
					this->ghost1.second = j;
				}
				else if (G == 1)
				{
					this->ghost2.first = i;
					this->ghost2.second = j;
				}

				else if (G == 2)
				{
					this->ghost3.first = i;
					this->ghost3.second = j;
				}
				else if (G == 3)
				{
					this->ghost4.first = i;
					this->ghost4.second = j;
				}
				this->map[i][j] = ' ';
				G++;
			}
			else if (this->map[i][j] == 'C')
			{
				this->player.first = i;
				this->player.second = j;
				this->map[i][j] = ' ';
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

bool pacman::is_at_pos(int i, int j, std::pair <int, int> value)
{
	if (i == value.first && j == value.second)
		return (true);
	return (false);
}

void pacman::reset()
{
	ghost1 = defaut_ghost1_pos;
	ghost2 = defaut_ghost2_pos;
	ghost3 = defaut_ghost3_pos;
	ghost4 = defaut_ghost4_pos;
	player = defaut_player_pos;
	defaut = Other;
	return ;
}

bool pacman::game_won()
{
	int i = 0, j = 0;
	while (i != map.size())
	{
		while (j != map[i].size())
		{
			if (map[i][j] == '.')
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

void pacman::reset_the_ghost()
{
	if (this->is_at_pos(player.first, player.second, ghost1) == true)
		ghost1 = defaut_ghost1_pos;
	else if (this->is_at_pos(player.first, player.second, ghost2) == true)
		ghost2 = defaut_ghost2_pos;
	else if (this->is_at_pos(player.first, player.second, ghost3) == true)
		ghost3 = defaut_ghost3_pos;
	else if (this->is_at_pos(player.first, player.second, ghost4) == true)
		ghost4 = defaut_ghost4_pos;
	return ;
}

int pacman::game_over()
{
	if (this->game_won() == true)
		return (2); //2 a win
	else if ((this->is_at_pos(player.first, player.second, ghost1) == true)
		 || (this->is_at_pos(player.first, player.second, ghost2) == true)
		 || (this->is_at_pos(player.first, player.second, ghost3) == true)
		 || (this->is_at_pos(player.first, player.second, ghost4) == true))
	{
		if (angry == true)
		{
			this->reset_the_ghost();
			return (0); //0 pas perdu
		}
		else if (this->angry != true)
		{
			this->life--;
			this->reset();
			if (life <= 0)
				return (1);// 1 perdu
			else
				return (0);
					
		}
		return (false);
	}
	return (false);
}

void pacman::display()
{
	int i = 0, j = 0;
	while (i != this->map.size())
	{
		while (this->map[i][j])
		{
			if (is_at_pos(i, j, this->ghost1) == true)
				std::cout << '1';
			else if (is_at_pos(i, j, this->ghost2) == true)
				std::cout << '2';
			else if (is_at_pos(i, j, this->ghost3) == true)
				std::cout << '3';
			else if (is_at_pos(i, j, this->ghost4) == true)
				std::cout << '4';
			else if (is_at_pos(i, j, this->player) == true)
			{
				if (this->angry == true)
					std::cout << 'M';
				else
					std::cout << 'C';
			}
			else
				std::cout << this->map[i][j];
			j++;
		}
		j = 0;
		i++;
		std::cout << std::endl;
	}
	return;
}

void pacman::move_player_left()
{
	if (this->map[this->player.first][this->player.second - 1] != 'B'
		&& this->map[this->player.first][this->player.second - 1] != '-')
		{
			if (this->player.second == 0)
				this->player.second = this->map[player.first].size() - 1;
			else
				this->player.second--;
			if (this->map[player.first][player.second] == '.')
				this->score++;
			if (this->map[player.first][player.second] == 'P')
				this->angry = true;
			this->map[player.first][player.second] = ' ';
			this->defaut = Left;
		}
	return ;
}

void pacman::move_player_right()
{
	if (this->map[this->player.first][this->player.second + 1] != 'B'
	    && this->map[this->player.first][this->player.second + 1] != '-')
	{
		if (this->player.second == this->map[this->player.first].size() - 1)
			this->player.second = 0;
		else
			this->player.second++;
		if (this->map[this->player.first][this->player.second] == '.')
			this->score++;
		if (this->map[this->player.first][this->player.second] == 'P')
			this->angry = true;
		this->map[this->player.first][this->player.second] = ' ';
		this->defaut = Right;
	}
	return ;
}

void pacman::move_player_up()
{
	if (this->map[this->player.first - 1][this->player.second] != 'B'
	    && this->map[this->player.first - 1][this->player.second] != '-')
	{
		this->player.first--;
		if (this->map[this->player.first][this->player.second] == '.')
			this->score++;
		if (this->map[this->player.first][this->player.second] == 'P')
			this->angry = true;
		this->map[this->player.first][this->player.second] = ' ';
		this->defaut = Up;
	}
	return ;
}


void pacman::move_player_down()
{
	if (this->map[this->player.first + 1][this->player.second] != 'B'
		&& this->map[this->player.first + 1][this->player.second] != '-')
	{
		this->player.first++;
		if (this->map[this->player.first][this->player.second] == '.')
			this->score++;
		if(this->map[this->player.first][this->player.second] == 'P')
			this->angry = true;
		this->map[this->player.first][this->player.second] = ' ';
		this->defaut = Down;
	}

	return ;
}

void pacman::move_defaut()
{
	if (this->defaut == Down)
		this->move_player_down();
	else if (this->defaut == Up)
		this->move_player_up();
	else if (this->defaut == Right)
		this->move_player_right();
	else if (this->defaut == Left)
		this->move_player_left();
	return ;
}

void pacman::move_player(std::string move)
{
	if (move.compare("Up") == 0)
		this->move_player_up();
	else if (move.compare("Down") == 0)
		this->move_player_down();
	else if (move.compare("Left") == 0)
		this->move_player_left();
	else if (move.compare("Right") == 0)
		this->move_player_right();
	else
		this->move_defaut();
	if(this->img == true)
		this->img = false;
	else
		this->img = true;
}

void pacman::move_ghost_1(std::string move)
{
	if (move.compare("Up") == 0)
	{
		if (this->map[this->ghost1.first - 1][this->ghost1.second] != 'B')
			this->ghost1.first--;
	}
	else if (move.compare("Down") == 0)
	{
		if (this->map[this->ghost1.first + 1][this->ghost1.second] != 'B')
			this->ghost1.first++;
	}
	else if (move.compare("Left") == 0)
	{
		if (this->map[this->ghost1.first][this->ghost1.second - 1] != 'B')
			if (this->ghost1.second == 0)
				this->ghost1.second = this->map[ghost1.first].size();
			else
				this->ghost1.second--;
	}
	else if (move.compare("Right") == 0)
	{
		if (this->map[this->ghost1.first][this->ghost1.second + 1] != 'B')
		{
			if (this->ghost1.second == this->map[this->ghost1.first].size())
				this->ghost1.second = 0;
			else
				this->ghost1.second++;
		}
	}
	return ;
}

void pacman::move_ghost_2(std::string move)
{
	if (move.compare("Up") == 0)
	{
		if (this->map[this->ghost2.first - 1][this->ghost2.second] != 'B')
			this->ghost2.first--;
	}
	else if (move.compare("Down") == 0)
	{
		if (this->map[this->ghost2.first + 1][this->ghost2.second] != 'B')
			this->ghost2.first++;
	}
	else if (move.compare("Left") == 0)
	{
		if (this->map[this->ghost2.first][this->ghost2.second - 1] != 'B')
			if (this->ghost2.second == 0)
				this->ghost2.second = this->map[ghost2.first].size();
			else
				this->ghost2.second--;
	}
	else if (move.compare("Right") == 0)
	{
		if (this->map[this->ghost2.first][this->ghost2.second + 1] != 'B')
		{
			if (this->ghost2.second == this->map[this->ghost2.first].size())
				this->ghost2.second = 0;
			else
				this->ghost2.second++;
		}
	}
	return ;
}

void pacman::move_ghost_3(std::string move)
{
	if (move.compare("Up") == 0)
	{
		if (this->map[this->ghost3.first - 1][this->ghost3.second] != 'B')
			this->ghost3.first--;
	}
	else if (move.compare("Down") == 0)
	{
		if (this->map[this->ghost3.first + 1][this->ghost3.second] != 'B')
			this->ghost3.first++;
	}
	else if (move.compare("Left") == 0)
	{
		if (this->map[this->ghost3.first][this->ghost3.second - 1] != 'B')
			if (this->ghost3.second == 0)
				this->ghost3.second = this->map[ghost3.first].size();
			else
				this->ghost3.second--;
	}
	else if (move.compare("Right") == 0)
	{
		if (this->map[this->ghost3.first][this->ghost3.second + 1] != 'B')
		{
			if (this->ghost3.second == this->map[this->ghost3.first].size())
				this->ghost3.second = 0;
			else
				this->ghost3.second++;
		}
	}
	return ;
}

void pacman::move_ghost_4(std::string move)
{
	if (move.compare("Up") == 0)
	{
		if (this->map[this->ghost4.first - 1][this->ghost4.second] != 'B')
			this->ghost4.first--;
	}
	else if (move.compare("Down") == 0)
	{
		if (this->map[this->ghost4.first + 1][this->ghost4.second] != 'B')
			this->ghost4.first++;
	}
	else if (move.compare("Left") == 0)
	{
		if (this->map[this->ghost4.first][this->ghost4.second - 1] != 'B')
			if (this->ghost4.second == 0)
				this->ghost4.second = this->map[ghost4.first].size();
			else
				this->ghost4.second--;
	}
	else if (move.compare("Right") == 0)
	{
		if (this->map[this->ghost4.first][this->ghost4.second + 1] != 'B')
		{
			if (this->ghost4.second == this->map[this->ghost4.first].size())
				this->ghost4.second = 0;
			else
				this->ghost4.second++;
		}
	}
	return ;
}

void pacman::move_ghost(std::string move, int nb)
{
	if (nb == 0)
		move_ghost_1(move);
	else if (nb == 1)
		move_ghost_2(move);
	else if (nb == 2)
		move_ghost_3(move);
	else if (nb == 3)
		move_ghost_4(move);
	return ;
}

void pacman::move_ghosts()
{
	int i;
	int j;
	int k;
	int l;

	srand(time(NULL));
	i = rand()%(4 - 0 + 1) + 1;
	j = rand()%(4 - 0 + 1) + 1;
	k = rand()%(4 - 0 + 1) + 1;
	l = rand()%(4 - 0 + 1) + 1;
	if ( i == 1)
		this->move_ghost("Up", 0);
	else if (i == 2)
		this->move_ghost("Down", 0);
	else if (i == 3)
		this->move_ghost("Left", 0);
	else if (i == 4)
		this->move_ghost("Right", 0);
	if ( j == 1)
		this->move_ghost("Up", 1);
	else if (j == 2)
		this->move_ghost("Down", 1);
	else if (j == 3)
		this->move_ghost("Left", 1);
	else if (j == 4)
		this->move_ghost("Right", 1);
	if ( k == 1)
		this->move_ghost("Up", 2);
	else if (k == 2)
		this->move_ghost("Down", 2);
	else if (k == 3)
		this->move_ghost("Left", 2);
	else if (k == 4)
		this->move_ghost("Right", 2);
	if ( l == 1)
		this->move_ghost("Up", 3);
	else if (l == 2)
		this->move_ghost("Down", 3);
	else if (l == 3)
		this->move_ghost("Left", 3);
	else if (l == 4)
		this->move_ghost("Right", 3);
}

void pacman::is_angry()
{
	if (this->angry == true && this->a > 0)
		this->a--;
	else if (this->a == 0 && this->angry == true)
	{
		this->a = 100;
		this->angry = false;
	}
	return ;
}

pacman::pacman()
{
	this->get_map("map.txt");
	this->fill_map();
	this->life = 3;
	this->score = 0;
	this->defaut = Other;
	this->angry = false;
	this->a = 100;
	this->img = true;
	this->defaut_player_pos = this->player;
	this->defaut_ghost1_pos = this->ghost1;
	this->defaut_ghost2_pos = this->ghost2;
	this->defaut_ghost3_pos = this->ghost3;
	this->defaut_ghost4_pos = this->ghost4;
	this->life_pos.first = 50;
	this->life_pos.second = 50;
	this->score_pos.first = 60;
	this->score_pos.second = 60;
}

pacman::~pacman(){}

std::vector<SE *> pacman::updateMap(std::string move)
{
	this->move_player(move);
	this->move_ghosts();
	this->is_angry();
	this->game.clear();
	Rect *tmp;
	int j = 0;
	for(int iter = 0; iter < this->map.size(); iter++)
	{
		while (j <= map[iter].length())
		{
			tmp = new Rect();
			if (this->map[iter][j] == 'B' || this->map[iter][j] == '-')
			{
				tmp->set_path("./rsc/snake_img/mur.png");
				tmp->set_color("Blue");
			}
			else if (this->map[iter][j] == ' ')
			{
				tmp->set_path("./rsc/snake_img/SOL.png");
				tmp->set_color("Yellow");
			}
			else if (this->map[iter][j] == '.')
			{
				tmp->set_path("./rsc/snake_img/snake_food.png");
				tmp->set_color("Magenta");
			}
			else if (this->map[iter][j] == 'P')
			{
				tmp->set_path("./rsc/snake_img/super_bonus.png");
				tmp->set_color("Magenta");
			}
			std::pair <int, int> bis;
			bis.first = iter;
			bis.second = j;
			tmp->set_pos(bis);
			tmp->set_bool(true);
			tmp->dim.first = 1;
			tmp->dim.second = 1;
			this->game.push_back(tmp);
			j++;
		}
		j = 0;
		iter++;
	}
	tmp = new Rect();
	tmp->set_pos(this->ghost1);
	tmp->set_bool(false);
	if (this->angry == true)
		tmp->set_path("./rsc/snake_img/ghosts_flee.png");
	else
		tmp->set_path("./rsc/snake_img/blue_ghost.png");
	tmp->set_color("Red");
	tmp->dim.first = 1;
	tmp->dim.second = 1;
	this->game.push_back(tmp);
	tmp = new Rect();
	tmp->set_pos(this->ghost2);
	tmp->set_bool(false);
	if (this->angry == true)
		tmp->set_path("./rsc/snake_img/ghosts_flee.png");
	else
		tmp->set_path("./rsc/snake_img/pink_ghost.png");
	tmp->set_color("Red");
	tmp->dim.first = 1;
	tmp->dim.second = 1;
	this->game.push_back(tmp);
	tmp = new Rect();
	tmp->set_pos(this->ghost3);
	tmp->set_bool(false);
	if (this->angry == true)
		tmp->set_path("./rsc/snake_img/ghosts_flee.png");
	else
		tmp->set_path("./rsc/snake_img/red_ghost.png");
	tmp->set_color("Red");
	tmp->dim.first = 1;
	tmp->dim.second = 1;
	this->game.push_back(tmp);
//	delete tmp;
	tmp = new Rect();
	tmp->set_pos(this->ghost4);
	tmp->set_bool(false);
	if (this->angry == true)
		tmp->set_path("./rsc/snake_img/ghosts_flee.png");
	else
		tmp->set_path("./rsc/snake_img/yellow_ghost.png");
	tmp->set_color("Red");
	tmp->dim.first = 1;
	tmp->dim.second = 1;
	this->game.push_back(tmp);
//	delete tmp;
	tmp = new Rect();
	tmp->set_pos(this->player);
	tmp->set_bool(false);
	if (this->defaut == Up)
	{
		if (this->img == true)
			tmp->set_path("./rsc/snake_img/pacman_up_first.png");
		else
			tmp->set_path("./rsc/snake_img/pacman_up_second.png");
	}
	else if (this->defaut == Down)
	{
		if (this->img == true)
			tmp->set_path("./rsc/snake_img/pacman_down_first.png");
		else
			tmp->set_path("./rsc/snake_img/pacman_down_second.png");
	}
	else if (this->defaut == Left)
	{
		if (this->img == true)
			tmp->set_path("./rsc/snake_img/pacman_left_first.png");
		else
			tmp->set_path("./rsc/snake_img/pacman_left_second.png");
	}
	else if (this->defaut == Right)
	{
		if (this->img == true)
			tmp->set_path("./rsc/snake_img/pacman_right_first.png");
		else
			tmp->set_path("./rsc/snake_img/pacman_right_second.png");
	}
	else
		tmp->set_path("./rsc/snake_img/pacman_up_first.png");
	tmp->set_color("Red");
	tmp->dim.first = 1;
	tmp->dim.second = 1;
	this->game.push_back(tmp);
	std::cout << "votre score est actuellement de : " << this->score << std::endl;
	std::cout << "il vous reste : " << this->life << " vie(s)" <<std::endl;
	return (this->game);
}

std::vector<SE *> pacman::updateTxt()
{
	txt  *tmp_bis;
	this->game_txt.clear();	
	tmp_bis = new txt();
	tmp_bis->set_pos(this->life_pos); //life display
	tmp_bis->set_bool(false);
	tmp_bis->set_txt("vous avez actuellement : " + std::to_string(this->life) + "vie(s)");
	tmp_bis->set_color("Red");
	tmp_bis->dim.first = 1;
	tmp_bis->dim.second = 1;
	this->game_txt.push_back(tmp_bis);
	tmp_bis = new txt();
	tmp_bis->set_pos(this->score_pos); //score display
	tmp_bis->set_bool(false);
	tmp_bis->set_txt("votre score est de : " + std::to_string(this->score));
	tmp_bis->set_color("Red");
	tmp_bis->dim.first = 1;
	tmp_bis->dim.second = 1;
	this->game_txt.push_back(tmp_bis);
	return (this->game_txt);
}


/*
int main(void)
{
	pacman *test = new pacman ();
	std::string move;
	while (42)
	{
		test->display();
		std::cin >> move;
		test->move_player(move);
		//test->move_ghosts();
		test->is_angry();
		if (test->game_over() == true)
			return (0);
		test->updateMap(move);
	}
	return (0);
	}*/
