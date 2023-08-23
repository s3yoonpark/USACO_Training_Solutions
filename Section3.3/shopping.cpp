/*
ID: s3yoonpark
LANG: C++
PROB: shopping
*/ 

#include <iostream> 
#include <cstring> 
#include <vector> 
using namespace std;

const int mxS = 99, mxC = 999; 
int s, b; 
int cost[5]; 
int p[5]; 
int num[5]; 

int dp[6][6][6][6][6];  
					   // dp[a][b][c][d][e]  = minimum price of buying a, b, c, d, e 

struct Offer {
	vector<pair<int,int>> items; 
	// {ID, num}
	int price; 
};
typedef struct Offer Offer; 

Offer lst[mxS]; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	freopen("shopping.in", "r", stdin); 
	freopen("shopping.out", "w", stdout); 

	cin >> s; 	
	for (int i = 0; i < s; ++i) {
		int n; 
		cin >> n; 
		for (int j = 0; j < n; ++j) {
			int x, y;
			cin >> x >> y; 
			lst[i].items.push_back({x, y}); 
		}
		cin >> lst[i].price; 
	}
	cin >> b; 
	for (int i = 0; i < b; ++i) {
		cin >> p[i]; 
		cin >> num[i]; 
		cin >> cost[i]; 
	}
	memset(dp, 0x3f, sizeof(dp)); // check if this is big enough later 	
	dp[0][0][0][0][0] = 0; 
	for (int A = 0; A <= num[0]; ++A) {
		for (int B = 0; B <= num[1]; ++B) {
			for (int C = 0; C <= num[2]; ++C) {
				for (int D = 0; D <= num[3]; ++D) {
					for (int E = 0; E <= num[4]; ++E) {
						if (A+B+C+D+E == 0) continue; 
						if (A >= 1) dp[A][B][C][D][E] = min(dp[A][B][C][D][E], dp[A-1][B][C][D][E] + cost[0]); 
						if (B >= 1) dp[A][B][C][D][E] = min(dp[A][B][C][D][E], dp[A][B-1][C][D][E] + cost[1]); 
						if (C >= 1) dp[A][B][C][D][E] = min(dp[A][B][C][D][E], dp[A][B][C-1][D][E] + cost[2]); 
						if (D >= 1) dp[A][B][C][D][E] = min(dp[A][B][C][D][E], dp[A][B][C][D-1][E] + cost[3]); 
						if (E >= 1) dp[A][B][C][D][E] = min(dp[A][B][C][D][E], dp[A][B][C][D][E-1] + cost[4]); 
						//cout << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << dp[A][B][C][D][E] << '\n'; 
						int cur[5] = {A, B, C, D, E}; 
						for (int i = 0; i < s; ++i) {
							int mod[5] = {A, B, C, D, E}; 
							bool ok = 1; 
							for (auto& x : lst[i].items) {
								// x.first - ID 
								// x.second - # 
								int ind = -1; 
								for (int j = 0; j < 5; ++j) {
									if (x.first == p[j]) ind = j; 
								}
								if (ind == -1) {
									ok = 0; 
									break; 
								}	
								if (cur[ind] < x.second || mod[ind] < x.second) {
									ok = 0; 
									break; 
								}
								mod[ind] -= x.second; 
								if (!ok) break; 
							}
							if (ok) {
								dp[A][B][C][D][E] = min(dp[A][B][C][D][E], dp[mod[0]][mod[1]][mod[2]][mod[3]][mod[4]] + lst[i].price); 
							}
						}
						//cout << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << ' ' << dp[A][B][C][D][E] << '\n'; 
					}
				}
			}
		}
	}

	cout << dp[num[0]][num[1]][num[2]][num[3]][num[4]] << '\n'; 

	

	return 0; 
}
