
//Here is a function for money swap.
//When the user step on this grid, the amount of money he has will automatically swap with another person
//Please help to link with the skeleton of the program 
//variable inside can be adjusted.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Modified function to randomly swap the money of two players in the Character array
void swap_money(int& player1_money, int& player2_money, int player1_num, int player2_num, struct Player Character[], int numberofplayers) {
    int temp = player1_money;
    player1_money = player2_money;
    player2_money = temp;
    
    cout << "Player " << player1_num << " now has $" << player1_money << "." << endl;
    cout << "Player " << player2_num << " now has $" << player2_money << "." << endl;
    cout << "The two players have swapped money!" << endl;
    for (int i = 0; i < numberofplayers; i++) {
        if (Character[i].name == "P" + to_string(player1_num)) {
            Character[i].balance = player1_money;
        }
        else if (Character[i].name == "P" + to_string(player2_num)) {
            Character[i].balance = player2_money;
        }
    }
}

int main() {
    srand(time(nullptr)); // Seed the random number generator with current time
    
    // Example usage of the function within Monopoly
    int num_players;
    cout << "How many players are playing Monopoly? ";
    cin >> num_players;
    cout << endl;
    
    // ... Code to initialize the game board and player information ...
    
    // Main game loop
    while (true) {
        // ... Code to move the current player to a new position on the board ...
        
        // Check if the current position triggers a money swap mini-game
        if (current_position == 10) { // Example position that triggers a money swap
            int player1_index = rand() % numberofplayers;
            int player2_index = rand() % numberofplayers;
            while (player2_index == player1_index) { // Make sure the other player is not the current player
                player2_index = rand() % numberofplayers;
            }
            int player1_money = Character[player1_index].balance;
            int player2_money = Character[player2_index].balance;
            swap_money(player1_money, player2_money, player1_index+1, player2_index+1, Character, numberofplayers);
        }
        
        // ... Code to handle other game actions ...
        
        current_player = (current_player + 1) % num_players; // Move to the next player's turn
    }
    
    return 0;
}
