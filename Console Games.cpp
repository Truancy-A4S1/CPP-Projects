#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include<sstream>


using namespace std;
bool gotoMenu = false;

void numberGuess();

int main()
{
    srand(time(NULL));
    int gameNum;

    cout << "Choose A Game: " << endl;
    cout << "[1] Number Guess" << endl;

    cin >> gameNum;
    switch(gameNum)
    {
    case 1:
        numberGuess();
        break;
    default:
        cout << "invalid game!" << endl;
    }

}

void numberGuess(){
    int randomNum = 1 + (rand() % 100);;
    int ans = 1000;
    int attempts{};
    string highScore;
    fstream File;

    //actual game
    while(1!=0){
        cout << "My Guess: ";
        cin >> ans;
        attempts++;
        if(ans == randomNum)
            break;
        else if(ans > randomNum)
            cout << "Too high \n";
        else
            cout << "Too low \n";
    }
    cout << "Your Score: " << attempts << endl;

    //check for highscore
    File.open("GuessHighScore.txt", ios::in);
    if(!File.is_open()){
        File.close();
        File.open("GuessHighScore.txt", ios::out);

        string number = highScore;
        stringstream ss;
        ss<<number;
        int i;
        ss>>i;

        File << attempts;
        cout << "New Record! " << endl;
        File.close();

    }

    while(getline(File, highScore)){ /* copy the highestscore inside File*/}


    cout << "Best Record: [" << highScore << "] " << endl;

    File.close();

}
