/* 
ID: s3yoonpark
LANG: C++ 
PROB: holstein
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int V, G; 
int req[25];
int vit[15][25]; 
int tmp[25]; 

int main() {
	ifstream cin("holstein.in"); 
	ofstream cout("holstein.out"); 
	
	cin >> V;
	for (int i = 0; i < V; ++i) {
		cin >> req[i]; 
	}
	cin >> G; 
	for (int i = 0; i < G; ++i) {
		for (int j = 0; j < V; ++j) {
			cin >> vit[i][j]; 
		}
	}

	// brute force 
	vector<vector<int>> ans; 
	int m = INT_MAX; 
	for (int i = 0; i < (1<<G); ++i) {
		memset(tmp, 0, sizeof(tmp)); 
		int present = __builtin_popcount(i); 
		if (present > m) continue; 
		vector<int> v; 
		v.push_back(0); 
		for (int k = 0; k < G; ++k) {
			if (i & (1<<k)) {
				v.push_back(k+1); 
				for (int j = 0; j < V; ++j) {
					tmp[j] += vit[k][j]; 
				}
			}
		}	
		bool ok = 1; 
		for (int j = 0; j < V && ok; ++j) {
			if (tmp[j] < req[j]) ok = 0; 
		}
		if (ok) {
			if (m >= present) {
				m = present; 	
				v[0] = m; 	
				sort(v.begin()+1, v.end()); 
				ans.push_back(v); 
			}
		}

	}	
	sort(ans.begin(), ans.end()); 
	
	for (int i = 0; i < ans[0].size(); ++i) {
		string t = " "; 
		if (i == ans[0].size()-1) t = "\n"; 
		cout << ans[0][i] << t;	
	}

	return 0; 
}
