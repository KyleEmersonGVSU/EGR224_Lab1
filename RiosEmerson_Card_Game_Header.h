
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
#include <conio.h>
#ifndef RiosEmerson_Card_Game_Header_H_
#define RiosEmerson_Card_Game_Header_H_


/********REQUIRED FUNCTIONS********/
void create_deck(int deck[]);
void shuffle_deck(int deck[], int size);
void display_card(int card);
void display_hand(int hand[], int size);
int popCard(int *size, int deck[]);
int findScore(int hand[], int size);
/***********************************/
/********EXTRA FUNCTIONS ********/
//Print introduction
//Print names and stuff
int Introduction(int Ans);
//Print small explination
//Starting the game
void LuckOfTheDraw(int deck[], int size);
//Add values for keep track of the wins and loses.
//Ask if the player wants to play



/*
    // Red text
    printf("\033[31mThis text is red!\033[0m\n");

    // Green text with blue background
    printf("\033[32;44mGreen text on blue background\033[0m\n");

    // Reset to default colors
    printf("\033[0mThis is default text color.\n");

    */

#endif //EGR_LabOne_h









