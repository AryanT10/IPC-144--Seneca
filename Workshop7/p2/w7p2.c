/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : ARYAN TUWAR
Student ID#: 112137229
Email      : atuwar@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAXIMUM_LENGTH 70
#define MINIMUM_LENGTH 10
#define MAXIMUM_LIVES 10
#define MINIMUM_LIVES 1
#define MULTIPLE 5

#include <stdio.h>

//Structure declaration for Player
struct playerInfo {
    int lives;
    char character;
    int treasureCount;
    int positionHistory[MAXIMUM_LENGTH];
};

//Structure declaration for Game
struct gameInfo {
    int moves;
    int pathLength;
    int bombLocations[MAXIMUM_LENGTH];
    int treasureLocations[MAXIMUM_LENGTH];
};

int main(void)
{
    int i, j, k;
    int flag = 0;
    int remainingMove, remainingLives, movePosition = MAXIMUM_LENGTH + 1;

    // Allocating memories
    struct playerInfo player;
    struct gameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    // Configuring Player
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.character);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
    }
    while (player.lives < MINIMUM_LIVES || player.lives > MAXIMUM_LIVES);
    
    printf("Player configuration set-up is complete\n");

    // Configuring Game
    printf("\nGAME Configuration\n");
    printf("------------------\n");
    
    // Path Length
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);

        if ((game.pathLength < MINIMUM_LENGTH || game.pathLength > MAXIMUM_LENGTH) || (game.pathLength % MULTIPLE != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    }
    while ((game.pathLength < MINIMUM_LENGTH || game.pathLength > MAXIMUM_LENGTH) || (game.pathLength % MULTIPLE != 0));

    // Number of moves
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);

        if (game.moves < player.lives || game.moves > (int) (0.75 * game.pathLength))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int) (0.75 * game.pathLength));
        }
    }
    while (game.moves < player.lives || game.moves > (int) (0.75 * game.pathLength));
    printf("\n");

    // Bomb Placement in Arrays
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    //bomb placement
    for (i = 0; i < game.pathLength; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombLocations[i], &game.bombLocations[i + 1], &game.bombLocations[i + 2], &game.bombLocations[i + 3], &game.bombLocations[i + 4]);
    }
    
    printf("BOMB placement set\n");
    printf("\n");

    // Treasure hunt configuration settings
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    //tresaure placement
    for (i = 0; i < game.pathLength; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasureLocations[i], &game.treasureLocations[i + 1], &game.treasureLocations[i + 2], &game.treasureLocations[i + 3], &game.treasureLocations[i + 4]);
    }

    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");

    // Displaying the treasure hunt configuration settings
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    //Player Details
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.character);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    // Game
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);

    // Bombs
    printf("   Bombs      : ");
    // Displaying bombs array
    for (j = 0; j < game.pathLength; j++)
    {
        printf("%d", game.bombLocations[j]);
    }
    printf("\n");

    // Treasures
    printf("   Treasure   : ");
    // Displaying treasures
    for (k = 0; k < game.pathLength; k++)
    {
        printf("%d", game.treasureLocations[k]);
    }
    printf("\n\n");

    // Starting line to play
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    //Values
    remainingMove = game.moves;
    remainingLives = player.lives;
    player.treasureCount = 0;
    char currentPosition[MAXIMUM_LENGTH];
    char positionItem[MAXIMUM_LENGTH];

    for (j = 0; j < game.pathLength; j++)
    {
        player.positionHistory[j] = 0;
    }

    for (k = 0; k < game.pathLength; k++)
    {
        positionItem[k] = '-';
    }

    for (k = 0; k < game.pathLength; k++)
    {
        currentPosition[k] = ' ';
    }

    // Table
    do {
        // Line first
        
        if (flag==1)
        {
        {
            printf("  ");
        }

        for (k = 0; currentPosition[k]!=player.character; k++)
        {
            printf("%c", currentPosition[k]);

        }
        printf("%c", currentPosition[k]);
        printf("\n");
       }
       flag = 1;
        // removing previous pointer to dissapear
        for (k = 0; k < game.pathLength; k++)
        {
            currentPosition[k] = ' ';
        }

        // Line second
        printf("  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%c", positionItem[k]);
        }
        printf("\n");

        // Line third
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if ( i % 10 == 0)
            {
                printf("%d", (int) i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        // Line fourth
        printf("  ");
        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");
        // Player Statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", remainingLives, player.treasureCount, remainingMove);
        printf("+---------------------------------------------------+\n");
        // The next move
        do {
            printf("Next Move [1-20]: ");
            scanf("%d", &movePosition);

            if (movePosition < 1 || movePosition > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }
            
        } while(movePosition < 1 || movePosition > game.pathLength);
        printf("\n");

        if (player.positionHistory[movePosition - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n\n");
            currentPosition[movePosition - 1] = 'V';
            remainingMove++; // so that the time when it decrements, there is no effect
        }
        
        else if (game.bombLocations[movePosition - 1] == 1 && game.treasureLocations[movePosition - 1] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            positionItem[movePosition - 1] = '&';
            currentPosition[movePosition - 1] = 'V';
            remainingLives--;
            player.treasureCount++;
        }

        else if (game.bombLocations[movePosition - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            positionItem[movePosition - 1] = '!';
            currentPosition[movePosition - 1] = 'V';
            remainingLives--;
        }

        else if (game.treasureLocations[movePosition - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            positionItem[movePosition - 1] = '$';
            currentPosition[movePosition - 1] = 'V';
            player.treasureCount++;
        }

         else
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            positionItem[movePosition - 1] = '.';
            currentPosition[movePosition - 1] = 'V';
        }

        // Storing the position in an array
        player.positionHistory[movePosition - 1] = 1;

        // Decrementing the number of moves
        remainingMove--;

        if (remainingLives == 0)
        {
            printf("No more LIVES remaining!\n\n");
        }
        if (remainingMove == 0)
        {
            printf("No more MOVES remaining!\n\n");
        }

    } while (remainingMove > 0 && remainingLives > 0);

    // Printing the final table          
        if (flag==1)
        {
        {
            printf("  ");
        }

        for (k = 0; currentPosition[k]!=player.character; k++)
        {
            printf("%c", currentPosition[k]);

        }
        printf("%c", currentPosition[k]);
        printf("\n");
       }
       flag = 1;
        // removing previous pointer to dissapear
        for (k = 0; k < game.pathLength; k++)
        {
            currentPosition[k] = ' ';
        }

        // Line second
        printf("  ");
        for (k = 0; k < game.pathLength; k++)
        {
            printf("%c", positionItem[k]);
        }
        printf("\n");

        // Line third
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if ( i % 10 == 0)
            {
                printf("%d", (int) i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        // Line fourth
        printf("  ");
        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");
        // Player Statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", remainingLives, player.treasureCount, remainingMove);
        printf("+---------------------------------------------------+\n\n");
    // Ending Lines
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");

    printf("You should play again and try to beat your score!\n");
    printf("\n");

    return 0;
}
