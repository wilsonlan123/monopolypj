//hangman game 
#include<iostream>      
#include<list>
#include<vector>
#include<random>
#include<map>
#include<string>
using namespace std;
vector<string> hmwordbank{ "INDEX", "MOUSE", "FALSE", "ABORT", "LINES","CLOSE","INPUT", "FLASH", "IMAGE", "BEGIN", "STACK", "LOGIC","CYBER","FIELD","QUERY" };
vector<char> hmguessbank{'B','C','D','E','A','K','M'};
map<string, int>hmplayer_scoremap;

int chances = 8; // maybe we can lower it 
vector<char> hmdisplay{ '_','_','_','_','_'};//list of display 
vector<char> hmanslist;	// list of ans 
bool hmwin = false;

int hmfloop(vector<char> w) { // for loop for vectors to print out the guess or current or ans 
	if (hmwin == true) {
		for (auto it = w.begin(); it != w.end(); ++it) {
			cout << *it;
			
		}
		return 0;
	}
	cout << "Current: ";
	for (auto it = w.begin(); it != w.end();++it) {
		cout << *it;
	}
	cout << endl;
	return 1;
}
vector<char> hmveclean() { //cleaning the vectors 
	hmdisplay.clear();
	for (int i =0; i<5;i++){
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
bool hmguess(vector<char> ans,char input){ //check whether the guess is correct 
	bool hmflag = false;
	list<char> hmguesslist;
	for (int i = 0; i < 5; i++) {
		char temp = ans[i];
		if (input ==ans[i] ) {
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
		chances -=1;
		cout << "You have " << chances << " chances left. " << endl;
	}
	return hmflag;
}
void phangman() { // hangman for human
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
		input = toUppercase(input);
		hmguess(hmanslist,input);
	}
	//player_scoremap[] = chances; // put player into this function then include its value into here
	


}
void bhangman() { // hangman for bot 
	chances = 8;
	hmwin = false;
	int hmrandom = rand() % hmwordbank.size();
	hmanslist.clear();
	string ans = hmwordbank[hmrandom];
	hmwin = false;
	hmveclean();
	hmfloop(hmdisplay);
	cout << "The answer is " << ans << endl;
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

	}
	if (hmwin == false && chances == 0) {
		cout << "You lose " << endl;
	}
}


int hangman() {
	int playernum = 4; // number of players  // Waiting for how to call those functions
	cout << "Wordle time! " << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Player 1's turn! " << endl;
	phangman();
	cout << "-----------------------------------------------------------------------------------------" << endl; 
	cout << "Bot 1's turn! " << endl;
	bhangman();
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Bot 2's turn! " << endl;
	bhangman();
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Bot 3's turn! " << endl;
	bhangman();
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Bot 4's turn! " << endl;
	bhangman();


}

