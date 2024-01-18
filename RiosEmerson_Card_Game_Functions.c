/*******************************************************************************
* Name:	Juan M. Rios & Kyle Emerson
* Course:           EGR 224 - Introduction to digital system design
* Project:          Lab One - Card game
* File:             EGR224_LabOne_.h
* Description:      A card game where someone has to compete against the computer.
* Pin Configs:
*   N/A
* Componets:
*   N/A
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RiosEmerson_Card_Game_Header.h"


/***********************************/
const char *PURPLE_Background = "\x1b[45m";
const char *BLUE_Background = "\x1b[44m";
const char *RED_Background = "\x1b[41m";
const char *GREEN_Background = "\x1b[42m";
const char *YELLOW_Background = "\x1b[43m";
const char *ORANGE_Background = "\x1b[43;1m";
const char *PURPLE_TEXT = "\x1b[35;5m";//Accidently found that adding ;5 causing it to blink for some reason
const char *GREEN_TEXT = "\x1b[32;5m";//Added five to cause it to blink like a circus
const char *BLUE_TEXT = "\x1b[34m";
const char *RED_TEXT = "\x1b[31m";
const char *YELLOW_TEXT = "\x1b[33m";
const char *RESETCOLORS= "\x1b[0m";
int Player_Wins = 0;
int Computer_Wins = 0;
int Ties = 0;
/***********************************/


void delayMS(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int color_Pattern(void){
    const char *colors[] = {BLUE_Background, RED_Background, GREEN_Background};
    int num_colors = 3;
    int num_spaces = 2; // Number of spaces to achieve a square
    int color_index = 0;

    for(int line = 0; line < 4; line++) {
        for (int i = 0; i < 50; i++){
            // Set the starting background color for each segment
            printf("%s", colors[(color_index + i) % num_colors]);
            for(int j = 0; j < num_spaces; j++) {
                printf(" "); // Print spaces with the current background color
            }
        }
        color_index = (color_index + 1) % num_colors; // Move to the next starting color for the next line
        printf("%s\n", RESETCOLORS); // Reset the background at the end of each line
    }
    printf("\n\n");
}
// Function Definitions
int Introduction(int Ans){
    char InitalPlay;
    delayMS(500);
        printf("\t\t\t\t");
    printf("%s From the creators of nothing else:%s\n", RED_TEXT, RESETCOLORS);
        printf("\t\t\t\t");

    printf("%sJuan M. Rios & Kyle Emerson\n \t\t\t\tPresent!%s\n", PURPLE_TEXT, RESETCOLORS);
    delayMS(1000);//use to add a delay in Seconds NOT MS
        printf("\t\t\t\t");

    printf("%sCards!%s\n", GREEN_TEXT, RESETCOLORS);
    delayMS(500);//use to add a delay in Seconds NOT MS
        printf("\t\t\t\t");

    printf("%sCards!%s\n", GREEN_TEXT, RESETCOLORS);
    delayMS(500);//use to add a delay in Seconds NOT MS
        printf("\t\t\t\t");

    printf("%sCards!%s\n", GREEN_TEXT, RESETCOLORS);
    delayMS(500);//use to add a delay in Seconds NOT MS
        printf("\t\t\t\t");

    printf("Are you ready?\n", GREEN_TEXT, RESETCOLORS);
            printf("\t\t\t\t");
    printf("Press [Y] for Yes or [N] for cowards:\n");
        printf("\n\n");
    color_Pattern();
    LOOP: scanf(" %c", &InitalPlay);

   switch (InitalPlay){
    default:
        printf("Please Enter 'Y' or 'N'");
        goto LOOP;
        case 'y':
        Ans = 1;
        break;
        case 'Y':
        Ans = 1;
        break;
        case 'n':
        Ans = 0;
        break;
        case 'N':
        Ans = 0;
        break;
   }
    return Ans;
}
/****************************************************
* create_deck
* argument: N/A
* return type:N/A
* Description:
*   Will create an array for deck
*   to randomize the results within
*   the proper amount of cards.
****************************************************/
void create_deck(int deck[]) {
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
}
/****************************************************
* shuffle_deck
* argument: N/A
* return type: N/A
* Description: 
*     Using the Rand function,
*     the deck values are radomized
****************************************************/
void shuffle_deck(int deck[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];//Need temparary value to be able to save both players
        deck[i] = deck[j];
        deck[j] = temp;
    }
}
/****************************************************
* display_card
* argument: N/A
* return type: N/A
* Description: 
*     Assigns print value
****************************************************/
void display_card(int card) {
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    printf("%s of %s", ranks[card % 13], suits[card / 13]);
}
/****************************************************
* display_hand
* argument: N/A
* return type: N/A
* Description: 
*     Prints values to each card
****************************************************/
void display_hand(int hand[], int size) {
    for (int i = 0; i < size; i++) {
        display_card(hand[i]);
        printf("\n");
        delayMS(500);
    }
}
/****************************************************
* popCard
* argument: int size, int deck
* return type: N/A
* Description: 
*     Function removes the top card from deck and decreases total cards in deck
****************************************************/
int popCard(int *size, int deck[]) {
    int card = deck[--(*size)];
    return card;
}
/****************************************************
* findScore
* argument: int hand[], int size
* return type: int score
* Description: 
*     Function adds up score for either player of computer
****************************************************/
int findScore(int hand[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        int rank = hand[i] % 13;
        if (rank >= 9) {  // Jack, Queen, King
            score += 10;
        } else if (rank == 12) {  // Ace
            score += 11;  // or 1, depending on your rules
        } else {
            score += rank + 2;
        }
    }
    return score;
}
/****************************************************
* LuckOfTheDraw
* argument: int deck[], int size
* return type: N/A
* Description: 
*     Function puts together shuffling, 
*     dealing, scoring, and 
*     printing of cards to serial monitor
****************************************************/
void LuckOfTheDraw(int deck[], int size){
int playerHand[5], computerHand[5];
int playerScore, computerScore;

        // Create and shuffle the deck
        create_deck(deck);
        shuffle_deck(deck, size);

        // Reset hand sizes and scores
        int playerHandSize = 0, computerHandSize = 0;
        playerScore = computerScore = 0;

        // Deal cards and calculate scores
        for (int i = 0; i < 5; i++) {
            playerHand[playerHandSize++] = popCard(&size, deck);
            computerHand[computerHandSize++] = popCard(&size, deck);
        }
        playerScore = findScore(playerHand, playerHandSize);
        computerScore = findScore(computerHand, computerHandSize);

        // Display hands and scores
        printf("\nYour hand:\n");
        display_hand(playerHand, playerHandSize);
        printf("Your score: %d\n", playerScore);
        printf("\n\n");
        printf("Computer's hand:\n");
        display_hand(computerHand, computerHandSize);
        printf("Computer's score: %d\n", computerScore);

        // Determine winner
        if (playerScore > computerScore) {
                Player_Wins++;
            printf("You win!\n");
        } else if (playerScore < computerScore) {
                Computer_Wins++;
            printf("Computer wins!\n");
        } else {
            Ties++;
            printf("It's a tie!\n");
        }
        printf("%sPlayer = %d, Computer = %d, Ties = %d%s\n", RED_TEXT, Player_Wins, Computer_Wins, Ties, RESETCOLORS);
        printf("\n\n\n");
}
