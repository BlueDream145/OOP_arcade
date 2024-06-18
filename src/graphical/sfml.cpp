/*
** EPITECH PROJECT, 2019
** sfml.cpp
** File description:
** sfml
*/
#include <algorithm>
#include "../../include/Libsfml.hpp"

extern "C" IGraphic *createObj(void) 
{
    return new libsfml();
}

extern "C" void destroyObj(IGraphic *gam) 
{
    delete gam;
}

sf::Color	check_Color(std::string Color, std::map<std::string, sf::Color> Color_list)
{
	auto i = Color_list.find(Color);
	if (i != Color_list.end())
		return (i->second);	      
	return (sf::Color::Cyan);
}

void libsfml::createWindow(std::pair<int, int> dim, std::string const &name)
{
	_window.create(sf::VideoMode(dim.first, dim.second), name);
	
}

const char    *libsfml::getInput() const
{
    for (auto &i : Key_list){
       if (sf::Keyboard::isKeyPressed(i.second))
       return (i.first.c_str());
    }
    return "Def";
}

void libsfml::displayAll()
{
    clearWindow();
    _window.setFramerateLimit(60);
    for (int i = 0;  i < disp_list.size(); i++){
       // std::cout << "map == " << i << std::endl;
        _window.draw(disp_list[i]->Sprite);
        //_window.draw(i->rect);
    }
    //std::cout << "NUM MAP == "<< num << std::endl;
   _window.display();
}

void libsfml::load_all(std::vector<SE *> disp)
 {
     int len = 0;
     //delet_elems();
    if (disp_list.empty()) {
        for (int i = 0; i < disp.size(); i++){
            Rect *info  = dynamic_cast<Rect *> (disp[i]);
            this->disp_list.push_back(std::make_unique<sf_list>());
            if (disp_list.back()->Texture.loadFromFile(info->path)){
                disp_list.back()->Sprite.setTexture(disp_list.back()->Texture);
                disp_list.back()->Sprite.setPosition(info->pos.first * 15, info->pos.second *  15);
                disp_list.back()->Sprite.scale(0.5f, 0.5f);
                disp_list.back()->fixed = info->fix;
            }
            else {
                disp_list.back()->rect = sf::RectangleShape(sf::Vector2f(15.f, 15.f));
                disp_list.back()->rect.setFillColor(check_Color(info->color, Color_list));
                disp_list.back()->pos = std::make_pair(info->pos.first, info->pos.second);
                disp_list.back()->fixed = info->fix;
            }
        }
    } else {
         delet_elems();
        for (int i = 0; i < disp.size(); i++){
            Rect *info  = dynamic_cast<Rect *> (disp[i]);
            if (info->fix == false)
                this->disp_list.push_back(std::make_unique<sf_list>());
            if (info->fix == false && disp_list.back()->Texture.loadFromFile(info->path)){
                disp_list.back()->Sprite.setTexture(disp_list.back()->Texture);
                disp_list.back()->Sprite.setPosition(info->pos.first * 15, info->pos.second *  15);
                disp_list.back()->Sprite.scale(0.5f, 0.5f);
                disp_list.back()->fixed = info->fix;
                len++;
            }
            else if (info->fix == false) {
                disp_list.back()->rect = sf::RectangleShape(sf::Vector2f(15.f, 15.f));
                disp_list.back()->rect.setFillColor(check_Color(info->color, Color_list));
                disp_list.back()->pos = std::make_pair(info->pos.first, info->pos.second);
                disp_list.back()->fixed = info->fix;
                len++;
            }
        }  
    }
    displayAll();
 }


void libsfml::delet_elems()
{
 disp_list.erase(
        std::remove_if(
            disp_list.begin(), disp_list.end(),
            [](std::unique_ptr<sf_list> const &i){return i->fixed == false;}
        ),
        disp_list.end()
    );
}
bool libsfml::clearWindow()
{
	this->_window.clear(sf::Color::Black);
	return (true);
}

bool libsfml::deleteAll()
 {
     disp_list.erase(disp_list.begin(), disp_list.end());
 }

bool libsfml::destroy_Window()
 {

     _window.close();
 }


bool libsfml::is_Run()
{
    sf::Event event;

    while (_window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            return (false);
    return (true);
} 