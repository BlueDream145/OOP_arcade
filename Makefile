##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## @epitech.eu
##

SRC			=	src/main.cpp \
				src/graphical/ncurses.cpp \
				src/engine/engine_events.cpp \
				src/engine/engine_game.cpp \
				src/engine/engine_rsc.cpp \
				src/engine/engine_lib.cpp \
				src/engine/engine_menu.cpp \
				src/engine/engine_music.cpp \
				src/engine/engine.cpp

CXXFLAGS	=	-Wall -Wextra -Wfatal-errors -std=c++17 -fPIC `sdl-config --cflags --libs`

LIBS		=	-lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -Wl,--no-as-needed -ldl -Wl,-rpath=/usr/local/lib -lSDL2 -lSDL2_image -lSDL2  

OBJS		=	$(SRC:.cpp=.o)

NAME		=	arcade

all: games graphicals core

core: $(OBJS)
	g++ -o $(NAME) $(OBJS) $(CFLAGS) $(LIBS)

graphicals:
	make -C ./lib

games:
	make -C ./games

clean:
	rm -rf $(OBJS)
	make -C ./games clean
	make -C ./lib clean

fclean:	clean
	rm -f $(NAME)
	make -C ./games fclean
	make -C ./lib fclean

re:	fclean all
	make -C ./games re
	make -C ./lib re

.PHONY: all clean fclean re core graphicals games arcade
