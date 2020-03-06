// #include "Board.cpp"
#include "ReadFile.cpp"

using namespace std;

int main(int argc, char **argv)
{
    //Board *myBoard = new Board(5, 4);
    deblog("Testing macro");
    deblog("Creating board");
    Board *myBoard = new Board(5, 4);

    BoardUpdater *boardUpdater = new BoardUpdater();
    boardUpdater->RandomizeBoard(*myBoard, 0.5);

    // for(int i = 0; i < 3; ++i)
    // {
        cout << "Printing board" << endl;
        myBoard->printBoard();

        cout << "Updating board." << endl;
        boardUpdater->UpdateBoard(*myBoard, 2);

        cout << "Printing board again" << endl;
        myBoard->printBoard();

        Board *myBoardAgain = new Board(5, 4);

        boardUpdater->CopyBoard(*myBoard, *myBoardAgain);

        cout << boardUpdater->AreBoardsSame(*myBoard, *myBoardAgain) << endl;


        //boardUpdater->WaitForEnter();
    //}

    return 0;
}