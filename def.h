
#ifndef def_h
#define def_h

#define SCREEN_WIDTH    700
#define SCREEN_HEIGHT    670


#define MAX_SCORE_NAME_LENGTH	16
#define MAX_NAME_LENGTH			32
#define MAX_LINE_LENGTH			1024

#define FPS						60

#define PLAYER_SPEED			4
#define PLAYER_BULLET_SPEED		8
#define ENEMY_BULLET_SPEED		6
#define MAX_KEYBOARD_KEYS		350

#define SIDE_PLAYER				0
#define SIDE_ALIEN				1

#define MAX_STARS				200
#define MAX_SPEED_STARS         5

#define MAX_SND_CHANNELS		8

#define NUM_HIGHSCORES			8

#define GLYPH_HEIGHT		    14
#define GLYPH_WIDTH			    9
#define RENDER_DRAW_COLOR       0xff
enum
{
	CH_ANY = -1,
	CH_PLAYER,
	CH_ALIEN_FIRE,
	CH_POINTS
};

enum
{
	SND_PLAYER_FIRE,
	SND_ALIEN_FIRE,
	SND_PLAYER_DIE,
	SND_ALIEN_DIE,
	SND_POINTS,
	SND_MAX
};

enum Aligin
{
	TEXT_LEFT,
	TEXT_RIGHT,
	TEXT_CENTER
};

enum PowerUpType {
    POWERUP_COIN,
    POWERUP_BULLET,
    POWERUP_SHIELD,
    POWERUP_LIFE
};
#endif // def
