/*
** EPITECH PROJECT, 2019
** IGraphic.hpp
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
    #define IGRAPHIC_HPP_

    #include <string>
    #include <iostream>
    #include <vector>

    #include <SFML/Graphics.hpp>

    #include "SE.hpp"

    class IGraphic
    {
        public:
            virtual ~IGraphic() = default;
            virtual void createWindow(std::pair<int, int>, std::string const &name) = 0;
            virtual const char *getInput() const = 0;
            virtual void displayAll() = 0;
            virtual void load_all(std::vector<SE *> disp) = 0;
            virtual void delet_elems() = 0;
            virtual bool clearWindow() = 0;
            virtual bool deleteAll() = 0;
            virtual bool destroy_Window() = 0;
            virtual bool is_Run() = 0;
    };

#endif /* !IGRAPHIC_HPP_ */