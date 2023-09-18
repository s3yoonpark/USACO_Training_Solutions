/*
ID: s3yoonpark
LANG: C++
PROB: range
*/ 

#include <iostream> 
using namespace std;

const int mxN = 250; 
int n; 
int cnt[mxN+1]; 
int dp[mxN][mxN];
bool field[mxN][mxN]; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	freopen("range.in", "r", stdin); 
	freopen("range.out", "w", stdout); 

	cin >> n; 	

	string s; 
	for (int i = 0; i < n; ++i) {
		cin >> s; 
		for (int j = 0; j < n; ++j) {
			field[i][j] = s[j] - '0'; 			
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			//cout << i << ' ' << j << '\n'; 
			int a = 0, b = 0, c = 0; 
			if (i-1 >= 0) a = dp[i-1][j]; 
			if (j-1 >= 0) b = dp[i][j-1]; 
			if (i-1 >= 0 && j-1 >= 0) c = dp[i-1][j-1]; 
			dp[i][j] = min(a, min(b,c)) + 1; 
			if (!field[i][j]) dp[i][j] = 0; 
			for (int k = 2; k <= dp[i][j]; ++k) ++cnt[k];
		}
	}		
	for (int k = 2; k <= n; ++k) if (cnt[k]) cout << k << ' ' << cnt[k] << '\n'; 

	return 0; 
}
