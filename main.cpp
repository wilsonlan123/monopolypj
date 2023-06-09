#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <limits>
#include "DiceRolling.h"
#include "OneInAHundred.h"
#include "drawnearn.h"
#include "hangman.h"
using namespace std;

//data structure for storing information on each square of the board
struct square{
	string title;
	int price;
	string owner;
	string visitors;
	int rent;
	int OwnerNum;
};

//declaring the array of the data strucuture for the board
square p[14] = { { "Start", 500, "     ", "     "},
		{ "$250M", 250, "     ", "     "},
		{ "$300M", 300, "     ", "     "},
		{ "Mini ", 0, "Game ", "     "},
		{ "$250M", 250, "     ", "     "},
		{ "$250M", 250, "     ", "     "},
		{ "Mini ", 0, "Game ", "     "},
		{ "$500M", 500, "     ", "     "},
		{ "$150M", 150, "     ", "     "},
		{ "$150M", 150, "     ", "     "},
		{ "Mini ", 0, "Game ", "     "},
		{ "$100M", 100, "     ", "     "},
		{ "$50M ", 50, "     ", "     "},
		{ "$100M", 100, "     ", "     "}};

//data structure for storing information on each player
struct playerdata{
	string name;
	string pawn;
	int BankBalance;
	int position;
	bool NPC;
	bool bankrupt;
};

//declaring the array of playerdata, NEED TO CHANGE TO DYNAMIC ARRAY FOR PROJECT REQUIRMENTS
playerdata Character[4];

//what it does: checking the input of whether the user wants PvP enabled
//inputs: user input and PvPcorrectness to check if user input is valid
//output: program will change variable PvPcorrectness to 1 if input is valid
void PvPcheck(string &PvP, int &PvPcorrectness){
    cout << "Multiplayers?\n( yes / no ): ";
    cin >> PvP;
    if (PvP == "yes" || PvP == "no"){
        PvPcorrectness = 1;
    } else{
        cout << "Invalid input" << endl << endl;
    }
}

//what it does: checking input of number player characters the user wants and storing the value if valid
//inputs: user input number of player characters and PvPcorrectness to check if user input is valid
//output: program will change variable PlayerNo to the user input if the input is valid
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

//what it does: simulate dice roll
//inputs: no input
//output: random int from 1 to 6;
int Rolladice (){
    srand(time(0));
    int dice = rand() % 6 + 1; 
    return dice;
}
//what it does: print the current state of the board
//inputs: none
//output: prints the game board
void PrintBoard() {
        cout << "------------------------------------------------------------------" << endl << endl;
	cout << "-------   -------   -------   -------   -------" << endl;
	cout << "|" << p[7].title << "|   |" << p[8].title << "|   |" << p[9].title << "|   |" << p[10].title << "|   |" << p[11].title << "|" << endl;
	cout << "|" << p[7].owner << "|   |" << p[8].owner << "|   |" << p[9].owner << "|   |" << p[10].owner << "|   |" << p[11].owner << "|" << endl;
	cout << "|" << p[7].visitors << "|   |" << p[8].visitors << "|   |" << p[9].visitors << "|   |" << p[10].visitors << "|   |" << p[11].visitors << "|" << endl;
	cout << "-------   -------   -------   -------   -------" << endl << endl;
	cout <<"-------                                 -------"  << endl;
	cout << "|" << p[6].title << "|                                 |" << p[12].title << "|" << endl;
	cout << "|" << p[6].owner << "|                                 |" << p[12].owner << "|" << endl;
	cout << "|" << p[6].visitors << "|                                 |" << p[12].visitors << "|" << endl;
	cout <<"-------                                 -------"  << endl << endl;
	cout <<"-------                                 -------"  << endl;
	cout << "|" << p[5].title << "|                                 |" << p[13].title << "|" << endl;
	cout << "|" << p[5].owner << "|                                 |" << p[13].owner << "|" << endl;
	cout << "|" << p[5].visitors << "|                                 |" << p[13].visitors << "|" << endl;
	cout <<"-------                                 -------"  << endl << endl;
	cout << "-------   -------   -------   -------   -------" << endl;
	cout << "|" << p[4].title << "|   |" << p[3].title << "|   |" << p[2].title << "|   |" << p[1].title << "|   |" << p[0].title << "|" << endl;
	cout << "|" << p[4].owner << "|   |" << p[3].owner << "|   |" << p[2].owner << "|   |" << p[1].owner << "|   |" << p[0].owner << "|" << "   <----- Get $" << p[0].price << "M" << endl;
	cout << "|" << p[4].visitors << "|   |" << p[3].visitors << "|   |" << p[2].visitors << "|   |" << p[1].visitors << "|   |" << p[0].visitors << "|" << "    each time passing Start" << endl;
	cout << "-------   -------   -------   -------   -------" << endl << endl;
}

