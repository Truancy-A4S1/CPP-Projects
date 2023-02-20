#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool isLoggedIn = false;
string username;

void homeOptions();
void createAcc();
void log_In();

void transactionOptions();
void withdraw();
void deposit();

int main()
{


    homeOptions();
    transactionOptions();
}


void homeOptions()
{
    int input;
    while(isLoggedIn == false){
    system("CLS");
    cout << "+---------------+\n";
    cout << "|    WELCOME    |\n";
    cout << "+---------------+\n";
    cout << "| PLEASE CHOOSE |\n";
    cout << "+---------------+\n";
    cout << "| [1] REGISTER  |\n";
    cout << "| [2] LOG IN    |\n";
    cout << "| [3] EXIT      |\n";
    cout << "+---------------+\n";

    cout << "  Input: "; cin >> input;

        switch (input)
        {
            case 1:
            createAcc();
            break;

            case 2:
            log_In();
            break;

            default:
            exit(0);
        }
    }
}


void createAcc()
{
    fstream File;
    string password, filename;

    cout << endl << " -- Create a New Account -- " << endl;
    cout << " Username: "; cin >> username;
    cout << " Password: "; cin >> password;
    filename = "acc/" + username + ".txt";

    //check if account already exists
    File.open(filename, ios::in);
    if(!File.is_open()){
        File.close();
        File.open(filename, ios::out);
        File << password;   //add password to username.txt file
        cout << endl << " New Account Created" << endl;
        File.close();
        return;
    }

    cout << endl << " Account Already Exists" << endl;
    File.close();
}

void log_In()
{
    isLoggedIn = false;

    fstream File;
    string password, filename, passwordFromText;

    cout << endl << " Enter username: "; cin >> username;
    cout << " Enter password: "; cin >> password;

    filename = "acc/" + username + ".txt";
    File.open(filename, ios::in);

    //if file doesnt exist
    if(!File.is_open())
    {
        cout << endl << " Invalid Username!" << endl;
        return;
    }

    while(getline(File, passwordFromText)){ /* copy the text into passwordFromText */}

    //if password is correct
    if(password == passwordFromText){
        system("CLS");
        cout << endl << " Welcome " << username << "!" << endl;
        isLoggedIn = true;
        return;
    }

    cout << endl << " Incorrect Password! " << endl;
    return;

    File.close();
}

void transactionOptions()
{
    int input;
    while(isLoggedIn == true){
        cout << endl;
        cout << " USER: " << username << endl;
        cout << "+---------------+\n";
        cout << "| PLEASE CHOOSE |\n";
        cout << "+---------------+\n";
        cout << "| [1] WITHDRAW  |" << endl;
        cout << "| [2] DEPOSIT   |" << endl;
        cout << "| [3] LOG OUT   |" << endl;
        cout << "+---------------+\n";

        cout << "  Input: "; cin >> input;

        switch (input)
        {
            case 1:
                withdraw();
                break;
            case 2:
                deposit();
                break;
            case 3:
                isLoggedIn = false;
                homeOptions();
        }
    }
}

void withdraw()
{
    cout << "\n  Successfully Withdrawn ! " << endl;

    //insert code here
}

void deposit()
{
    cout << "\n  Successfully Deposited ! " << endl;

    //insert code here
}
