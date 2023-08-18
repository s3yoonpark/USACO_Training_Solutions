/*
ID: s3yoonpark
LANG: C++
PROB: msquare
*/ 

#include <iostream> 
#include <cassert> 
#include <vector> 
#include <map> 
#include <queue> 
#include <unordered_set> 
using namespace std;

vector<vector<int>> initial = {{1,2,3,4}, {8,7,6,5}};  
vector<vector<int>> target(2, vector<int>(4)); 
vector<char> option = {'A', 'B', 'C'}; 

map<string, vector<vector<int>>> mp; 
unordered_set<string> vis; 

vector<vector<int>> modify(vector<vector<int>>& curS, char c) {
	vector<vector<int>> cpy (curS.begin(), curS.end()); 
	if (c == 'A') {
		swap(cpy[0], cpy[1]); 	
	} else if (c == 'B') {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 4; ++j) {
				int ind = j-1; 
				if (ind < 0) ind += 4; 
				cpy[i][j] = curS[i][ind]; 
			}
		}
	} else if (c == 'C') {
		cpy[0][1] = curS[1][1]; 
		cpy[0][2] = curS[0][1]; 
		cpy[1][1] = curS[1][2]; 
		cpy[1][2] = curS[0][2]; 
	}
	return cpy; 
}

string convert(vector<vector<int>>& v) {
	string res = ""; 
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			res += to_string(v[i][j]) + ' ';
		}
	}
	return res; 
}

bool equal(vector<vector<int>>& v) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (v[i][j] != target[i][j]) return false; 
		}
	}
	return true; 
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	//freopen("msquare.in", "r", stdin); 
	//freopen("msquare.out", "w", stdout); 
	for (int j = 0; j < 4; ++j) cin >> target[0][j]; 	
	for (int j = 3; j >= 0; --j) cin >> target[1][j]; 

	queue<string> q; 
	q.push(""); 
	mp[""] = initial; 
	while (!q.empty()) {
		string curT = q.front(); q.pop(); 
		vector<vector<int>> curS = mp[curT]; 
		if (vis.count(convert(curS))) continue; 
		vis.insert(convert(curS)); 
		if (equal(mp[curT])) {
			cout << (int)curT.length() << '\n'; 
			for (int i = 0; i < (int)curT.length(); ++i) {
				if (i % 60 == 59) cout << curT[i] << '\n'; 
				else cout << curT[i]; 
			}
			cout << '\n'; 
			break; 
		}
		for (char& i : option) {
			mp[curT+i] = modify(curS, i); 
			q.push(curT+i); 
		}
	}

	return 0; 
}
