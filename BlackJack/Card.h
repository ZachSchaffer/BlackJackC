#ifndef CARD_H
#define CARD_H

typedef struct Card Card;

struct Card {
	int rank;
	char suit;
};


Card* card(int rank, char suit);

char* card_to_string(Card* card);

void card_free(Card* card);






#endif