#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <random>
#include <thread>
using namespace std;

void PvPcheck(string &PvP, int &PvPcorrectness){
    cout << "Multiplayers?\n( yes / no ): ";
    cin >> PvP;
    if (PvP == "yes" || PvP == "no"){
        PvPcorrectness = 1;
    }
    else{
        cout << "Invalid input" << endl << endl;
    }
}

void PlayerNocheck(int &PlayerNo, int &PlayerNocorrectness){
    string PlayerNoStr;
    cout << "Number of players( < 5 ): ";
    cin >> PlayerNoStr;
    int check = 0;
    for (int i = 0; i < PlayerNoStr.size(); i++){
        if (isdigit(PlayerNoStr[i])){
            check++;
        }
    }
    if (check == PlayerNoStr.size()){
        PlayerNo = stoi(PlayerNoStr);
        if (PlayerNo > 4){
            cout << "Too much players!" << endl << endl;
        }
        else if (PlayerNo < 2){
            cout << "There must be at least two players!" << endl << endl;
        }
        else{
            PlayerNocorrectness = 1;
        }
    }
    else{
        cout << "Invalid input" << endl << endl;
    }
}

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
    cout<<"ALL THE BEST!"<<endl;
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

int main(){
    cout << "---Welcome to monopoly! ( special edition )---" << endl;
    cout << "-----------------------------Settings-----------------------------" << endl;
    int PvPcorrectness = 0;
    string PvP = "temp";
    while (PvPcorrectness == 0){
        PvPcheck(PvP, PvPcorrectness);
    }
    string PvE;
    int BotNo;
    int PlayerNo;
    if (PvP == "yes"){
        PvE = "no";
        int PlayerNocorrectness = 0;
        PlayerNo = 0;
        while (PlayerNocorrectness == 0){
            PlayerNocheck(PlayerNo, PlayerNocorrectness);
        }
        if (PlayerNo < 4){
            int PvEcorrectness = 0;
            PvE = "temp";
            while (PvEcorrectness == 0) {
                cout << "Add NPC?\n( yes / no ) ";
                cin >> PvE;
                if (PvE == "yes" || PvE == "no") {
                    PvEcorrectness = 1;
                    break;
                } else {
                    cout << "Invalid input" << endl << endl;
                }
            }
            if (PvE == "yes"){
                if (PlayerNo == 3){
                    cout << "Number of NPCs: 1" << endl <<endl;
                    BotNo = 1;
                } 
                else if (PlayerNo < 3){
                    int BotNocorrectness = 0;
                    while (BotNocorrectness == 0){
                        string BotNoStr;
                        cout << "Number of NPCs: ";
                        cin >> BotNoStr;
                        int check = 0;
                        for (int i = 0; i < BotNoStr.size(); i++){
                            if (isdigit(BotNoStr[i])){
                                check++;
                            }
                        }
                        if (check == BotNoStr.size()){
                            BotNo = stoi(BotNoStr);
                            if (BotNo + PlayerNo > 4) {
                                cout << "Too many NPCs!" << endl << endl;
                            }
                            else{
                                BotNocorrectness = 1;
                                break;
                            }
                        }
                        else{
                            cout << "Invalid input" << endl << endl;
                        }
                    }
                }
            }
        }
    }
    else{
        int BotNocorrectness = 0;
        int BotNo = 0;
        while (BotNocorrectness == 0){
            string BotNoStr;
            cout << "Number of NPCs: ";
            cin >> BotNoStr;
            int check = 0;
            for (int i = 0; i < BotNoStr.size(); i++){
                if (isdigit(BotNoStr[i])){
                    check++;
                }
            }
            if (check == BotNoStr.size()){
                BotNo = stoi(BotNoStr);
                if (BotNo == 0){
                    cout << "There must be at least 1 NPC!" << endl << endl;
                }
                else if (BotNo > 3){
                    cout << "Too many NPCs!" << endl;
                }
                else{
                    BotNocorrectness = 1;
                    break;
                }
            }
            else{
                cout << "Invalid input" << endl << endl;
            }
        }
    }
    string Symbols[2][4] = {{"○","△","□","⬡"}, {"●","▲","■","⬢"}};
    map<string, int> Characters;
    if (PvP == "yes"){
        for (int i = 1; i <= PlayerNo; i++){
            Characters["Player" + to_string(i)] = 1500;
        }
        if (PvE == "yes"){
            for (int j = 1; j <= BotNo; j++){
                Characters["Bot" + to_string(j)] = 1500;
            }
        }
    } else{
        Characters["Player"] = 1500;
        for (int a = 1; a <= BotNo; a++) {
            Characters["Bot" + to_string(a)] = 1500;
        }
    }
    cout << "------------------------------------------------------------------" << endl;
}

