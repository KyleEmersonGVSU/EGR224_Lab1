/*******************************************************************************
* Name:	Juan M. Rios & Kyle Emerson
* Course:           EGR 224 - Introduction to digital system design
* Project:          Lab One - Card game
* File:             EGR224_LabOne_CardGame
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
#include "RiosEmerson_Card_Game_Header.h"
int main() {
    char playAgain;//Char to ask if they want to play again
    int deckSizeM = 52;//
    int deckM[52];//deck with 52 for the amount of cards cant add decksizeM because of the functions he wants on the paperwork
    srand(time(NULL));// Random number generator
    int AnsM=0;
    color_Pattern();
    AnsM=Introduction(AnsM);
    //printf("%d",AnsM);
    if (AnsM == 1 ){
    do {
        LuckOfTheDraw(deckM,deckSizeM);
        //Askig if they want to play again?
        LOOP:printf("Play again? (Y/N): ");
        scanf(" %c", &playAgain);
        switch(playAgain){

        case 'y':
        break;
        case 'Y':
        break;
        case 'n':
        break;
        case 'N':
        break;
        default:
        printf("Invalid Input, please enter 'Y/N'\n");
        goto LOOP;
        }
    } while (playAgain == 'Y' || playAgain == 'y');//He wants both upper and lower case
    //End of the game
    }
    else {

    }
    printf("\nThanks for playing!\n");
    return 0;
}

