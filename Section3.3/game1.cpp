/*
ID: s3yoonpark
LANG: C++
PROB: game1
*/

#include <iostream> 
using namespace std;

const int mxN = 100; 
int N; 
int best[mxN+1][mxN+1]; 
int sum[mxN+1]; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	freopen("game1.in", "r", stdin); 
	freopen("game1.out", "w", stdout); 
	
	cin >> N; 	
	for (int i = 1; i <= N; ++i) {
		cin >> best[i][i]; 
		sum[i] = sum[i-1] + best[i][i]; 
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j+i <= N; ++j) {
			best[j+i][j] = (sum[j+i] - sum[j-1]) - min(best[j+i-1][j], best[j+i][j+1]); 
		}
	}
	cout << best[N][1] << ' ' << sum[N] - best[N][1] << '\n'; 

	return 0; 
}
