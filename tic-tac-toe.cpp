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
