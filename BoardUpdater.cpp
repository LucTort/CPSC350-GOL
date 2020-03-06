//https://stackoverflow.com/questions/21257544/c-wait-for-user-input
#include "BoardUpdater.h"

//default constructor
BoardUpdater::BoardUpdater()
{

}



void  BoardUpdater::UpdateBoard(Board& currentBoard, int gameMode)
{
    int surroundingCells = 0;
    Board *placeholderBoard = new Board(currentBoard.width, currentBoard.height);


    //
    //outer loop                                                                          

     for (int xBoard = 0; xBoard < currentBoard.width; ++xBoard)
     {
         for (int yBoard= 0; yBoard < currentBoard.height; ++yBoard)
         {
           //inner loop
           for(int xLocal = -1; xLocal < 2; ++xLocal)
           {
               for(int yLocal = -1; yLocal < 2; ++yLocal)
                {
                    if (currentBoard.isInBounds((xBoard + xLocal), (yBoard + yLocal))) 
                    {      
                       surroundingCells += currentBoard.isCellAlive( (xBoard + xLocal) , (yBoard + yLocal) ) ;
                       //cout << currentBoard.isCellAlive( (xBoard + xLocal) , (yBoard + yLocal) ) << " ";
                    }
                    else
                    {
                        switch (gameMode)
                        {
//      __  ____                     
//     /  |/  (_)_____________  _____
//    / /|_/ / / ___/ ___/ __ \/ ___/
//   / /  / / / /  / /  / /_/ / /    
//  /_/  /_/_/_/  /_/   \____/_/     
//                                 
                            case 1:
                            //checks four directions
                            //. X .
                            //X . X
                            //. X .

                                if (currentBoard.isInBounds((xBoard + xLocal - 1), (yBoard + yLocal)))
                                    {surroundingCells += currentBoard.isCellAlive((xBoard + xLocal - 1), (yBoard + yLocal));}

                                else if ( currentBoard.isInBounds((xBoard + xLocal + 1), (yBoard + yLocal)) )
                                    {surroundingCells += currentBoard.isCellAlive((xBoard + xLocal + 1), (yBoard + yLocal));}

                                else if (currentBoard.isInBounds((xBoard + xLocal), (yBoard + yLocal - 1)) )
                                    {surroundingCells += currentBoard.isCellAlive((xBoard + xLocal), (yBoard + yLocal - 1));}

                                else if ( currentBoard.isInBounds((xBoard + xLocal), (yBoard + yLocal + 1)) )
                                    {surroundingCells += currentBoard.isCellAlive((xBoard + xLocal), (yBoard + yLocal + 1));}

                            //checks other four directions
                            //X . X
                            //. . .  
                            //X . X

                                else if ( currentBoard.isInBounds(xBoard + xLocal - 1, yBoard + yLocal - 1) )
                                    {surroundingCells += currentBoard.isCellAlive(xBoard + xLocal - 1, yBoard + yLocal - 1);}

                                else if ( currentBoard.isInBounds(xBoard + xLocal + 1, yBoard + yLocal - 1) )
                                    {surroundingCells += currentBoard.isCellAlive(xBoard + xLocal + 1, yBoard + yLocal - 1);}

                                else if ( currentBoard.isInBounds(xBoard + xLocal - 1, yBoard + yLocal + 1) )
                                    {surroundingCells += currentBoard.isCellAlive(xBoard + xLocal - 1, yBoard + yLocal + 1);}

                                else if ( currentBoard.isInBounds(xBoard + xLocal + 1, yBoard + yLocal + 1) )
                                    {surroundingCells += currentBoard.isCellAlive(xBoard + xLocal + 1, yBoard + yLocal + 1);}

                                //surroundingCells += currentBoard.isCellAlive( (xBoard + xLocal) , (yBoard + yLocal) ) ;
                                break;

//      ____                    __                __ 
//     / __ \____  __  ______ _/ /_  ____  __  __/ /_
//    / / / / __ \/ / / / __ `/ __ \/ __ \/ / / / __/
//   / /_/ / /_/ / /_/ / /_/ / / / / / / / /_/ / /_  
//  /_____/\____/\__,_/\__, /_/ /_/_/ /_/\__,_/\__/  
//                    /____/                        
                            case 2:
                                int xToCheck = xBoard + xLocal;
                                int yToCheck = yBoard + yLocal;
                                
                                //wraps the x direction
                                if ( (xBoard + xLocal) < 0) {xToCheck = currentBoard.width - 1;}
                                if ( (xBoard + xLocal) == currentBoard.width) {xToCheck = 0;}

                                //wraps the x direction
                                if ( (yBoard + yLocal) < 0) {yToCheck = currentBoard.height - 1;}
                                if ( (yBoard + yLocal) == currentBoard.height) {yToCheck = 0;}

                                surroundingCells += currentBoard.isCellAlive(xToCheck, yToCheck);

                                break;
//     ________                _     
//    / ____/ /___ ___________(_)____
//   / /   / / __ `/ ___/ ___/ / ___/
//  / /___/ / /_/ (__  |__  ) / /__  
//  \____/_/\__,_/____/____/_/\___/  
//                                  
                            //default://classic
                              //  break;
                        }
                    }
                    
                //cout << surroundingCells << endl;
                }//for
                //cout << endl;
                
           }//for
           //cout << endl << endl;


            //end inner loop

            surroundingCells -= currentBoard.isCellAlive(xBoard , yBoard);//subtracts from number of cells if the starting cell is alive
            placeholderBoard->setCellState(xBoard, yBoard, DoesCellLive(surroundingCells, currentBoard.isCellAlive(xBoard, yBoard) ));

            //cout << "Surrounding Cells:" << surroundingCells << endl;

            surroundingCells = 0;
         }//for
         surroundingCells = 0;
     }//for
     CopyBoard(*placeholderBoard, currentBoard);
}//UpdateBoard

void  BoardUpdater::RandomizeBoard(Board& currentBoard, double percentLiving)
{
    int spacesToPopulate = ( int (currentBoard.width * currentBoard.height * percentLiving));

    if (spacesToPopulate > currentBoard.width * currentBoard.height)
    {
        cout << "Cannot produce more than 100 percent population" << endl;
        return;
    }

    //clears board
    for (int i = 0; i < currentBoard.height; ++i)
    {
        for (int j = 0; j < currentBoard.width; ++j)
        {
           currentBoard.boardArray[i][j] = false;//random cells
        }
    } 


    int randX = rand() % currentBoard.width;
    int randY = rand() % currentBoard.height;
    for (int i = 0; i < spacesToPopulate; ++i)
    {
        while (currentBoard.isCellAlive(randX , randY) )
        {
            randX = rand() % currentBoard.width;
            randY = rand() % currentBoard.height;
        }
        

        currentBoard.setCellState(randX, randY, true);
    }  

}

void  BoardUpdater::CopyBoard(Board& boardToCopy, Board& boardToUpdate)
{
     for (int i = 0; i < boardToCopy.width; ++i)
    {
        for (int j = 0; j < boardToCopy.height; ++j)
        {
           *(*(boardToUpdate.boardArray+i)+j) = *(*(boardToCopy.boardArray+i)+j);
        }
    }
}

bool BoardUpdater::DoesCellLive(int surroundingCells, bool currentState)
{
    //cout << surroundingCells << " ";

    if (surroundingCells >= 4)
        return false;
    else if (surroundingCells == 3)
        return true;
    else if (surroundingCells >= 2)
        return currentState;
    else 
         return false;
}

void BoardUpdater::WaitForEnter()
{
    cout << "Please press enter" << endl;

    cin.get();
}