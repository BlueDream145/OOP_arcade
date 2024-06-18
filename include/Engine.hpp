/*
** EPITECH PROJECT, 2019
** Engine.hpp
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
    #define ENGINE_HPP_

    // # Lib Imports

    #include <stdbool.h>

    // # Local Imports

    #include "Libsfml.hpp"
    #include "Libncurses.hpp"
    #include "IGraphic.hpp"
    #include "IGame.hpp"
    #include "SE.hpp"

    // # Engine Imports

    class Engine;

    #include "Engine_Lib.hpp"
    #include "Engine_Game.hpp"
    #include "Engine_Music.hpp"
    #include "Engine_Menu.hpp"

    // # Enums

    enum lib_enum {
        SFML,
        SDL,
        NCURSES
    };

    enum game_enum {
        SNAKE,
        PACMAN
    };

    enum step_enum {
        MENU,
        GAME
    };

    enum level_enum {
        EASY,
        MEDIUM,
        HARD
    };

    // # Class

    class Engine {
        private:
            std::vector<IGraphic> libs;
            std::vector<IGame> games;
            std::vector<SE *> gameEntities;

            bool force;
            bool running;
            step_enum step;

            void loop(void);
        public:
            Engine(char *);
            ~Engine(void);

            IGraphic *currentLib;
            IGame *currentGame;
            void (*destroyGame)(IGame*);
            void (*destroyLib)(IGraphic*);

            Engine_Lib *engineLib;
            Engine_Game *engineGame;
            Engine_Menu *engineMenu;
            Engine_Music *engineMusic;

            lib_enum typeLib;
            game_enum typeGame;
            level_enum levelGame;

            void startEngine(void);
            void stopEngine(void);
            void changeDifficulty(void);
            int getDifficultyRatio(void);
            void setStep(step_enum);
            void switchLib(lib_enum);
            void autoSwitchLib(void);
            void switchGame(game_enum);
            void run(void);
            void free(void);
    };

#endif /* !ENGINE_HPP_ */