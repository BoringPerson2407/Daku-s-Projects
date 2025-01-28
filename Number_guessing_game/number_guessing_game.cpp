// Date: 28/01/2025
// Project: Number guessing game
// Project function: Program will generate a random number and user has to guess it in 5 attempts
// status: finished

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

bool guess(int num, int user_guess, int* attempts);

int main()
{   
    srand(time(0));
    int action_input, difficulty;
    int user_guess, attempts;
    while (action_input != -1)
    {
        cout << "\n**********************************************" << endl;
        cout << "*                                            *" << endl;
        cout << "*              Play the game: 0              *" << endl;
        cout << "*              exit: -1                      *" << endl;
        cout << "*                                            *" << endl;
        cout << "**********************************************" << endl;
        cin >> action_input;
        if (action_input==-1)
        {
            break;
        }
        else if (action_input != 0)
        {
            cout << "Please enter a correct input!" << endl;
            continue;
        }
        
        
        cout << endl;
        cout << "**********************************************" << endl;
        cout << "*                                            *" << endl;
        cout << "*              Difficulty: 1-3               *" << endl;
        cout << "*                                            *" << endl;
        cout << "**********************************************" << endl;
        cin >> difficulty;
        attempts = 5;
        int num = 0;
        switch (difficulty)
        {
        case 1:
            num = rand() % 10 + 1;
            break;
        case 2:
            num = rand() % 50 + 1;
            break;
        case 3:
            num = rand() % 100 + 1;
            break;
        default:
            cout << "Invalid input! please enter a number between 1 and 3" << endl;
            continue;
            break;
        }
        while (attempts > 0)
        {
            cout << "Guess the number!" << endl;
            cin >> user_guess;
            if (guess(num, user_guess, &attempts))
            {   
                cout << "You guessed the right number! " << endl;
                cout << "Play again: 0" << endl;
                cout << "exit: -1" << endl;
                break;
            }
            else
            {   
                if (user_guess < num)
                {
                    cout << "go higher" << endl;
                }
                else
                {
                    cout << "go lower" << endl;
                }
                
                
                cout << "you have " << attempts << " attempts!" << endl;
            }   
            
        }
        

    }
    


    return 0;
}
bool guess(int num, int user_guess, int *attempts)
{
    if(num == user_guess)
    {
        return true;
    }
    else
    {
        (*attempts)--;
        return false;
    }
}
