#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <string>
using namespace std;

string filename;

void showText()
{
    fstream mF;
    mF.open("file handling.txt", ios::in);//read
    if(mF.is_open())
    {
        string display;
        while(getline(mF, display))
        {
            cout << display << endl;
        }
    mF.close();
    }
}

string getFilename()
{
    cout << "\nEnter the subject: " << endl;
    cout << "[1] Sub1" << endl;
    cout << "[2] Sub2" << endl;
    cout << "[3] Sub3" << endl;
    cout << "[4] Sub4" << endl;
    int sub;
    cin >> sub;
    switch(sub)
    {
case 1:
    return "Sub1.txt";
case 2:
    return "Sub2.txt";
case 3:
    return "Sub3.txt";
case 4:
    return "Sub4.txt";
default:
    break;
    }

}


int main()
{
    time_t timetoday;
    time(&timetoday);
    fstream myFile;
    string newText;

    cout << "\t\t\t - - - - - S T A R T - - - - -" << endl;
    getFilename();

    while(newText != "admin")
    {
    // Prompt
    cout << endl << asctime(localtime(&timetoday)) << "- ";
    getline(cin, newText);

        // Display the text inside file.txt
        if(newText == "show" || newText == "display" || newText == "view")
        {
            showText();
            continue;
        }

        // Exit
        if(newText == "exit" || newText == "close" || newText == "end")
        {
            myFile.close();
            cout << "\t\t\t - - - - - - E N D - - - - - -" << endl;
            return 0;
        }

        // enter a text file to a new file
        if(myFile.is_open())
        {
            myFile.open("file handling.txt", ios::app); //app to appent an existing file
            myFile << "\n\n" << asctime(localtime(&timetoday)) << "- ";
            myFile << newText;
            myFile.close();
        }
    }
    myFile.close();
}
