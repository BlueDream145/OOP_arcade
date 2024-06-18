/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main
*/

// # Lib Imports

#include <stdbool.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

// # Local Imports

#include "../include/Engine.hpp"

// # Static values

static const int success = 0;
static const int fail = 84;

// # Methods

static void usage(char *binary)
{
    static const char *usage = "USAGE :\n"
        "\t\t%s [lib]\tgraphical library "
        "to use, default if empty.\n";

    printf(usage, binary);
}

static bool check(int ac, char **as)
{
    if (ac != 1 && ac != 2) {
        usage(as[0]);
        return (false);
    }
    return (true);
}

int main(int ac, char **as)
{
	Engine *eng;
    bool err;

    if (ac == 2 && !std::strcmp(as[1], "-h"))
    {
	    usage(as[0]);
	    return (success);
    }
    if (!check(ac, as) || (as[1] &&
        !(eng = new Engine(as[1]))) ||
        (!as[1] &&
	 !(eng = new Engine(NULL))))
	    return (fail);
    eng->startEngine();
    err = eng->engineMenu->error;
    delete eng;
    if (err)
        return (fail);
    return (success);
}
