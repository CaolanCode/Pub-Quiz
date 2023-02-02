/*
  Pub Quiz
 */
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "questions.h"
using std::cin;
using std::string;
using std::ofstream;

int askQuestion();
void storeScore(string name, int score);

int main() {
    
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    
    int score = askQuestion();
    
    cout <<"\nScore: " << score << endl;
    
    storeScore(name, score);
    
    return 0;
}

int askQuestion()
{
    srand(time(0));
    int score = 0;
    char answer = 'Z';
    char input = 'Z';
    
    while(input != 'Q')
    {
        int question = rand() % 10;
        switch (question) {
            case 0:
                answer = question1();
                break;
            case 1:
                answer = question2();
                break;
            case 2:
                answer = question3();
                break;
            case 3:
                answer = question4();
                break;
            case 4:
                answer = question5();
                break;
            case 5:
                answer = question6();
                break;
            case 6:
                answer = question7();
                break;
            case 7:
                answer = question8();
                break;
            case 8:
                answer = question9();
                break;
            case 9:
                answer = question10();
                break;
            default:
                cout << "Error\n";
                break;
        }
        cout << "\nAnswer (Q to Quit): ";
        cin >> input;
        input = toupper(input);
        
        if(input == 'Q') break;
        
        if(input == answer) {
            cout << "\nCorrect!\n";
            score++;
        } else {
            cout << "\nWrong!\n";
        }
    }
    
    return score;
}

void storeScore(string name, int score)
{
    ofstream scoreFile;
    scoreFile.open("results.txt", std::ios_base::app);
    
    if(scoreFile.is_open()) {
        scoreFile << name << "\n" << score << "\n\n";
    } else {
        cout << "Could not open file\n";
    }
    scoreFile.close();
    
}
