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





void rolling_dice(int pdice, vector<int>& plst) { //function to generate a vector of random dice
    plst.clear();
    for (int i = 0; i < pdice; i++) {
        int roll = rand() % 6 + 1;
        plst.push_back(roll);
    }
    return;}

int check_number(int choice, vector<int> plst, int pdice) { //function to check whether or not players' guess is in list of dice
    int number_of_dulplicate = 0;
    for (int j : plst) {
        if (j == choice) {
            number_of_dulplicate++;
        }
    }
    cout << "You got " << number_of_dulplicate << " dice correct." << endl;
    return number_of_dulplicate;
    }

void dice_rolling(string player1, string player2){//MiniGame Rolling Dice
int choice = 0;
    cout << "========================================================================================" << endl;
    cout<< "Welcome to Mini-Game: Rolling dice"<<endl;
    cout<<"In this game, both players have 5 dices initially."<<endl;
    cout<<"Both players take turn to take a guess between number from 1 to 6"<<endl;
    cout<<"A correct guess allows players to eliminate the number from its dice"<<endl;
    cout<<"For example, Player 1 has 5 dices, he takes a guess of 3, fortunately, dice are [1,3,4,2,3] after the round."<<endl;
    cout<<"His dice become [1,4,2] after eliminating 3"<<endl;
    cout<<endl;
    cout<<"Player with 0 dice left will win the game"<<endl;
    cout<<"GAME BEGINS NOW!"<<endl;
    cout<<"Lets go!"<<endl;
    cout<<endl;
   
    vector<int> p1lst;
    vector<int> p2lst;
    int p1dice = 5;
    int p2dice = 5;
    rolling_dice(p1dice, p1lst);
    rolling_dice(p2dice, p2lst);
    bool p1turn = true;
    int a =0;
    int b= 0;
    while (true) {
        if (p1turn) {
            while (true) {
                cout<<"Now is "<<player1<<"'s turn!"<<endl;
                cout << "Number of dice of " << player1 << "= " << p1dice << endl;
                if (player1 == "Bot1" || player1 == "Bot2" || player1 == "Bot3") {
                    choice = rand() % 6 + 1;
                    std::cout << player1 << ", guess a number from your dice: " << choice << std::endl;}
                else{
                    cout << player1 << ", guess a number from your dice: ";
                    cin >> choice;}
                if ((choice<1)||(choice>6)){
                    cout<<"Error: invalid input."<<endl;
                    continue;}
                else{
                    break;
                }}
            rolling_dice(p1dice, p1lst);
            cout << "Dice are : " ;
            for (int i=0;i<p1lst.size();i++){
                cout<<p1lst[i]<<"  ";
            }
            cout << endl;
            a = check_number(choice, p1lst, p1dice);
            p1dice -= a;
            cout << "Number of dice of " << player1 << "= " << p1dice << endl;
            cout<<endl;
            p1turn = !p1turn;}
        else{
            while (true) {
                cout<<"Now is "<<player2<<"'s turn!"<<endl;

                cout << "Number of dice of " << player2 << "= " << p1dice << endl;
                if (player2 == "Bot1" || player2 == "Bot2" || player2 == "Bot3") {
                    choice = rand() % 6 + 1;
                    cout << player2 << ", guess a number from your dice: " << choice << endl;}
                else{
                    cout << player2 << ", guess a number from your dice: ";
                    cin >> choice;}
                if ((choice<1)||(choice>6)){
                    cout<<"Error: invalid input."<<endl;
                    continue;}
                else{
                    break;
                }}
        rolling_dice(p2dice, p2lst);
        cout << "Dice are : " ;
        for (int i=0;i<p2lst.size();i++){
                cout<<p2lst[i]<<"  ";
            }
        cout << endl;
        b = check_number(choice, p2lst, p2dice);
        p2dice -= b;
        cout << "Number of dice of " << player2 << "= " << p2dice << endl;
        cout<<endl;
        p1turn = !p1turn;}
    if (p1dice <= 0) {
        cout << "Winner is " << player1 << " ! Congratulations!\n";
        cout << "You win 500m!"<<endl;
        //Characters[player1] += 500;
        //Characters[player2] -= 500;
        break;
    }
    else if (p2dice <= 0) {
        cout << "Winner is " << player2 << " ! Congratulations!\n";
        cout << "You win 500m!"<<endl;
        //Characters[player2] += 500;
        //Characters[player1] -= 500;
        break;
    }
    return ;
}}
