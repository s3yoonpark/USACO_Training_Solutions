/*
ID: s3yoonpark
LANG: C++
PROB: palsquare
*/ 

#include <bits/stdc++.h> 

using namespace std; 


string r = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

string convert(int t, int b) {
	int n = floor(log(t) / log(b)) + 1; 
	string s = string(n, '0'); 
	while (1) {
		n = floor(log(t) / log(b)) + 1; 	
		int temp = pow(b, n-1); 
		s[s.length() - n] = r[t/temp]; 
		t -= temp * (t/temp); 
		if (!t) break; 	
	}
	return s; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	ifstream cin("palsquare.in"); 
	ofstream cout("palsquare.out"); 

	int b; 
	cin >> b; 
	

	for (int i = 1; i <= 300; ++i) {
		// work out how many digits are required
		string s = convert(pow(i, 2), b); 	
		string s2 = convert(i, b); 	
		string temp (s.rbegin(), s.rend())  ; 
		if (s == temp) {
			cout << s2 << " " << s << "\n"; 
		}
	}

	return 0; 
}
