#include <stdio.h>
#include <stdlib.h>
#include "Card.h"

int main() {
	Card* card1 = card(2, 'd');
	char* card_string = card_to_string(card1);

	printf("%s", card_string);
	free(card_string);
}