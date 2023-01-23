#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;


bool isAccExisting(string filename);
bool isLoggedIn = false;


void log_In()
{
    string username;
    string password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    string filename = username + ".txt";

    fstream File;
    File.open(filename, ios::in); // open filename and read

    if(!File.is_open()) // if file is not opened; file doesnt exist
    {
        cout << "\nNo " << username << " username registered!\n";
        return;
    }
    else    // check if password is corred
    {
        string passwordFromText;
        while(getline(File, passwordFromText)){}

        if(password == passwordFromText) //if password is correct
        {
            cout << "\nLogged in successfully! \n";
            isLoggedIn = true;
            return;
        }
        else    //password is incorrect
        {
            cout << "\nIncorrect Password! \n";
            return;
        }
    }
    File.close();
}


void createAcc()
{
    fstream File;

    string username;
    string password;

    bool accountExist = false;

    cout << "\n -- Create a New Account -- \n";
    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    string filename = username + ".txt";

    accountExist = isAccExisting(filename);

    if(accountExist == true)
    {
        cout << "Account Already Exists\n";
        return;
    }

    File.open(filename, ios::out);  //create a file
    File << password;   //add the password inside username.txt file
    File.close();
}


bool isAccExisting(string filename)
{
    fstream File;
    File.open(filename, ios::in);

    if(!File.is_open())    // if filename/username doesnot exist
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    bool wannaDie = false;
    int option{};
    while(wannaDie != true)
    {

        cout << "\n-----------------------\n  Log in to continue   \n";
        cout << "+---------------------+\n";
        cout << "| Enter 1 to register |\n";
        cout << "| Enter 2 to log int  |\n";
        cout << "| Enter 3 to exit     |\n";
        cout << "+---------------------+\n";
        cout << "  Input: "; cin >> option;

        switch (option)
        {
        case 1:
            createAcc();
            break;

        case 2:
            log_In();
            break;

        case 3:
            wannaDie = true;
            break;
        }

        if(isLoggedIn == true)
        {
            break;
        }
    }
}
