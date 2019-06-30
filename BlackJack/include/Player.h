#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

typedef struct Player Player;

struct Player {
    Card* hand;
    int score;
};

Player* player(Card* hand, int score);

void player_add_card(Player* player, Card* card);

void player_empty_hand(Player* player);

void player_free(Player* player);

int player_hand_score(Player* player);

#endif