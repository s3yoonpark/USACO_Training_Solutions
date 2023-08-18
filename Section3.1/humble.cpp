/*
ID: s3yoonpark
LANG: C++
PROB: humble
*/ 

#include <iostream> 
#include <algorithm>  
#include <cstring> 
using namespace std; 

typedef long long ll; 

int K, N; 
const int mxK = 100, mxN = 1e5; 
ll s[mxK], ar[mxN+1], dex[mxK]; 


int main() {
	freopen("humble.in", "r", stdin); 
	freopen("humble.out", "w", stdout); 
	memset(ar, 0x3f, sizeof(ar)); 	
	cin >> K >> N; 
	for (int i = 0; i < K; ++i) cin >> s[i]; 
	ar[0] = 1; 
	ar[1] = s[0]; 
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < K; ++j) {
			while (1) {
				if ((ll) ar[dex[j]] * s[j] > ar[i-1]) {
					ar[i] = min(ar[i], ar[dex[j]] * s[j]); 
					break; 
				}
				++dex[j]; 
			}
		}	
	}
	cout << ar[N] << '\n'; 

	return 0; 
}
