#include "Card.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


void my_itoa(int num, char *arr);

Card* card(int rank, char suit, Card* next) {

	Card* newCard = (Card *) malloc(sizeof(Card));

	newCard->rank = rank;
	newCard->suit = suit;
	newCard->next = next;

	return newCard;

}

void card_add(Card** head, Card* toAdd) {

	Card* current = *head;

	if (current == NULL) {
		*head = toAdd;
	} else {
		while (current->next != NULL) { //Iterate to the end of linked list
			current = current->next;
		}
		current->next = toAdd;
	}
}

Card* card_deal() {

    int validRanks[] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    char validSuits[] = {'c','s','h','d'};

    return card(validRanks[rand()%13], validSuits[rand()%4], NULL);
    
}


char* card_to_string(Card* card) { //TODO: remember to free me
	
	char* result = (char*) calloc(1,4); //calloc zeroes out, ensuring we have a null terminatr, card is max 4 bytes
	char rankAsString[3] = {'\0','\0','\0'};


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
	else {
        my_itoa(card->rank, rankAsString);
		strcat(result, rankAsString);
	}

	if(result[1] == '\0') { //Check last available space in result and place suit there
        result[1] = card->suit;
	} else {
	    result[2] = card->suit;
	}

    result[3] = '\0';
    return result;
}

void my_itoa(int num, char *arr) {

	switch (num) {
	case 1:
		arr[0] = '1';
		arr[1] = '\0';
		break;
	case 2:
		arr[0] = '2';
		arr[1] = '\0';
		break;
	case 3:
		arr[0] = '3';
		arr[1] = '\0';
		break;
	case 4:
		arr[0] = '4';
		arr[1] = '\0';
		break;
	case 5:
		arr[0] = '5';
		arr[1] = '\0';
		break;
	case 6:
		arr[0] = '6';
		arr[1] = '\0';
		break;
	case 7:
		arr[0] = '7';
		arr[1] = '\0';
		break;
	case 8:
		arr[0] = '8';
		arr[1] = '\0';
		break;
	case 9:
		arr[0] = '9';
		arr[1] = '\0';
		break;
	case 10:
		arr[0] = '1';
        arr[1] = '0';
		arr[2] = '\0';
		break;
	case 11:
		arr[0] = '1';
        arr[1] = '1';
		arr[2] = '\0';
		break;
	case 12:
		arr[0] = '1';
		arr[1] = '2';
        arr[2] = '\0';
		break;
	case 13:
		arr[0] = '1';
		arr[1] = '3';
        arr[2] = '\0';
		break;
	case 14:
		arr[0] = '1';
		arr[1] = '4';
        arr[2] = '\0';
		break;
	default:
		break;
	}
	
}

char* card_print(Card* head) {
    if (head->next == NULL) {
        return card_to_string(head);
    } else {
        return strcat(strcat(card_to_string(head), ", "), card_print(head->next));
    }
}

int card_size(Card* card) {
    if (card != NULL) {
        return 1 + card_size(card->next);
    } else {
        return 0;
    }
}

void card_free(Card* card) {
    if(card == NULL) {
        return;
    } else{
        card->rank = NULL;
        card->suit = NULL;
        card_free(card->next);
        free(card);
    }
}


