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
// Function Definitions
int Introduction(int Ans){
    char InitalPlay;
printf("\t\t\t\t\t\033[31mFrom the creators of nothing else:\033[0m\n");
printf("\t\t\t\t\tJuan M. Rios & Kyle Emerson\n \t\t\t\t\t Present!\n");
sleep(1);//use to add a delay in Seconds NOT MS
printf("\t\t\t\t\t\033[32;44mCards!\033[0m\n");
sleep(1);//use to add a delay in Seconds NOT MS
printf("\t\t\t\t\t\033[32;44mCards!\033[0m\n");
sleep(1);//use to add a delay in Seconds NOT MS
printf("\t\t\t\t\t\033[32;44mCards!\033[0m\n");
sleep(1);//use to add a delay in Seconds NOT MS
printf("Are you ready?\n");
printf("Press [Y] for Yes or [N] for cowards:_\n");
scanf(" %c", &InitalPlay);
    if(InitalPlay == 'Y' || InitalPlay == 'y'){
        Ans = 1;
    }
    else{
        Ans = 0;
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
* Description: Using the Rand function
we give both the player and computer random
values to
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
****************************************************/
void display_hand(int hand[], int size) {
    for (int i = 0; i < size; i++) {
        display_card(hand[i]);
        printf("\n");
    }
}
/****************************************************
* popCard
* argument: N/A
* return type: N/A
* Description:
****************************************************/
int popCard(int *size, int deck[]) {
    int card = deck[--(*size)];
    return card;
}
/****************************************************
* findScore
* argument: N/A
* return type: N/A
* Description:
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
* argument: N/A
* return type: N/A
* Description:
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
            printf("You win!\n");
        } else if (playerScore < computerScore) {
            printf("Computer wins!\n");
        } else {
            printf("It's a tie!\n");
        }
        printf("\n\n\n");
}
/*
    // Red text
    printf("\033[31mThis text is red!\033[0m\n");

    // Green text with blue background
    printf("\033[32;44mGreen text on blue background\033[0m\n");

    // Reset to default colors
    printf("\033[0mThis is default text color.\n");

        sleep(1);//use to add a delay in Seconds NOT MS
    system("cls");// Use to clear the screen
    */










