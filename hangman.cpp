#include<iostream>      
#include<list>
#include<vector>
#include<random>
#include<map>
#include<string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
vector<string> hmwordbank{ "INDEX", "MOUSE", "FALSE", "ABORT", "LINES","CLOSE","INPUT", "FLASH", "IMAGE", "BEGIN", "STACK", "LOGIC","CYBER","FIELD","QUERY" };

int chances = 8; // maybe we can lower it 
vector<char> hmdisplay{ '_','_','_','_','_' };//list of display 
vector<char> hmanslist;	// list of ans 
bool hmwin = false;




int errorchecking(vector<int> w) { // for loop for vectors to print out the guess or current or ans 
	if (hmwin == true) {
		for (auto it = w.begin(); it != w.end(); ++it) {
			cout << *it;

		}
		return 0;
	}
	cout << "Current: ";
	for (auto it = w.begin(); it != w.end(); ++it) {
		cout << *it;
	}
	cout << endl;
	return 1;
}

int hmfloop(vector<char> w) { // for loop for vectors to print out the guess or current or ans 
	if (hmwin == true) {
		for (auto it = w.begin(); it != w.end(); ++it) {
			cout << *it;

		}
		return 0;
	}
	cout << "Current: ";
	for (auto it = w.begin(); it != w.end(); ++it) {
		cout << *it;
	}
	cout << endl;
	return 1;
}
vector<char> hmveclean() { //cleaning the vectors 
	hmdisplay.clear();
	for (int i = 0; i < 5; i++) {
		hmdisplay.push_back('_');
	}
	return hmdisplay;
}
char toUppercase(char a) { // change a char into 
	if (a >= 'a' && a <= 'z') {
		a -= 32;
		return a;
	}
	if (a >= 'A' && a <= 'Z') {
		return a;
	}
	else{
		return ' ';}
}

bool hmcheck() {
	bool flag = true;
	for (int i = 0; i < 5; i++) {
		if (hmdisplay[i] != hmanslist[i]) {
			flag = false;
			return flag;
		}
	}
	hmwin = true;
	return flag;
}
bool hmguess(vector<char> ans, char input) { //check whether the guess is correct 
	bool hmflag = false;
	for (int i = 0; i < 5; i++) {
		char temp = ans[i];
		if (input == ans[i]) {
			hmdisplay[i] = ans[i];
			hmflag = true;
			if (hmcheck() == true) {
				cout << "You win. " << endl;
				cout << "The answer is ";
				hmfloop(hmdisplay);
				cout << endl;
				return hmflag;
			}
			//else if(check() == true && chances == 0)  {
			//	cout << "You lose. ";
			//	cout << "The answer is ";
			//	floop(display);
			//	cout << endl;
			//}
			break;
		}
	}

	hmfloop(hmdisplay);
	if (hmflag == false) {
		cout << "Incorrect" << endl;
		chances -= 1;
		cout << "You have " << chances << " chances left. " << endl;
	}
	return hmflag;
}
int phangman() { // hangman for human
	hmveclean();
	chances = 8;
	hmwin = false;
	int random = rand() % hmwordbank.size();
	string ans = hmwordbank[random];
	hmanslist.clear();
	hmfloop(hmdisplay);
	for (int i = 0; i < 5; i++) {
		char temp = ans[i];
		hmanslist.push_back(temp);
	}
	while (chances > 0 && hmwin == false) {
		cout << "Please guess a letter: ";
		char input;
		cin >> input;
		if (isalpha(input) == true){
			input = toUppercase(input);
			hmguess(hmanslist, input);
		}else{
			cout << "Invalid Input "<<endl;
	
		}
	}
	//player_scoremap[] = chances; // put player into this function then include its value into here
	return chances;


}
int bhangman() { // hangman for bot 
	chances = 8;
	hmwin = false;
	vector<char> hmguessbank{ 'A','B','C','D','E','F','G','H','J','K','L','M','N','O','P','Q','R','S','T'};
	int hmrandom = rand() % hmwordbank.size();
	hmanslist.clear();
	string ans = hmwordbank[hmrandom];
	hmwin = false;
	hmveclean();
	hmfloop(hmdisplay);
	for (int i = 0; i < 5; i++) {
		char temp = ans[i];
		hmanslist.push_back(temp);
	}
	int hmrandom2 = rand() % hmwordbank.size();
	string randguess = hmwordbank[hmrandom2];
	for (int i = 0; i < 5; i++) { //ok
		char temp = randguess[i];
		hmguessbank.push_back(temp);
	}
	while (chances > 0 && hmwin == false) {
		cout << "Please guess a letter: ";
		char input;
		int hmrandom3 = rand() % hmguessbank.size();
		input = hmguessbank[hmrandom3];
		input = toUppercase(input);
		cout << input << endl;
		hmguess(hmanslist, input);
		hmguessbank.erase(remove(hmguessbank.begin(), hmguessbank.end(), input), hmguessbank.end());
	}
	if (hmwin == false && chances == 0) {
		cout << "You lose " << endl;
	}
	return chances;
}


vector<int> hangman(int size) {
	vector<int> rank;
	vector<int> chancelist;
	vector<int> hmoplist;
	srand(time(nullptr));
	cout << "Wordle time! " << endl;
	cout << "You have to guess a five letters word. \nEvery chances you left unused will be converted to a hundred! " << endl;
	for (int i = 0; i < size; i++) {
		cout << "-----------------------------------------------------------------------------------------" << endl;
		cout << "Player "<< i << "'s turn! " << endl;
		cout << "Is player " << i << " NPC?(y/n) " << endl;
		string npc;
		cin >> npc;
		if (npc == "y") {
			int temp = bhangman();
			chancelist.push_back(temp);
			hmoplist.push_back(temp);
		}else {
			int temp = phangman();
			chancelist.push_back(temp);
			hmoplist.push_back(temp);		
		}
		if (hmwin == true) {
			cout << "Player "<< i << " wins with " << chances << " chances left! " << endl;
		}
	}
	//cout << errorchecking(chancelist);
	//cout << "----------------" << endl;
	///cout << "The current balance: "<<endl;
	//cout << "----------------"<< endl;
	//cout << "|Name | Balance|" << endl;
	//for (int i = 0; i < sizeof(Character) / sizeof(Character[0]); i++) {
	//	cout << "|" << Character[i].name << "   |  " << Character[i].BankBalance << " |" << endl;
	//}
	//cout << "----------------" << endl;
	for (int i = 0; i < hmoplist.size(); i++) {
	for (int j = 0; j < chancelist.size(); j++) {
		if (chancelist[j] == hmoplist[i]) {
			rank.push_back(j);
			}
		}
	}
	return rank;
	}


