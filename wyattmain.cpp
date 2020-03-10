// #include "Board.cpp"
// http://www.cplusplus.com/forum/beginner/106204/
//https://www.techiedelight.com/convert-string-to-int-cpp/
#include "ReadFile.cpp"

using namespace std;

int main(int argc, char **argv)

{
    string path = "";
    int number = 0;
    fstream f;
    string lengthString;
    string widthString;
    int length = 0;
    int width = 0;
    string line = "";
    char grid[length][width];
    int xcount = -1;
    int ycount = -1;
    int randlength = 0;
    int randwidth = 0;
    double percentageAlive = 0.0;
    int mode = 0;



    cout<< "Please choose an option ('1' or '2'): "<< endl;
    cout << "1) To enter a file path "<<endl;
    cout << "2) For a random configuration"<<endl;
    cin >> number;

    if (number == 1){
      cout << "Please specify the .txt file you would like to run: "<<endl;
      cin >> path;
      cout << "this is the path: "<< path << endl;
      f.open(path);
      if (!f.is_open()){
        cout<<"the file could not be opened: "<<endl;
        return 0;
      }
      // cout<<"The file has been opened"<< endl;
      //finding the length and width of the txt file
      for (int i = 0; i<=2; ++i){
        if (i == 1){
          getline(f, widthString);
          width = std::stoi(widthString);
          cout <<"Width: "<< width<<endl;
        }
        else if (i == 2){
          getline(f, lengthString);
          length = std::stoi(lengthString);
          cout <<"Length: "<<length<< endl;
        }
      }
      cout<<"Here is the board"<<endl;
      cout<< length << "Length"<< endl;
      cout<< width << "Width"<< endl;
      cout<<  "fchghjnhgcfgvhbjnjbhvgcfhvbjnhvgcfhvbjnkbhvgcfxhjkhgcfhjnhgcfxdgcvhbjbhgf"<< endl;
      Board *myBoard = new Board(width, length);
      myBoard->printBoard();

      for (int i =0; i<length ; ++i){
        getline(f,line);
        cout<<line<<endl;
        int index = 0;
        xcount += 1;
        ycount = -1;
        // cout << "xcount is:"<< xcount << endl;
        //https://stackoverflow.com/questions/1315041/how-can-i-iterate-through-a-string-and-also-know-the-index-current-position
        for (auto it = line.begin() ; it < line.end(); ++it, ++index){
          ycount += 1;
          cout << "xcount is:"<< xcount << endl;
          cout << "ycount is:"<< ycount << endl;
          cout << index << ": "<<*it<< endl;
          if (*it == 'X'){
            myBoard->setCellState(xcount, ycount, 1);
            cout<<"X added to the board"<< endl;
          }
          else if (*it == '.'){
            myBoard->setCellState(xcount, ycount, 0);
            cout<<". added to the board"<< endl;
          }
        }
      }
      cout<<"Here is the board we want to be printed correctly"<< endl;
      myBoard->printBoard();

      f.close();

      cout << "Which mode would you like to play? (1,2,3)"<< endl;
      cout << "0) Classic Mode "<< endl;
      cout << "1) Mirror Mode "<< endl;
      cout << "2) Donut Mode "<< endl;
      cin >> mode;
      BoardUpdater *myBoardUpdater = new BoardUpdater();
      myBoardUpdater -> UpdateBoard (*myBoard, mode);
      if (mode>2){
        cout << "That is not an option, please restart!! "<< endl;
        return 1;
      }
      myBoard->printBoard();
     }
    else if (number == 2){
      cout << "RANDOM BOARD"<< endl;
      cout << "What length do you want your board? "<< endl;
      cin >> randlength;
      cout << "What width do you want your board? "<< endl;
      cin >> randwidth;
      cout << "What percent of the cells would you like to be alive (0-100)"<<endl;
      cin >> percentageAlive;
      percentageAlive = percentageAlive/100.0;
      Board *myBoard = new Board(randlength, randwidth);
      BoardUpdater *myBoardUpdater = new BoardUpdater();
      myBoardUpdater -> RandomizeBoard(*myBoard, percentageAlive);
      myBoard -> printBoard();

      cout << "Which mode would you like to play? (1,2,3)"<< endl;
      cout << "0) Classic Mode "<< endl;
      cout << "1) Mirror Mode "<< endl;
      cout << "2) Donut Mode "<< endl;
      cin >> mode;
      myBoardUpdater -> UpdateBoard (*myBoard, mode);
      if (mode>2){
        cout << "That is not an option, please restart!! "<< endl;
        return 1;
      }
      myBoard->printBoard();
    }


    BoardUpdater *boardUpdater = new BoardUpdater();

//        TO DO LIST
// OUTPUT TO A FILE
// SLEEP OUTPUT
// ENTER FUNCTIONALITY
// . TO -
// DONUT MODE NEEDS FIXING


    return 0;
}
