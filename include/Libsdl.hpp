/*
** EPITECH PROJECT, 2019
** Libopengl.hpp
** File description:
** Libopengl
*/

#ifndef LIBSDL_HPP_
    #define LIBSDL_HPP_

    #include <string>
    #include <iostream>
    #include <memory>
    #include <vector>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "IGraphic.hpp"
    #include "SE.hpp"

    struct sdl_list {
        SDL_Rect rect;
        SDL_Surface *Sprite;
        SDL_Texture *Texture;
        bool fixed;
        int vanich;
    }; 

    class Libsdl : public IGraphic {
        public:
            Libsdl();
             ~Libsdl();

            void createWindow(std::pair<int, int>, std::string const &name) override;
            const char *getInput() const override;
            void displayAll()override;
            void load_all(std::vector<SE *> disp)override;
            void delet_elems()override;
            bool clearWindow()override;
            bool deleteAll()override;
            bool destroy_Window()override;
            bool is_Run()override;
            
            std::vector<std::unique_ptr<sdl_list>> disp_list;
    };

#endif /* !LIBSDL_HPP_ */