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


int main() {
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


