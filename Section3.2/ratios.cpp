/*
ID: s3yoonpark
LANG: C++
PROB: ratios
*/ 

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int sumN = 300; 

vector<int> ans(4); 
vector<int> target(3); 
vector<vector<int>> mixture(3, vector<int>(3)); 

bool valid(vector<int>& ar) {
	int ratio = ar[0] / target[0]; 
	for (int i = 0; i < 3; ++i) {
		if (target[i] * ratio != ar[i]) return false; 
	}
	return true; 
}

int main() {
	ios_base::sync_with_stdio(0); 	
	cin.tie(0); 
	freopen("ratios.in", "r", stdin); 
	freopen("ratios.out", "w", stdout); 
	for (int i = 0; i < 3; ++i) cin >> target[i]; 
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> mixture[i][j]; 
		}
	}
	for (int a = 0; a < 100; ++a) {
		for (int b = 0; b < 100; ++b) {
			for (int c = 0; c < 100; ++ c) {
				int sumT = a+b+c;
				if (!sumT || sumT > sumN) continue; 
				vector<int> arT(3, 0); 
				for (int i = 0; i < 3; ++i) {
					arT[i] = mixture[0][i] * a + mixture[1][i] * b + mixture[2][i] * c; 
				}
				if (valid(arT)) {
					sumN = sumT; 
					ans[0] = a; 
					ans[1] = b; 
					ans[2] = c; 
					ans[3] = arT[0] / target[0]; 
				}
			}
		}
	}
	if (count(ans.begin(), ans.end(), 0) == 4) {
		cout << "NONE" << '\n'; 
	} else {
		for (int i = 0; i < 4; ++i) {
			if (i == 3) cout << ans[i] << '\n'; 
			else cout << ans[i] << ' ';
		}
	}
	return 0; 
}
