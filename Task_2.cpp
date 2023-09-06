/*
-----------------------------------------------------------------------------------------------------------------------
file  : Task_2.cpp
brief : A simple calculator program that performs the fundamental arithmetic operations such as addition, subtraction,
multiplication, divison and modulo. the user is allowed to input two numbers and to choose the operation to perform
author: hana maged mohamed
date  : September 6, 2023
-----------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>

using namespace std;

int main()
{
    int Number_One = 0;   /*variable to store input one*/
    int Number_Two = 0;   /*variable to store input two*/
    float Result = 0;     /*variable to store the result of operation*/
    char Operation = '+'; /*variable to store the chosen arithmetic operation*/
    cout << "Please enter the first input: ";
    cin >> Number_One;
    cout << "Please enter the second input: ";
    cin >> Number_Two;
    cout << "Choose an arithmetic operation: ";
    cin >> Operation;
    /*check the value of Operation and perform the corresponding arithmetic operation*/
    switch (Operation)
    {
        /*addition operation*/
    case '+':
        Result = Number_One + Number_Two;
        break;
        /*subtraction operation*/
    case '-':
        Result = Number_One - Number_Two;
        break;
        /*multiplication operation*/
    case '*':
        Result = Number_One * Number_Two;
        break;
        /*division operation*/
    case '/':
        Result = (float)(Number_One) / Number_Two;
        break;
        /*modulo operation*/
    case '%':
        Result = Number_One % Number_Two;
        break;
    default:
        cout << "Invalid Operation!\n";
    }
    cout << "Result = " << Number_One << " " << Operation << " " << Number_Two << " = " << Result << "\n";
    return 0;
}