#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//Struct to denote a single card. A card have value of in_Game = 1 if it is used by players else 0 , and a value of that card
struct card {
	int in_Game; //either 0 or 1
	char val[5]; //values are defined in detail in document for each card 
};

/*
	A player can have maximum 14 cards from the other player during game
	and Books of 13 indices each representing the card indexValber , during the
	start of game only first 7 indices of playerHand will be randomely 
	initialized. pHandsize will keep the record of current cards in Hand
	during gameplay
*/

struct player {
	int playerHand[14]; //Current cards in player hands
	int pHandsize; 		//Count of current cards in hands
	int books[13];		// Count of books , if any index contains the value 4 , it has that specific card defined in document 
};
/*
	Initialize the deck cards. First set the 
*/
void initializeDeck(struct card *D, int size) {
	for (int i = 0; i < size; i++) {
		D[i].in_Game = 0;
	}

	/*
		Initializing Spades
	*/

	strcpy(D[0].val, "2S");
	strcpy(D[1].val , "3S");
	strcpy(D[2].val , "4S");
	strcpy(D[3].val , "5S");
	strcpy(D[4].val , "6S");
	strcpy(D[5].val , "7S");
	strcpy(D[6].val , "8S");
	strcpy(D[7].val , "9S");
	strcpy(D[8].val , "10S");
	strcpy(D[9].val , "JS");
	strcpy(D[10].val , "QS");
	strcpy(D[11].val , "KS");
	strcpy(D[12].val , "AS");

	/*
		Initializing Diamonds
	*/

	strcpy(D[13].val , "2D");
	strcpy(D[14].val , "3D");
	strcpy(D[15].val , "4D");
	strcpy(D[16].val , "5D");
	strcpy(D[17].val , "6D");
	strcpy(D[18].val , "7D");
	strcpy(D[19].val , "8D");
	strcpy(D[20].val , "9D");
	strcpy(D[21].val , "10D");
	strcpy(D[22].val , "JD");
	strcpy(D[23].val , "QD");
	strcpy(D[24].val , "KD");
	strcpy(D[25].val , "AD");



	/*
	Initializing Hearts
	*/

	strcpy(D[26].val , "2H");
	strcpy(D[27].val , "3H");
	strcpy(D[28].val , "4H");
	strcpy(D[29].val , "5H");
	strcpy(D[30].val , "6H");
	strcpy(D[31].val , "7H");
	strcpy(D[32].val , "8H");
	strcpy(D[33].val , "9H");
	strcpy(D[34].val , "10H");
	strcpy(D[35].val , "JH");
	strcpy(D[36].val , "QH");
	strcpy(D[37].val , "KH");
	strcpy(D[38].val , "AH");


	/*
	Initializing Clubs
	*/

	strcpy(D[39].val , "2C");
	strcpy(D[40].val , "3C");
	strcpy(D[41].val , "4C");
	strcpy(D[42].val , "5C");
	strcpy(D[43].val , "6C");
	strcpy(D[44].val , "7C");
	strcpy(D[45].val , "8C");
	strcpy(D[46].val , "9C");
	strcpy(D[47].val , "10C");
	strcpy(D[48].val , "JC");
	strcpy(D[49].val , "QC");
	strcpy(D[50].val , "KC");
	strcpy(D[51].val , "AC");
	
}

//Function to print the deck with the index , its value and the in_Game value either 1 or 0
void printDeck(struct card *D, int size) {
	for (int i = 0; i < 52; i++) {
		printf("index: %d	In Game: %d	Value: ", i, D[i].in_Game);
		for (int j = 0; D[i].val[j] != '\0'; j++) {
			printf("%c", D[i].val[j]);
		}
		printf("\n");
	}
}

//Function to initialize a player before the game
void initializePlayer(struct player *p, struct card D[]) {

	p->pHandsize = 0; //In the start a player have 0 cards so 0 handsize
	for (int i = 0; i < 13; i++) {
		p->books[i] = 0;  //A player have 0 books so store 0 at all the 14 indices
	}

	int j = 0;
	while (j < 7) {  //Generate 7 numbers

		int indexVal = rand() % 52; //Generate a random number between 0 to 52
	
		if (D[indexVal].in_Game == 1) { //If that the random number index's card is already in game then generate any other index
			continue;
		}
		else{
			D[indexVal].in_Game = 1; //1 to denote if the card is alloted to the specific player
			p->playerHand[j] = indexVal; //store that index value of card in the playerHand, we will access card with the index value not actually a whole card
			j++;
			p->pHandsize++; //Increase the handsize as we got a card in our hand
		}
	}

}


/*
	Card in hand of a player , All the cards are shown according to the document description
*/

