/*
** EPITECH PROJECT, 2019
** Engine_Rsc.hpp
** File description:
** Engine_Rsc
*/

#ifndef ENGINE_RSC_HPP_
    #define ENGINE_RSC_HPP_

    // # Local Imports

    #include "Engine_Menu.hpp"

    // # Class

    class Engine_Rsc {
        public:
            Engine_Rsc(void);
            ~Engine_Rsc(void);

            void LoadRsc(Engine_Menu *);
    };

#endif /* !ENGINE_RSC_HPP_ */