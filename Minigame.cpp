

 
  
void rolling_dice(int pdice, vector<int>& plst) { //function to generate a vector of random dice
    plst.clear();
    for (int i = 0; i < pdice; i++) {
        int roll = rand() % 6 + 1;
        plst.push_back(roll);
    }
    return;}

int check_number(int choice, vector<int> plst, int pdice) { //function to check whether or not players' guess is in list of dice
    int number_of_dulplicate = 0;
    for (int j : plst) {
        if (j == choice) {
            number_of_dulplicate++;
        }
    }
    cout << "You got " << number_of_dulplicate << " dice correct." << endl;
    return number_of_dulplicate;
    }

void dice_rolling(string player1, string player2){//MiniGame Rolling Dice
int choice = 0;
    cout << "========================================================================================" << endl;
    cout<< "Welcome to Mini-Game: Rolling dice"<<endl;
    cout<<"In this game, both players have 5 dices initially."<<endl;
    cout<<"Both players take turn to take a guess between number from 1 to 6"<<endl;
    cout<<"A correct guess allows players to eliminate the number from its dice"<<endl;
    cout<<"For example, Player 1 has 5 dices, he takes a guess of 3, fortunately, dice are [1,3,4,2,3] after the round."<<endl;
    cout<<"His dice become [1,4,2] after eliminating 3"<<endl;
    cout<<endl;
    cout<<"Player with 0 dice left will win the game"<<endl;
    cout<<"GAME BEGINS NOW!"<<endl;
    cout<<"Lets go!"<<endl;
    cout<<endl;
   
    vector<int> p1lst;
    vector<int> p2lst;
    int p1dice = 5;
    int p2dice = 5;
    rolling_dice(p1dice, p1lst);
    rolling_dice(p2dice, p2lst);
    bool p1turn = true;
    int a =0;
    int b= 0;
    while (true) {
        if (p1turn) {
            while (true) {
                cout<<"Now is "<<player1<<"'s turn!"<<endl;
                cout << "Number of dice of " << player1 << "= " << p1dice << endl;
                if (player1 == "Bot1" || player1 == "Bot2" || player1 == "Bot3") {
                    choice = rand() % 6 + 1;
                    std::cout << player1 << ", guess a number from your dice: " << choice << std::endl;}
                else{
                    cout << player1 << ", guess a number from your dice: ";
                    cin >> choice;}
                if ((choice<1)||(choice>6)){
                    cout<<"Error: invalid input."<<endl;
                    continue;}
                else{
                    break;
                }}
            rolling_dice(p1dice, p1lst);
            cout << "Dice are : " ;
            for (int i=0;i<p1lst.size();i++){
                cout<<p1lst[i]<<"  ";
            }
            cout << endl;
            a = check_number(choice, p1lst, p1dice);
            p1dice -= a;
            cout << "Number of dice of " << player1 << "= " << p1dice << endl;
            cout<<endl;
            p1turn = !p1turn;}
        else{
            while (true) {
                cout<<"Now is "<<player2<<"'s turn!"<<endl;

                cout << "Number of dice of " << player2 << "= " << p1dice << endl;
                if (player2 == "Bot1" || player2 == "Bot2" || player2 == "Bot3") {
                    choice = rand() % 6 + 1;
                    cout << player2 << ", guess a number from your dice: " << choice << endl;}
                else{
                    cout << player2 << ", guess a number from your dice: ";
                    cin >> choice;}
                if ((choice<1)||(choice>6)){
                    cout<<"Error: invalid input."<<endl;
                    continue;}
                else{
                    break;
                }}
        rolling_dice(p2dice, p2lst);
        cout << "Dice are : " ;
        for (int i=0;i<p2lst.size();i++){
                cout<<p2lst[i]<<"  ";
            }
        cout << endl;
        b = check_number(choice, p2lst, p2dice);
        p2dice -= b;
        cout << "Number of dice of " << player2 << "= " << p2dice << endl;
        cout<<endl;
        p1turn = !p1turn;}
    if (p1dice <= 0) {
        cout << "Winner is " << player1 << " ! Congratulations!\n";
        cout << "You win 500m!"<<endl;
        Characters[player1] += 500;
        Characters[player2] -= 500;
        break;
    }
    else if (p2dice <= 0) {
        cout << "Winner is " << player2 << " ! Congratulations!\n";
        cout << "You win 500m!"<<endl;
        Characters[player2] += 500;
        Characters[player1] -= 500;
        break;
    }
    return ;
}}
    

