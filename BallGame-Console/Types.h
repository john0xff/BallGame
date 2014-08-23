#pragma once

#define MAX_CHAR 6
#define MAX_SAVE_SCORE 5

typedef int int16;

struct Point2D
{
	int y, x;
};

typedef struct
{
	char name[ MAX_CHAR ];
	short score;
} BestScore;

