/*
** EPITECH PROJECT, 2019
** engine_lib.cpp
** File description:
** engine_lib
*/

// # Lib Imports

#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

// # Local Imports

#include "../../include/Engine.hpp"

// # Static values

static const char *directory = "lib";
static const char *creat = "createObj";
static const char *destroy = "destroyObj";
static const char *error_load = "Error while loading library file : ";
static const char *error_found = "Cannot found library file : ";
static const char *error_folder = "Lib folder doesn't exists or is empty.";
static const char *success = " -> Library loaded successfully";

// # Builder / Destructor

Engine_Lib::Engine_Lib(void) { }

Engine_Lib::~Engine_Lib(void) { }

// Public Methods

bool Engine_Lib::loadLib(Engine *engine, const char *lib)
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
            success = initLib(lib, engine);
            found = true;
        }
    closedir(dir);
    if (!found)
        std::cout << error_found << lib << std::endl;
    delete rent;
    return (success);
}

bool Engine_Lib::initLib(const char *av, Engine *eng)
{
        if (eng->destroyLib) {
        eng->destroyLib(eng->currentLib);
        eng->destroyLib = NULL;
        eng->currentLib = NULL;
    }
    char path[strlen(av) + strlen(directory) + 2];
    strcpy(path, directory);
    strcat(path, "/");
    strcat(path, av);
    std::cout << path << std::endl;
    void *handle = dlopen(path, RTLD_LAZY);
    IGraphic* (*create)();

    try {
        create = (IGraphic* (*)())dlsym(handle, creat);
        eng->currentLib = (IGraphic*)create();
        eng->destroyLib = (void (*)(IGraphic*))dlsym(handle, destroy);
        if (!eng->currentLib || !eng->destroyLib) {
            std::cout << error_load << av << std::endl;
            eng->destroyLib = NULL;
            eng->currentLib = NULL;
            return (false);
        } else
            std::cout << av << success << std::endl;
    } catch (const std::exception & e) {
        std::cout << error_load << av << std::endl;
        eng->destroyLib = NULL;
        eng->currentLib = NULL;
        return (false);
    }
    return (true);
}