//Rock paper scissors mini-game 
//when the user stay on this grid, he has to play with npc. If he win, he can move forward two step. If he lose, he has to go back 3 steps
//the program has not completed, wait for the branch to compete so that the moving step can be linked to the game, please help if you have time!
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    srand(time(nullptr)); // Seed the random number generator with current time
    
    int npc_choice = rand() % 3; // Randomly choose NPC's option (0 = rock, 1 = paper, 2 = scissors)
    
    cout << "Enter your choice (0 = rock, 1 = paper, 2 = scissors): ";
    int user_choice;
    cin >> user_choice;
    
    // Display the NPC's choice with a corresponding figure
    cout << "NPC chose ";
    if (npc_choice == 0) {
        cout << "rock" << setw(10) << R"(
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
)" << endl;
    } else if (npc_choice == 1) {
        cout << "paper" << setw(9) << R"(
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________)
)" << endl;
    } else {
        cout << "scissors" << setw(6) << R"(
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
)" << endl;
    }
    
    // Determine the winner
    if (user_choice == npc_choice) {
        cout << "Tie!" << endl;
    } else if (user_choice == 0 && npc_choice == 2 || user_choice == 1 && npc_choice == 0 || user_choice == 2 && npc_choice == 1) {
        cout << "You win!" << endl;
    } else {
        cout << "NPC wins!" << endl;
    }
    
    return 0;
}

//Here is a function for money swap.
//When the user step on this grid, the amount of money he has will automatically swap with another person
//Please help to link with the skeleton of the program 
//variable inside can be adjusted.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to randomly swap the money of two players
void swap_money(int& player1_money, int& player2_money, int player1_num, int player2_num) {
    int temp = player1_money;
    player1_money = player2_money;
    player2_money = temp;
    
    cout << "Player " << player1_num << " now has $" << player1_money << "." << endl;
    cout << "Player " << player2_num << " now has $" << player2_money << "." << endl;
    cout << "The two players have swapped money!" << endl;
}

int main() {
    srand(time(nullptr)); // Seed the random number generator with current time
    
    // Example usage of the function within Monopoly
    int num_players;
    cout << "How many players are playing Monopoly? ";
    cin >> num_players;
    cout << endl;
    
    int player_money[num_players];
    for (int i = 0; i < num_players; i++) {
        player_money[i] = 1500; // Set each player's starting money to $1500
    }
    
    int current_player = 0; // Index of the current player
    int current_position = 0; // Index of the current position on the board
    
    // Main game loop
    while (true) {
        // ... Code to move the current player to a new position on the board ...
        
        // Check if the current position triggers a money swap
        if (current_position == 10) { // Example position that triggers a money swap
            int other_player = rand() % num_players;
            while (other_player == current_player) { // Make sure the other player is not the current player
                other_player = rand() % num_players;
            }
            swap_money(player_money[current_player], player_money[other_player], current_player+1, other_player+1);
        }
        
        // ... Code to handle other game actions ...
        
        current_player = (current_player + 1) % num_players; // Move to the next player's turn
    }
    
    return 0;
}
