/*
** EPITECH PROJECT, 2019
** sfml.cpp
** File description:
** sfml
*/

// # Local Imports

#include "../../include/Libsdl.hpp"

// # Global values

SDL_Window *window;
SDL_Renderer *render;
int width;
int height;
bool run;

// # Static values

static const std::map<const char *, int> Key_list =
{
	{"A", 97},
	{"Z", 122},
	{"L", 108},
	{"Q", 113},
	{"S", 115},
	{"D", 100},
	{"F", 102},
	{"M", 109},
	{"E", 101},
	{"Left", 1073741904},
	{"Right", 1073741903},
	{"Up", 1073741906},
	{"Down", 1073741905}
};

// static const std::map<std::string, uint> Sdl_Color_list = {
//     {"Red", SDL_MapRGB(s->format, 255, 0, 0)},
//     {"Black", SDL_MapRGB(s->format, 0, 0, 0)},
//     {"White", SDL_MapRGB(s->format, 255, 255, 255)},
//     {"Green", SDL_MapRGB(s->format, 0, 128, 0)},
//     {"Blue", SDL_MapRGB(s->format, 0, 0, 255),
//     {"Yellow", SDL_MapRGB(s->format, 255, 255, 0)},
//     {"Cyan", SDL_MapRGB(s->format, 0, 255, 255)},
//     {"Transparent", SDL_MapRGB(s->format, 255, 255, 255)},
//     {"Magenta", SDL_MapRGB(s->format, 255, 0, 255)},
// };

// # Shared Object Methods

extern "C" IGraphic *createObj(void) 
{
    return new Libsdl();
}

extern "C" void destroyObj(IGraphic *gam) 
{
    delete gam;
}

// # Builder / Destructor

Libsdl::Libsdl(void)
{
}

Libsdl::~Libsdl(void)
{
    SDL_Quit();
}

// # Methods

void Libsdl::createWindow(std::pair<int, int> pair, std::string const &name)
{
    width = pair.first;
    height = pair.second;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        fprintf(stderr, "Impossible d'initialiser SDL.");
        exit(84);
    }
    window = SDL_CreateWindow(
        name.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        pair.first,
        pair.second,
        SDL_WINDOW_SHOWN
    );
    if(!window) {
        std::cout << "Could not create window." << '\n';
        SDL_Quit();
    }
    run = true;
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

const char *Libsdl::getInput() const
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type)
        {
            case SDL_QUIT:
                run = false;
                break;
            case SDL_KEYDOWN:
                for (auto &i : Key_list) {
                        if (event.key.keysym.sym == i.second) {
                            return (i.first);
                        }
                }
                break;
        }
    }
    return ("");
}

// sf::Color	check_Color(std::string Color, std::map<std::string, sf::Color> Color_list)
// {
// 	auto i = Color_list.find(Color);
// 	if (i != Color_list.end())
// 		return (i->second);	      
// 	return (sf::Color::Cyan);
// }

void Libsdl::displayAll()
{
    if (disp_list.size() == 0)
        return;
    clearWindow();
    for (auto &i : disp_list)
        if (render && i && i->Texture && &i->rect)
            SDL_RenderCopy(render, i->Texture, NULL, &i->rect);
    SDL_RenderPresent(render);
}

void Libsdl::load_all(std::vector<SE *> disp)
{
    int coef = 15.5;
    delet_elems();

    if (disp_list.empty()) {
        for (uint i = 0; i < disp.size(); i++){
            Rect *info  = dynamic_cast<Rect *> (disp[i]);
            this->disp_list.push_back(std::make_unique<sdl_list>());
                disp_list.back()->Sprite = IMG_Load(info->path.c_str());
                if (disp_list.back()->Sprite) {
                    disp_list.back()->Texture = SDL_CreateTextureFromSurface(render, disp_list.back()->Sprite);
                    disp_list.back()->rect.w = info->dim.first * coef;
                    disp_list.back()->rect.h = info->dim.second * coef;
                    disp_list.back()->rect.x = info->pos.first * coef;
                    disp_list.back()->rect.y = info->pos.second * coef;
                    disp_list.back()->fixed = info->get_fixed();
                    continue;
                } else
                {
                    std::cout << "CAN'T LOAD " << info->path << std::endl;
                }
                disp_list.back()->Sprite = SDL_CreateRGBSurface(0,  7.f,  7.f, 32, 0, 0, 0, 0);
                SDL_FillRect(disp_list.back()->Sprite, NULL, SDL_MapRGB(disp_list.back()->Sprite->format, 255, 0, 0));
                disp_list.back()->Texture = SDL_CreateTextureFromSurface(render, disp_list.back()->Sprite);
                disp_list.back()->fixed = info->get_fixed();
            
        }
    } else {
        for (uint i = 0; i < disp.size(); i++){
            Rect *info  = dynamic_cast<Rect *> (disp[i]);
            if (info->fix == false)
                this->disp_list.push_back(std::make_unique<sdl_list>());
            if (info->get_fixed() == false){
                disp_list.back()->Sprite = IMG_Load(info->path.c_str());
                if (disp_list.back()->Sprite) {
                    disp_list.back()->Texture = SDL_CreateTextureFromSurface(render, disp_list.back()->Sprite);
                    disp_list.back()->rect.w = info->dim.first * coef;
                    disp_list.back()->rect.h = info->dim.second * coef;
                    disp_list.back()->rect.x = info->pos.first * coef;
                    disp_list.back()->rect.y = info->pos.second * coef;
                    disp_list.back()->fixed = info->get_fixed();
                    continue;
                }
            }
        }
    }
}

void Libsdl::delet_elems()
{
    disp_list.erase(
        std::remove_if(
            disp_list.begin(), disp_list.end(),
            [](std::unique_ptr<sdl_list> const &i){return i->fixed == false;}
        ),
        disp_list.end()
    );
}

bool Libsdl::clearWindow()
{
    SDL_RenderClear(render);
    return (false);
}

bool Libsdl::deleteAll()
{
    disp_list.erase(disp_list.begin(), disp_list.end());
    return (false);
}

bool Libsdl::destroy_Window()
{
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return (true);
}

bool Libsdl::is_Run()
{
    return (run);
}