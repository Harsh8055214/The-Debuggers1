#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int highScore = 0;

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(console, &info);
}

void drawBorders() {
    for (int i = 0; i < 42; i++) {
        gotoxy(i, 0); cout << "#";
        gotoxy(i, 24); cout << "#";
    }
    for (int i = 0; i < 25; i++) {
        gotoxy(0, i); cout << "#";
        gotoxy(41, i); cout << "#";
    }
}
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawBoard(int paddleX, int paddleSize, int ballX, int ballY, int score, int lives, bool powerUpActive, int powerUpX, int powerUpY) {
    hideCursor();
     setColor(8);
    system("cls");

    drawBorders();

    gotoxy(paddleX, 20);
    for (int i = 0; i < paddleSize; i++) cout << "=";

    gotoxy(ballX, ballY);
    cout << "O";

    if (powerUpActive) {
        gotoxy(powerUpX, powerUpY);
        cout << "+";
    }

    setColor(13);
    gotoxy(45, 5);
    cout << "Score: " << score;
    gotoxy(45, 6);
    cout << "High:  " << highScore;
    gotoxy(45, 8);
    cout << "Lives: " << lives;
}

void loadHighScore() {
    ifstream file("highscore.txt");
    if (file.is_open()) file >> highScore;
    file.close();
}

void saveHighScore(int score) {
    if (score > highScore) {
        ofstream file("highscore.txt");
        file << score;
        file.close();
    }
}

void showStartScreen() {
    system("cls");
    
    setColor(12);
    cout << "Simple Console Pong Game\n";
    cout << "------------------------\n";
    cout << "Instructions:\n";
    cout << "-> Use LEFT and RIGHT arrows to move the paddle\n";
    cout << "-> Press 'P' to pause\n";
    cout << "-> Press ESC to exit\n\n";
    cout << "Press any key to start...";
    _getch();
}

int main() {
    system("mode con: cols=70 lines=30");
    srand(time(0));
    loadHighScore();
    showStartScreen();

    int paddleX = 20, paddleSize = 6;
    int ballX = 32, ballY = 19;
    int ballDirX = 1, ballDirY = -1;
    int score = 0;
    int lives = 3;
    int speed = 100;

    bool powerUpActive = false;
    int powerUpX = 0, powerUpY = 0;

    while (lives > 0) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 75 && paddleX > 1) paddleX--;
            if (key == 77 && paddleX + paddleSize < 40) paddleX++;
            if (key == 27) break;
            if (key == 'p' || key == 'P') {
                gotoxy(20, 12);
                cout << "Paused. Press any key...";
                _getch();
            }
        }

        ballX += ballDirX;
        ballY += ballDirY;

        if (ballY == 20 && ballX >= paddleX && ballX < paddleX + paddleSize) {
            ballDirY = -ballDirY;
            score++;
            if (score % 5 == 0 && speed > 30) speed -= 5;
            if (score % 10 == 0 && paddleSize > 3) paddleSize--; 
        }

        if (ballX == 1 || ballX == 40) ballDirX = -ballDirX;
        if (ballY == 1) ballDirY = -ballDirY;

        if (ballY == 23) {
            lives--;
            ballX = 20; ballY = 19;
            ballDirY = -1;
        }

        
        if (!powerUpActive && rand() % 100 == 0) {
            powerUpActive = true;
            powerUpX = 2 + rand() % 37;
            powerUpY = 1;
        }

        if (powerUpActive) {
            powerUpY++;
            if (powerUpY == 20 && powerUpX >= paddleX && powerUpX < paddleX + paddleSize) {
                lives++;
                powerUpActive = false;
            } else if (powerUpY >= 23) {
                powerUpActive = false;
            }
        }

        drawBoard(paddleX, paddleSize, ballX, ballY, score, lives, powerUpActive, powerUpX, powerUpY);
        Sleep(speed);
    }

    system("cls");
    gotoxy(20, 10); cout << "Game Over!";
    gotoxy(20, 12); cout << "Final Score: " << score;

    saveHighScore(score);

    gotoxy(20, 14);
    cout << "Press R to restart or ESC to quit...";
    while (true) {
        char ch = _getch();
        if (ch == 27) break;
        if (ch == 'r' || ch == 'R') {
            main(); 
            break;
        }
    }

    return 0;
}
