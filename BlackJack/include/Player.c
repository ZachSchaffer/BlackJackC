#include <stdio.h>
#include <stdlib.h>
#include "Player.h"

Player *player(Card *hand, int score) {
    Player *newPlayer = (Player *) malloc(sizeof(Player));
    newPlayer->hand = hand;
    newPlayer->score = score;
    return newPlayer;
}

void player_add_card(Player *player, Card *card) {
    card_add(&player->hand, card);
}

void player_empty_hand(Player *player) {
    card_free(player->hand);
    player->hand = NULL;
}

void player_free(Player *player) {
    player_empty_hand(player);
    player->score = 0;
    free(player);
}

int player_hand_score(Player *player) {
    int sum = 0;
    Card *current_card = player->hand;

    if (card_size(player->hand) == 2) {
        if (player->hand->rank == 14 && player->hand->next->rank >= 10) {
            return 21;
        }
        if(player->hand->rank >= 10 && player->hand->next == 14) {
            return 21;
        }
    }
    while (current_card != NULL) {
        if (current_card->rank == 14) { //Ace
           sum += 11;
        } else if (current_card->rank >= 10) { //Face card
            sum += 10;
        } else { //Regular card
            sum += current_card->rank;
        }
        current_card = current_card->next;
    }

    current_card = player->hand;

    while (current_card != NULL && sum > 21) {
        if (current_card->rank == 14) {
            sum -= 10;
        }
        current_card = current_card->next;
    }

    return sum;
}