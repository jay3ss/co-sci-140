#include <iostream>
#include <string>

#include <iostream>
#include <string>

using namespace std;

struct Player
{
    string name;
    unsigned int number;
    unsigned int pointsScored;
};

struct Testing1
{
    int integer;
    int integers[];
};

// struct Testing2
// {
//     int integers[];
//     int integers;
// };

struct Testing3
{
    int integers[5];
    int integer;
};

bool isNumberTaken(const Player[], const int, const int, const int);

int main()
{
	// const int NUM_PLAYERS = 4;
    // Player players[NUM_PLAYERS];

    // for (int i = 0; i < NUM_PLAYERS; i++)
    // {
    //     players[i].name = "a";
    //     players[i].number = i * i;
    //     players[i].pointsScored = NUM_PLAYERS - i;
    // }

	// int numsToCheck = NUM_PLAYERS * NUM_PLAYERS + 1;
    // for (int idx = 0; idx < numsToCheck; idx++)
    // {
    //     if (isNumberTaken(players, idx, idx, NUM_PLAYERS))
    //     {
    //         cout << idx << " is taken\n";
    //     }
    //     else {
    //         cout << idx << " is not taken\n";
    //     }
    // }

	system("pause");
    return 0;
}

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