#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice, player;
char mark;
int sPlayer1=0;
int sPlayer2=0;

int Winner();
void displayBoard();
int startover();
int name();

FILE* fPtr;
FILE* fptr;

int main()
{
    int Status;
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

        mark = (player == 1) ? 'X' : 'O';

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
            printf("Invalid move ");

            player--;
        }
        Status = Winner();

        player++;
    } while (Status == -1);

    displayBoard();
    if (Status == 1) {
        printf("==>Player %d win \n\n", --player);
        
        if (player % 2 == 0)
        {
            sPlayer2++;
            
            
            fPtr = fopen("file1.txt", "w");
            if (fPtr == NULL)
            {
                /* File not created hence exit */
                printf("Unable to create file.\n");
                exit(EXIT_FAILURE);
            }
            fprintf(fPtr, "%d", sPlayer2);
            fclose(fPtr);

            fclose(fPtr);
            startover();
        }
        else
        {
            sPlayer1++;
            char data[100];
            
            fptr = fopen("file2.txt", "w");
            if (fptr == NULL)
            {
                /* File not created hence exit */
                printf("Unable to create file.\n");
                exit(EXIT_FAILURE);
            }
            fprintf(fptr, "%d", sPlayer1);
            fclose(fptr);
            startover();
        }
    }
    else {
        printf("==>Game draw\n\n");
        startover();
    }
}

int startover()
{
    int yesorno = 0;

    printf("\nDo you want to play again? Yes ==> 1  : No ==> 2  ");
    scanf_s("%d", &yesorno);
    if (yesorno == 1)
    {

        square[0] = 'o';
        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';
        main();

    }
    else if (yesorno == 2)
    {
        printf("Ok Bye");
        return 0;
    }
    else
    {
        printf("Wrong number, please try again");
        startover();
    }
}

void displayBoard()
{
    system("cls"); // To clear the screen

    fptr = fopen("file2.txt", "r");
    int num1;
    fscanf(fptr, "%d", &num1);
    printf("\n\tThe Highest Score for player1 : %d", num1);
    fPtr = fopen("file1.txt", "r");
    int num2;
    fscanf(fPtr, "%d", &num2);
    printf("\nThe Highest Score for player2 : %d", num2);

    printf("\nScore :");
    printf("\t Player 1: %d", sPlayer1);
    printf("\t\t Player 2: %d", sPlayer2);

    printf("\n\n\n\t\tTic Tac Toe\n\n");

    printf("\n       Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("\n\t          |     |     \n");
    printf("\n\t       %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("\n\t     _____|_____|_____\n");
    printf("\n\t          |     |     \n");

    printf("\n\t       %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("\n\t     _____|_____|_____\n");
    printf("\n\t          |     |     \n");
   
    printf("\n\t       %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("\n\t          |     |     \n\n");
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






