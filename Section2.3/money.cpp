/*
ID: s3yoonpark
LANG: C++ 
PROB: money
*/ 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

ll V, N; 
ll coins[25]; 
ll dp[10001]; 

int main() {
	ifstream cin("money.in"); 
	ofstream cout("money.out"); 
	cin >> V >> N; 	
	for (int i = 0; i < V; ++i) cin >> coins[i]; 
	// let dp[n] contain the number of ways to form n 
	dp[0] = 1; 
	for (int i = 0; i < V; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (coins[i] <= j) {
				dp[j] += dp[j-coins[i]]; 
			}
		}
	}
	cout << dp[N] << '\n'; 

	return 0; 
}
