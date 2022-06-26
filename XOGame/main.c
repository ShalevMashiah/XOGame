#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice, player;

int Winner();
void displayBoard();
void markBoard(char mark);

int main()
{
    int Status;
    char mark;
    player = 1;

    do{
    
        displayBoard();
        // החלפת שחקנים
        if (player % 2 == 0)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }

        printf("Player %d,enter a number: ", player);
        scanf_s("%d", &choice);

        if (player == 1)
        {
            mark = 'X';
            markBoard(mark);
            Status = Winner();
            player++;
        }
        else
        {
                mark = 'O';
                markBoard(mark);
                Status = Winner();
                player++;
        }

    } while (Status == -1);

    if(Status == 1)
        printf("==>Player %d win \n\n", --player);
    else {
        printf("==>Game draw\n\n");
    }
    return 0;  
}

void displayBoard()
{
    system("cls"); //clear 

    printf("\n\n\t\tTic Tac Toe\n\n");

    printf("       Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("\t          |     |     \n");
    printf("\t       %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("\t     _____|_____|_____\n");
    printf("\t          |     |     \n");

    printf("\t       %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("\t     _____|_____|_____\n");
    printf("\t          |     |     \n");
   
    printf("\t       %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("\t          |     |     \n\n");
}

int Winner()
{
    int result = 0;

    if (square[1] == square[2] && square[2] == square[3])
    {
        result = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        result = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        result = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        result = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        result = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        result = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        result = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        result = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        result = 0;
    else
        result = -1;

    return result;
}


void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("Invalid step Please try again");

        player--;
    }



}





