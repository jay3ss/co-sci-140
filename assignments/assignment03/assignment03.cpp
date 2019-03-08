// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 03
// Due March 10, 2019
//
// Write a program that scores the following data about a soccer player in a
// structure:
//
//     Player’s Name
//     Player’s Number
//     Points Scored by Player
//
// The program should keep an array of 12 of these structures. Each element is
// for a different player on a team. When the program runs, it should ask the
// user to enter the data for each player. It should then show a table that
// lists each player’s number, name, and points scored. The program should also
// calculate and display the total points earned by the team. The number and
// name of the player who has earned the most points should also be displayed.
//
// Input Validation: Do no accept negative values for players’ numbers or
// points scored.
// 
// NOTE: Extra credit has been attempted with making sure that no two players
// have the same number.
#include <iostream>
#include <string>

using namespace std;

// Struct that defines a soccer player:
// - name (string):                  name of the player
// - number (unsigned int):          player's number
// - pointsScored (unsigned int):    number of points the player scored during
//                                   a game
struct Player
{
    string name;
    unsigned int number;
    unsigned int pointsScored;
};

/*
 *  FUNCTION PROTOTYPES
 */
// Function that sets an individual player's information (i.e., name, number,
// and number of points)
void setPlayersInfo(Player [], const int);

// Function that gets the player's number. No two players can have the same
// number and the number must not be negative
unsigned int getPlayerNumber(Player [], const int, const int);

// Function that checks if a desired number (number) is currently taken by any
// other players.
bool isNumberTaken(const Player [], const int, const int, const int);

// Displays each player's stats on an individual line, the total points scored
// in the game, and displays the player with the most points
void finalOutput(const Player players[], const int size);

// Function that finds the player that scored the most points in the players
// array and returns that player's index
int highestScorerIndex(const Player players[], const int size);

// Function that finds the total points scored in the game
unsigned int totalPoints(const Player players[], const int size);

// Convenience function that determines if an integer is negative
bool isNegative(int);

// Convenience function that gets an unsigned int from the user. Does
// input validation and prints a message to the screen if the user
// doesn't enter a non-negative number
unsigned int getUnsignedInt();

int main()
{
    const int NUM_PLAYERS = 12;
    Player players[NUM_PLAYERS];

    // Set the information for each player in the players array
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        cout << "PLAYER #" << i + 1 << "\n---------";
        cout << "\nPlayer name: ";
        getline(cin, players[i].name);
        cout << "Player's number: ";
        players[i].number = getPlayerNumber(players, i, NUM_PLAYERS);
        cout << "Points scored: ";
        players[i].pointsScored = getUnsignedInt();
        cout << "\n";
    }

    finalOutput(players, NUM_PLAYERS);

    return 0;
}

// void setPlayersInfo(Player players[], const int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         cout << "PLAYER #" << i + 1 << "\n---------";
//         cout << "\nPlayer name: ";
//         getline(cin, players[i]->name);
//         cout << "Player's number: ";
//         players[i]->number = getUnsignedInt();
//         cout << "Points scored: ";
//         players[i]->pointsScored = getUnsignedInt();
//         cout << "\n";
//     }
// }

// Function that gets the player's number. No two players can have the same
// number and the number must not be negative.
// HACK: For now, acts as a shim to the getUnsignedInt function
unsigned int getPlayerNumber(Player players[], const int index, const int size)
{
    int number = -1;
    bool isTaken = true;

    // Keep trying to get the player number until the number is both
    // non-negative AND the number is not taken.
    while (isNegative(number) || isTaken)
    {
        number = getUnsignedInt();
        isTaken = isNumberTaken(players, number, index, size);

        if (isTaken) {
            cout << number << " is taken. Please try again.\n";
        }
    }

    return number;
}

// Function that checks if a desired number (number) is currently taken by any
// other players.
bool isNumberTaken(const Player players[], const int number,
                   const int index, const int size)
{
    int stop;

    // Make sure that we're not going beyond the bounds of the array
    if (index < size)
    {
        stop = index;
    }
    else
    {
        stop = size;
    }

    for (int i = 0; i < stop; i++)
    {
        if (players[i].number == number)
        {
            return true;
        }
    }

    return players[index].number == number;
}

// Displays each player's stats on an individual line, the total points scored
// in the game, and displays the player with the most points
void finalOutput(const Player players[], const int size)
{
    unsigned int total = totalPoints(players, size);
    int highestIndex = highestScorerIndex(players, size);

    cout << "NAME\t\tNUMBER\t\tPOINTS SCORED\n";
    for (int i = 0; i < size; i++)
    {
        cout << players[i].name << "\t\t "
             << players[i].number << "\t\t "
             << players[i].pointsScored << "\n";
    }

    cout << "TOTAL POINTS: " << total << "\n"
         << "The player who scored the most points is: "
         << players[highestIndex].name;
}

// Function that finds the player that scored the most points in the players
// array and returns that player's index
int highestScorerIndex(const Player players[], const int size)
{
    return 0;
}

// Function that finds the total points scored in the game
unsigned int totalPoints(const Player players[], const int size)
{
    return 0;
}

// Convenience function that gets an unsigned int from the user. Does
// input validation and prints a message to the screen if the user
// doesn't enter a non-negative number
unsigned int getUnsignedInt()
{
    int number = -1;
    do {
        cin >> number;
        cin.ignore();
        if (isNegative(number))
        {
            cout << "No negative numbers please\n";
        }
    } while(isNegative(number));

    return number;
}

// Convenience function that determines if an integer is negative
bool isNegative(int number)
{
    return number < 0;
}
