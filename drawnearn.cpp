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



int main() {
	srand(time(nullptr));
	playerdata Character[4] = { {"B1", "A", 15000,1, true}, {"B2", "B",15000,1,true}, {"B3", "B",15000,1,true}, {"B4", "",15000,1,true} };
	cout << "Random Draw time! " << endl;
	cout << "Draw a number! And the larger is your number among you guys, the greater you will earn! " << endl;
	for (int i = 0; i < sizeof(Character) / sizeof(Character[0]); i++) {
		cout << "--------------------------------" << endl;
		cout << Character[i].name << "'s turn! " << endl;
		for (int i = 0; i < 500; i++) {
			dgnumbank.push_back(i);
		}
		string temp = to_string(i);
		dgdrawnum();
		
	}
	sort(oplist.begin(), oplist.end());
	for (int i = 0; i < oplist.size(); i++) {
		for (int j = 0; j < scorelist.size(); j++) {
			if (scorelist[j] == oplist[i]) {
				Character[i].BankBalance += i * 50;
			}
		}
	}
	cout << "----------------" << endl;
	cout << "The current balance: " << endl;
	cout << "----------------" << endl;
	cout << "|Name | Balance|" << endl;
	for (int i = 0; i < sizeof(Character) / sizeof(Character[0]); i++) {
		cout << "|" << Character[i].name << "   |  " << Character[i].BankBalance << " |" << endl;
	}
	cout << "----------------" << endl;
	return 0;
	}
