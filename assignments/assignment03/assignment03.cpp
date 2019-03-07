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
// - name (string):             name of the player
// - number (integer):          player's number (no negative values)
// - pointsScored (integer):    number of points the player scored during a
//                              game (no negative values)
struct Player
{
    string name;
    int number;
    int pointsScored;
};

// Sets the players information (i.e., name, number, and number of points)
Player setPlayerInfo(Player *);

int main()
{
    const int NUM_PLAYERS = 12;
    Player players[NUM_PLAYERS];

    // Set the information for each player in the players array
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        cout << "PLAYER #" << i + 1 << "\n---------";
        setPlayerInfo(&players[i]);
        cout << "\n";
    }

    return 0;
}

Player setPlayerInfo(Player *player)
{
    cout << "\nPlayer name: ";
    getline(cin, player->name);
    cout << "Player's number: ";
    cin >> player->number;
    cin.ignore();
    cout << "Points scored: ";
    cin >> player->pointsScored;
    cin.ignore();
}