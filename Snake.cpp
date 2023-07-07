#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x,y,frux,fruy; // frux and fruy fruit coordinates
int score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int tailx[100],taily[100];
int nTail;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width/2, y = height/2;
    frux = rand() % width;
    fruy = rand() % height;
    score = 0;
    nTail = 0;
}

void Draw()
{
    system("cls"); // clear the screen of console

    for(int i=0; i<width; i++)
        cout<<"#";
    cout<<"\n";

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(j==0 || j== width-1)
            cout<<"#";
            else if(j==x && i==y)
            cout<<"O";
            else if(j==frux && i==fruy) 
            cout<<"+";
            else
            {
                bool print = false;
                for(int k=0;k<nTail;k++)
                {
                    if(i==taily[k] && j==tailx[k])
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                cout<<" ";
            }
        }
        cout<<"\n";
    }

    for(int i=0; i<width; i++)
        cout<<"#";
    cout<<"\n";
    cout<<"SCORE : "<<score<<"\n";
}

void Input()
{
    if(_kbhit()) // returns positive value if user enters key otherwise 0
    {
        switch(_getch()) // returns ascii value
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
    int prevx = tailx[0];
    int prevy = taily[0];
    tailx[0] = x, taily[0] = y;
    int tempx,tempy;
    for(int i=1;i<nTail;i++)
    {
        tempx = tailx[i];
        tailx[i] = prevx;
        prevx = tempx;

        tempy = taily[i];
        taily[i] = prevy;
        prevy = tempy;
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
    if(x==0 || x==width || y==-1 || y==height)
    gameOver = true;

    for(int i=0;i<nTail;i++)
    {
        if(tailx[i] == x && taily[i] == y)
        gameOver = true;
    }

    if(x==frux && y==fruy)
    {
        score++;
        nTail++;
        frux = rand() % width;
        fruy = rand() % height;
    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();

        if(gameOver)
        {
            cout<<"Press e to play again, x to exit\n";
            if(char ch = getchar() == 'e')
            {
                Setup();
            }
        }
        Sleep(5); //slows down console
    }
    return 0;
}