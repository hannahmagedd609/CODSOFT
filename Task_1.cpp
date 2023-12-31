/*
------------------------------------------------------------------------------------------------------------------------------
file: Task_1.cpp
brief : a console-based guessing game, the program generates a random number between 1 and 100, and the user
 has to guess the correct number. the program provides feedback on each guess, indicating whether the guess
 is too high or too low. the game ends once the user guess the number right,or when the user consumes all allowed attempts
author: hana maged mohamed
date  : September 5, 2023
------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(0));                         /*seeding the random number to ensure that the sequence of generated random numbers will be unique for each program execution*/
    int Random_Number = 1 + rand() % (100); /*the range of the random number to be generated is from 1:100*/
    bool Guess_Flag = false;
    int Attempts_Counter = 0;
    int Max_Attempts = 10; /*ten trials are only allowed*/
    int Guess = 0;
    cout << "Hey Guess Wizards! Welcome to our astounding guessing game!!\n";
    cout << "I've picked a number somewhere in the range of 1 and 100, you have " << Max_Attempts << " attempts to figure the number right.\n";
    Sleep(2000);
    std::cout << "Starting in 3";
    Sleep(1000);
    std::cout << " 2";
    Sleep(1000);
    std::cout << " 1\n";
    cout << "GO!\n";
    /*guessing loop: Continues until the correct number is guessed or the maximum attempts limit is reached*/
    while ((!Guess_Flag) && (Attempts_Counter < Max_Attempts))
    {
        cout << "Enter your guess: ";
        cin >> Guess;
        ++Attempts_Counter;
        if ((Guess) == (Random_Number))
        {
            Guess_Flag = true;
        }
        else if ((Guess) > (Random_Number))
        {
            cout << "Your guess is too high, try again\n";
        }
        else
        {
            cout << "Your guess is too low, try again\n";
        }
    }
    if (Guess_Flag == true)
    {
        cout << "WOHOO! You guessed it right after " << Attempts_Counter << " attempts!\n";
    }
    else
    {
        cout << "You have ran out all your attempts, better luck next time :)\n";
    }

    return 0;
}