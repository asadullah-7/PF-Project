//Asad Ullah_L1F23BSCS 0225 B-11
#include <iostream>
#include <conio.h>   // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

using namespace std;

const int width = 20;
const int height = 20;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
int x, y, foodX, foodY, score;
int tailX[100], tailY[100];
int nTail;
bool gameOver;
void Setup() 
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
}
void Draw() 
{
    system("cls"); 

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == foodY && j == foodX)
                cout << "F"; // Food
            else
            {
                bool print = false;

                for (int k = 0; k < nTail; k++) 
                {
                    if (tailX[k] == j && tailY[k] == i) 
                    {
                        cout << "o"; // Snake body
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}
void Input() 
{
    if (_kbhit()) 
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic() 
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) 
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) 
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == foodX && y == foodY) 
    {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        nTail++;
    }
}
int main()
{
    int x{}, speed{}, spd{};
    cout << "                 WELCOME " << endl;
    cout << "              HUNGRY $NAKE  " << endl;
    cout << "LETS PLAY:  " << endl;
    cout << "Enter for game speed:\n1.slow\n2.medium\n3.fast" << endl;
    cin >> speed;
    if (speed == 1)
    {
        spd = 500;
    }
    else if (speed == 2)
    {
        spd = 100;
    }
    else if (speed == 3)
    {
        spd = 0;
    }


    cout << "         Loading....      ";
    for (int i = 0; i < 10; i++)
    {
        cout << ". ";
        Sleep(500);
    }
    system("clear");
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(spd);

    }
    return 0;
}
