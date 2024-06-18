/*
** EPITECH PROJECT, 2019
** Engine_Menu.hpp
** File description:
** Engine_Menu
*/

#ifndef ENGINE_MENU_HPP_
    #define ENGINE_MENU_HPP_

    // # Local Imports

    #include "Engine.hpp"

    // # Class

    class Engine_Menu {
        private:
            Engine *engine;

            void destroyComponents();
            void mouseMoved(int, int);
            void mouseClicked(int, int);
        public:
            Engine_Menu(Engine *);
            ~Engine_Menu(void);
            void loadComponents();

            sf::RenderWindow window;
            sf::Texture background;
            sf::Texture background_run;
            sf::Texture background_game1;
            sf::Texture background_game2;
            sf::Texture background_gl;
            sf::Texture background_sfml;
            sf::Texture background_ncurses;
            sf::Texture background_exit;
            sf::Texture background_level;
            sf::Texture sound_off;
            sf::Texture sound_on;
            sf::Sprite backgroundImage;
            sf::Sprite sound;
            sf::Font font;
            sf::Text game;
            sf::Text library;
            sf::Text level;

            bool music;
            int state;
            bool runGame;
            bool run;
            bool error;

            void manageEvents(sf::Event);
            void loopMenu(void);
            void draw(void);
    };

#endif /* !ENGINE_MENU_HPP_ */