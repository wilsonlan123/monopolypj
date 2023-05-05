#include<iostream>
#include<list>
#include<vector>
#include<random>
#include<map>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> scorelist;
vector<int> oplist;

struct playerdata {
	string name;
	string pawn;
	int BankBalance;
	int position;
	bool NPC;
};

int hmfloop(vector<int> w) { // for loop for vectors to print out the guess or current or ans 
	cout << "Current: ";
	for (auto it = w.begin(); it != w.end(); ++it) {
		cout << *it ;
	}
	cout << endl;
	return 1;
}
vector<int> dgnumbank;
map<string, int>player_scoremap;
void dgdrawnum() {
	cout << "Time to draw! " << endl;
	int dgrandom = rand() % dgnumbank.size();

	int score = dgnumbank[dgrandom];
	cout << "The drawn number is " << dgnumbank[dgrandom] << endl;
	scorelist.push_back(score);
	oplist.push_back(score);
}



vector<int> drawnearn(int size) {
	vector<int> rank;
	srand(time(nullptr));
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Random Draw time! " << endl;
	cout << "Draw a number! And the larger is your number among you guys, the greater you will earn! " << endl;
	for (int i = 0; i < size; i++) {
		cout << "--------------------------------" << endl;
		cout << "Player "<< i << "'s turn! " << endl;
		for (int i = 0; i < 500; i++) {
			dgnumbank.push_back(i);
		}
		string temp = to_string(i);
		dgdrawnum();
		
	}
	sort(oplist.begin(), oplist.end(),greater<>());
	
	for (int i = 0; i < oplist.size(); i++) {
		for (int j = 0; j < scorelist.size(); j++) {
			if (scorelist[j] == oplist[i]) {
				rank.push_back(j);
			}
		}
	}
	//cout << "----------------" << endl;
	//cout << "The current balance: " << endl;
	//cout << "----------------" << endl;
	//cout << "|Name | Balance|" << endl;
	//for (int i = 0; i < sizeof(Character) / sizeof(Character[0]); i++) {
		//cout << "|" << Character[i].name << "   |  " << Character[i].BankBalance << " |" << endl;
	//}
	//cout << "----------------" << endl;
	cout << "End of game"  << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;

	return rank;
	}
