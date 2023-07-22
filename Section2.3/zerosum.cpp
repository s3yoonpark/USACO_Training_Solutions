/*
ID: s3yoonpark
LANG: C++
PROB: zerosum
*/ 

#include <bits/stdc++.h>
using namespace std;

int N; 
vector<string> ans; 
string n = ""; 

void gen(int c) {
	if (c == N) {
		// calculate
		int res = 0; 
		for (int i = 0; i < n.length(); i+=2) {
			int p = 0;
			for (int j = i+1; j < n.length(); j+=2) {
				if (n[j] == ' ') ++p; 
				else break; 
			}
			char sign = ' ';
			if (i == 0) sign = '+';
			for (int j = i-1; j >= 0; j -= 2) {
				if (n[j] != ' ') {
					sign = n[j]; 
					break; 
				}
			}
			if (sign == '-') res -= (n[i]-'0') * pow(10, p); 
			else res += (n[i] - '0') * pow(10, p); 
		}
		if (!res) {
			ans.push_back(n); 
		}
		return; 
	}
	for (int i = 0; i < 3; ++i) {
		if (i == 0) {
			// +
			n[2*c-1] = '+'; 
		} else if (i == 1) {
			// -
			n[2*c-1] = '-'; 			
		} else if (i == 2) {
			// ' ' 
			n[2*c-1] = ' '; 
		}
		gen(c+1); 
		n[2*c-1] = ' ';
	}
	return; 
}

int main() {
	ifstream cin("zerosum.in"); 
	ofstream cout("zerosum.out"); 
	
	cin >> N; 
	for (int i = 1; i <= N; ++i) {
		n += to_string(i) + " ";
	}
	n = n.substr(0, n.length()-1); 
	gen(1); 
	sort(ans.begin(), ans.end()); 
	for (string& s : ans) cout << s << '\n'; 

	return 0; 
}
