/*
ID: s3yoonpark
LANG: C++
PROB: kimbits
*/ 

#include <iostream> 
#include <vector> 
using namespace std;

typedef long long ll; 
const int mxN = 31; 
vector<vector<int>> dp (mxN+1, vector<int>(mxN+1, 0)); 
ll N, L, I; 

void init() {
	for (int j = 0; j <= mxN; ++j) dp[0][j] = 1; 
	for (int i = 1; i <= mxN; ++i) {
		for (int j = 0; j <= mxN; ++j) {
			if (j == 0) dp[i][j] = 1; 
			else dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
		}
	}
	return; 
}

void printbits(ll nbits, ll nones, ll ind) {
	if (nbits == 0) return; 
	ll s = dp[nbits-1][nones]; 
	if (s <= ind) {
		cout << 1; 
		printbits(nbits-1, nones-1, ind-s); 
	} else {
		cout << 0; 
		printbits(nbits-1, nones, ind); 
	}
}

int main() {
	freopen("kimbits.in", "r", stdin); 
	freopen("kimbits.out", "w", stdout); 
	init(); 
	cin >> N >> L >> I; 	
	printbits(N, L, I-1); 
	cout << '\n'; 

	return 0; 
}
