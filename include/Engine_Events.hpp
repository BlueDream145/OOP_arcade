/*
** EPITECH PROJECT, 2019
** Engine_Events.hpp
** File description:
** Engine_Events
*/

#ifndef ENGINE_EVENTS_HPP_
    #define ENGINE_EVENTS_HPP_

    // # Local Imports

    #include "Engine_Menu.hpp"

    // # Class

    class Engine_Events {
        public:
            Engine_Events(void);
            ~Engine_Events(void);

            void Handle_Mouse_Move(int, int, Engine_Menu *);
            void Handle_Mouse_Clicked(int, int, Engine_Menu *, Engine *);
    };

#endif /* !ENGINE_EVENTS_HPP_ */