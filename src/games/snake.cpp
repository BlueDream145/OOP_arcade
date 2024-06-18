//
// EPITECH PROJECT, 2019
// snake
// File description:
// snake
//

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "../../include/snake.hpp"

extern "C" IGame *createObj(void) 
{
    return (new map());
}

extern "C" void destroyObj(IGame *gam) 
{
    delete gam;
}

bool map::InitMap()
{
	std::string basic_line;
	std::string exte_line;
	int i = 0;
	while (i <= 30)
	{
		exte_line.push_back('-');
		i++;
			
	}
	basic_line.push_back('|');
	i = 0;
	while (i < 30)
	{
		basic_line.push_back(' ');
		i++;
	}
	basic_line.push_back('|');
	this->container.push_back(exte_line);
	i = 0;
	while (i < 30)
	{
		this->container.push_back(basic_line);
		i++;
	}
	this->container.push_back(exte_line);
	return (true);
}

void map::init_snake()
{
	std::pair <int, int> first = std::make_pair(25, 25);
	std::pair <int, int> last = std::make_pair(25, 24);
	this->snake.push_back(first);
	this->snake.push_back(last);
}

std::vector<SE *> map::updateMap(std::string move)
{
	this->game.clear();
	Rect *tmp;
	int j = 0;
	this->move_snake(move);
	this->check();
	tmp = new Rect();
	for(int iter = 0; iter != this->container.size(); iter++)
	{
		while (j != container[iter].size())
		{
			tmp = new Rect();
			if (container[iter][j] == '|' || container[iter][j] == '-')
			{
				tmp->set_path("./rsc/snake_img/snake_wall.png");
				tmp->set_color("Blue");
			}
			else
			{
				tmp->set_path("./rsc/snake_img/SOL.png");
				tmp->set_color("Black");
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
	}
	tmp = new Rect();
	tmp->set_pos(food);
	tmp->set_bool(false);	
	tmp->set_path("./rsc/snake_img/topaz.png");
	tmp->set_color("Red");
	tmp->dim.first = 1;
	tmp->dim.second = 1;
	this->game.push_back(tmp);
	for (int iter = 0; iter != snake.size(); iter++)
	{
		tmp = new Rect();
		if (iter == 0)
		{
			if (this->defaut == right)
				tmp->set_path("./rsc/snake_img/head_right.png");
			else if (this->defaut == left)
				tmp->set_path("./rsc/snake_img/head_left.png");
			else if (this->defaut == up)
				tmp->set_path("./rsc/snake_img/head_up.png");
			else if (this->defaut == down)
				tmp->set_path("./rsc/snake_img/head_down.png");
			else
				tmp->set_path("./rsc/snake_img/head_up.png");
			
		}
		else if (iter == snake.size() - 1)
			tmp->set_path("./rsc/snake_img/snake_body.png");
		else
			tmp->set_path("./rsc/snake_img/snake_body.png");
		tmp->set_pos(snake[iter]);
		tmp->set_bool(false);
		tmp->set_color("Green");
		tmp->dim.first = 1;
		tmp->dim.second = 1;
		this->game.push_back(tmp);
	}
	std::cout << "votre score est actuellement de : " << this->score << std::endl;
	return (this->game);
}

std::vector<SE *> map::updateTxt()
{
	this->game_txt.clear();
	txt *tmp_bis;
	tmp_bis = new txt();                                                                                       
        tmp_bis->set_pos(score_pos);
        tmp_bis->set_bool(false);                                                                                    
        tmp_bis->set_txt("votre score est de : " + std::to_string(this->score));
        tmp_bis->set_color("Red");                                                                                   
        tmp_bis->dim.first = 1;                                                                                      
        tmp_bis->dim.second = 1;                                                                                     
        this->game_txt.push_back(tmp_bis);
	return (this->game_txt);
}


map::map()
{
	this->InitMap();
	this->init_snake();
	this->gen_food();
	this->score = 0;
	this->score_pos.first = 40;
	this->score_pos.second = 40;
	return ;
}

map::~map(){}

bool map::at_this_point(int i, int j)
{
	int iter = 0;
	while (iter != this->snake.size())
	{

		if (this->snake[iter].first == i && this->snake[iter].second == j)
			return (true);
		iter++;
	}
	return (false);
}

bool map::at_head(int i, int j)
{
	if (this->snake[0].first == i && this->snake[0].second == j)
		return (true);
	return (false);
}

bool map::food_check()
{
	int iterator = 0;
	if (this->food.first == 0 && this->food.second == 0)
		return (false);
	while (iterator <= (this->snake.size() - 1))
	{
		if (this->snake[iterator].first == this->food.first
		    && this->snake[iterator].second == this->food.second)
			return (false);
		iterator++;
	}
	return (true);
}

void map::gen_food()
{
	this->food = std::make_pair(0, 0);
	srand(time(NULL));
	while (this->food_check() != true)
	{
		this->food.second = rand()%(30-1 + 1) + 1;
		this->food.first = rand()%(30-1 + 1) + 1;
	}
	return ;
}

bool map::is_food(int i, int j)
{
	if (i == this->food.first && j == this->food.second)
		return (true);
	return (false);
}

void map::move_left()
{
	std::pair <int, int> tmp;
	std::vector<std::pair <int, int> >::iterator it = this->snake.begin();
	
	tmp.second = this->snake[0].second - 1;
	tmp.first = this->snake[0].first;
	this->snake.insert(it, tmp);
	this->snake.pop_back();
	this->defaut = left;
	return ;
}

void map::move_right()
{
	std::pair <int, int> tmp;
	std::vector<std::pair <int, int> >::iterator it = this->snake.begin();

	tmp.second = this->snake[0].second + 1;
	tmp.first = this->snake[0].first;
	this->snake.insert(it, tmp);
	this->snake.pop_back();
	this->defaut = right;
	return ;
}

void map::move_up()
{
	std::pair <int, int> tmp;
	std::vector<std::pair <int, int> >::iterator it = this->snake.begin();

	tmp.second = this->snake[0].second;
	tmp.first = this->snake[0].first - 1;
	this->snake.insert(it, tmp);
	this->snake.pop_back();
	this->defaut = up;
	return ;
}

void map::move_down()
{
       	std::pair <int, int> tmp;
	std::vector<std::pair <int, int> >::iterator it = this->snake.begin();

	tmp.second = this->snake[0].second;
	tmp.first = this->snake[0].first + 1;
	this->snake.insert(it, tmp);
	this->snake.pop_back();
	this->defaut = down;
	return ;
}

void map::move_defaut(std::string inst)
{
	if (inst.compare("Up") == 0 && this->defaut == down)
		this->move_down();
	else if (inst.compare("Down") == 0 && this->defaut == up)
		this->move_up();
       	else if (inst.compare("Left") == 0 && this->defaut == right)
		this->move_right();
	else if (inst.compare("Right") == 0 && this->defaut == left)
		this->move_left();
	else if (this->defaut == up)
		this->move_up();
	else if (this->defaut == down)
		this->move_down();
	else if (this->defaut == left)
		this->move_left();
	else if (this->defaut == right)
		this->move_right();
	return ;
}

void map::move_snake(std::string inst)
{
	if ((inst.compare("Left") == 0) && this->defaut != right)
		this->move_left();
	else if ((inst.compare("Right") == 0) && this->defaut != left)
		this->move_right();
	else if ((inst.compare("Down") == 0) && this->defaut != up)
		this->move_down();
	else if ((inst.compare("Up") == 0) && this->defaut != down)
		this->move_up();
	else
		this->move_defaut(inst);
	return ;
}

void map::eat_left()
{
	std::pair <int, int> tmp;
	std::vector<std::pair <int, int> >::iterator it = this->snake.begin();
	
	tmp.second = this->snake[0].second - 1;
	tmp.first = this->snake[0].first;
	this->snake.insert(it, tmp);
	return ;
}

void map::eat_right()
{
	std::pair <int, int> tmp;
	std::vector<std::pair <int, int> >::iterator it = this->snake.begin();
	
	tmp.second = this->snake[0].second + 1;
	tmp.first = this->snake[0].first;
	this->snake.insert(it, tmp);
	return ;
}

void map::eat_up()
{
	std::pair <int, int> tmp;
	std::vector<std::pair <int, int> >::iterator it = this->snake.begin();

	tmp.second = this->snake[0].second;
	tmp.first = this->snake[0].first - 1;
	this->snake.insert(it, tmp);
	return ;
}

void map::eat_down()
{
	std::pair <int, int> tmp;
	std::vector<std::pair <int, int> >::iterator it = this->snake.begin();

	tmp.second = this->snake[0].second;
	tmp.first = this->snake[0].first + 1;
	this->snake.insert(it, tmp);

}

void map::check()
{
	if (at_this_point(food.first, food.second) == true)
	{
		if (this->defaut == up)
			this->eat_up();
		else if (this->defaut == down)
			this->eat_down();
		else if (this->defaut == left)
			eat_left();
		else if (this->defaut == right)
			eat_right();
		this->gen_food();
		this->score++;
	}
	return ;
}
/*
void map::display()
{
	int i = 0, j = 0;
	while (i != container.size())
	{
		while (j != container[i].size())
		{
			if (is_food(i, j) == true)
				std::cout << "A";
			else if (at_this_point(i, j) == false)
				std::cout << this->container[i][j];
			else 
			{
				if (this->snake[0].first == i && this->snake[0].second == j)
					std::cout << "@";
				else if (this->snake[snake.size() - 1].first == i
					 && this->snake[snake.size() - 1].second == j)
					std::cout << "0";
				else
					std::cout << 'N';
			}
			j++;
		}
		std::cout << std::endl;
		i++;
		j = 0;
	}
	return ;
}*/

int map::game_over()
{
	int i = 0;
	while (i != this->snake.size())
	{
		if (this->snake[i].first == 0 || this->snake[i].first == (container.size() - 1))
			return (1);
		else if (this->snake[i].second == 0 || snake[i].second == container[0].size())
			return (1);
		i++;
	}
	i = 1;
	while (i != this->snake.size())
	{
		if (this->at_head(snake[i].first, snake[i].second) == true)
			return (1);
		i++;
	}
	return (0);
}

bool map::DestroyMap()
{
    return (true);
}

/*
int main(void)
{
	map *tmp = new map();
	std::string keyboard;
	while (tmp->game_over() != true)
	{
		tmp->display();
		std::cin >> keyboard;
		tmp->updateMap(keyboard);
		tmp->check();
	}
	return (0);
}
*/
