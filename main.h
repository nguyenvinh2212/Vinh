#ifndef main_h
#define main_h

#include "Common.h"
#include "menu.h"
#include "graphic.h"
#include "Highscore.h"
extern void initgame();
extern void initSDL();
extern void initFonts();
extern void initTitle();
extern void initStage();
extern void prepareScene();
extern void presentScene();
extern void close();
extern doInput();
extern TextRenderer textManager;
#endif // main_h