//A show hand to print the cards a player have currently in the hand
void show_hand(struct player *p) {

	printf("Your hand\n");
	for (int i = 0; i < p->pHandsize; i++) {

		int indexVal = p->playerHand[i];
		if (indexVal == -1) {
			continue;
		}
		/*
			How i use these if statements , consult the document where prof discussed about the cards and their indices
		*/

		printf("(%d) ", i + 1);
		if (indexVal % 13 >= 0 && indexVal % 13 <= 8) {
			printf("%d of ", indexVal % 13 + 2);
		}

		if (indexVal % 13 == 9) {
			printf("Jack of ");
		}

		if (indexVal % 13 == 10) {
			printf("Queen of ");
		}
		
		if (indexVal % 13 == 11) {
			printf("King of ");
		}

		if (indexVal % 13 == 12) {
			printf("Ace of ");
		}

		if (indexVal <= 12 && indexVal >= 0) {
			printf("spades\n");
		}
		if ( indexVal <= 25 && indexVal >= 13) {
			printf("diamonds\n");
		}

		if (indexVal <= 38 && indexVal >= 26) {
			printf("hearts\n");
		}

		if ( indexVal <= 51 && indexVal >= 39 ) {
			printf("clubs\n");
		}


	}
}


/*
Get Number of specific card in the deck using index 
*/

char *getNumber(int index, char *num) {
	num = (char*)malloc(BUFSIZ);

	if (strcmp( num, "-1" ) == 0) {
		strcpy(num, "N"); //return nothing as N
	}

	if (index % 13 >= 0 && index % 13 <= 8) {
		sprintf(num, "%d", index % 13 + 2);
	}

	if (index % 13 == 9) {
		strcpy(num, "J");
	}

	if (index % 13 == 10) {
		strcpy(num, "Q");
	}

	if (index % 13 == 11) {
		strcpy(num, "K");
	}

	if (index % 13 == 12) {
		strcpy(num, "A");
	}

	return num;
}

/*
	if book value is 4 then number of books for a player is 1
*/

int check_for_books(struct player *p) {

	char *val1 = NULL;
	char *val2 = NULL;
	int num_i = 0;
	int num_j = 0;
	int count = 0;
	for (int i = 0; i < p->pHandsize; i++) {
		val1 = getNumber(p->playerHand[i], val1); //get the index of that specific card from player's hand
		//sscanf(val, "%d", &num_i);
		for (int j = 0; j < p->pHandsize; j++) {
			val2 = getNumber(p->playerHand[j], val2); //using that value compare it with all the cards in the player hands
			//sscanf(val, "%d", &num_j);
			if (strcmp(val1,val2)==0) { //if it occour more than one
				count++; //increase the count
			}
		}
		
		/*
			We don't know which card it was , therefore we will compare the values of each card and then make that index = 4
		*/
		if (count == 4) {
			if (strcmp(val1, "2")) {  
				p->books[0] = 4;
			}
			if (strcmp(val1, "3")) {
				p->books[1] = 4;
			}
			if (strcmp(val1, "4")) {
				p->books[2] = 4;
			}
			if (strcmp(val1, "5")) {
				p->books[3] = 4;
			}
			if (strcmp(val1, "6")) {
				p->books[4] = 4;
			}
			if (strcmp(val1, "7")) {
				p->books[5] = 4;
			}
			if (strcmp(val1, "8")) {
				p->books[6] = 4;
			}
			if (strcmp(val1, "9")) {
				p->books[7] = 4;
			}
			if (strcmp(val1, "10")) {
				p->books[8] = 4;
			}

			if (strcmp(val1, "J")) {
				p->books[9] = 4;
			}

			if (strcmp(val1, "Q")) {
				p->books[10] = 4;
			}

			if (strcmp(val1, "K")) {
				p->books[11] = 4;
			}

			if (strcmp(val1, "A")) {
				p->books[12] = 4;
			}
			//p->books[val1] = 4;
		}
		else {
			count = 0; //if count < 3 therefore no books found , make it zero and check for the next card if it occours 4 times in player hand
		}
	}

	int books = 0;
	for (int i = 0; i < 14; i++) {
		if (p->books[i] == 4) {
			books++; //Count the total number of books
		}
	}



	return books;
}


