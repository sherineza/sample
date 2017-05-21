#ifndef ___FUNCTIONS__H__
#define ___FUNCTIONS__H__
bool coinflip();
bool checkwin(char * table);
void couttable(char * table);
bool validmove(char * table, char loc);
void makemove(char * table);
void automove(char * table);
bool gameover(char * table);
#endif
