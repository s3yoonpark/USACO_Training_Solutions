/*
ID: s3yoonpark
LANG: C++
PROB: msquare
*/ 

#include <bits/stdc++.h> 
using namespace std;

unordered_set<string> vis; 

string target; 

string tA(string& s) {
	return string() + s[4] + s[5] + s[6] + s[7] + s[0] + s[1] + s[2] + s[3]; 
}

string tB(string& s) {
	return string() + s[3] + s[0] + s[1] + s[2] + s[7] + s[4] + s[5] + s[6];  
}

string tC(string& s) {
	return string() + s[0] + s[5] + s[1] + s[3] + s[4] + s[6] + s[2] + s[7]; 
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	freopen("msquare.in", "r", stdin); 
	freopen("msquare.out", "w", stdout); 
	for (int j = 0; j < 4; ++j) {
		char c; 
		cin >> c; 
		target += c; 
	}	
	string t = "";
	for (int j = 0; j < 4; ++j) {
		char c; 
		cin >> c; 
		t += c; 
	}
	for (int j = 3; j >= 0; --j) target += t[j]; 

	queue<pair<string, string>> q; 
	q.push(make_pair("", "12348765")); 

	while (!q.empty()) {
		string curInstruction = q.front().first; 
		string curState = q.front().second; 
		q.pop(); 

		if (vis.count(curState)) continue; 
		vis.insert(curState); 

		if (curState == target) {
			cout << (int)curInstruction.length() << '\n'; 
			for (int i = 0; i < (int)curInstruction.length(); ++i) {
				if (i % 60 == 59) cout << curInstruction[i] << '\n'; 
				else cout << curInstruction[i]; 
			}
			cout << '\n'; 
			break; 
		}

		q.push(make_pair(curInstruction + 'A', tA(curState))); 
		q.push(make_pair(curInstruction + 'B', tB(curState))); 
		q.push(make_pair(curInstruction + 'C', tC(curState))); 
	}

	return 0; 
}
