
#include "Game_object.h"
#include "animation.h"
#include "Common.h"

Player::Player()
{
    texture = playerTexture;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    x = SCREEN_WIDTH / 2 - w / 2;
    y = 620;
    health = 3;
    reload = 8;
    dx = 0;
    dy = 0;
    side = SIDE_PLAYER;
    playerTail = new Animation("animation/Nairan - Frigate - Engine.png", app.renderer, 8, 32, 10, 58,30);
    plannet = new Animation("animation/Earth-Like planet.png", app.renderer, 60, 62, 64, 34, 100);
    hasShield = false;
    shieldTimer = 0;
    shieldAnimation = nullptr;
}

void Player::update()
{
    x += dx;
    y += dy;
    clip();
    if(playerTail) playerTail->update(deltaTime);
    if (playerTail)
        playerTail->update(deltaTime);
    if (hasShield) {
        shieldTimer -= (float)deltaTime / 1000;
        if (shieldTimer <= 0) {
            hasShield = false;
            shieldTimer = 0;
            // delete shieldAnimation; shieldAnimation = nullptr;
        } else {
            if (shieldAnimation)
                shieldAnimation->update(deltaTime);
        }
    }
}

void Player::clip()
{
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > SCREEN_WIDTH - w) x = SCREEN_WIDTH - w;
    if (y > SCREEN_HEIGHT - h) y = SCREEN_HEIGHT - h;
}

void Player::applyShield()
{
    hasShield = true;
    shieldTimer = 10;
    if (!shieldAnimation) {
        shieldAnimation = new Animation("animation/Shield_animation.png", app.renderer,
                                          11, 68, 68, 16.5 , 100, true);
    }

}
Enemy::Enemy(int i)
{
    texture = enemyTexture;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    x = std::max(w/2, rand() % SCREEN_WIDTH - (w/2));
    side = SIDE_ALIEN;
    wave = i;
    health = healthArr[i];
    reload = FPS * (4 + rand() % 3);
    switch (wave % 7 ) {
        case 1: // Đi ziczac ngang
            dx = (SDL_GetTicks() / 300 % 2 == 0) ? 1.5 : -1.5;
            dy = 1;
            texture = loadTexture("Image/enemy1.png");
            break;
        case 2: // Lượn sóng
            dx = sin(SDL_GetTicks() / 200.0) * 3;
            dy = 1.2;
            texture = loadTexture("Image/enemy2.png");
            break;
        case 3: // Đi chéo trái
            dx = -1.2;
            dy = 1;
            texture = loadTexture("Image/enemy1.png");
            break;
        case 4: // Đi chéo phải
            dx = 1.2;
            dy = 1;
            texture = loadTexture("Image/enemy2.png");
            break;
        case 5: // Hình sin mạnh
            dx = sin(SDL_GetTicks() / 100.0) * 3.5;
            dy = 1.2;
            texture = loadTexture("Image/enemy3.png");
            break;
        case 6: // Đi chậm dần
            dx = 0;
            dy = std::max(0.5, 1.8 - SDL_GetTicks() / 2000.0);
            texture = loadTexture("Image/enemy4.png");
            break;
        case 0:
            dx = 2;
            dy = 0.1;
            texture = loadTexture("Image/boss.png");
            break;
    }
}

void Enemy::update_enemy()
{
    if (x < 0) dx=-dx;
    else if (x > SCREEN_WIDTH - w) {
        dx = -dx;
    }
    x += dx;
    y += dy;

}
