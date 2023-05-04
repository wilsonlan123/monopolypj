
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
        player_money[i] = 1500; // Set each player's starting money to $1500 (set any suitable amount of money is ok)
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
