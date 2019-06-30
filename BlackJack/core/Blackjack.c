#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/Card.h"
#include "../include/Player.h"

void win_state(Player *player);
void loss_state(Player *player);

int main() {
    int playerTurn = 0;
    Player* human = player(NULL,0);
    Player* dealer = player(NULL,0);
    srand(time(0));


    printf("Welcome to Blackjack!\n");
    while(1) {
        //Deal cards
        for(int i = 0; i < 2; i++) {
            player_add_card(human,card_deal());
            player_add_card(dealer,card_deal());
        }

        printf("Dealer cards: %s\n", card_print(dealer->hand));
        printf("Your cards: %s\n", card_print(human->hand));


        if(player_hand_score(dealer) > 21) {
            win_state(human);
        }

        if(player_hand_score(human) == 21) {

        }

        break;
    }

}

void win_state(Player *player) {
    player->score += 10;
    printf("You win! Score: %d", player->score);
}

void loss_state(Player *player) {
    player->score -= 10;
    printf("You lose! Score: %d", player->score);
}