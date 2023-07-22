/*
ID: s3yoonpark
LANG: C++
PROB: prefix
*/ 

#include <bits/stdc++.h> 
using namespace std;

vector<string> primitives; 
string sequence = ""; 
bool dp[200001]; 
int ans = 0; 


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
	//cin >> sequence; 

	// let dp[n] denote 
	dp[0] = 1; 
	for (int i = 0; i <= sequence.length(); ++i) {
		if (dp[i]) ans = max(ans, i); 
		else continue; 
		for (string& s : primitives) {
			if (i+s.length() > sequence.length()) continue; 
			if (s == sequence.substr(i, s.length())) {
				dp[i+s.length()] = 1; 
			}
		}
	}

	cout << ans << '\n'; 


	return 0; 
}
