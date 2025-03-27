#ifndef MENU_H
#define MENU_H

#include "Common.h"
extern void doBackground();
extern void drawBackground();
extern bool gameState;
struct MenuItem {
    std::string label;
    int x, y;
    SDL_Texture* normal;
    SDL_Texture* selected;
    void (*action)();
};

class Menu {
public:
    Menu();
    ~Menu();
    void init();
    void update();
    void draw();
    bool isActive() const { return active; }
    void setActive(bool a) { active = a; }

private:
    std::vector<MenuItem> items;
    int activeIndex;
    bool active;
    SDL_Texture* title;

};

#endif // MENU_H
