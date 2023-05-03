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

//function for monopoly boxing game
//please help to link with the monopoly board and change some of the variable if necessary
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void boxing_match(int player1_num, int player2_num, int& player1_money, int& player2_money);

int main() {
    srand(time(nullptr)); // Seed the random number generator with current time
    
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
        
        // Check if the current position triggers a boxing match
        if (current_position == 20) { // Example position that triggers a boxing match
            int other_player = rand() % num_players;
            while (other_player == current_player) { // Make sure the other player is not the current player
                other_player = rand() % num_players;
            }
            boxing_match(current_player+1, other_player+1, player_money[current_player], player_money[other_player]);
        }
        
        // ... Code to handle other game actions ...
        
        current_player = (current_player + 1) % num_players; // Move to the next player's turn
    }
    
    return 0;
}

void boxing_match(int player1_num, int player2_num, int& player1_money, int& player2_money) {
    cout << "Let the boxing match begin between Player " << player1_num << " and Player " << player2_num << "!" << endl;
    
    int player1_health = 100;
    int player2_health = 100;
    
    // Main game loop
    while (player1_health > 0 && player2_health > 0) {
        // Player 1's turn
        cout << "Player " << player1_num << ", it's your turn." << endl;
        int player1_move = rand() % 6 + 1; // Roll a six-sided die to determine the move
        if (player1_move <= 3) { // Player 1 punches
            int damage = rand() % 11 + 5; // Roll a random number between 5 and 15 for the damage
            player2_health -= damage;
            cout << "Player " << player1_num << " punches Player " << player2_num << " for " << damage << " damage!" << endl;
        } else { // Player 1 blocks
            cout << "Player " << player1_num << " blocks!" << endl;
        }
        cout << "Player " << player2_num << " has " << player2_health << " health left." << endl;
        cout << endl;
        
        if (player2_health <= 0) { // Player 1 wins
            cout << "Player " << player1_num << " wins the boxing match and takes $100 from Player " << player2_num << "!" << endl;
            player1_money += 100;
            player2_money -= 100;
            break;
        }
        
        // Player 2's turn
        cout << "Player " << player2_num << ", it's your turn." << endl;
        int player2_move = rand() % 6 + 1; // Roll a six-sided die to determine the move
        if (player2_move <= 3) { // Player 2 punches
            int damage = rand() % 11 + 5; // Roll a random number between 5 and 15 for the damage
            player1_health -= damage;
            cout << "Player " << player2_num << " punches Player " << player1_num << " for " << damage << " damage!" << endl;
        } else { // Player 2 blocks
            cout << "Player " << player2_num << " blocks!" << endl;
        }
        cout << "Player " << player1_num << " has " << player1_health << " health left." << endl;
        cout << endl;
        
        if (player1_health <= 0) { // Player 2 wins
            cout << "Player " << player2_num << " wins the boxing match and takes $100 from Player " << player1_num << "!" << endl;
            player2_money += 100;
            player1_money -= 100;
            break;
        }
    }
}

//tic tac toe game function that can be implement in the momopoly game 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 3; // Size of the Tic Tac Toe board

void print_board(char board[][BOARD_SIZE]);
bool is_valid_move(char board[][BOARD_SIZE], int row, int col);
bool is_game_over(char board[][BOARD_SIZE]);
char get_winner(char board[][BOARD_SIZE]);
void make_move(char board[][BOARD_SIZE], char player, int row, int col);
void play_tic_tac_toe(int& player_money, int& current_position);

int main() {
    srand(time(nullptr)); // Seed the random number generator with current time
    
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
        
        // Check if the current position triggers a Tic Tac Toe game
        if (current_position == 12) { // Example position that triggers a Tic Tac Toe game
            play_tic_tac_toe(player_money[current_player], current_position);
        }
        
        // ... Code to handle other game actions ...
        
        current_player = (current_player + 1) % num_players; // Move to the next player's turn
    }
    
    return 0;
}

void print_board(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_valid_move(char board[][BOARD_SIZE], int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false; // Move is out of bounds
    }
    if (board[row][col] != ' ') {
        return false; // Move has already been made in this position
    }
    return true;
}

