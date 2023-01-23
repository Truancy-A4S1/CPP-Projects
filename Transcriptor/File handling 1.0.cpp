#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
    time_t timetoday;
    time(&timetoday);

    fstream myFile;
    string newText;

    while(newText != "exit"){
    myFile.open("file handling.txt", ios::out); //out to write a new file
    getline(cin, newText);
        if(newText == "exit")
        {
            myFile.close();
            return 0;
        }
        // enter a text file to a new file
        if(myFile.is_open())
        {
            myFile << "\n\n" << asctime(localtime(&timetoday)) << "- ";
            myFile << newText;
        }
        myFile.close();
    }
}
