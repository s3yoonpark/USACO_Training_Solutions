/*
ID: s3yoonpark
LANG: C++
PROB: ariprog
*/ 

#include <bits/stdc++.h> 

using namespace std; 

const int mxN = 2*250*250; 
int N, M; 
bool bisquares[mxN+1]; 
vector<vector<int>> ans; 

bool check(int s, int d) {
	for (int i = 0; i < N; ++i) {
		if (!bisquares[s+i*d]) return false; 
	}
	return true; 
}

int main() {
	//ifstream cin("ariprog.in"); 
	//ofstream cout("ariprog.out"); 
	cin >> N >> M; 	
	for (int i = 0; i <= M; ++i) {
		for (int j = 0; j <= M; ++j) {
			bisquares[i*i+j*j] = 1; 
		}
	}	

	int m2 = 2*M*M;
	for (int s = 0; s <= m2; ++s) {
		for (int d = 1; d <= (m2-s)/(N-1); ++d) {
			if (check(s,d)) ans.push_back({d,s});
		}
	}	
	sort(ans.begin(), ans.end()); 
	for (vector<int>& i : ans) cout << i.at(1) << " " << i.at(0) << "\n"; 
	if (ans.size() == 0) cout << "NONE" << "\n"; 

	return 0; 
}
