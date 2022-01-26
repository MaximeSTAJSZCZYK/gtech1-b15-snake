
#ifndef SNAKE_PLAYER_H
#define SNAKE_PLAYER_H

// Player rectangles geometry.
#define PLAYER_WIDTH  25
#define PLAYER_HEIGHT 25

typedef struct
{
	/// The Y position of the player's racket, in pixels.
	int posY;

	/// The player's score.
	int score;

} player_t;

#endif 