/*
** EPITECH PROJECT, 2019
** engine_menu.cpp
** File description:
** engine_menu
*/

// # Lib Imports

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// # Local Imports

#include "../../include/Engine.hpp"
#include "../../include/Engine_Rsc.hpp"
#include "../../include/Engine_Events.hpp"

// # Static values

static const char *sfml_s = "SFML";
static const char *selected_snake = "Selected: SNAKE";
static const char *window_name = "Arcade";
static const char *default_level = "EASY";
static const int window_width = 900;
static const int window_height = 506;

// # Builder / Destructor

Engine_Menu::Engine_Menu(Engine *eng)
{
    engine = eng;
    runGame = false;
    music = true;
    loadComponents();
}

Engine_Menu::~Engine_Menu(void)
{
    engine = NULL;
}

// # Methods

void Engine_Menu::mouseMoved(int x, int y)
{
    Engine_Events *events = new Engine_Events();

    if (!x || !y || !engine)
        return;
    events->Handle_Mouse_Move(x, y, this);
    delete events;
}

void Engine_Menu::mouseClicked(int x, int y)
{
    Engine_Events *events = new Engine_Events();

    if (!x || !y || !engine)
        return;
    events->Handle_Mouse_Clicked(x, y, this, engine);
    delete events;
}

void Engine_Menu::manageEvents(sf::Event event)
{
    switch(event.type)
    {
        case sf::Event::Closed:
            engine->engineMusic->Stop();
            engine->free();
            window.close();
            break;
        case sf::Event::MouseMoved:
            mouseMoved(event.mouseMove.x, event.mouseMove.y);
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
                mouseClicked(event.mouseButton.x, event.mouseButton.y);
            break;
        default:
            break;
    }
}

void Engine_Menu::draw()
{
    window.draw(backgroundImage);
    window.draw(library);
    window.draw(game);
    window.draw(sound);
    window.draw(level);
}

void Engine_Menu::loadComponents()
{
    Engine_Rsc *rsc = new Engine_Rsc();
    window.create(sf::VideoMode(window_width, window_height),
        window_name, sf::Style::Titlebar | sf::Style::Close);

    game = sf::Text();
    library = sf::Text();
    level = sf::Text();
    
    rsc->LoadRsc(this);
    library.setCharacterSize(18);
    library.setStyle(sf::Text::Regular);
    library.setFont(font);
    library.setString(sfml_s);
    library.setPosition(460, 334);

    game.setCharacterSize(20);
    game.setStyle(sf::Text::Regular);
    game.setFont(font);
    game.setString(selected_snake);
    game.setPosition(280, 170);

    level.setCharacterSize(20);
    level.setStyle(sf::Text::Regular);
    level.setFont(font);
    level.setString(default_level);
    level.setPosition(340, 270);

    backgroundImage.setTexture(background);
    sound.setTexture(sound_on);
    delete rsc;
}

void Engine_Menu::destroyComponents() { }

void Engine_Menu::loopMenu()
{
    if (music)
        engine->engineMusic->Play();
    loadComponents();
    while (window.isOpen() && run)
    {
        sf::Event event;
        while (window.pollEvent(event))
            manageEvents(event);
        window.clear();
        draw();
        window.display();
    }
    destroyComponents();
    if (runGame) {
        runGame = false;
        engine->setStep(GAME);
        engine->run();
    } else {
        engine->engineMusic->Stop();
        engine->free();
    }
}
