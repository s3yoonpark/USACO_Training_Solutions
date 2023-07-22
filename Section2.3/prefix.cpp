/*
ID: s3yoonpark
LANG: C++
PROB: prefix
*/ 

#include <bits/stdc++.h> 
using namespace std;

vector<string> primitives; 
string sequence = ""; 
bool vis[200000]; 
int ans = 0; 

void process(int i) {
	if (vis[i]) return; 
	vis[i] = 1; 
	ans = max(ans, i); 
	if (i == sequence.length()) return; 
	for (string& s : primitives) {
		if (i+s.length() > sequence.length()) continue; 
		if (s == sequence.substr(i, s.length())) {
			process(i+s.length()); 
		}
	}
}

int main() {
	ifstream cin("prefix.in"); 
	ofstream cout("prefix.out"); 
	string t; 	
	cin >> t; 
	while (t != ".") {
		primitives.push_back(t);
		cin >> t; 
	}
	string tmp; 
	while (cin >> tmp) {
		sequence += tmp; 
	}
	cin >> sequence; 
	process(0);
	cout << ans << '\n'; 


	return 0; 
}
