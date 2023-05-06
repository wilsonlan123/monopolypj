#include<iostream>      
#include<list>
#include<vector>
#include<random>
#include<map>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

int errorchecking(vector<int> w);
vector<char> hmveclean();
char toUppercase(char a);
int hmfloop(vector<char> w);
bool hmguess(vector<char> ans, char input);
int phangman();
int bhangman();
vector<int> hangman(int size, playerdata c[4]);

