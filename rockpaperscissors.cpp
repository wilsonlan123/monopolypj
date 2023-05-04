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
