#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/Card.h"
#include "../include/Player.h"

void win_state(Player *player);
void loss_state(Player *player);

int main() {
    int human_hitting = 1;
    int comp_hitting = 1;
    Player* human = player(NULL,0);
    Player* dealer = player(NULL,0);
    srand(time(0));


    printf("Welcome to Blackjack!\n");
    while(1) {

        human_hitting = 1;

        player_empty_hand(human);
        player_empty_hand(dealer);
        printf("\n\n");
        //Deal cards
        for(int i = 0; i < 2; i++) {
            player_add_card(human,card_deal());
            player_add_card(dealer,card_deal());
        }

        printf("Dealer cards: %s\n", card_print(dealer->hand));
        printf("Your cards: %s\n", card_print(human->hand));


        if(player_hand_score(dealer) > 21) {
            printf("Dealer Busts!");
            win_state(human);
            continue;
        }

        if(player_hand_score(human) > 21) {
            printf("You Bust!");
            loss_state(human);
            continue;
        }

        if(player_hand_score(human) == 21) {
            printf("Blackjack!\n");
            win_state(human);
            continue;
        }

        if(player_hand_score(dealer) == 21) {
            printf("Dealer has BlackJack!");
            loss_state(human);
            continue;
        }

        while(human_hitting) {


            printf("Your hand: %s\n Total: %d\n",card_print(human->hand), player_hand_score(human));

            if(player_hand_score(human) >= 21) {
                human_hitting = 0;
            } else {
                printf("Hit or Stay? (h/s)\n");
                char choice[2];

                fgets(choice, sizeof(choice),stdin);
                char c;
                while((c = getchar()) != '\n' && c != EOF);
                if(choice[0] != 'h' && choice[0] != 's') {
                    printf("Invalid input.\n");
                } else if(choice[0] == 'h'){
                    player_add_card(human,card_deal());
                } else {
                    human_hitting = 0;
                }
            }
        }

        if(player_hand_score(human) == 21) {
            printf("Blackjack!\n");
            win_state(human);
            continue;
        }

        if(player_hand_score(human) > 21) {
            printf("You Bust!");
            loss_state(human);
            continue;
        }

        while(player_hand_score(dealer) < 16) {
            player_add_card(dealer,card_deal());
        }

        if(player_hand_score(dealer) == 21) {
            printf("Dealer has BlackJack!");
            loss_state(human);
            continue;
        }

        if(player_hand_score(dealer) > 21) {
            printf("Dealer Busts!");
            win_state(human);
            continue;
        }

        if(player_hand_score(human) >= player_hand_score(dealer)) {
            win_state(human);
            continue;
        } else {
            loss_state(human);
        }


        //prompt to continue playing maybe
        break;
    }



}

void win_state(Player *player) {
    player->score += 10;
    printf("You win! Score: %d\n", player->score);
}

void loss_state(Player *player) {
    player->score -= 10;
    printf("You lose! Score: %d\n", player->score);
}