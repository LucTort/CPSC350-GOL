// #include "Board.cpp"
#include "ReadFile.cpp"

using namespace std;

int main(int argc, char **argv)
{
    Board *myBoard = new Board();

    BoardUpdater *boardUpdater = new BoardUpdater();
    boardUpdater->RandomizeBoard(*myBoard, 0.4);

    for(int i = 0; i < 3; ++i)
    {
        myBoard->printBoard();

        boardUpdater->UpdateBoard(*myBoard, 0);

        boardUpdater->WaitForEnter();
    }




    return 0;
}