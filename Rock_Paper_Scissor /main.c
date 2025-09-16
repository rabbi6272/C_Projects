#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Choice(char c[], int choice)
{
    switch (choice)
    {
    case 1:
        strcpy(c, "Rock");
        break;
    case 2:
        strcpy(c, "Paper");
        break;
    case 3:
        strcpy(c, "Scissor");
        break;
    }
}

int main()
{
    int t = 1;
    while (t)
    {
        int u_choice, c_choice;
        char u[10], c[10];
        printf("\n1. Rock\n2. Paper\n3. Scissor\nPlease enter your choice: ");
        scanf("%d", &u_choice);
        c_choice = (rand() % (3 - 1 + 1)) + 1;
        Choice(u, u_choice);
        Choice(c, c_choice);
        printf("You chose %s & computer chose %s.\n", u, c);
        switch (u_choice)
        {
        case 1:
            switch (c_choice)
            {
            case 1:
                printf("It's a tie.");
                break;
            case 2:
                printf("Computer wins.");
                break;
            case 3:
                printf("You win.");
                break;
            }
            break;
        case 2:
            switch (c_choice)
            {
            case 1:
                printf("You win.");
                break;
            case 2:
                printf("It's a tie.");
                break;
            case 3:
                printf("Computer wins.");
                break;
            }
            break;
        case 3:
            switch (c_choice)
            {
            case 1:
                printf("Computer wins.");
                break;
            case 2:
                printf("You win.");
                break;
            case 3:
                printf("It's a tie.");
                break;
            }
            break;
        }

        printf("\nDo you want to play again(y/n): ");
        char play;
        scanf(" %c", &play);
        if (play == 'n')
        {
            t = 0;
            break;
        }
    }

    return 0;
}