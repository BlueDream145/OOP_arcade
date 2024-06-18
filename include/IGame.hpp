/*
** EPITECH PROJECT, 2019
** IGame
** File description:
** IGame
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

# include "SE.hpp"

    class IGame {
        public:
            virtual bool InitMap() = 0;
            virtual std::vector<SE *> updateMap(std::string) = 0;
	    virtual std::vector<SE *> updateTxt() = 0;
            virtual bool DestroyMap() = 0;
            virtual int game_over() = 0;

        private:
            // std::unordered_map<Type, std::make_pair<int, int>> map;
    };

#endif /* !IGAME_HPP_ */
