#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <string>
#include <iostream>
using std::string; using std::cin; using std::cout; using std::endl;
// Forward declarations of functions:
void drawBoard(const string boardToDraw[9]);
void takePlayerNames(string& player1Name, string& player2Name);
void chooseCheck(string boardToCheck[9], int player, const string& symbol, const string& name);
bool checkWin(const string boardToCheck[9], int player, const string& symbol, const string& currentName);
bool checkFull(const string boardToCheck[9]);
// End Forward declarations of functions.

#endif

