#include "Card.h"
#include <stdlib.h>
#include <string.h>


Card* card(int rank, char suit) {

	Card* newCard = (Card *) malloc(sizeof(Card));

	newCard->rank = rank;
	newCard->suit = suit;

	return newCard;

}

char* to_string(Card* card) { //TODO: remember to free me
	
	char* result = (char*) calloc(1,4); //calloc zeroes out, ensuring we have a null terminator, card is max 4 bytes

	//Kd
	//2c
	//10d

	//[ J d \0 \0]
	if (card->rank == 11) {
		strcat(result, "J");
	}
	else if (card->rank == 12) {
		strcat(result, "Q");
	}
	else if (card->rank == 13) {
		strcat(result, "K");
	}
	else if (card->rank == 14) {
		strcat(result, "A");
	}
	else
		strcat(result, itoa(card->rank));

	return strcat(result, card->suit); //FIXME

}

char* itoa(int num) {
	//TODO
}