//what it does: prints list of current characters and their bank balances
//inputs: number of players, int n
//output: prints the character name and their bank balance on each line
void PrintBalance(int n) {
	  for (int i = 0; i < n; i++) {
	  	if (Character[i].bankrupt == true){
			cout << Character[i].pawn << " " << Character[i].name << " is bankrupt :(" << endl;
		}else{
			cout << Character[i].pawn << " " << Character[i].name << " Bank Balance = $" << Character[i].BankBalance << "M" << endl;
	  	}
	  }
}

//what it does: allows users to select their pawns for the game, places pawn on the board and links to their playerdata
//inputs: player number, string of pawn options, playerdata array index
//output: program will output the pawn of the users choosing as a string, additionally the pawn will be added to board (p[])
string PawnSelect(int n, string &Symbols, int i) {
	     int temp;
	     string selection;
	     cout << "Player " << n <<  " select your pawn:" << endl;
             for (int k = 1; k <= Symbols.length(); k++){
                  cout << k << ":" << Symbols[k-1] << "   ";
             }
             cout << endl;
             cin >> temp;
             while (temp > Symbols.length() || temp < 1){
                  cin.clear();
		  cin.ignore(numeric_limits<streamsize>::max(),'\n');
		  cout << "Invalid input" << endl;
                  cin >> temp;
             }
	     selection = Symbols[temp-1];
	     Symbols.erase(temp-1,1);
	     p[0].visitors.replace(i,1,selection);
	     return selection;
}

//what it does: checks if game has ended by checking if only 1 player remains and by asking the user if they wish to end the game
//inputs: number of active character, playerdata array index of active character, number of game rounds completed
//output: true if conditions have been met for game to be over, false if not
bool gameover(int charactercount, int RollCount, int RoundCount) {
	if (charactercount == 1) {
		return true;
	}
	if (RollCount == 0){
		cout << "Round " << RoundCount << " Complete! Do you want to continue playing?\n(Yes/No): ";
		string ans;
		cin >> ans;
		if (ans == "Yes" || ans == "yes"){
			return false;
		} else if (ans == "No" || ans == "no"){ 
			return true;
		} else {
			cout << "Invalid input" << endl;
			return gameover(charactercount, RollCount, RoundCount);
		}
	} else {
	return false;
	}
}

//what it does: declares character as bankrupt and transfers all their money and property to the player they owe rent to
//inputs: playerdata array index of bankrupt character, playerdata array index of character charging rent
//output: no output, bankrupt character marked as bankrupt, money and properties moved to other player
void bankrupt(int payer, int payee){
	cout << Character[payer].name << " declares bankrupcy :(" << endl;
	Character[payee].BankBalance += Character[payer].BankBalance;
	Character[payer].BankBalance = 0;
	Character[payer].bankrupt = true;
	for (int i = 1; i < 14; i++){
		if (p[i].OwnerNum == payer){
			p[i].OwnerNum = payee;
			if (Character[payee].NPC == true){
				p[i].owner = Character[payee].name + " ";
			} else {
				 p[i].owner = " " + Character[payee].name + "  ";
			}
		}
	}
	p[Character[payer].position].visitors.replace(payer, 1, " ");
}

