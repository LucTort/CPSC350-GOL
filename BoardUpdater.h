// 1) 
// a. Lucas Torti
// b. 2351555
// c. torti@chapman.edu
// d. CPSC350 - 01
// e. Assignment 2, Game of Life
// 2) 
// This .h file declares the constructors, destructors, functions, and variables needed for the BoardUpdater class.

#include "Board.cpp"
using namespace std;

class BoardUpdater
{
    public:
        BoardUpdater(); //default constructor
        ~BoardUpdater(); //destructor

        void UpdateBoard(Board&, int);
        void RandomizeBoard(Board&, double);
        void CopyBoard(Board&, Board&);
        bool AreBoardsSame(Board&, Board&);
        bool DoesCellLive(int, bool);
        void WaitForEnter();
};