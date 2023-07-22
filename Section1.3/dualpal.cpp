/*
ID: s3yoonpark
LANG: C++ 
PROB: dualpal
*/ 

#include <bits/stdc++.h> 

using namespace std; 

string v = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

string convert(int n, int b) {
	int t = floor(log(n) / log(b)) + 1; 
	string s = string(t, '0'); 

	while (1) {
		int i = floor(log(n) / log(b)) + 1; 
		int a = pow(b, i-1); 
		s[s.length()-i] = v[n/a];  
		n -= a * (n/a); 
		if (!n) break; 
	}
	return s; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	ifstream cin("dualpal.in"); 
	ofstream cout("dualpal.out"); 

	int n, s;
	cin >> n >> s; 

	for (int i = s+1; n != 0; ++i) {
		int cnt = 0; 
		for (int b = 2; b <= 10; ++b) {
			string s = convert(i, b); 
			string r (s.rbegin(), s.rend()); 
			if (s == r) {
				++cnt; 
			}
		}
		if (cnt >= 2) {
			cout << i << "\n"; 
			--n; 
		}
	}

	return 0;
}
