/*
** EPITECH PROJECT, 2019
** Engine_Game.cpp
** File description:
** Engine_Game
*/

// # Lib Imports

#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

// # Local Imports

#include "../../include/Engine.hpp"

// # Static values

static const char *directory = "games";
static const char *creat = "createObj";
static const char *destroy = "destroyObj";
static const char *error_load = "Error while loading game file : ";
static const char *error_found = "Cannot found library file : ";
static const char *error_folder = "Game folder doesn't exists or is empty.";
static const char *success = " -> Game loaded successfully";

// # Builder / Destructor

Engine_Game::Engine_Game(void) { }

Engine_Game::~Engine_Game(void) { }

// Public Methods

bool Engine_Game::loadGame(Engine *engine, const char *lib)
{
    DIR * dir = opendir(directory);
    struct dirent * rent;
    bool found = false;
    bool success = false;

    if (!dir)
        std::cout << error_folder << std::endl;
    if (!dir || !lib)
        return (false);
    while ((rent = readdir(dir)) != NULL)
        if (!strcmp(lib, rent->d_name)) {
            success = initGame(lib, engine);
            found = true;
        }
    closedir(dir);
    if (!found)
        std::cout << error_found << lib << std::endl;
    delete rent;
    return (success);
}

bool Engine_Game::initGame(const char *av, Engine *eng)
{
    if (eng->destroyGame && eng->currentGame) {
        eng->destroyGame(eng->currentGame);
        eng->destroyGame = NULL;
        eng->currentGame = NULL;
    }
    char path[strlen(av) + strlen(directory) + 2];
    strcpy(path, directory);
    strcat(path, "/");
    strcat(path, av);
    void *handle = dlopen(path, RTLD_LAZY);
    IGame* (*create)();

    try {
        create = (IGame* (*)())dlsym(handle, creat);
        eng->currentGame = (IGame*)create();
        eng->destroyGame = (void (*)(IGame*))dlsym(handle, destroy);
        if (!eng->currentGame || !eng->destroyGame) {
            std::cout << error_load << av << std::endl;
            eng->destroyGame = NULL;
            eng->currentGame = NULL;
            return (false);
        }
        else
            std::cout << av << success << std::endl;
    } catch (const std::exception & e) {
        std::cout << error_load << av << std::endl;
        eng->destroyGame = NULL;
        eng->currentGame = NULL;
        return (false);
    }
    return (true);
}