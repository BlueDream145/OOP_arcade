/*
** EPITECH PROJECT, 2019
** engine_rsc.cpp
** File description:
** engine_rsc
*/

// # Local Imports

#include "../../include/Engine.hpp"
#include "../../include/Engine_Rsc.hpp"

// # Static Values

static const char *error_load = "Can't load ";
static const char *font_path = "rsc/PMingLiU.ttf";
static const char *bg_path = "rsc/menu_bg.png";
static const char *bg_run = "rsc/menu_run.png";
static const char *bg_game1 = "rsc/menu_game1.png";
static const char *bg_game2 = "rsc/menu_game2.png";
static const char *bg_sfml = "rsc/menu_bg_sfml.png";
static const char *bg_sdl = "rsc/menu_sdl.png";
static const char *bg_ncurses = "rsc/menu_bg_ncurses.png";
static const char *bg_exit = "rsc/menu_exit.png";
static const char *bg_level = "rsc/menu_level.png";
static const char *sound_disable = "rsc/sound_off.png";
static const char *sound_enable = "rsc/sound_on.png";

// # Builder / Destructor

Engine_Rsc::Engine_Rsc(void) { }

Engine_Rsc::~Engine_Rsc(void) { }

// # Public Methods

void Engine_Rsc::LoadRsc(Engine_Menu *menu)
{
    if (!menu->font.loadFromFile(font_path))
        std::cout << error_load << font_path << std::endl;
    if (!menu->background.loadFromFile(bg_path))
        std::cout << error_load << bg_path << std::endl;
    if (!menu->background_run.loadFromFile(bg_run))
        std::cout << error_load << bg_run << std::endl;
    if (!menu->background_game1.loadFromFile(bg_game1))
        std::cout << error_load << bg_game1 << std::endl;
    if (!menu->background_game2.loadFromFile(bg_game2))
        std::cout << error_load << bg_game2 << std::endl;
    if (!menu->background_sfml.loadFromFile(bg_sfml))
        std::cout << error_load << bg_sfml << std::endl;
    if (!menu->background_gl.loadFromFile(bg_sdl))
        std::cout << error_load << bg_sdl << std::endl;
    if (!menu->background_ncurses.loadFromFile(bg_ncurses))
        std::cout << error_load << bg_ncurses << std::endl;
    if (!menu->background_exit.loadFromFile(bg_exit))
        std::cout << error_load << sound_disable << std::endl;
    if (!menu->background_level.loadFromFile(bg_level))
        std::cout << error_load << sound_enable << std::endl;
    if (!menu->sound_off.loadFromFile(sound_disable))
        std::cout << error_load << sound_disable << std::endl;
    if (!menu->sound_on.loadFromFile(sound_enable))
        std::cout << error_load << sound_enable << std::endl;
}