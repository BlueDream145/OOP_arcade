/*
** EPITECH PROJECT, 2019
** sfml.cpp
** File description:
** sfml
*/

#include "../../include/Libncurses.hpp"

extern "C" IGraphic *createObj(void)
{
    return new libncurses();
}

extern "C" void destroyObj(IGraphic *gam)
{
    delete gam;
}
  
void libncurses::createWindow(std::pair<int, int> dim, std::string const &name)
{
    initscr();
    noecho();
    timeout(10);
    keypad(stdscr, TRUE);
    attron(A_BOLD);
    curs_set(FALSE);
}

const char *libncurses::getInput() const
{
     int ch = getch();

    for (auto &i : Key_list) {
        if (i.second == ch)
            return (i.first.c_str());
    }
    return "def";
}

void libncurses::displayAll()
{

}

void libncurses::load_all(std::vector<SE *> disp)
{
    Rect *info;

    for(auto &i : disp) {
        Rect *info  = static_cast<Rect *> (i);
        if (info->color == "Blue")
            mvprintw(info->pos.second, info->pos.first * 2, "#");
        if (info->color == "Black")
            mvprintw(info->pos.second, info->pos.first * 2, " ");
        if (info->color == "Yellow" || info->color == "Green") {
            mvprintw(info->pos.second, info->pos.first * 2, "0");
        }
        if (info->color == "Red") {
            mvprintw(info->pos.second, info->pos.first * 2, "A");
        }
        if (info->color == "Magenta")
            mvprintw(info->pos.second, info->pos.first * 2, "-");
    }
}

void libncurses::delet_elems()
{

}
bool libncurses::clearWindow()
{
    return true;
}

bool libncurses::deleteAll()
{
    endwin();
    return true;
}

bool libncurses::destroy_Window()
{
    return true;
}

bool libncurses::is_Run()
{
    return true;
}