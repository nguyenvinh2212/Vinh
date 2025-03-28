
#ifndef Game_object_h
#define Game_object_h
#include "animation.h"
#include "Common.h"

extern Uint32 deltaTime;
class Entity
{
public :
    float x, y, dx, dy, time;
    int w, h, health, reload , side;
     int powerupType;
    SDL_Texture* texture;
    Entity(float x = 0 , float y = 0,float dx =0, float dy = 0,
        int health = 0, SDL_Texture* tex = nullptr)
        : x(x), y(y), dx(dx),dy(dy), health(health), texture(tex) {}
    virtual~Entity() {}
    virtual void update(){x += dx;y += dy;}
};


class Player : public Entity
{
public:
    int reload;
    bool hasShield;           // Cờ báo khiên đang hoạt động
    float shieldTimer;        // Thời gian hiệu lực của khiên (tính bằng giây)
    Animation* shieldAnimation;
    SDL_Texture* playerTexture = loadTexture("Image/player.png");
    Animation* plannet = nullptr;
    Animation* playerTail = nullptr ;
    Player();

    virtual void update();
    void clip();
    void applyShield();
};


class Explosion : public Entity
{
public :
    int a, r, g, b;
    virtual void update() override {a--;}

};
class Debris : public Entity
{
public :
    SDL_Rect rect;
    virtual void update() override
    {
        x += dx;
        y += dy +5;
    }
};
class Enemy : public Entity
{
public :
    SDL_Texture* enemyTexture = loadTexture("Image/enemy1.png");
    int wave;
    int healthArr[15] = {1, 2, 2, 3, 3, 4, 4, 20, 5, 5, 5, 6, 6, 6 ,40};
    Enemy(int i = 1);
     int diamondPhase; // 0: lên phải, 1: xuống phải, 2: xuống trái, 3: lên trái

    // Dành cho chuyển động lượn cong:
    float base_dy; // tốc độ dọc cơ bản

    // Dành cho chuyển động vòng tròn:
    float angle;      // góc hiện tại (radians)
    float radius;     // bán kính vòng tròn
    int centerX, centerY; // tâm di chuyển (có thể thay đổi theo thời gian)
    virtual void update() override;
private:
    void updateDiamond();
    void updateCurved();
    void updateCircular();
};


class Stage
{
public:
    int score , wave = 7, coint  ;
    int enemySpawnTimer = 0;
    int StageRestTimer = FPS *3;
    Player* player = nullptr;

    bool victory;
    bool gameOver;
    std::vector<Entity*> bullets;
    std::vector<Explosion*> explosions;
    std::vector<Debris*> debris;
    std::vector<Entity*> PowerUp;
    std::vector<Enemy*> enemies;
   // std::vector<PowerUp*> powerUp;
    Stage(){}
    ~Stage(){reset();}
    void reset();
    void initPlayer();
    void fireBullet();
    void doPlayer();
    void fireAlienBullet(Enemy *e);
    void doFighters();
    void doBullets();
    bool checkBulletHit(Entity* e = nullptr, Player* p = nullptr);
    void spawnEnemies();
    void doExplosions();
    void doDebris();
    void doPowerUp();
    void addExplosions(int x, int y, int num);
    void addDebris(Enemy* e);
    void addPowerUp(int x, int y, int type);
    void logic();
    void draw();
};


extern Stage stage;
#endif // Game_object_h



