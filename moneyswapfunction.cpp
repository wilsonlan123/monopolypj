
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
