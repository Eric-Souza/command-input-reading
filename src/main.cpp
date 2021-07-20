#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  // Checks if the command line file input is correct
  if (argc > 1)
  {
    fstream inputTextFile(argv[1]);

    if (inputTextFile.is_open() && inputTextFile.good())
    {
      string line = "";

      while (getline(inputTextFile, line))
      {
        cout << line << endl;
      }
    }

    else
    {
      cout << "Error while reading file, exiting..." << endl;
      return -1;
    }
  }

  // If file can't be read by command line, reads it using fstream
  else
  {
    fstream testTextFile;
    testTextFile.open("../text.txt", ios::in);

    if (testTextFile.is_open() && testTextFile.good())
    {
      string line = "";

      while (getline(testTextFile, line))
      {
        cout << line << endl;
      }
    }

    else
    {
      cout << "Error while reading file, exiting..." << endl;
      return -1;
    }
  }

  return 0;
}