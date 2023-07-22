/*
ID: s3yoonpark
LANG: C++
PROB: runround
*/ 

#include <bits/stdc++.h> 
using namespace std;

typedef unsigned long long ull; 

ull M; 
string t = "";
bool found = 0; 

ifstream fin("runround.in"); 
ofstream fout("runround.out"); 

bool valid() {
	bool check[t.length()]; 
	memset(check, 0, sizeof(check)); 
	int ind = 0; 
	while (count(check, check+t.length(), 0)) {
		if (check[ind]) return false; 
		check[ind] = 1; 	
		ind += (t[ind]-'0')%(t.length()); 
		ind %= t.length(); 
	}	
	return ind == 0; 
}

void gen(int n) {
	if (t.length() == n) {
		if (valid() && stoull(t) > M) {
			fout << t << '\n'; 
			found = 1; 
		}
		return; 
	}

	for (int i = (t.length() == 0 ? 1 : 0); i <= 9; ++i) {
		if (!t.length() && !i) {
			continue; 
		}
		if (found) return; 
		if (count(t.begin(), t.end(), (char)(i+'0'))) continue; 
		t += (char)(i+'0'); 
		gen(n); 
		t = t.substr(0, t.length()-1);
	}	
	return; 
}

void solve() {
	int n = to_string(M).length(); 
	while (!found) {
		gen(n); 
		++n; 
	}
	return; 
}

int main() {
	fin >> M;	
	solve(); 

	return 0; 
}
