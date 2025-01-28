// Date: 28/01/2025
// Project: Number guessing game
// Project function: Program will generate a random number and user has to guess it in 5 attempts
// status: work in progress

#include<iostream>
using namespace std;

bool guess(int num, int user_input, int* attempts);

int main()
{
    int user_input, difficulty;
    int user_guess, attempts;
    while (user_input != -1)
    {
        cout << "\n**********************************************" << endl;
        cout << "*                                            *" << endl;
        cout << "*              Play the game: 0              *" << endl;
        cout << "*              exit: -1                      *" << endl;
        cout << "*                                            *" << endl;
        cout << "**********************************************" << endl;
        cin >> user_input;
        if (user_input==-1)
        {
            break;
        }
        
        cout << endl;
        cout << "**********************************************" << endl;
        cout << "*                                            *" << endl;
        cout << "*              Difficulty: 1-3               *" << endl;
        cout << "*                                            *" << endl;
        cout << "**********************************************" << endl;
        cin >> difficulty;
        attempts = 5;
        int num = 90;
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
                cout << "you have " << attempts << " attempts!" << endl;
            }   
            
        }
        

    }
    


    return 0;
}
bool guess(int num, int user_input, int *attempts)
{
    if(num == user_input)
    {
        return true;
    }
    else
    {
        (*attempts)--;
        return false;
    }
}
