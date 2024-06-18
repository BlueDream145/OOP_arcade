/*
** EPITECH PROJECT, 2019
** Libncurses.hpp
** File description:
** Libncurses
*/

#ifndef LIBNCURSES_HPP_
    #define LIBNCURSES_HPP_

    # include <termios.h>
    # include <sys/ioctl.h>
    # include <curses.h>
    # include "IGraphic.hpp"
    #include "SE.hpp"

   class libncurses : public IGraphic
    {
        public:
            libncurses() { };
             ~libncurses() { };
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
             std::map<std::string, int> Key_list = {
		{"A", 'a'},
		{"Z", 'z'},
		{"L", 'l'},
		{"Q", 'q'},
		{"S", 's'},
		{"D", 'd'},
		{"F",'f'},
		{"M", 'm'},
		{"E", 'e'},
		{"Left", 0404},
		{"Right", 0405},
		{"Up", 0403},
		{"Down", 0402},
	};
    };

#endif /* !LIBNCURSES_HPP_ */