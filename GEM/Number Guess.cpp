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
    fstream File;

    int randomNum = 1 + (rand() % 100);
    int guess = -1;
    int score{};

    bool isBestRecord = false;
    string name;
    string nameFile;

    //actual game
    while(1!=0){
        if(guess > -1){
            if(guess > randomNum)
                cout << "Too high" << endl;
            else
                cout << "Too low" << endl;
        }

        cout << "My Guess: ";
        cin >> guess;
        score++;
        system("CLS");

        if(guess == randomNum){
            cout << "Your Score: " << score << endl;
            break;
        }
    }

    //If file doesn't exist, write a new file and insert the scoreStr in it
    stringstream ss;
    ss << score;
    string str = ss.str();

    File.open("GuessHighScore.txt", ios::in);

    if(!File.is_open())
    {
        isBestRecord = true;
        File.close();

    }
    else
    {
        string scoreFileStr;
        while(getline(File, scoreFileStr)){ /* copy the highestscore inside File*/}

        int scoreFileInt = stoi(scoreFileStr); //score from file(string) into integer for comparison
        File.close();

        if(score < scoreFileInt)
        {
            isBestRecord = true;
            File.close();

        }
        else
        {
            File.close();
            cout << "Best Record: " << scoreFileInt << endl;
            File.open("GuessHighScoreName.txt", ios::in);
            while(getline(File, nameFile)){}
            cout << "By: " << nameFile << endl;
            File.close();
        }
    }

    if(isBestRecord == true)
    {
        cout << "New Record: " << score << endl;
        cout << "Enter Your Name: "; cin >> name;

        //save the new record inside a file
        File.open("GuessHighScore.txt", ios::out);
        File << str;
        File.close();

        //save the high scorers' name
        File.open("GuessHighScoreName.txt", ios::out);
        File << name;
        File.close();
    }

    Sleep(5000);
    system("CLS");
}

