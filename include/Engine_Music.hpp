/*
** EPITECH PROJECT, 2019
** Engine_Music.hpp
** File description:
** Engine_Music
*/

#ifndef ENGINE_MUSIC_HPP_
    #define ENGINE_MUSIC_HPP_

    // # Local Imports

    #include "Engine.hpp"

    // # Class

    class Engine_Music {
        public:
            Engine_Music(Engine *);
            ~Engine_Music(void);

            void Play(void);
            void Break(void);
            void Stop(void);
        private:
            Engine *engine;
            sf::Music music;
    };

#endif /* !ENGINE_MUSIC_HPP_ */