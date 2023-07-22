/*
ID: s3yoonpark
LANG: C++
PROB: nocows
*/ 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

int N, K; 
ll dp[201][101]; 
ll dp2[201][101]; 

int main() {
	ifstream cin("nocows.in"); 
	ofstream cout("nocows.out"); 
	cin >> N >> K; 
	// let dp[i][j] = # of ways to make a tree with i nodes and height j 
	// let dp2[i][j] = # of ways to make a tree with i nodes and height <= j
	
	dp[1][1] = 1; 
	for (int i = 1; i <= K; ++i) dp2[1][i] = 1; 

	for (int i = 3; i <= N; i+=2) {
		for (int j = 2; j <= K; ++j) {
			for (int k = 1; k <= i-2; k+=2) {
				dp[i][j] += dp[k][j-1] * dp2[i-1-k][j-2]; 
			}
			dp[i][j] *= 2; 
			for (int k = 1; k <= i-2; k+=2) {
				dp[i][j] += dp[k][j-1] * dp[i-1-k][j-1]; 
			}
			dp[i][j] %= 9901;
			dp2[i][j] = (dp2[i][j-1] + dp[i][j]) % 9901; 
		}
	}
	cout << dp[N][K] << '\n'; 
	

	return 0; 
}
