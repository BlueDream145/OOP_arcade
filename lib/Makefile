##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SOURCES_SFML		=	../src/graphical/sfml.cpp

SOURCES_SDL			=	../src/graphical/sdl.cpp

SOURCES_NCURSES		=	../src/graphical/ncurses.cpp

CPPFLAGS		=	-fPIC -g	-std=c++17

LDFLAGS			=	-shared

OBJECTS_SFML		=	$(SOURCES_SFML:.cpp=.o)

OBJECTS_SDL			=	$(SOURCES_SDL:.cpp=.o)

OBJECTS_NCURSES		=	$(SOURCES_NCURSES:.cpp=.o)

FIKSENGINE_LIBDIR	=	./

FIKSENGINE_INCDIR	=	../include

TARGET_SFML		=	$(FIKSENGINE_LIBDIR)/lib_arcade_sfml.so

TARGET_SDL		=	$(FIKSENGINE_LIBDIR)/lib_arcade_sdl2.so

TARGET_NCURSES	=	$(FIKSENGINE_LIBDIR)/lib_arcade_ncurses.so

all: $(TARGET_SFML) $(TARGET_SDL) $(TARGET_NCURSES)

$(TARGET_SFML) : $(OBJECTS_SFML)
	$(CC) $(CFLAGS) $(OBJECTS_SFML) -o $@ $(LDFLAGS)

$(TARGET_SDL) : $(OBJECTS_SDL)
	$(CC) $(CFLAGS) $(OBJECTS_SDL) -o $@ $(LDFLAGS)

$(TARGET_NCURSES) : $(OBJECTS_NCURSES)
	$(CC) $(CFLAGS) $(OBJECTS_NCURSES) -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJECTS_SFML) $(TARGET_SFML)
	rm -f $(OBJECTS_SDL) $(TARGET_SDL)
	rm -f $(OBJECTS_NCURSES) $(TARGET_NCURSES)

fclean:	clean
	rm -f $(TARGET_SFML)
	rm -f $(TARGET_SDL)
	rm -f $(TARGET_NCURSES)

re:	fclean all

.PHONY: all clean fclean re
