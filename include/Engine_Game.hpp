/*
** EPITECH PROJECT, 2019
** Engine_Game.hpp
** File description:
** Engine_Game
*/

#ifndef ENGINE_GAME_HPP_
    #define ENGINE_GAME_HPP_

    // # Local Imports

    #include "Engine.hpp"

    // # Class

    class Engine_Game {
        public:
            Engine_Game(void);
            ~Engine_Game(void);

            bool loadGame(Engine *, const char *);
            bool initGame(const char *, Engine *);
    };

#endif /* !ENGINE_GAME_HPP_ */