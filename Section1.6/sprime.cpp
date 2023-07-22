/*
ID: s3yoonpark
LANG: C++
PROB: sprime
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int N; 
int starter[4] = {2, 3, 5, 7}; 
vector<int> ans; 

bool prime(int n) {
	if (n == 1) return false; 
	if (n == 2) return true; 
	if (n % 2 == 0) return false; 
	for (int i = 3; i*i <= n; ++i) {
		if (n % i == 0) return false; 
	}
	return true; 
}

void dfs(int tmp) {
	if (!prime(tmp)) return; 
	if (to_string(tmp).length() == N) {
		ans.push_back(tmp); 	
		return; 
	}
	for (int i = 0; i <= 4; ++i) {
		// 2i + 1 to generate odd 
		dfs(tmp*10 + 2*i+1); 
	}
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	ifstream cin("sprime.in"); 
	ofstream cout("sprime.out"); 
	
	cin >> N; 	
	for (int i = 0; i < 4; ++i) {
		dfs(starter[i]); 
	}
	for (int i : ans) cout << i << "\n"; 

	return 0; 
}
