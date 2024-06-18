# OOP_arcade
Epitech Second Year Project, OOP arcade game in CPP


![alt text](https://github.com/alexandre10044/OOP_arcade/blob/master/example1.png)


![alt text](https://github.com/alexandre10044/OOP_arcade/blob/master/example2.png)


Subject:

Arcade is agaming platform: a program that lets the user choose a game to play and keeps a register ofplayer scores.

To be able to deal with the elements of your gaming plate-form at run-time, your graphic libraries and your gamesmust be implemented asdynamic libraries, loaded at run-time.

Each GUI available for the program must be used as a sharedlibrary that will be loaded and used dynamically by the mainprogram.

You must use dynamic libraries at run-time.This means that you MUST use thedlopen,dlclose,dlsymanddlerrorfunctions to handle your dynamiclibraries.

These dynamic libraries can be seen as plug-ins providing various capabilities to your main program.In NO CASE must graphic libraries influence the game logic.Game libraries must not contain any information about screen rendering or low-level events.

Usage:

The program must take as a startup argument the graphics library to use initially.It must nevertheless be possible to change the graphics library at run-time.

./arcade ./lib_arcade_opengl.so

When the program starts, it must display in separated boxes:

•the games available in the./gamesdirectory (at least 2),
•the graphic libraries in the./libdirectory,
•scores,
•a field for the user to enter their name.
