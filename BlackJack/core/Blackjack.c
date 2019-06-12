#include <stdio.h>
#include <stdlib.h>
#include "../include/Card.h"
#include "../include/Player.h"

int main() {
    int playerTurn = 0;
    Player* human = player(NULL,0);
    Player* dealer = player(NULL,0);

    printf("Welcome to Blackjack!\n");
    while(1) {

        
        
        //Deal cards
        for(int i = 0; i < 2; i++) {
            player_add_card(human,card_deal());
            player_add_card(dealer,card_deal());
        }



                

    }
    
}