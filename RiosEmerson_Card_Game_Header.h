
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

/**********Constants Colors***************/
extern const char *PURPLE_Background;
extern const char *BLUE_Background;
extern const char *RED_Background;
extern const char *GREEN_Background;
extern const char *YELLOW_Background;
extern const char *ORANGE_Background;
extern const char *RESET_Background;
/***********************************/


/********EXTRA FUNCTIONS ********/
void delayMS(unsigned int mseconds);
//Print introduction
//Print names and stuff
int color_Pattern(void);
int Introduction(int Ans);
//Print small explination
//Starting the game
void LuckOfTheDraw(int deck[], int size);
//Add values for keep track of the wins and loses.
//Ask if the player wants to play
/********EXTRA FUNCTIONS ********/


/* COLOR CODE
PURPLE
    const char *PURPLE_BG = "\x1b[45m";
    const char *RESET = "\x1b[0m";

    printf("%s   ", PURPLE_BG); // Purple space
    printf("%s\n", RESET);      // Reset to default color
RED
    const char *RED_BG = "\x1b[41m";
    const char *RESET = "\x1b[0m";

    printf("%s   ", RED_BG); // Red space
    printf("%s\n", RESET);   // Reset to default color
GREEN
    const char *GREEN_BG = "\x1b[42m";
    const char *RESET = "\x1b[0m";

    printf("%s   ", GREEN_BG); // Green space
    printf("%s\n", RESET);     // Reset to default color
Yellow
    const char *YELLOW_BG = "\x1b[43m";
    const char *RESET = "\x1b[0m";

    printf("%s   ", YELLOW_BG); // Yellow space
    printf("%s\n", RESET);      // Reset to default color
Orange
    const char *ORANGE_BG = "\x1b[43;1m"; // Bright yellow for approximation
    const char *RESET = "\x1b[0m";

    printf("%s   ", ORANGE_BG); // "Orange" space
    printf("%s\n", RESET);      // Reset to default color


    // Red text
    printf("\033[31mThis text is red!\033[0m\n");

    // Green text with blue background
    printf("\033[32;44mGreen text on blue background\033[0m\n");

    // Reset to default colors
    printf("\033[0mThis is default text color.\n");

    */

#endif //EGR_LabOne_h









