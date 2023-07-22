/*
ID: s3yoonpark
LANG: C++ 
PROB: pprime
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int A, B; 
set<int> s; 

void f(string tmp, int t, int n) {
	if (!t) {
		int v = tmp.length(); 
		if (n%2 == 1) {
			for (int i = v-2; i >= 0; --i) {
				tmp += tmp[i];
			}
		} else {
			for (int i = v-1; i >= 0; --i) {
				tmp += tmp[i]; 
			}
		}
		int z = stoi(tmp); 
		if (!(z >= A && z <= B)) return; 
		bool prime = 1; 
		for (int i = 2; i*i <= z && prime; ++i) {
			if (z%i == 0) prime = 0; 
		}
		if (z == 1) prime = 0;
		if (prime) s.insert(z); 
		return; 
	}
	
	int start = 0; 
	if (tmp.length() == 0) start = 1; 
	for (int i = start; i <= 9; ++i) {
		f(tmp+(char)(i+'0'), t-1, n); 
	}
	return; 
}

void gen(int n) {
	// generates palindromes 
	// ceil(n/2) for loops required 
	// use recursion to simulate general case 
	f("", ceil(n/2.0), n); 
	return; 
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	ifstream cin("pprime.in"); 
	ofstream cout("pprime.out"); 

	cin >> A >> B; 

	for (int i = to_string(A).length(); i <= to_string(B).length(); ++i) {
		gen(i); 
	}

	for (int i : s) cout << i << "\n"; 

	return 0; 
}
