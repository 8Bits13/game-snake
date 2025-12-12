#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define WIDTH 100
#define HEIGHT 25
#define MAX_LEN 1000

typedef struct {
    int x, y;
} Segindo;

typedef struct {
    Segindo seg[MAX_LEN];
    int size;
} Cobra;

typedef struct {
    int x, y;
} Comida;

Cobra cobra;
Comida comida;
int dx = 1, dy = 0;
int score = 0;
int gameover = 0;
int speed = 80;
HANDLE hConsole;

void pontoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(hConsole, coord);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursor);
}

void SetColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void draw_border() {
    SetColor(9);
    for (int x = 0; x <= WIDTH + 1; x++) {
        pontoxy(x, 0);  printf("-");
        pontoxy(x, HEIGHT + 1);  printf("-");
    }
    for (int y = 0; y <= HEIGHT + 1; y++) {
        pontoxy(0, y);  printf("|");
        pontoxy(WIDTH + 1, y);  printf("|");
    }
    SetColor(7);
}

void place_food() {
    int valid = 0;
    while (!valid) {
        valid = 1;
        comida.x = (rand() % WIDTH) + 1;
        comida.y = (rand() % HEIGHT) + 1;
        for (int i = 0; i < cobra.size; i++) {
            if (cobra.seg[i].x == comida.x && cobra.seg[i].y == comida.y) {
                valid = 0;
                break;
            }
        }
    }
    pontoxy(comida.x, comida.y);
    SetColor(12);
    printf("X");
    SetColor(7);
}

void iniciar_game() {
    cobra.size = 4;
    int startX = WIDTH / 2;
    int startY = HEIGHT / 2;


    for (int i = 0; i < cobra.size; i++) {
        cobra.seg[i].x = startX - i;
        cobra.seg[i].y = startY;
        pontoxy(cobra.seg[i].x, cobra.seg[i].y);
        SetColor(2);
        printf("O");
    }
    dx = 1; dy = 0;
    score = 0;
    gameover = 0;
    speed = 80;
    place_food();
}

void atualizacao() {
    int newX = cobra.seg[0].x + dx;
    int newY = cobra.seg[0].y + dy;


    if (newX <= 0 || newX >= WIDTH + 1 || newY <= 0 || newY >= HEIGHT + 1) {
        gameover = 1;
        return;
    }


    for (int i = 0; i < cobra.size; i++) {
        if (cobra.seg[i].x == newX && cobra.seg[i].y == newY) {
            gameover = 1;
            return;
        }
    }

    int ate = (newX == comida.x && newY == comida.y);

    if (ate) {

        if (cobra.size < MAX_LEN - 1) {
            for (int i = cobra.size; i > 0; i--) {
                cobra.seg[i] = cobra.seg[i - 1];
            }
            cobra.seg[0].x = newX;
            cobra.seg[0].y = newY;
            cobra.size++;
        }
        score++;
        if (speed > 30) speed -= 7;
        place_food();
    } else {

        pontoxy(cobra.seg[cobra.size - 1].x, cobra.seg[cobra.size - 1].y);
        printf(" ");


        for (int i = cobra.size - 1; i > 0; i--) {
            cobra.seg[i] = cobra.seg[i - 1];
        }
        cobra.seg[0].x = newX;
        cobra.seg[0].y = newY;
    }


    pontoxy(newX, newY);
    SetColor(10);
    printf("O");
    SetColor(7);
}

int main() {
    srand(time(NULL));
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    hideCursor();
    system("cls");

    draw_border();
    iniciar_game();

    while (!gameover) {
        if (_kbhit()) {
            char jc = _getch();
            if (jc == 'w' && dy != 1) { dx = 0; dy = -1; }
            else if (jc == 's' && dy != -1) { dx = 0; dy = 1; }
            else if (jc == 'a' && dx != 1) { dx = -1; dy = 0; }
            else if (jc == 'd' && dx != -1) { dx = 1; dy = 0; }
            else if (jc == 'q') { break; }
        }

        atualizacao();

        pontoxy(0, HEIGHT + 3);
        SetColor(7);
        printf("Score %d | Velocidade %dms | Controles W A S D | Q = sair ", score, speed);

        Sleep(speed);
    }

    pontoxy(WIDTH / 2 - 8, HEIGHT / 2);
    SetColor(12);
    printf("Game Over! Score Final: %d\n", score);
    SetColor(7);
    return 0;
}