//what it does: selects a random minigame, creates prizepool, distributes prizemoney
//inputs: playerdata array index of active character
//output: no output, prizemoney distrubuted to winning characters
void minigame(int PlayerNum){
    //betting <- System needs to be determined
    //MoneyPool ($xxxM)
    //Subtract $yyyM from each player
    //if one winner, output needs to be array index of winning player
    //if ranked, output needs to be the array of player indexes in ranked order,
    			//{3,2,0,1}
			//function ranking[0] + 0.5* prize pool
			//function ranking[1] + 0.25 * prize pool
    int prizepool;
    srand(time(0));
    int choice = rand() % 4 + 1;
	
    if (choice == 1){
	if (dice_rolling(Character[PlayerNum].name,"Bot1")){
		Character[PlayerNum].BankBalance += 500;}
	else{
		Character[PlayerNum].BankBalance -= 500;}
    }else if (choice == 2){
	if (one_in_a_hundred(Character[PlayerNum].name,"Bot1")){
		Character[PlayerNum].BankBalance += 500;}
	else{
		Character[PlayerNum].BankBalance -= 500;}	
    }else if (choice == 3){
	//implement drawnearn.cpp
	 // just call and bring in the size
	  // return the ranking list where 0 is First place , 1 is second place.etc
	vector<int> drawnearnranklist = drawnearn(4);
	for (int i=0; i<4;i++){
	    	Character[i].BankBalance += (4-drawnearnranklist[i])/10.0 * 60;
	    }
    } 
     else if (choice == 4){
	    //call hangman game and brings in the number of players which is used to initiate the for loop
	    //return the array of chances left each player
	    // each player earn for $50 per chance
    	vector<int> hangmanchancelist = hangman(4);
    	for (int i=0; i<4;i++){
		Character[i].BankBalance += ((4-hangmanchancelist[i]))/10.0 * 50;
	}//implement hangman.cpp
    } 
}

//what it does: regular character turnsequence, roll dice, line on square, buy property/pay rent/play mini game etc
//inputs: number of players, playerdata array index of active character
//output: no output, changes playerdata and board based on events
void turnsequence(int activeplayers, int Rollcount){
	int roll = Rolladice();
	string temp;
	if (Character[Rollcount].NPC == false){
		cout << Character[Rollcount].name << "'s turn! Press any key then ENTER to roll the dice!";
		cin >> temp;
	}
	else {
		cout << Character[Rollcount].name << "'s turn!" << endl;
		this_thread::sleep_for(2000ms);
	}
	cout << Character[Rollcount].name << " rolled a " << roll << endl;
	this_thread::sleep_for(2000ms);
	p[Character[Rollcount].position].visitors.replace(Rollcount, 1, " ");
	if (Character[Rollcount].position + roll > 13) {
		cout << Character[Rollcount].name << " passed the start and earns $" << p[0].price << "M!" << endl;
		this_thread::sleep_for(2000ms);
		Character[Rollcount].BankBalance += p[0].price;
	}
	Character[Rollcount].position = (Character[Rollcount].position + roll) % 14;
	p[Character[Rollcount].position].visitors.replace(Rollcount, 1, Character[Rollcount].pawn);
	if (p[Character[Rollcount].position].title == "Mini "){
		PrintBoard();
		cout << Character[Rollcount].name << " landed on a mini game square!" << endl;
		minigame(Rollcount);
		this_thread::sleep_for(2000ms);
		return;
	}
	else if (p[Character[Rollcount].position].title == "Start"){
		PrintBoard();
		this_thread::sleep_for(2000ms);
		return;
	}else {
		if (p[Character[Rollcount].position].owner == "     "){
			string temp;
			PrintBoard();
			if (Character[Rollcount].NPC == false){
				cout << Character[Rollcount].name << " landed on a free property! Would you like to purchase for $" << p[Character[Rollcount].position].price << "M?\n(Yes/No): ";
				cin >> temp;
				while (temp != "Yes" && temp != "No"){
					cout << endl << "Invalid input" << endl;
					cin >> temp;
				}
			} else {
				cout << Character[Rollcount].name << " landed on a free property!" << endl;
				this_thread::sleep_for(2000ms);
			}
			if (temp == "Yes" || Character[Rollcount].NPC == true){
				if (Character[Rollcount].BankBalance < p[Character[Rollcount].position].price){
					cout << "Oh no! " << Character[Rollcount].name << " can't afford this property! :(" << endl;
					this_thread::sleep_for(2000ms);
					return;
				}else{
					if (Character[Rollcount].NPC == true){
						p[Character[Rollcount].position].owner =  Character[Rollcount].name + " ";
					} else {
						p[Character[Rollcount].position].owner = " " + Character[Rollcount].name + "  ";
					}
				 	p[Character[Rollcount].position].OwnerNum = Rollcount;
				 	p[Character[Rollcount].position].title = "Owned";
				 	Character[Rollcount].BankBalance -= p[Character[Rollcount].position].price;
					PrintBoard();
					cout << Character[Rollcount].name << " purchased a property!" << endl;
					this_thread::sleep_for(2000ms);
					return;
				}
			}
		} else {
			PrintBoard();
			int owner = p[Character[Rollcount].position].OwnerNum;
			if (owner == Rollcount) {
				cout << Character[Rollcount].name << " landed on a their own property, they're safe!" << endl;
			} else {
				cout << "Oh no! " << Character[Rollcount].name << " landed on " <<  Character[owner].name << "'s property!" << endl;
				if (Character[Rollcount].BankBalance < p[Character[Rollcount].position].rent){
					cout << Character[Rollcount].name << " can't afford to pay rent! :(" << endl;
					this_thread::sleep_for(2000ms);
					bankrupt(Rollcount, owner);
				}
				else {
					cout << Character[Rollcount].name << " pays $" << p[Character[Rollcount].position].rent << "M in rent to " << Character[owner].name << endl;
					Character[Rollcount].BankBalance -= p[Character[Rollcount].position].rent;
					Character[owner].BankBalance += p[Character[Rollcount].position].rent;
					return;
				}
			}
		}
	}
}


