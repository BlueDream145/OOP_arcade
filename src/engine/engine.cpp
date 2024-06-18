/*
** EPITECH PROJECT, 2019
** engine.cpp
** File description:
** engine
*/

// # Lib Imports

#include <cstring>
#include <unistd.h>
#include <iostream>

// # Local Imports

#include "../../include/Engine.hpp"
#include "../../include/SE.hpp"

// # Static values

static const int width = 500;
static const int height = 500;
static const char *windowName = "Arcade";
static const char *sfml_lib = "lib_arcade_sfml.so";
static const char *ncurses_lib = "lib_arcade_ncurses.so";
static const char *sdl_lib = "lib_arcade_sdl2.so";
static const char *pacman_game = "lib_arcade_pacman.so";
static const char *snake_game = "lib_arcade_nibbler.so";
static const char *level_easy = "EASY";
static const char *level_medium = "MEDIUM";
static const char *level_hard = "HARD";

// # Builder / Destructor

Engine::Engine(char *lib_name)
{
    running = false;
    engineMenu = new Engine_Menu(this);
    engineMusic = new Engine_Music(this);
    engineGame = new Engine_Game();
    engineGame->loadGame(this, snake_game);
    engineLib = new Engine_Lib();
    if (lib_name && strlen(lib_name) > 1)
        engineLib->loadLib(this, lib_name);
    else
        engineLib->loadLib(this, sfml_lib);
    if (!currentLib) {
        std::cout << "Error, can not load file, does not exists, or invalid library file." << std::endl;
        engineMenu->error = true;
    } else
        engineMenu->run = true;
    step = MENU;
    levelGame = EASY;
    setStep(MENU);
}

Engine::~Engine(void)
{
    free();
    delete engineMenu;
    delete engineMusic;
    delete engineGame;
    delete engineLib;
}

// Public Methods

void Engine::startEngine(void)
{
    if (running)
        return;
    running = true;
    run();
}

void Engine::stopEngine(void)
{
    if (!running)
        return;
    running = false;
}

void Engine::changeDifficulty(void)
{
    if (levelGame <= 1)
        levelGame = (level_enum)(levelGame + 1);
    else
        levelGame = EASY; 
    switch(levelGame) {
        case EASY:
            engineMenu->level.setString(level_easy);
            break;
        case MEDIUM:
            engineMenu->level.setString(level_medium);
            break;
        case HARD:
            engineMenu->level.setString(level_hard);
            break;
    }
}

int Engine::getDifficultyRatio(void)
{
    switch(levelGame) {
        case EASY:
            return (3);
        case MEDIUM:
            return (8);
        case HARD:
            return (17);
        default:
            return (3);
    }
}

void Engine::setStep(step_enum _step)
{
    if (step == _step)
        return;
    step = _step;
}

void Engine::switchLib(lib_enum lib)
{
    if (typeLib == lib)
        return;
    switch(lib) {
        case SFML:
            engineLib->loadLib(this, sfml_lib);
            break;
        case SDL:
            engineLib->loadLib(this, sdl_lib);
            break;
        case NCURSES:
            engineLib->loadLib(this, ncurses_lib);
            break;
        default:
            break;
    }
    typeLib = lib;
}

void Engine::autoSwitchLib(void)
{
    switch(typeLib) {
        case SFML:
            switchLib(SDL);
            break;
        case SDL:
            switchLib(NCURSES);
            break;
        case NCURSES:
            switchLib(SFML);
            break;
        default:
            break;
    }
    force = true;
}

void Engine::switchGame(game_enum game)
{
    if (typeGame == game)
        return;
    switch(game) {
        case PACMAN:
            engineGame->loadGame(this, pacman_game);
            break;
        case SNAKE:
            engineGame->loadGame(this, snake_game);
            break;
        default:
            break;
    }
    typeGame = game;
}

void Engine::run(void)
{
    if (step == MENU)
        engineMenu->loopMenu();
    else if (step == GAME) {
        if (!currentGame || !currentLib)
            running = false;
        else
            running = true;
        loop();
    }
}

void Engine::free(void)
{
    if (destroyGame) {
        if (currentGame)
            currentGame->DestroyMap();
        if (currentGame && destroyGame)
            destroyGame(currentGame);
        destroyGame = NULL;
        currentGame = NULL;
    }
    if (destroyLib) {
        //if (destroyLib && currentLib)
        //    destroyLib(currentLib);
        destroyLib = NULL;
        currentLib = NULL;
    }
}

// Private Methods

void Engine::loop(void)
{
    int time = 100000;
    if (!currentLib)
        return;
    if (typeGame == PACMAN)
        currentLib->createWindow(
            std::make_pair(600, 600), windowName);
    else
        currentLib->createWindow(
            std::make_pair(width, height), windowName);
    engineMusic->Play();

    while (running && currentLib->is_Run() && !currentGame->game_over())
    {
        const char *tmp = currentLib->getInput();
        std::vector<SE *> vect;

        if (!strcmp(tmp, "S")) {
            currentLib->destroy_Window();
            autoSwitchLib();
            break;
        }
        vect = currentGame->updateMap(tmp);
        if (!vect.size())
            continue;
        currentLib->load_all(vect);
        currentLib->displayAll();
        usleep(time);
        time -= getDifficultyRatio();
    }
    if (!force) {
        currentLib->destroy_Window();
        currentLib->deleteAll();
        switchLib(SFML);
        levelGame = EASY;
        setStep(MENU);
    } else
        force = false;
    run();
}
