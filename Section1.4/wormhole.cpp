/*
ID: s3yoonpark
LANG: C++ 
PROB: wormhole
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int n, x[13], y[13], partner[13];
int next_on_right[13]; 

bool cycle() {
	for (int i = 1; i <= n; ++i) {
		// bruteforcing the starting point of wormholes 
		int pos = i; 	
		for (int j = 1; j <= n; ++j) {
			pos = next_on_right[partner[pos]]; 
		}
		if (pos != 0) return true; 
	}	
	return false; 
}

int solve() {
	// find the first unpaired wormhole 
	// let the pair wormhole of wormhole i be partner[i]
	int total = 0; 
	int i;
	for (i = 1; i <= n; ++i) {
		if (partner[i] == 0) break; 		
	}
	if (i > n) {
		// all paired
		if (cycle()) return 1;	
		else return 0;
	}

	for (int j = i+1; j <= n; ++j) {
		if (partner[j] == 0) {
			// attempt to pair wormhole i and j 
			partner[i] = j; 
			partner[j] = i; 
			total += solve(); 
			partner[i] = partner[j] = 0; 
		}
	}

	return total; 
}

int main() {
	ifstream cin("wormhole.in"); 
	ofstream cout("wormhole.out"); 
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i]; 
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (x[j] > x[i] && y[i] == y[j]) {
				if (next_on_right[i] == 0 || x[j] - x[i] < x[next_on_right[i]] - x[i]) {
					next_on_right[i] = j; 
				}
			}
		}
	}
	cout << solve() << "\n"; 

	return 0; 
}