//what it does: Runs main functionality of the game, calls other functions
//inputs: none
//output: no output
int main(){
    for (int i = 0; i < 14; i++){
    	p[i].rent = p[i].price/5;
    }
    int numberofplayers = 0;
    cout << "---Welcome to monopoly! ( special edition )---" << endl;
    cout << "-----------------------------Settings-----------------------------" << endl;
    int PvPcorrectness = 0;
    string PvP = "temp";
    while (PvPcorrectness == 0){
        PvPcheck(PvP, PvPcorrectness);
    }
    string PvE;
    int BotNo = 0;
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
    string Symbols = "~@#%^&<>";
    int temp;
    int Start$ = 1500;
    if (PvP == "yes"){
        for (int i = 1; i <= PlayerNo; i++){
	    Character[numberofplayers] = {"P" + to_string(i), PawnSelect(i, Symbols, numberofplayers) , Start$, 0, false};
	    numberofplayers += 1;
	}
        if (PvE == "yes"){
            for (int j = 1; j <= BotNo; j++){
	    	temp = rand() % Symbols.length();
                Character[numberofplayers] = {"Bot" + to_string(j), Symbols.substr(temp,1), Start$, 0, true};
		p[0].visitors.replace(numberofplayers,1,Symbols.substr(temp,1));
		numberofplayers += 1;
		Symbols.erase(temp,1);
            }
        }
    } else{
        Character[numberofplayers] = {"P1", PawnSelect(1, Symbols, numberofplayers), Start$, 0, false};
	numberofplayers +=1;
        for (int a = 1; a <= BotNo; a++) {
	    temp = rand() % Symbols.length();
	    Character[numberofplayers] = {"Bot" + to_string(a), Symbols.substr(temp,1), Start$, 0, true};
            p[0].visitors.replace(numberofplayers,1,Symbols.substr(temp,1));
	    numberofplayers += 1;
	    Symbols.erase(temp,1);
        }
    }
	PrintBoard();
	PrintBalance(numberofplayers);
	int activeplayers = numberofplayers;
	string FinalRank[numberofplayers];
	bool GAMEOVER = false;
	int RollCount = 0;
	int RoundCount = 0;
	while (GAMEOVER == false){
		if (Character[RollCount].bankrupt == false){
			turnsequence(numberofplayers, RollCount);
			PrintBalance(numberofplayers);
			this_thread::sleep_for(5000ms);
			if (Character[RollCount].bankrupt == true) {
				activeplayers -= 1;
				FinalRank[activeplayers] = Character[RollCount].name;
			}
		}
		if (RollCount == numberofplayers -1){
			RoundCount += 1;
		}
		RollCount = (RollCount + 1) % numberofplayers;
		GAMEOVER = gameover(activeplayers, RollCount, RoundCount);
	}
	cout << "--------------------GAME OVER--------------------" << endl;
	playerdata tempdata;
    	for (int i = 0; i < numberofplayers - 1; i++){
        	for (int j = 0; j < numberofplayers - i - 1; j++){
        		if (Character[j].BankBalance < Character[j+1].BankBalance){
	    			tempdata = Character[j];
				Character[j] = Character[j+1];
				Character[j+1] = tempdata;
			}
		}
	}
	string Awards[4] = {"1st", "2nd", "3rd", "4th"};
	for (int i = 0; i < numberofplayers; i++) {
		if (Character[i].bankrupt == true){
			cout << Awards[i] << " place: " << FinalRank[i] << endl;
		}else{
			cout << Awards[i] << " place: " << Character[i].name << endl;
		}
	}
}
