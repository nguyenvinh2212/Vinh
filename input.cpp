

#include "Common.h"
#include <algorithm>

void doInput()
{
    SDL_Event event;
    // Xoá nội dung inputText nhanh hơn
    std::fill(std::begin(app.inputText), std::end(app.inputText), '\0');
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                if (event.key.repeat == 0 && event.key.keysym.scancode < MAX_KEYBOARD_KEYS)
                    app.keyboard[event.key.keysym.scancode] = 1;
                break;
            case SDL_KEYUP:
                if (event.key.repeat == 0 && event.key.keysym.scancode < MAX_KEYBOARD_KEYS)
                    app.keyboard[event.key.keysym.scancode] = 0;
                break;
            case SDL_TEXTINPUT:
                strncpy_s(app.inputText, 32, event.text.text, MAX_LINE_LENGTH);
                break;
            default:
                break;
        }
    }
}

int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	return (std::max(x1, x2) <= std::min(x1 + w1, x2 + w2)) && (std::max(y1, y2) <= std::min(y1 + h1, y2 + h2));
}
void calcSlope(int x1, int y1, int x2, int y2, float &dx, float &dy)
{
	int steps = std::max(abs(x1 - x2), abs(y1 - y2));
	if (steps == 0)
	{
		dx = dy = 0;
		return;
	}
	dx = (x1 - x2);
	dx /= steps;
	dy = (y1 - y2);
	dy /= steps;
}

