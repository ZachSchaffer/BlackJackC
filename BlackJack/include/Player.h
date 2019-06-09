#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

typedef struct Player Player;

struct Player {
    Card* hand;
    int score;
};

#endif