// Date: 29/01/2025
// Project: Tic-Tac-Toe
// Program function: A simple console based Tic-Tac-Toe game in C++
// Status: Work in progress

#include<iostream>

using namespace std;

void draw_board(char (*grid)[3]);   // this function accept grid as an input and draws a board.
void player_move(char (*grid)[3], char player); // this function inputs the player's move and draw them on board.
void computer_move(char (*grid)[3], char computer); // this function generates moves for computer and draw them on board.
bool check_winner(char (*grid)[3], char  player, char computer);
int main()
{
    char grid[3][3] = 
    {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    char player = 'O';
    char computer = 'X';
    bool running = true;

    draw_board(grid);
    while (running)
    {
        player_move(grid, player);
        draw_board(grid);
        cout << endl;
        if (check_winner)
        {
            running = false;
            break;
        }

        computer_move(grid, computer);
        draw_board(grid);
        if (check_winner)
        {
            running = false;
            break;
        }
        
        running= false;   
    }
    

    return 0;
}
void draw_board(char (*grid)[3])    
{
    for (int i = 0; i < 3; i++)
    {   
        cout << " | " << grid[i][0] << " | " << grid[i][1] << " | " << grid[i][2] << " | " << endl;
        cout << "_|___|___|___|_" << endl;
    }
    cout << " |   |   |   |" << endl;  
}
void player_move(char (*grid)[3], char player)
{
    int r,c;
    do
    {
        cout << "Enter row(1-3): ";
        cin >> r;
        cout << endl << "Enter column(1-3): ";
        cin >> c; 
        if (grid[r-1][c-1]=='-')
        {
            grid[r-1][c-1] = player;
            break;
        }
        
    } while ( !(r > 0 || r <= 3) && !(c > 0 || c <= 3));
    
}
void computer_move(char (*grid)[3], char computer)
{
    int r,c;
    srand(time(0));
    while (true)
    {
        r=rand()%3+1;
        c=rand()%3+1;
        if (grid[r][c]=='-')
        {
            grid[r][c] = computer;
            break;
        }
    }  
}
bool check_winner(char (*grid)[3], char  player, char computer)
{

}