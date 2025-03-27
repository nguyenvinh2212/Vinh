
#include "Menu.h"
#include "graphic.h"
void startGame() {


    gameState = true;
}

void optionsMenu() {
    std::cout << "Options selected\n";
}
void exitGame() {
    exit(0);
}

Menu::Menu() : activeIndex(0), active(true), title(nullptr) {}
Menu::~Menu() {
    // Giải phóng các texture của menu items
    for (auto& item : items) {
        SDL_DestroyTexture(item.normal);
        SDL_DestroyTexture(item.selected);
    }
    items.clear();
    if (title) SDL_DestroyTexture(title);
}
void Menu::init() {
    active = true;
    activeIndex = 0;
    items.clear();
    title = loadTexture("Image/Title.png");
    MenuItem item;
    // "Start"
    item.label = "Start";
    item.x = 250;
    item.y = 300;
    item.normal = loadTexture("Image/start.png");
    item.selected = loadTexture("Image/start_selected.png");
    item.action = startGame;
    items.push_back(item);

    // "Options"
    item.label = "Options";
    item.x = 250;
    item.y = 360;
    item.normal = loadTexture("Image/option.png");
    item.selected = loadTexture("Image/option_selected.png");
    item.action = optionsMenu;
    items.push_back(item);

    // "Exit"
    item.label = "Exit";
    item.x = 250;
    item.y = 420;
    item.normal = loadTexture("Image/exit.png");
    item.selected = loadTexture("Image/exit_selected.png");
    item.action = exitGame;
    items.push_back(item);
}

void Menu::update() {
    if (app.keyboard[SDL_SCANCODE_UP]) {
        activeIndex--;
        if (activeIndex < 0)
            activeIndex = items.size() - 1;
        app.keyboard[SDL_SCANCODE_UP] = 0;  // reset key
    }
    if (app.keyboard[SDL_SCANCODE_DOWN]) {
        activeIndex++;
        if (activeIndex >= (int)items.size())
            activeIndex = 0;
        app.keyboard[SDL_SCANCODE_DOWN] = 0;
    }
    if (app.keyboard[SDL_SCANCODE_RETURN]) {
        if (!items.empty() && items[activeIndex].action != nullptr) {
            items[activeIndex].action();
        }
        app.keyboard[SDL_SCANCODE_RETURN] = 0;
    }
}

void Menu::draw() {
    doBackground();
    drawBackground();
    SDL_Rect titleRect = { 65,120, 600, 150};
    SDL_RenderCopy(app.renderer, title, NULL, &titleRect);

    for (size_t i = 0; i < items.size(); i++) {
        SDL_Texture* tex = (i == (size_t)activeIndex) ? items[i].selected : items[i].normal;
        SDL_Rect dest = { items[i].x, items[i].y, 200, 50 };  // kích thước của nút (có thể điều chỉnh)
        SDL_RenderCopy(app.renderer, tex, NULL, &dest);
    }
}
