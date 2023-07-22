/*
ID: s3yoonpark
LANG: C++ 
PROB: numtri
*/ 

#include <bits/stdc++.h> 

using namespace std; 

const int mxN = 1000; 
int R; 
int triangle[mxN][mxN];
int dp[mxN][mxN]; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	ifstream cin("numtri.in"); 
	ofstream cout("numtri.out"); 
	
	cin >> R; 
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < i+1; ++j) {
			cin >> triangle[i][j]; 
		}
	}
	memcpy(dp, triangle, sizeof(triangle)); 
	
	int ans = dp[0][0]; 
	for (int i = 1; i < R; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0) {
				// boundary 
				dp[i][j] += dp[i-1][j]; 
			} else if (j == i) {
				// boundary 
				dp[i][j] += dp[i-1][j-1]; 
			} else {
				dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]); 
			}
			
			if (i == R-1) {
				// last row 
				ans = max(ans, dp[i][j]); 
			}
		}
	}
	
	cout << ans << "\n"; 

	return 0; 
}
