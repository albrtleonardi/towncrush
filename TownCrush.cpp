#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void art()
{
    printf("  _______                   _____                _     \n");
    printf(" |__   __|                 / ____|              | |    \n");
    printf("    | | _____      ___ __ | |     _ __ _   _ ___| |__  \n");
    printf("    | |/ _ \\ \\ /\\ / / '_ \\| |    | '__| | | / __| '_ \\ \n");
    printf("    | | (_) \\ V  V /| | | | |____| |  | |_| \\__ \\ | | |\n");
    printf("    |_|\\___/ \\_/\\_/ |_| |_|\\_____|_|   \\__,_|___/_| |_|\n");
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void flushInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void pauseScreen()
{
#ifdef _WIN32
    system("pause");
#else
    printf("Press Enter to continue...");
    flushInputBuffer();
    getchar();
#endif
}

void splashscreen()
{
    art();
    printf("\nWelcome to battleKtown.");
    fflush(stdout);
    sleep(1);
    clearScreen();
    art();
    printf("\nWelcome to battleKtown..");
    fflush(stdout);
    sleep(1);
    clearScreen();
    art();
    printf("\nWelcome to battleKtown...");
    fflush(stdout);
    sleep(1);
    clearScreen();
}

void playGame()
{
    // Game logic will go here
}

void gameRule()
{
    clearScreen();
    printf("1. You have to destroy your opponent's town before he destroys yours\n");
    printf("2. The battle field is of 10x10 grid size in which you place your towns\n");
    printf("3. You can place your towns by entering its orientation, i.e horizontal or vertical\n");
    printf("   For horizontal orientation, type 'h' in the orientation option and type 'v' for vertical\n");
    printf("   and its x y coordinates (both separated by a space) where x is the row number and y is the column number\n");
    printf("4. You have a fleet of 4 towns:\n");
    printf("   -- Addersfield (5 units long)\n");
    printf("   -- Beachcastle (4 units long)\n");
    printf("   -- Davenport (3 units long)\n");
    printf("   -- Cherrytown (2 units long)\n");
    printf("5. After placing your towns, you can attack the enemy area\n");
    printf("   To attack a area, enter its x y coordinate (separated by a space)\n");
    printf("6. Attack hit to the enemy town is denoted by a 'H' and you get an extra turn\n");
    printf("7. Attack miss is denoted by a '*' and your turn ends\n");
    printf("\n");
    pauseScreen();
    clearScreen();
}

void exitGame()
{
    printf("Exiting the game. Goodbye!\n");
}

void menu()
{
    int choose;
    do
    {
        clearScreen();
        printf("[1] Play Game\n");
        printf("[2] Game Rules\n");
        printf("[3] Exit\n");
        printf("Choose: ");

        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            playGame();
            break;
        case 2:
            gameRule();
            break;
        case 3:
            exitGame();
            break;
        default:
            printf("[*] Wrong input, please input again!\n");
            flushInputBuffer();
            break;
        }
    } while (choose != 3);
}

int main()
{
    splashscreen();
    menu();
    return 0;
}
