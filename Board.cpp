//https://www.youtube.com/watch?v=fwYlzznrId4
//https://www.cplusplus.com/reference/cstdlib/rand/

// 1) 
// a. Lucas Torti
// b. 2351555
// c. torti@chapman.edu
// d. CPSC350 - 01
// e. Assignment 2, Game of Life
// 2) 
// This is a class which stores all the values for the board of game of life. In addition it contains helper functions.

// 3) All classes/methods/functions/member variables/etc will be documented individually
// with block comments providing the following:

#include "Board.h"

//
Board::Board()
{
    height = 5;

    width = 5;

//sets up the 2d array
    boardArray = new bool*[height];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            boardArray[i] = new bool [width];
        }
    }


    //initializes array to false
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
           *(*(boardArray+i)+j) = false;//random cells
        }
        cout << endl;
    }


}

Board::Board(int xSizeInput, int ySizeInput)
{



    width = xSizeInput;

    height = ySizeInput;


    //sets up 2d array
    boardArray = new bool*[height];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            boardArray[i] = new bool [width];
            deblog("success");
        }
    }

    //initialize array to false

    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
           //*(*(boardArray+i)+j) = false;//random cells
           boardArray[j][i] = false;
        }
        cout << endl;
    }

}

Board::~Board()
{

}

// a. printBoard
// b. Returns no value
// c. No parameter type
// d. No exception types
void Board::printBoard()
    {
        deblog("Starting outer loop");
        for (int y = 0; y < height; ++y)
        {
            //deblog("Starting inner loop");
            for (int x = 0; x < width; ++x)
            {

                 if (isCellAlive(x, y))
                {
                    cout << "X";
                } else cout << "-";
             }
            cout << endl;
        }

        cout << endl;

    }

    bool Board::isCellAlive(int xPosition, int yPosition)
    {
        return boardArray[yPosition][xPosition];
    }

    void Board::setCellState(int xPosition, int yPosition, bool isAlive)
    {
        boardArray[yPosition][xPosition] = isAlive;
    }

    bool Board::isInBounds(int xPosition, int yPosition)
    {
        if ((xPosition < 0) || (yPosition < 0))
            return false;
        else if((xPosition >= width) || (yPosition >= height))
            return false;
        else
            return true;
    }

    bool  Board::IsBoardEmpty()
{
    //iterates through array and returns false if any location in the array is full, otherwise returns true
     for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j <width; ++j)
        {
           if (boardArray[i][j] == true)
           {
               return false;
           }
        }
    }

    return true;
}

string Board::GetBoardAsString()
{

    string boardValues = "";

    //iterates through array, ceating a string of values as it does so
    for(int y = 0; y < height; ++y)
    {
        for(int x = 0; x < width; ++x)
        {
            if (boardArray[y][x])
            {
                boardValues += "X";
            }
            else
            {
                boardValues += "-";
            }

        }
        boardValues += '\n';
    }

    //provides some extra whitespace equal to the height of the board
    for(int y = 0; y < height; ++y)
    {
        boardValues += '\n';
    }

    return boardValues;
}
