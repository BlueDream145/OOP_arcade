/*
** EPITECH PROJECT, 2019
** engine_events.cpp
** File description:
** engine_events
*/

// # Local Imports

#include "../../include/Engine.hpp"
#include "../../include/Engine_Events.hpp"

// # Static Values

static const char *sfml_s = "SFML";
static const char *sdl_s = "SDL";
static const char *ncurses_s = "NCURSES";

static const char *sfml_lib = "lib_arcade_sfml.so";
static const char *ncurses_lib = "lib_arcade_ncurses.so";
static const char *sdl_lib = "lib_arcade_sdl2.so";
static const char *pacman_game = "lib_arcade_pacman.so";
static const char *snake_game = "lib_arcade_nibbler.so";

static const char *selected_snake = "Selected: SNAKE";
static const char *selected_pacman = "Selected: PACMAN";

// # Builder / Destructor

Engine_Events::Engine_Events(void) { }

Engine_Events::~Engine_Events(void) { }

// # Public Methods

void Engine_Events::Handle_Mouse_Clicked(int x, int y, Engine_Menu *menu, Engine *engine)
{
    try {
        if (x >= 0 && x <= 64 && y >= 0 && y <= 64) {
            if (menu->music) {
                menu->sound.setTexture(menu->sound_off);
                engine->engineMusic->Break();
                menu->music = false;
            } else {
                menu->sound.setTexture(menu->sound_on);
                engine->engineMusic->Play();
                menu->music = true;
            }
        } else if (x >= 448 && x <= 607 && y >= 177 && y <= 198) {
            if (!engine->currentLib || !engine->currentGame)
                return;
            if (engine->typeGame == SNAKE)
                engine->engineGame->loadGame(engine, snake_game);
            else if (engine->typeGame == PACMAN)
                engine->engineGame->loadGame(engine, pacman_game);
            menu->runGame = true;
            menu->window.close();
        } else if (x >= 285 && x <= 401 && y >= 216 && y <= 234) {
            engine->typeGame = SNAKE;
            if (engine->engineGame->loadGame(engine, snake_game))
                menu->game.setString(selected_snake);
        } else if (x >= 423 && x <= 588 && y >= 241 && y <= 265) {
            engine->typeGame = PACMAN;
            if (engine->engineGame->loadGame(engine, pacman_game))
                menu->game.setString(selected_pacman);
            else {
                engine->engineGame->loadGame(engine, snake_game);
                menu->game.setString(selected_snake);
            }
        } else if (x >= 818 && x <= 877 && y >= 158 && y <= 209) {
            engine->typeLib = SDL;
            if (engine->engineLib->loadLib(engine, sdl_lib))
                menu->library.setString(sdl_s);
            else {
                engine->engineLib->loadLib(engine, sfml_lib);
                menu->library.setString(sfml_s);
            }
        } else if (x >= 818 && x <= 877 && y >= 229 && y <= 279) {
            engine->typeLib = SFML;
            if (engine->engineLib->loadLib(engine, sfml_lib))
                menu->library.setString(sfml_s);
        } else if (x >= 818 && x <= 877 && y >= 295 && y <= 348) {
            engine->typeLib = NCURSES;
            if (engine->engineLib->loadLib(engine, ncurses_lib))
                menu->library.setString(ncurses_s);
            else {
                engine->engineLib->loadLib(engine, sfml_lib);
                menu->library.setString(sfml_s);
            }
        } else if (x >= 276 && x <= 414 && y >= 268 && y <= 298)
            engine->changeDifficulty();
        else if (x >= 420 && x <= 602 && y >= 297 && y <= 325)
            engine->engineMenu->window.close();
    } catch (const std::exception & e) { }
}

void Engine_Events::Handle_Mouse_Move(int x, int y, Engine_Menu *menu)
{
    try {
        if (x >= 448 && x <= 607 && y >= 177 && y <= 198) {
            if (menu->state == 1)
                return;
            menu->backgroundImage.setTexture(menu->background_run);
            menu->state = 1;
            return;
        } else if (x >= 285 && x <= 401 && y >= 216 && y <= 234) {
            if (menu->state == 2)
                return;
            menu->backgroundImage.setTexture(menu->background_game1);
            menu->state = 2;
            return;
        } else if (x >= 423 && x <= 588 && y >= 241 && y <= 265) {
            if (menu->state == 3)
                return;
            menu->backgroundImage.setTexture(menu->background_game2);
            menu->state = 3;
            return;
        } else if (x >= 818 && x <= 877 && y >= 158 && y <= 209) {
            if (menu->state == 4)
                return;
            menu->backgroundImage.setTexture(menu->background_gl);
            menu->state = 4;
            return;
        } else if (x >= 818 && x <= 877 && y >= 229 && y <= 279) {
            if (menu->state == 5)
                return;
            menu->backgroundImage.setTexture(menu->background_sfml);
            menu->state = 5;
            return;
        } else if (x >= 818 && x <= 877 && y >= 295 && y <= 348) {
            if (menu->state == 6)
                return;
            menu->backgroundImage.setTexture(menu->background_ncurses);
            menu->state = 6;
            return;
        } else if (x >= 276 && x <= 414 && y >= 268 && y <= 298) {
            if (menu->state == 7)
                return;
            menu->backgroundImage.setTexture(menu->background_level);
            menu->state = 7;
            return;

        } else if (x >= 420 && x <= 602 && y >= 297 && y <= 325) {
            if (menu->state == 8)
                return;
            menu->backgroundImage.setTexture(menu->background_exit);
            menu->state = 8;
            return;

        } else if (menu->state != 0) {
            menu->backgroundImage.setTexture(menu->background);
            menu->state = 0;
        }
    } catch (const std::exception & e) { }
}