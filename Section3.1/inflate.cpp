/*
ID: s3yoonpark
LANG: C++
PROB: inflate
*/ 

#include <bits/stdc++.h> 
using namespace std;

const int mxM = 1e4, mxN = 1e4; 
int M, N; 
int category[mxN][2]; 
int dp[mxM+1];

int main() {
	freopen("inflate.in", "r", stdin); 
	freopen("inflate.out", "w", stdout); 

	cin >> M >> N; 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2; ++j) cin >> category[i][j]; 
	}	
	
	// let dp[n] = maximum amount of points with n minutes
	for (int i = 1; i <= M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (category[j][1] <= i) {
				dp[i] = max(dp[i], dp[i-category[j][1]] + category[j][0]); 
			}
		}
	}	
	cout << dp[M] << '\n'; 	

	return 0; 
}
