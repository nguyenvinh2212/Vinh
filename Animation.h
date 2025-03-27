#ifndef Animation_h
#define Animation_h
#include<string>
#include<SDL2/SDL.h>

extern SDL_Texture *loadTexture(const char *filename);
extern void blitRect(SDL_Texture* texture, SDL_Rect* src, float x, float y);
class Animation {
public:
    Animation();
    Animation(const std::string& texturePath, SDL_Renderer* renderer,int numFrames,
                     int frameWidth, int frameHeight, float gap, Uint32 frameDelay, bool repeat = true);
    ~Animation();
    void update(Uint32 deltaTime);
    int getFrameWidth() const { return frameWidth; }
    void render(SDL_Renderer* renderer, float  x, float y);
    bool Finished() const
    {
        return (!repeat && currentFrame == numFrames - 1);
    }
    void reset()
    {
        currentFrame = 0;
        timeSinceLastFrame =0;
    }

private:
    SDL_Texture* texture;
    SDL_Rect* frameClips;
    int numFrames;
    int currentFrame;
    int frameWidth;
    int frameHeight;
    int gap;
    Uint32 timeSinceLastFrame;
    Uint32 frameDelay; // ms giữa 2 frame
    bool repeat;
};
#endif // Animation_h
