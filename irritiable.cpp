#include <stdio.h>
#include <TextControl.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

void RandomlyGenerateMaze(int Walls[][16]) {

    int temp = 0;

    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            temp = rand() % 7;
            if (Walls[x][y] == 0 && temp > 5) {
                Walls[x][y] = 1;
            }
        }
    }

    return;
}

void DisplayMaze(int Walls[][16]) {

    SetColor(DARK_WHITE, BLACK);

    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            if (Walls[x][y] == 1) {
                PlaceCursor(x + 25, y + 10);
                printf("#");
            }
        }
    }

    return;
}

void ResetMaze(int Walls[][16]) {

    for (int x = 1; x < 14; x++) {
        for (int y = 1; y < 14; y++) {
            PlaceCursor(x + 25, y + 10);
            printf(" ");
            Walls[x][y] = 0;
        }
    }

    return;
}

bool MovePlayer(const int Direction, const int Walls[][16], int &PlayerX, int &PlayerY) {

    switch (Direction) {
        case UP: {
            if (Walls[PlayerX - 25][(PlayerY + 1) - 12] != 1) {
                PlaceCursor(PlayerX, PlayerY);
                printf(" ");

                PlayerY -= 1;
                PlaceCursor(PlayerX, PlayerY);
                printf("X");
            }
        } break;

        case DOWN: {
            if (Walls[PlayerX - 25][(PlayerY + 1) - 10] != 1) {
                PlaceCursor(PlayerX, PlayerY);
                printf(" ");

                PlayerY += 1;
                PlaceCursor(PlayerX, PlayerY);
                printf("X");
            }
        } break;

        case LEFT: {
            if (Walls[(PlayerX - 1) - 25][PlayerY - 10] != 1) {
                PlaceCursor(PlayerX, PlayerY);
                printf(" ");

                PlayerX -= 1;
                PlaceCursor(PlayerX, PlayerY);
                printf("X");
            }
        } break;

        case RIGHT: {
            if (Walls[(PlayerX + 1) - 25][PlayerY - 10] != 1) {
                PlaceCursor(PlayerX, PlayerY);
                printf(" ");

                PlayerX += 1;
                PlaceCursor(PlayerX, PlayerY);
                printf("X");
            }
        } break;

        default: return false;
    }

    return true;
}

int main() {

    HANDLE OutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTitle("Snake - AI Module");
    SMALL_RECT windowSize = {0, 0, 79, 49};
    SetConsoleWindowInfo(OutHandle, TRUE, &windowSize);

    ClearConsole(GREY, BLACK);
    RemoveCursor();

    int Walls[16][16] = {
        { 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1  },
    };

GAME_START:

    srand(time(NULL));

    PlaceCursor(25, 12);
    SetColor(BLACK, GREEN);
    printf(" ");
    SetColor(GREY, BLACK);

    Walls[1][2] = 15;
    Walls[13][11] = 5; // The player

    RandomlyGenerateMaze(Walls);
    DisplayMaze(Walls);

    PlaceCursor(39, 21);
    SetColor(BLACK, RED);
    printf(" ");
    SetColor(GREY, BLACK);

    int PlayerX = 38;
    int PlayerY = 21;

    PlaceCursor(PlayerX, PlayerY);
    SetColor(CYAN, BLACK);
    printf("X");

    while (true) {
        Sleep(50);

        if (GetAsyncKeyState(VK_UP)) { MovePlayer(UP, Walls, PlayerX, PlayerY); } else
        if (GetAsyncKeyState(VK_DOWN)) { MovePlayer(DOWN, Walls, PlayerX, PlayerY); } else
        if (GetAsyncKeyState(VK_LEFT)) { MovePlayer(LEFT, Walls, PlayerX, PlayerY); } else
        if (GetAsyncKeyState(VK_RIGHT)) { MovePlayer(RIGHT, Walls, PlayerX, PlayerY); }

        if (Walls[(PlayerX) - 25][PlayerY - 10] == 3) {
            SetColor(GREEN, BLACK);
            PlaceCursor(PlayerX, PlayerY);
            printf("X");
            SetColor(GREY, BLACK);
            break;
        }
    }

    PlaceCursor(0, 0);
    printf("YOU WIN!\n\n");

    int temp = 0;

    printf("Play again (0/1)? ");
    scanf("%d", &temp);

    if (temp >= 1) {
        PlaceCursor(0, 0);
        printf("        \n\n                    ");

        ResetMaze(Walls);
        goto GAME_START;
    }

    std::cin.get();
    return 0;
}
