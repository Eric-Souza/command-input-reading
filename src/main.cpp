#include <fstream>
#include <iostream>
#include <string>

#include <LinkedQueue.hpp>

using namespace std;

int main(int argc, char *argv[])
{
  // Reads file using command line
  if (argc > 1)
  {
    fstream inputTextFile(argv[1]);

    if (inputTextFile.is_open() && inputTextFile.good())
    {
      string line = "";

      // Prints line by line
      while (getline(inputTextFile, line))
      {
        cout << line << endl;
      }
    }

    // Error handling
    else
    {
      cout << "Error while reading file, exiting..." << endl;
      return -1;
    }
  }

  // Error handling
  else
  {
    cout << "Error while executing code, please check the command again";
    return -1;
  }

  return 0;
}