void play(struct player *p1, struct player *p2 , struct card *D) {
	int turn = 1; //Variable to change the turn between 2 players , if turn is 1 then player 1 will play else player 2
	int match = 0; 
	bool catch1 = true; //catch for player 1 then he will play again (True case)
	bool catch2 = false; //catch for player 2 then he will play again (True case)
	int cardNum = 0; //generate a card number into this variable
	char op; //your option to play or exit
	char *temp = NULL;
	printf("Welcome to Go Fish!\n\n");
	
	while (true) {
		printf("Do you want to play (p) or exit (e): ");
		scanf(" %c", &op);

/*
	If user press e then it will check for the books and then will compare book count for both player then it will
	generate the result who win and who fail
*/
		if (op == 'e') {
			printf("Checking for books.....\n");
			int p1Book = check_for_books(p1);
			int p2Book = check_for_books(p2);

			printf("Player1 have %d books\n", p1Book);
			printf("Player2 have %d books\n", p2Book);

			if (p1Book > p2Book) {
				printf("Player1 wins\n");
			}

			if (p2Book > p1Book) {
				printf("Player2 wins\n");
			}

			if (p2Book == p1Book) {
				printf("Draw\n");
			}

			printf("Goodbye! Thanks for playing Go Fish!\n");
			break;
		}

/*
	If option is to play 
*/
		if (op == 'p') {
			if_catch1: //A label to forcefully go to back start of the if statement 
			if (turn == 1 && catch1) { 
				printf("It is Player 1's turn.\n");
				show_hand(p1); //Show the cards of players
				printf("Player1, choose a card to play: ");
				scanf("%d", &cardNum); //Choose which card player 1 wants to play
				int indexVal = p1->playerHand[cardNum - 1]; //Get the card index of deck from the player hand
				char *arr = NULL;
				arr = getNumber(indexVal, arr); //get the number from the deck
				/*
					The whole code below this is to:
					1) If player2 have that card then it will get that card from the player2 hands
					2) And store it into player1 hands and increment player1's handsize by 1
					3) remove that card from player2 hands and decrement player2's handsize by 1
					4) Make the catch1 variable to true and don't change the turn from 1 to 2 so a player1 can play again
					5) If player2 donot have card then it will do nothing except changing the turn to 2 and catch1 to false
				*/
				printf("Player2, do you have any %s's ?\n", arr); 
				for (int i = 0; i < p2->pHandsize; i++) {
					temp = getNumber(p2->playerHand[i], temp);
					if (strcmp(temp, "N") == 0) {
						continue;
					}
					if (strcmp(temp, arr) == 0) {
						p1->playerHand[p1->pHandsize++] = p2->playerHand[i];
						p2->playerHand[i] = -1;
						match++;
					}
				}

				if (match >= 1) {
					printf("Player2 gave player1 %d cards\n", match);
					catch1 = true;
					turn = 1;
					match = 0;
					goto if_catch1;
				}
				else {
					printf("Player2 says go fish\n");
					catch1 = false;
					catch2 = true;
					turn = 2;
					continue;
				}

			}

			//catch = true;

			if (turn == 2 && catch2) {
				if_catch2:
				printf("It is Player 2's turn.\n");
				show_hand(p2);
				printf("Player2, choose a card to play: ");
				scanf("%d", &cardNum);
				int indexVal = p2->playerHand[cardNum - 1];
				char *arr = NULL;
				arr = getNumber(indexVal, arr);
				printf("Player1, do you have any %s's ?\n", arr);
				for (int i = 0; i < p1->pHandsize; i++) {
					temp = getNumber(p1->playerHand[i], temp);
					if (strcmp(temp, "N") == 0) {
						continue;
					}
					if (strcmp(temp, arr) == 0) {
						p2->playerHand[p2->pHandsize++] = p1->playerHand[i];
						p1->playerHand[i] = -1;
						match++;
					}
				}
				if (match >= 1) {
					printf("Player1 gave player1 %d cards\n", match);
					catch2 = true;
					turn = 2;
					match = 0;
					goto if_catch2;
				}
				else {
					printf("Player1 says go fish\n");
					catch2 = false;
					catch1 = true;
					turn = 1;
					continue;
				}
			}
		}
	}
}

int main() {
	
	struct card Deck[52];
	struct player Player1;
	struct player Player2;
	
	//printf("Deck has been initialized\n");
	initializeDeck(Deck, 52); // Initiaze the deck
	//printDeck(Deck, 52);
	
	srand((unsigned int)time(0));

	//printf("\nPlayer1 has been initialized\n");
	initializePlayer(&Player1, Deck); //Initialize the player 1
	
	//printf("\nPlayer2 has been initialized\n");
	initializePlayer(&Player2, Deck); //Initialize the player 2
	

	//printf("\nUpdated Deck\n");
	//printDeck(Deck, 52);

	//show_hand(&Player1);

	//show_hand(&Player2);

	play(&Player1, &Player2, Deck); //Play the go fish game now

	return 0;


}
