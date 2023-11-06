// Kevin Bui
// HW2.cpp
// 10/16/22

// Purpose: test set operations using bit strings

// Input: numbers from 0 - 9, -1 to stop

// Processing: loops and if statements

// Output: bit strings of the sets A and B including set operations applied

#include <iostream>

using namespace std;

void display(int); // function for displaying sets

int main()
{
    int setA = 0, setB = 0, userInput = 0, unionOf, intersection, difference;

    cout << "\n\nWelcome to HW 2: programming!  Given subsets A and B of a "
        << "universal set with 10 elements\n {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, "
        << "we will use bit strings to find A U B, A ∩ B, and A - B. \n"
        << "Users will be asked to populate each set. For example, if the user "
        << "enters 1, 2, 6, the bit \nstring will display from left to right "
        << "and display 0110001000.\n" ;

    while(userInput != -1){ // inputs elements for set A
        cout << "\nPlease enter a number for set A (enter -1 to stop): ";
        cin >> userInput;
        setA |= (1 << userInput); 
    }

    userInput = 0; // resets variable for next loop

    while(userInput != -1){ // inputs element for set B
        cout << "\nPlease enter a number for set B (enter -1 to stop): ";
        cin >> userInput;
        setB |= (1 << userInput); 
    }

    cout << "\n\nSet A:     ";
    display(setA);

    cout << "\n\nSet B:     ";
    display(setB);

    // operations
    unionOf = setA | setB;
    intersection = setA & setB;
    difference = setA & ~setB;

    cout << "\n\nUnion:     ";
    display(unionOf);

    cout << "\n\nIntersection:     ";
    display(intersection);

    cout << "\n\nDifference:     ";
    display(difference);

    cout << endl << endl;

    return 0;
}

void display(int set)
{
    for(int x = 0; x <= 9; x++){
        int mask = 1;
        mask &= (set >> x);
        cout << mask;
    }
}