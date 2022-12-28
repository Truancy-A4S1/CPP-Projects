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
    mF.open(filename, ios::in);//read
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

void getFilename()
{
    cout << endl <<"Enter a filename: ";
    getline(cin, filename);

    // Save as backup ng inamo if the user didn't enter a filename
    if(filename.empty())
    {
        filename = "Backup ng inamo.txt";
    }
}

int main()
{
    fstream myFile;
    string newText;
    time_t timetoday1;
    time(&timetoday1);

    getFilename();
    myFile.open(filename, ios::in); //in to read an existing file

    // if the file is not opened, then the file doesn't exists
    if(!myFile.is_open())
    {
        myFile.open(filename, ios::out); //write an new file

        // Title inside the txt file
        myFile << endl <<"\t\t" << filename << endl << "\t\t";
        for(int i = 0; i< filename.length(); i++)
        {
            myFile << "-";
        }

        myFile.close();
    }

    cout << "\t\t - - - - - S T A R T - - - - -" << endl;
    while(newText != "admin")
    {
        cout << endl << asctime(localtime(&timetoday1)) << "- ";
        getline(cin, newText);

        // Display the text inside file.txt
        if(newText == "show pls" || newText == "display pls" || newText == "view pls")
        {
            showText();
        }
        else if(newText == "exit pls" || newText == "close pls" || newText == "end pls")
        {
            myFile.close();
            cout << "\t\t - - - - - - E N D - - - - - -" << endl;
            return 0;
        }
        else
        {
            time_t timetoday;
            time(&timetoday);
            myFile.open(filename, ios::app); //app to append an existing file
            myFile << "\n\n" << asctime(localtime(&timetoday)) << " -";
            myFile << newText;
            myFile.close();
        }
    }
}
