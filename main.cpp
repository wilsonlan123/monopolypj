#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "Minigame.h"
using namespace std;

struct square{
	string title;
	int price;
	string owner;
	string visitors;
};

square p[14] = { { "Start", -500, "     ", "     "},
		{ "$250M", 250, "     ", "     "},
		{ "$300M", 300, "     ", "     "},
		{ "Empty", 0, "     ", "     "},
		{ "$250M", 250, "     ", "     "},
		{ "$250M", 250, "     ", "     "},
		{ "Empty", 0, "     ", "     "},
		{ "$500M", 500, "     ", "     "},
		{ "$150M", 150, "     ", "     "},
		{ "$150M", 150, "     ", "     "},
		{ "Empty", 0, "     ", "     "},
		{ "$100M", 100, "     ", "     "},
		{ "$50M", 50, "     ", "     "},
		{ "$100M", 100, "     ", "     "}};
		
//below is a suggested structure to record the data of the players/bots to replace the current map variable (Oscar)
struct playerdata{
	string name;
	int number;
	char pawn;
	int BankBalance;
	int position;
};

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

int Rolladice (int numberofplayers,int &Rollcount){
    srand(time(0));
    int dice = rand() % 6 + 1;
    if (Rollcount % numberofplayers == 0){
        //play a minigame
    }
    Rollcount += 1;
    return dice;
}

void PrintBoard() {
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
	cout << "|" << p[4].owner << "|   |" << p[3].owner << "|   |" << p[2].owner << "|   |" << p[1].owner << "|   |" << p[0].owner << "|" << "   <----- Get $500M" << endl;
	cout << "|" << p[4].visitors << "|   |" << p[3].visitors << "|   |" << p[2].visitors << "|   |" << p[1].visitors << "|   |" << p[0].visitors << "|" << "    each time passing Start" << endl;
	cout << "-------   -------   -------   -------   -------" << endl << endl;
}

void PrintBalance(map<string, int> Characters) {
	  map<string, int>::iterator it = Characters.begin();
	  while (it != Characters.end()){
    		cout  << it->first << " Bank Balance = "  << it->second << endl;
    		++it;
	}
}

int main(){
    int numberofplayers = 0;
    int Rollcount = 0;
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
    int temp;
    if (PvP == "yes"){
        numberofplayers += PlayerNo;
        for (int i = 1; i <= PlayerNo; i++){
            cout << "Player " << i <<  " select your pawn:" << endl;
	    for (int k = 1; k <= Symbols.length(); k++){
                 cout << k << ":" << Symbols[k-1] << "   ";
            }
            cout << endl;
            cin >> temp;
	    while (temp > Symbols.length() || temp < 1) {
                 cout << "Invalid input" << endl;
		 cin >> temp;
	    }
	    Characters["Player" + to_string(i) + " " + Symbols[temp-1]] = 1500;
	    Symbols.erase(temp-1,1);
	}
        if (PvE == "yes"){
            numberofplayers += BotNo;
            for (int j = 1; j <= BotNo; j++){
	    	temp = rand() % Symbols.length() + 1;
                Characters["Bot" + to_string(j) + " " + Symbols[temp-1]] = 1500;
		Symbols.erase(temp-1,1);
            }
        }
    } else{
        numberofplayers = numberofplayers + 1 +BotNo;
        Characters["Player"] = 1500;
        for (int a = 1; a <= BotNo; a++) {
	    temp = rand() % Symbols.length() + 1;
            Characters["Bot" + to_string(a) + " " + Symbols[temp-1]] = 1500;
	    Symbols.erase(temp-1,1);
        }
    }
    cout << "------------------------------------------------------------------" << endl;
	PrintBoard();
	PrintBalance(Characters);
}
