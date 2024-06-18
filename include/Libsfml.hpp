/*
** EPITECH PROJECT, 2019
** Libsfml.hpp
** File description:
** Libsfml
*/

#ifndef LIBSFML_HPP_
 #define LIBSFML_HPP_

    #include <string>
    #include <iostream>
    #include <memory>
    #include <vector>
    #include <SFML/Audio.hpp>
    #include <SFML/Config.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/Main.hpp>
    #include "IGraphic.hpp"
    #include "SE.hpp"

struct  sf_list {
	sf::RectangleShape rect;
	sf::Sprite Sprite;
	sf::Texture Texture;
    std::pair<int, int> pos;
    bool fixed;
}; 

    class libsfml : public IGraphic
    {
        public:
            libsfml() { }
             ~libsfml() { }
            void createWindow(std::pair<int, int>, std::string const &name) override;
            const char *getInput() const override;
            void displayAll()override;
            void load_all(std::vector<SE *> disp)override;
            void delet_elems()override;
            bool clearWindow()override;
            bool deleteAll()override;
            bool destroy_Window()override;
            bool is_Run()override;
        private:

        sf::RenderWindow	_window;
        sf::Font		_font;
        std::vector<sf::Texture> text;
        std::vector<std::unique_ptr<sf_list>> disp_list;

        
        std::map<std::string, sf::Keyboard::Key> Key_list = {
		{"A", sf::Keyboard::A},
		{"Z", sf::Keyboard::Z},
		{"L", sf::Keyboard::L},
		{"Q", sf::Keyboard::Q},
		{"S", sf::Keyboard::S},
		{"D", sf::Keyboard::D},
		{"F", sf::Keyboard::F},
		{"M", sf::Keyboard::M},
		{"E", sf::Keyboard::E},
		{"Left", sf::Keyboard::Left},
		{"Right", sf::Keyboard::Right},
		{"Up", sf::Keyboard::Up},
		{"Down", sf::Keyboard::Down},
	};
        std::map<std::string, sf::Color>  Color_list = {
		{"Red", sf::Color::Red},
		{"Black",sf::Color::Black},
		{"White",sf::Color::White},
		{"Green",sf::Color::Green},
		{"Blue",sf::Color::Blue},
		{"Yellow",sf::Color::Yellow},
		{"Cyan", sf::Color::Cyan},
		{"Transparent", sf::Color::Transparent},
		{"Magenta", sf::Color::Magenta},
	};
};



#endif /* !LIBSFML_HPP_ */