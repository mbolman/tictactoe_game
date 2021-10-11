// tictactoe.cpp : 
// By: M. Bolman
// last edit: 03-10-2021
// last edit: 03-10-2021
// last edit: 10-10-2021

 
#include "tictactoe.h"
using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    int currentPlayer = 1;
    string playerSymbol = "X";
    char again = 'y';

    while (again == 'y')
    {
        string player1Name, player2Name;
        takePlayerNames(player1Name, player2Name);
        string currentName = player1Name;
        cout << player1Name << " and " << player2Name << ", welcome to TicTocToe!" << endl;
        cout << "Here's is the current board:" << endl << endl;
        bool fullBoard = false;
        bool winner = false;
        string board[9] = { "1", "2", "3", "4", "5", "6","7", "8", "9" };
        drawBoard(board);
        while (!fullBoard && !winner)
        {
            // Let the current player choose a pos and check this
            chooseCheck(board, currentPlayer, playerSymbol, currentName);

            // Draw the board
            drawBoard(board);

            //Somebody winning?
            winner = checkWin(board, currentPlayer, playerSymbol, currentName);

            // Check  full
            fullBoard = checkFull(board);

            // Switch player
            if (currentPlayer == 1)
            {
                currentPlayer = 2;
                playerSymbol = "O";
                currentName = player2Name;
            }
            else
            {
                currentPlayer = 1;
                playerSymbol = "X";
                currentName = player1Name;
            }
        }
        cout << "End of game.." << endl << "Play again? (y/n)" << endl;
        cin >> again;
        
    }
    cout << "Have a nice day!" << endl;
    return 0;
}


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