#include <stdio.h>
#include "Player.h"

Player* player(Card* hand, int score) {
    Player* newPlayer = (Player*) malloc(sizeof(Player));
    newPlayer->hand = hand;
    newPlayer->score = score;
    return newPlayer;
}

void player_add_card(Player* player, Card* card) {
    card_add(player->hand, card);
}

void player_empty_hand(Player* player) {
    recursive_free(player->hand);
    player = NULL;
}

void recursive_free(Card* card) {
    if(card == NULL) {
        return;
    } else{
        recursive_free(card->next);
        card_free(card);
    }
}

void player_free(Player* player) {
    //TODO: go through each card in the players hand and free it
    free(player);
}