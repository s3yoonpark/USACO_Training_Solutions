/*
ID: s3yoonpark
LANG: C++
PROB: subset
*/

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int N; 

ll dp[40][39*40/2+1]; 

// dp[x][y] -> the number ways of using first x numbers to make the sum of y

int main() {
	ifstream cin("subset.in"); 
	ofstream cout("subset.out"); 

	cin >> N; 
	int test = N*(N+1)/4; 
	if (test*4/(N+1) != N) {
		cout << 0 << '\n'; 
		return 0; 
	}
	for (int i = 0; i <= N; ++i) dp[i][0] = 1; 
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N*(N+1)/4; ++j) {
			dp[i][j] += dp[i-1][j]; 
			if (j >= i) dp[i][j] += dp[i-1][j-i]; 
		}
	}
	cout << dp[N][N*(N+1)/4]/2 << '\n'; 


	return 0; 
}
