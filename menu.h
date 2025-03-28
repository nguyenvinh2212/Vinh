#ifndef MENU_H
#define MENU_H

#include "Common.h"

// Cấu trúc một item trong menu
struct MenuItem {
    std::string label;
    int x, y;
    SDL_Texture* normal;
    SDL_Texture* selected;
    void (*action)();  // Hàm xử lý khi chọn item này

};

class Menu {
public:
    Menu();
    ~Menu();
    void init();
    void update();
    void draw();
    void switchToOptions();
    void switchToMain();
    void switchToControls();
    void switchToHighScores();
private:
    // Hai hàm khởi tạo danh sách items riêng cho từng trạng thái

    int activeIndex;
    bool active;
    SDL_Texture* title;
    bool inOptionsMenu;
    bool inControlsMenu; // (MỚI) true = đang ở màn hình Controls
    bool inHighScoresMenu;

    std::vector<MenuItem> items;

    void initMainItems();
    void initOptionsItems();
    void initControlsItems();
    void initHighScores();
};

#endif // MENU_H