bool is_game_over(char board[][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    
    // Check if the board is full
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false; // Board is not full yet
            }
        }
    }
    
    return true; // Board is full and no winner
}

char get_winner(char board[][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    return ' '; // No winner
}

void make_move(char board[][BOARD_SIZE], char player, int row, int col) {
    board[row][col] = player;
}

void play_tic_tac_toe(int& player_money, int& current_position) {
    char board[BOARD_SIZE][BOARD_SIZE]; // Create an empty Tic Tac Toe board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    
    char player_symbol = 'X'; // Player starts as X
    char npc_symbol = 'O'; // NPC plays as O
    
    bool player_turn = true; // Player goes first
    while (!is_game_over(board)) {
        cout << endl;
        print_board(board);
        cout << endl;
        
        if (player_turn) {
            // Player's turn
            cout << "Your turn (symbol " << player_symbol << "). Enter row and column (e.g. 1 2): ";
            int row, col;
            cin >> row >> col;
            cout << endl;
            
            if (is_valid_move(board, row-1, col-1)) {
                make_move(board, player_symbol, row-1, col-1);
            } else {
                cout << "Invalid move. Try again." << endl;
                continue; // Ask the player for another move
            }
        } else {
            // NPC's turn
            int row, col;
            do {
                row = rand() % BOARD_SIZE;
                col = rand() % BOARD_SIZE;
            } while (!is_valid_move(board, row, col));
            cout << "NPC's turn (symbol " << npc_symbol << "): " << row+1 << " " << col+1 << endl;
            make_move(board, npc_symbol, row, col);
        }
        
        player_turn = !player_turn; // Switch turns
    }
    
    // Game is over, determine winner
    char winner = get_winner(board);
    if (winner == player_symbol) {
        cout << "Congratulations, you won!" << endl;
        player_money += 1000;
        current_position += 1;
    } else if (winner == npc_symbol) {
        cout << "Sorry, you lost." << endl;
        player_money -= 500;
        current_position -= 1;
    } else {
        cout << "It's a tie." << endl;
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
        Characters[player1] += 500;
        Characters[player2] -= 500;
        break;
    }
    else if (p2dice <= 0) {
        cout << "Winner is " << player2 << " ! Congratulations!\n";
        cout << "You win 500m!"<<endl;
        Characters[player2] += 500;
        Characters[player1] -= 500;
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

#include<iostream>      // drawnum game earn by how large they random 
#include<list>
#include<vector>
#include<random>
#include<map>
#include<string>
using namespace std;

vector<int> dgnumbank;
map<string, int>player_scoremap;
void dgdrawnum(string i) {
	cout << "Time to draw! " << endl;
	int dgrandom = rand() % numbank.size();

	int score = numbank[dgrandom];
	cout << "The drawn number is " << numbank[dgrandom] << endl;
	player_scoremap.insert({ i,score });
}


int main() {
	cout << "The drawing number game. The larger number you can draw, the more you can get! " << endl;
	for (int i = 0; i < 500; i++) {
		dgnumbank.push_back(i);
	}
	for (int i = 0; i < 6; i++) {
		string temp = to_string(i);
		dgdrawnum(temp);
	}
	return 0;

}

#include<iostream> //hangman game 
#include<list>
#include<vector>
#include<random>
#include<map>
#include<string>

using namespace std;
vector<string> hmwordbank{ "INDEX", "MOUSE", "FALSE", "ABORT", "LINES","CLOSE","INPUT", "FLASH", "IMAGE", "BEGIN", "STACK", "LOGIC","CYBER","FIELD","QUERY" };
vector<char> hmguessbank{'B','C','D','E','A','K','M'};
map<string, int>hmplayer_scoremap;
// we should just let the bot to guess from 20 words
int chances = 8;
vector<char> hmdisplay{ '_','_','_','_','_'};//list of display 
vector<char> hmanslist;	// list of ans 
bool hmwin = false;

int hmfloop(vector<char> w) {
	if (hmwin == true) {
		for (auto it = w.begin(); it != w.end(); ++it) {
			cout << *it;
			
		}
		return 0;
	}
	cout << "Current: ";
	for (auto it = w.begin(); it != w.end();++it) {
		cout << *it;
	}
	cout << endl;
	return 1;
}
vector<char> hmveclean() {
	hmdisplay.clear();
	for (int i =0; i<5;i++){
		hmdisplay.push_back('_');
	}
	return hmdisplay;
}
char toUppercase(char a) {
	if (a >= 'a' && a <= 'z') {
		a -= 32;
		return a;
	}
	if (a >= 'A' && a <= 'Z') {
		return a;
	}
}

bool hmcheck() {
	bool flag = true;
	for (int i = 0; i < 5; i++) {
		if (hmdisplay[i] != hmanslist[i]) {
			flag = false;
			return flag;
		}
	}
	hmwin = true;
	return flag;
}
bool hmguess(vector<char> ans,char input){ // why dont we replace the display directly?		// guessiing a letter is easier
	bool hmflag = false;
	list<char> hmguesslist;
	for (int i = 0; i < 5; i++) {
		char temp = ans[i];
		if (input ==ans[i] ) {
			hmdisplay[i] = ans[i];
			hmflag = true;
			if (hmcheck() == true) {
				cout << "You win. " << endl;
				cout << "The answer is ";
				hmfloop(hmdisplay);
				cout << endl;
				return hmflag;
			}
			//else if(check() == true && chances == 0)  {
			//	cout << "You lose. ";
			//	cout << "The answer is ";
			//	floop(display);
			//	cout << endl;
			//}
			break;
		}
	}

	hmfloop(hmdisplay);
	if (hmflag == false) {
		cout << "Incorrect" << endl;
		chances -=1;
		cout << "You have " << chances << " chances left. " << endl;
	}
	return hmflag;
}
void phangman() { // hangman for human
	hmveclean();
	chances = 8;
	hmwin = false;
	int random = rand() % hmwordbank.size();
	string ans = hmwordbank[random];
	hmanslist.clear();
	hmfloop(hmdisplay);
	for (int i = 0; i < 5; i++) {
		char temp = ans[i];
		hmanslist.push_back(temp);
	}
	while (chances > 0 && hmwin == false) {
		cout << "Please guess a letter: ";
		char input;
		cin >> input;
		input = toUppercase(input);
		hmguess(hmanslist,input);
	}
	//player_scoremap[] = chances; // put player into this function then include its value into here
	


}
void bhangman() { // hangman for bot 
	chances = 8;
	hmwin = false;
	int hmrandom = rand() % hmwordbank.size();
	hmanslist.clear();
	string ans = hmwordbank[hmrandom];
	hmwin = false;
	hmveclean();
	hmfloop(hmdisplay);
	cout << "The answer is " << ans << endl;
	for (int i = 0; i < 5; i++) {
		char temp = ans[i];
		hmanslist.push_back(temp);
	}
	int hmrandom2 = rand() % hmwordbank.size();
	string randguess = hmwordbank[hmrandom2];
	for (int i = 0; i < 5; i++) { //ok
		char temp = randguess[i];
		hmguessbank.push_back(temp);
	}
	while (chances > 0 && hmwin == false) {
		cout << "Please guess a letter: ";
		char input;
		int hmrandom3 = rand() % hmguessbank.size();
		input = hmguessbank[hmrandom3];
		input = toUppercase(input);		
		cout << input << endl;
		hmguess(hmanslist, input);

	}
	if (hmwin == false && chances == 0) {
		cout << "You lose " << endl;
	}
}


int main() {
	int playernum = 4; // number of players 
	cout << "Wordle time! " << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Player 1's turn! " << endl;
	phangman();
	cout << "-----------------------------------------------------------------------------------------" << endl; 
	cout << "Bot 1's turn! " << endl;
	bhangman();
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Bot 2's turn! " << endl;
	bhangman();
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Bot 3's turn! " << endl;
	bhangman();
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Bot 4's turn! " << endl;
	bhangman();


}

