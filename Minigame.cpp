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
