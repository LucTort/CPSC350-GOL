//https://www.youtube.com/watch?v=fwYlzznrId4
//https://www.cplusplus.com/reference/cstdlib/rand/

#include "Board.h"

//default constructor
Board::Board()
{
    height = 5;

    width = 5;

    boardArray = new bool*[height];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            boardArray[i] = new bool [width];
        }
    }

    //initialize array

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



    height = xSizeInput;

    width = ySizeInput;

    boardArray = new bool*[height];
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            boardArray[i] = new bool [width];
        }
    }

    //initialize array

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
           *(*(boardArray+i)+j) = false;//random cells
        }
        cout << endl;
    }   

}

Board::~Board()
{

}



void Board::printBoard()
    {

        for (int x = 0; x < height; ++x)
        {
            for (int y = 0; y < width; ++y)
            {

                if (isCellAlive(x, y))
                {
                    cout << "X ";
                } else cout << ". ";
            }
            cout << endl;
        }

        cout << endl;

    }

    bool Board::isCellAlive(int xPosition, int yPosition)
    {
        return boardArray[xPosition][yPosition];
    }

    void Board::setCellState(int xPosition, int yPosition, bool isAlive)
    {
        boardArray[xPosition][yPosition] = isAlive;
    }

    bool Board::isInBounds(int xPosition, int yPosition)
    {
        if ((xPosition < 0) || (yPosition < 0))
            return false;
        else if((xPosition > width-1) || (yPosition > height-1))
            return false;
        else 
            return true;
    }