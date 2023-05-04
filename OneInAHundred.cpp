#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include<iostream> 
#include<list>
#include<vector>
#include<random>
#include<map>
#include<string>



bool test_number(int a,int choice,int numrange[]){ //function used to update numrange used in One In A Hundred
    if (choice>a){
        numrange[1] = choice;
        cout << "Guess a number between "<<numrange[0] << " to "<< numrange[1]<<endl;
        return true;
    }
    else if(choice<a){
        numrange[0] = choice;
        cout << "Guess a number between "<<numrange[0] << " to "<< numrange[1]<<endl;
        return true;}
    else {
        return false;
    }}

void one_in_a_hundred(string player1, string player2){//MiniGame One In A Hundred
    int turn = 0;
    bool p1turn = true;
    int choice = 0;
    string players[] = {player1,player2};
    int a =  rand() % 100; // this is the winning number
    int numrange[] = {0,100};
    cout<<"Welcome to Mini Game: <One in a hundred>"<<endl;
    cout<<"In this game, you are going to keep guessing a number until you guessed the correct GOLDEN NUMBER"<<endl;
    cout<<"You will be given the range of the number before every guess, and the range will become smaller each time a guess is made."<<endl;
    cout<<"Winner will be rewarded 500m!"<<endl;
    cout<<"ALL THE BEST!"<<endl;
    cout<<"Let's go!"<<endl;
    cout << "Guess a number between "<< numrange[0] << " to " << numrange[1] << endl;


        while (true) {

            if (p1turn) {
                while (true){
                    if (player1 == "Bot1" || player1 == "Bot2" || player1 == "Bot3") {
                        choice = rand() % (numrange[1] - numrange[0] + 1) + numrange[0];
                        cout << player1 << ", choose a number: " << choice << endl;}
                    else {
                        cout << player1 << ", choose a number: ";
                        cin >> choice;}
                    if ((choice<numrange[0])||(choice>numrange[1]))
                        {cout << "Error: invalid input" << endl;
                        continue;}
                    else{
                        break;}}
                test_number(a, choice, numrange);
                turn = turn + 1;
                if (p1turn==true){p1turn = false;}
                else {p1turn = true;}}
            else{
                while (true){
                    if (player2 == "Bot1" || player2 == "Bot2" || player2 == "Bot3") {
                        choice = rand() % (numrange[1] - numrange[0] + 1) + numrange[0];
                        cout << player2 << ", choose a number: " << choice << endl;}
                    else{
                        cout << player2 << ", choose a number: ";
                        cin >> choice;}
                    if ((choice<numrange[0])||(choice>numrange[1])){
                        cout<<"Error: invalid input" << endl;
                        continue;}
                    else{
                        break;}}
                test_number(a, choice, numrange);
                turn = turn + 1;
                if (p1turn==true){p1turn = false;}
                else {p1turn = true;}}
            if (choice == a){
                break;}
            }
        cout<<"Winner is ..."<<players[(turn+1)%2]<<endl;
        cout<<"Congratulations! You win 500m!"<<endl;
        
   Characters[players[(turn+1)%2]] += 500
   Characters[players[(turn)%2]] -= 500 
   }
