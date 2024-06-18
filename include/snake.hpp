//
// EPITECH PROJECT, 2019
// snake
// File description:
// snake
//

#ifndef GAME_H_
    #define GAME_H_

    #include "IGame.hpp"
    #include "SE.hpp"

    enum type
    {
        WALL,
        HEAD,
        BODY,
        TAIL,
        FOOD,
        FLOOR,
        TEXT
    };

    enum direction
    {
        up,
        down,
        left,
        right,
	other
    };

    class map : public IGame
    {
        public:
            map();
            ~map();
            bool InitMap();
            void init_snake();
	    std::vector<SE *> updateMap(std::string);
	    std::vector<SE *> updateTxt();
            bool DestroyMap();
            bool at_this_point(int i, int j);
            bool at_head(int i, int j);
            bool food_check();
            void gen_food();
            bool is_food(int i, int j);
            void move_left();
            void move_right();
            void move_up();
            void move_down();
	    void move_defaut(std::string inst);
            void move_snake(std::string inst);
            void eat_up();
            void eat_down();
            void eat_left();
            void eat_right();
            void check();
            int game_over();
	    void display();
        private:
            std::vector <std::string> container;
            std::vector <SE *> game;
	    std::vector <SE *> game_txt;
            std::vector <std::pair <int, int> > snake;
            std::pair <int, int> food;
            direction defaut;
	    int score;
	    std::pair <int, int> score_pos;
    };
	
#endif /* GAME_H_ */
