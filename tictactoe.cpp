//
// Definitions of functions
//

#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

// Draw the current board,  In: reference to string of arrays board
//  Out: none
void drawBoard(const string boardToDraw[9])
{
    for (int c = 0; c < 9; ++c)
    {
        cout << boardToDraw[c];
        if (c != 2 && c != 5 && c != 8)
            cout << " | ";
        else if (c != 8)
            cout << endl << "----------" << endl;
    }
    cout << endl << endl;
}

// Take 2 player names, In: reference to string: names
//                      Out: none

void takePlayerNames(string& player1Name, string& player2Name)
{
    cout << "Player 1, you get the 'X', your name please : ";
    cin >> player1Name;
    cout << "Player 2, you get the 'O', your name please: ";
    cin >> player2Name;
}

//
//
void chooseCheck(string boardToCheck[9], int player, const string& symbol, const string& currentName)
{
    int pos;
    cout << "Hello, " << currentName << ". Please choose a position on the board (1 ..9): for " << symbol << endl;
    cin >> pos;
    while (pos < 1 || pos > 10 || (boardToCheck[pos - 1] == "X" || boardToCheck[pos - 1] == "O"))
    {
        cout << "That position is already taken,  or numer is not (1 .. 9) please choose another one" << endl;
        cin >> pos;
    }
    if (player == 1)
    {
        boardToCheck[pos - 1] = "X";
    }
    else if (player == 2)
    {
        boardToCheck[pos - 1] = "O";
    }
}

bool checkWin(const string boardToCheck[9], int player, const string& symbol, const string& currentName)
{
    // Check if player wins
    if ((boardToCheck[0] == symbol && boardToCheck[1] == symbol && boardToCheck[2] == symbol) ||
        (boardToCheck[3] == symbol && boardToCheck[4] == symbol && boardToCheck[5] == symbol) ||
        (boardToCheck[6] == symbol && boardToCheck[7] == symbol && boardToCheck[8] == symbol) ||
        (boardToCheck[0] == symbol && boardToCheck[3] == symbol && boardToCheck[6] == symbol) ||
        (boardToCheck[1] == symbol && boardToCheck[4] == symbol && boardToCheck[7] == symbol) ||
        (boardToCheck[2] == symbol && boardToCheck[5] == symbol && boardToCheck[8] == symbol) ||
        (boardToCheck[0] == symbol && boardToCheck[4] == symbol && boardToCheck[8] == symbol) ||
        (boardToCheck[2] == symbol && boardToCheck[4] == symbol && boardToCheck[6] == symbol))
    {
        cout << currentName << " wins!" << endl;
        return true;
    }
    else
        return false;

}

bool checkFull(const string boardToCheck[9])
{
    for (int c = 0; c != 9; ++c)
    {
        if (boardToCheck[c] != "X" && boardToCheck[c] != "O")
            return false;
    }
    return true;
}
