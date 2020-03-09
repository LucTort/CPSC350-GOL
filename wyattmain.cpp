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
    int xcount = 0;
    int ycount = 0;



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
      Board *myBoard = new Board(length+1, width);
      myBoard->printBoard();

      for (int i =0; i<length ; ++i){
        getline(f,line);
        cout<<line<<endl;
        int index = 0;
        xcount += 1;
        ycount = 0;
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
     }
    else if (number == 2){
      cout << "this is where lucas enters the random generation code"<< endl;
    }

    // Board *myBoard = new Board();

    BoardUpdater *boardUpdater = new BoardUpdater();

    // ReadFile *myReadFile = new ReadFile();
    // // myReadFile->argRead(int, char**);
    // myReadFile->option(argv[0]);

    // for(int i = 0; i < 3; ++i)
    // {
    //     myBoard->printBoard();
    //
    //     boardUpdater->UpdateBoard(*myBoard);
    // }




    //delete myBoard;

    //cout << myTestArray[0][1] << endl;

    return 0;
}
