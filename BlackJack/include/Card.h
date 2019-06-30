#ifndef CARD_H
#define CARD_H

typedef struct Card Card;

struct Card {
	int rank;
	char suit;
	Card* next;
};


Card* card(int rank, char suit, Card* next);

void card_add(Card** head, Card* toAdd);

Card* card_deal();

char* card_to_string(Card* card);

char* card_print(Card* head);

int card_size(Card* card);

void card_free(Card* card);



#endif