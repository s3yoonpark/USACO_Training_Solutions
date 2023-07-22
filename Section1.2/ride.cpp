/*
ID: s3yoonpark
LANG: C++
TASK: ride
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	ifstream fin("ride.in"); 
	ofstream fout("ride.out"); 

	int base = (int)('A'); 
	string group, comet; 
	fin >> group >> comet; 
	int g=1; int c=1;
	for (char i : group) {
		g *= ((int)i - base + 1); 
	}
	for (char i : comet) {
		c *= ((int)i - base + 1); 
	}
	g %= 47; 
	c %= 47; 
	if (g == c) {
		fout << "GO" << "\n"; 
	} else {
		fout << "STAY" << "\n"; 
	}

	return 0; 
}
