/*
** EPITECH PROJECT, 2019
** Engine_Lib.hpp
** File description:
** Engine_Lib
*/

#ifndef ENGINE_LIB_HPP_
    #define ENGINE_LIB_HPP_

    // # Local Imports

    #include "Engine.hpp"

    // # Class
    
    class Engine_Lib {
        public:
            Engine_Lib(void);
            ~Engine_Lib(void);

            bool loadLib(Engine *, const char *);
            bool initLib(const char *, Engine *);
    };

#endif /* !ENGINE_LIB_HPP_ */