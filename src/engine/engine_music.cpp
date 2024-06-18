/*
** EPITECH PROJECT, 2019
** engine_music.cpp
** File description:
** engine_music
*/

// # Lib Imports

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

// # Local Imports

#include "../../include/Engine.hpp"

// # Static values

static const char *music_path = "rsc/music.wav";
static const char *music_error = "Can't load music.wav.";

// # Builder / Destructor

Engine_Music::Engine_Music(Engine *eng)
{
    engine = eng;
    if (!music.openFromFile(music_path))
        std::cout << music_error << std::endl;
}

Engine_Music::~Engine_Music(void)
{
    engine = NULL;
}

// # Public Methods

void Engine_Music::Play(void)
{
    if (music.getStatus() == sf::SoundSource::Status::Playing)
        return;
    music.play();
    music.setLoop(true);
}

void Engine_Music::Break(void)
{
    music.pause();
}

void Engine_Music::Stop(void)
{
    music.stop();
}