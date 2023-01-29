#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;


void numberGuess();

int main()
{
    srand(time(NULL));
    int gameNum{};

    do{
        cout << "Choose A Game " << endl;
        cout << " [0] Exit " << endl;
        cout << " [1] Number Guess" << endl;

        cout << endl;
        cout << "Game : "; cin >> gameNum;

        switch(gameNum)
        {
        case 1:
            system("CLS");
            numberGuess();
            break;


        }

    }while(gameNum != 0);
}

void numberGuess(){
    int randomNum = 1 + (rand() % 100);
    cout << randomNum;
    int ans = 1000;
    int attempts{};
    bool isBestRecord = false;
    string nameFile;
    string name;

    fstream File;

    //actual game
    while(1!=0){
        if(ans < 101)
        {
            if(ans > randomNum)
                cout << "Too high \n";
            else
                cout << "Too low \n";
        }
        cout << "My Guess: ";
        cin >> ans;
        attempts++;
        system("CLS");
        if(ans == randomNum){
            break;
        }
    }
    cout << "Your Score: " << attempts << endl;

    // convert score from int to string (for writing inside file)
    stringstream ss;
    ss << attempts;
    string str = ss.str();

    File.open("GuessHighScore.txt", ios::in);
    //if file doesn't exist
    if(!File.is_open()){
        File.close();

        File.open("GuessHighScore.txt", ios::out);
        File << str;
        cout << "New Record! " << endl;
        File.close();

        cout << "Enter Your Name: ";
        cin >> name;
        File.open("GuessHighScoreName.txt", ios::out);
        File << name;
        File.close();
        Sleep(5000);
        system("CLS");
        return;
    }

    //else get the highscore from the file
    string scoreFileStr;
    while(getline(File, scoreFileStr)){ /* copy the highestscore inside File*/}
    int scoreFileInt = stoi(scoreFileStr); //scoreFile from string to int (for comparison)
    File.close();

    if(attempts < scoreFileInt){
        cout << "New Record SET: " << attempts << endl;

        File.open("GuessHighScore.txt", ios::out);
        File << str;
        File.close();

    }else{
        cout << "Best Record: " << scoreFileInt << endl;
        File.open("GuessHighScoreName.txt", ios::in);
        while(getline(File, nameFile)){}
        cout << "By: " << nameFile << endl;
        File.close();
    }


    if(attempts < scoreFileInt)
    {
        cout << "Enter Your Name: ";
        cin >> name;
        File.open("GuessHighScoreName.txt", ios::out);
        File << name;
        File.close();
    }
    Sleep(5000);
    system("CLS");
}
