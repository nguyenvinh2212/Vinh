#ifndef main_h
#define main_h

#include "Common.h"
#include "menu.h"


extern void initgame();
extern void initSDL();
extern void initFonts();
extern void initTitle();
extern void initStage();
extern void prepareScene();
extern void presentScene();
extern void close();
extern doInput();
App app;
Stage stage;
#endif // main_h
