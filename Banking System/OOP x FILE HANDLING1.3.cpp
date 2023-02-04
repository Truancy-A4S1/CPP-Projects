#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string username;
string password;
string acc_details;

class Account{
    public:
    string owner;
    float balance;
    int account_number;

    Account(string own, float bal, int acc_num)
    {
        owner = own;
        balance = bal;
        account_number = acc_num;
    }

    void deposit(float amount)
    {
        balance += amount;
    }

    void widthraw(float amount)
    {
        if(balance < amount)
        {
            cout << "Insufficient Balance!" << endl;
        }
        else
        {
            balance -= amount;
        }
    }

    float check_Balance()
    {
        return balance;
    }

    void logOut()
    {
        fstream File;
        string filename = username + ".txt";
        File.open(filename, ios::out);
        File << "Owner:" << owner;
        File << "Balance:" << balance;
        File << "Acc Number:" << account_number;
        File.close();
    }


};


void logIn()
{
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    string filename = username + ".txt";

    fstream File;
    File.open(filename, ios::in);
    if(!File.is_open())
    {
        cout << "Acc doesn't Exist!";
    }
    
    while()
}


int main()
{


    logIn();


    Account Ryan("ryan", 12.34,23423);
}