bool test_number(int a,int choice,int numrange[]){ //function used to update numrange used in One In A Hundred
    if (choice>a){
        numrange[1] = choice;
        cout << "Guess a number between "<<numrange[0] << " to "<< numrange[1]<<endl;
        return true;
    }
    else if(choice<a){
        numrange[0] = choice;
        cout << "Guess a number between "<<numrange[0] << " to "<< numrange[1]<<endl;
        return true;}
    else {
        return false;
    }}

void one_in_a_hundred(string player1, string player2){//MiniGame One In A Hundred
    int turn = 0;
    bool p1turn = true;
    int choice = 0;
    string players[] = {player1,player2};
    int a =  rand() % 100; // this is the winning number
    int numrange[] = {0,100};
    cout<<"Welcome to Mini Game: <One in a hundred>"<<endl;
    cout<<"In this game, you are going to keep guessing a number until you guessed the correct GOLDEN NUMBER"<<endl;
    cout<<"You will be given the range of the number before every guess, and the range will become smaller each time a guess is made."<<endl;
    cout<<"Winner will be rewarded 500m!"<<endl;
    cout<<"ALL THE BEST!"<<endl;
    cout<<"Let's go!"<<endl;
    cout << "Guess a number between "<< numrange[0] << " to " << numrange[1] << endl;


        while (true) {

            if (p1turn) {
                while (true){
                    if (player1 == "Bot1" || player1 == "Bot2" || player1 == "Bot3") {
                        choice = rand() % (numrange[1] - numrange[0] + 1) + numrange[0];
                        cout << player1 << ", choose a number: " << choice << endl;}
                    else {
                        cout << player1 << ", choose a number: ";
                        cin >> choice;}
                    if ((choice<numrange[0])||(choice>numrange[1]))
                        {cout << "Error: invalid input" << endl;
                        continue;}
                    else{
                        break;}}
                test_number(a, choice, numrange);
                turn = turn + 1;
                if (p1turn==true){p1turn = false;}
                else {p1turn = true;}}
            else{
                while (true){
                    if (player2 == "Bot1" || player2 == "Bot2" || player2 == "Bot3") {
                        choice = rand() % (numrange[1] - numrange[0] + 1) + numrange[0];
                        cout << player2 << ", choose a number: " << choice << endl;}
                    else{
                        cout << player2 << ", choose a number: ";
                        cin >> choice;}
                    if ((choice<numrange[0])||(choice>numrange[1])){
                        cout<<"Error: invalid input" << endl;
                        continue;}
                    else{
                        break;}}
                test_number(a, choice, numrange);
                turn = turn + 1;
                if (p1turn==true){p1turn = false;}
                else {p1turn = true;}}
            if (choice == a){
                break;}
            }
        cout<<"Winner is ..."<<players[(turn+1)%2]<<endl;
        cout<<"Congratulations! You win 500m!"<<endl;
        
   Characters[players[(turn+1)%2]] += 500
   Characters[players[(turn)%2]] -= 500 
   }

#include<iostream>      // drawnum game earn by how large they random 
#include<list>
#include<vector>
#include<random>
#include<map>
#include<string>
using namespace std;

vector<int> dgnumbank;
map<string, int>player_scoremap;
void dgdrawnum(string i) {
	cout << "Time to draw! " << endl;
	int dgrandom = rand() % numbank.size();

	int score = numbank[dgrandom];
	cout << "The drawn number is " << numbank[dgrandom] << endl;
	player_scoremap.insert({ i,score });
}


int drawingnumber() {
	cout << "The drawing number game. The larger number you can draw, the more you can get! " << endl;
	for (int i = 0; i < 500; i++) {
		dgnumbank.push_back(i);
	}
	for (int i = 0; i < 6; i++) {
		string temp = to_string(i);
		dgdrawnum(temp);
	}
	return 0;

}

#include<iostream> //hangman game 
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

