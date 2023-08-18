/*
ID: s3yoonpark
LANG: C++
PROB: contact
*/ 

#include <iostream> 
#include <vector>
#include <unordered_map> 
#include <algorithm> 
using namespace std;

int A, B, N; 
string s, tmp; 
string t; 
const int mxN = 2*1e5; 

vector<string> ans; 
vector<string> freq[mxN+1];
unordered_map<string, int> mp; 

bool cmp(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b; 
	} else {
		return a.length() < b.length(); 
	}
}

int main() {
	freopen("contact.in", "r", stdin); 
	freopen("contact.out", "w", stdout); 
	cin >> A >> B >> N; 
	while (getline(cin, tmp)) {
		s += tmp; 
	}
	for (int i = A; i <= B; ++i) {
		for (int j = 0; j < (int)s.length()-i+1; ++j) {
			t = s.substr(j, i); 
			if (!mp[t]) {
				ans.push_back(t); 
			}
			++mp[t]; 
		}
	}
	for (string& v : ans) {
		freq[mp[v]].push_back(v); 	
	}
	for (int i = mxN; i >= 0; --i) {
		if ((int)freq[i].size()) {
			--N; 
			sort(freq[i].begin(), freq[i].end(), cmp); 
			cout << i << '\n'; 
			cout << freq[i][0]; 
			for (int j = 1; j < freq[i].size(); ++j) {
				if (j%6 == 0) {
					cout << '\n'; 
					cout << freq[i][j]; 
					continue; 
				}
				cout << ' ' << freq[i][j];  
			}
			cout << '\n'; 
		}
		if (!N) break; 
	}
	

	return 0; 
}
