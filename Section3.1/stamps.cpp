/*
ID: s3yoonpark
LANG: C++
PROB: stamps
*/ 

#include <iostream> 
#include <algorithm> 
#include <cstring> 
using namespace std;

const int mxM = 1e4 * 200; 
const int mxN = 50; 
const int mxK = 200; 
int K, N; 
int stamp[mxN]; 
int dp[mxM+1]; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	freopen("stamps.in", "r", stdin); 
	freopen("stamps.out", "w", stdout); 
	memset(dp, 0x3f, sizeof(dp)); 
	cin >> K >> N; 
	for (int i = 0; i < N; ++i) {
		cin >> stamp[i]; 
	}
	sort(stamp, stamp + N); 	
	dp[0] = 0; 	
	for (int i = 1; i <= mxM; ++i) {
		for (int j = 0; j < N; ++j) {
			if (stamp[j] > i) break; 
			dp[i] = min(dp[i], dp[i-stamp[j]]+1); 
		}
		if (dp[i] > K) {
			cout << i-1 << '\n'; 
			break; 
		}
	}

	return 0; 
}
