##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SOURCES_SNAKE		=	../src/games/snake.cpp

SOURCES_PACMAN		=	../src/games/pacman.cpp

CPPFLAGS		=	-fPIC -g	-std=c++11

LDFLAGS			=	-shared

OBJECTS_SNAKE		=	$(SOURCES_SNAKE:.cpp=.o)

OBJECTS_PACMAN		=	$(SOURCES_PACMAN:.cpp=.o)

FIKSENGINE_LIBDIR	=	./

FIKSENGINE_INCDIR	=	../include

TARGET_SNAKE		=	$(FIKSENGINE_LIBDIR)/lib_arcade_nibbler.so

TARGET_PACMAN		=	$(FIKSENGINE_LIBDIR)/lib_arcade_pacman.so

all: $(TARGET_SNAKE) $(TARGET_PACMAN)

$(TARGET_SNAKE) : $(OBJECTS_SNAKE)
	$(CC) $(CFLAGS) $(OBJECTS_SNAKE) -o $@ $(LDFLAGS)

$(TARGET_PACMAN) : $(OBJECTS_PACMAN)
	$(CC) $(CFLAGS) $(OBJECTS_PACMAN) -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJECTS_SNAKE) $(TARGET_SNAKE)
	rm -f $(OBJECTS_PACMAN) $(TARGET_PACMAN)

fclean:	clean
	rm -f $(TARGET_SNAKE)
	rm -f $(TARGET_PACMAN)

re:	fclean all

.PHONY: all clean fclean re
