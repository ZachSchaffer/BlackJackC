#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/Card.h"
#include "../include/Player.h"

void win_state(Player *player);

void loss_state(Player *player);

int main() {
    int human_hitting = 1;
    int firstPass = 1;
    char buffer[2];
    Player *human = player(NULL, 0);
    Player *dealer = player(NULL, 0);
    srand(time(0));


    printf("Welcome to Blackjack!\n");
    while (1) {
        printf("\n\n");

        if (!firstPass) {
            printf("Would you like to continue? (y/n)\n");
            fgets(buffer, sizeof(buffer), stdin);
            char c;
            while ((c = getchar()) != '\n' && c != EOF);

            if (buffer[0] == 'n' || buffer[0] == 'N') {
                break;
            }
        }

        firstPass = 0;
        human_hitting = 1;

        player_empty_hand(human);
        player_empty_hand(dealer);

        //Deal cards
        for (int i = 0; i < 2; i++) {
            player_add_card(human, card_deal());
            player_add_card(dealer, card_deal());
        }

        printf("Dealer cards: %s, Total: %d\n\n", card_print(dealer->hand), player_hand_score(dealer));

        while (human_hitting) {

            printf("Your hand: %s\n Total: %d\n", card_print(human->hand), player_hand_score(human));

            if (player_hand_score(human) >= 21) {
                human_hitting = 0;
            } else {
                printf("Hit or Stay? (h/s)\n");

                fgets(buffer, sizeof(buffer), stdin);
                char c;
                while ((c = getchar()) != '\n' && c != EOF);
                if (buffer[0] != 'h' && buffer[0] != 's') {
                    printf("Invalid input.\n");
                } else if (buffer[0] == 'h') {
                    player_add_card(human, card_deal());
                } else {
                    human_hitting = 0;
                }
            }
        }

        if (player_hand_score(human) == 21) {
            printf("Blackjack!\n");
            win_state(human);
            continue;
        }

        if (player_hand_score(human) > 21) {
            printf("You Bust!\n");
            loss_state(human);
            continue;
        }

        while (player_hand_score(dealer) < 16 && player_hand_score(human) >= player_hand_score(dealer)) {
            player_add_card(dealer, card_deal());
        }

        printf("\n==Dealer draws cards and winds up with: \n%s, a total of %d\n", card_print(dealer->hand),
               player_hand_score(dealer));

        if (player_hand_score(dealer) == 21) {
            printf("Dealer has BlackJack!\n");
            loss_state(human);
            continue;
        }

        if (player_hand_score(dealer) > 21) {
            printf("Dealer Busts!\n");
            win_state(human);
            continue;
        }

        if (player_hand_score(human) >= player_hand_score(dealer)) {
            printf("Your %d beats the dealer's %d!\n", player_hand_score(human), player_hand_score(dealer));
            win_state(human);
        } else {
            printf("Your %d loses to the dealer's %d!\n", player_hand_score(human), player_hand_score(dealer));
            loss_state(human);
        }

    }

    printf("======================\n");
    printf("Final Score: %d\n", human->score);
    printf("======================\n");

}

void win_state(Player *player) {
    player->score += 10;
    printf("You win! Score: %d\n", player->score);
}

void loss_state(Player *player) {
    player->score -= 10;
    printf("You lose! Score: %d\n", player->score);
}