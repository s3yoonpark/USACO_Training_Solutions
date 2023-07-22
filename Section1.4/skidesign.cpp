/*
ID: s3yoonpark
LANG: C++ 
PROB: skidesign
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int N;
int hills[1000]; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	ifstream cin("skidesign.in"); 
	ofstream cout("skidesign.out"); 

	cin >> N; 
	for (int i = 0; i < N; ++i) {
		cin >> hills[i]; 
	}
	
	int cost = INT_MAX; 
	for (int i = 0; i <= 83; ++i) {
		int j = i+17; 
		// minimum as i and maximum as j 
		int t = 0; 
		for (int k = 0; k < N; ++k) {
			if (j - hills[k] <= 17 && j-hills[k] >= 0) continue; 
			if (abs(hills[k]-i) < abs(hills[k]-j)) {
				t += abs(hills[k]-i) * abs(hills[k]-i); 
			} else {
				t += abs(hills[k]-j) * abs(hills[k]-j); 
			}
		}	
		cost = min(cost, t); 
	}
	cout << cost << "\n"; 

	return 0; 
}
