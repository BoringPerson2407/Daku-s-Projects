// Date: 29/01/2025
// Project: Tic-Tac-Toe
// Program function: A simple console based Tic-Tac-Toe game in C++
// Status: Finished

#include<iostream>

using namespace std;

void draw_board(char (*grid)[3]);   // this function accept grid as an input and draws a board.
void player_move(char (*grid)[3], char player); // this function inputs the player's move and draw them on board.
void computer_move(char (*grid)[3], char computer); // this function generates moves for computer and draw them on board.
bool check_winner(char (*grid)[3], char  player, char computer); // check if winning conditions satisfied and who wins
bool check_tie(char (*grid)[3]); // check if the game is tied
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
        if (check_winner(grid, player, computer))
        {
            running = false;
            break;
        }
        else if (check_tie(grid))
        {
            running = false;
            break;
        }
        

        computer_move(grid, computer);
        draw_board(grid);
        if (check_winner(grid, player, computer))
        {
            running = false;
            break;
        }    
    }
    cout << "Game over!" << endl;
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
    if (grid[0][0]!='-' && grid[0][0]==grid[0][1] && grid[0][1]==grid[0][2])
    {
        grid[0][0] == player ? cout << "You win!\n" : cout << "You lose!\n"; 
    }
    else if (grid[1][0]!='-' && grid[1][0]==grid[1][1] && grid[1][1]==grid[1][2])
    {
        grid[1][0] == player ? cout << "You win!\n" : cout << "You lose!\n";
    }
    else if (grid[2][0]!='-' && grid[2][0]==grid[2][1] && grid[2][1]==grid[2][2])
    {
        grid[2][0] == player ? cout << "You win!\n" : cout << "You lose!\n";
    }
    else if (grid[0][0]!='-' && grid[0][0]==grid[1][0] && grid[1][0]==grid[2][0])
    {
        grid[0][0] == player ? cout << "You win!\n" : cout << "You lose!\n";
    }
    else if (grid[0][1]!='-' && grid[0][1]==grid[1][1] && grid[1][1]==grid[2][1])
    {
        grid[0][1] == player ? cout << "You win!\n" : cout << "You lose!\n";
    }
    else if (grid[0][2]!='-' && grid[0][2]==grid[1][2] && grid[1][2]==grid[2][2])
    {
        grid[0][2] == player ? cout << "You win!\n" : cout << "You lose!\n";
    }
    else if (grid[0][0]!='-' && grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
    {
        grid[0][0] == player ? cout << "You win!\n" : cout << "You lose!\n";
    }
    else if (grid[0][2]!='-' && grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
    {
        grid[0][2] == player ? cout << "You win!\n" : cout << "You lose!\n";
    }
    else
    {
        return false;
    }
    return true;
}
bool check_tie(char (*grid)[3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if (grid[i][j]=='-')
            {
                return false;
            }
            
        }
    }
    cout << "It's a tie!\n";
    return true;
}