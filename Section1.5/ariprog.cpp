/*
ID: s3yoonpark
LANG: C++
PROB: ariprog
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int N, M; 
vector<int> b; 
vector<vector<int>> ans; 
unordered_set<int> s; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	//ifstream cin("ariprog.in"); 
	//ofstream cout("ariprog.out"); 

	cin >> N >> M; 	

	for (int i = 0; i <= M; ++i) {
		for (int j = i; j <= M; ++j) {
			if (!s.count(i*i+j*j)) {
				s.insert(i*i+j*j); 
				b.push_back(i*i+j*j); 
			}
		}
	}
	sort(b.begin(), b.end()); 

	int largest = b[b.size()-1]; 

	bool check = 0; 

	for (int i = 0; i < b.size(); ++i) {
		for (int j = i+1; (j < b.size()) && b.at(j)-b.at(i) <= (largest-b.at(i))/(N-1); ++j) {
			int diff = b.at(j) - b.at(i); 	
			bool ok = 1; 			
			for (int k = 1; k <= N-2; ++k) {
				ok = s.count(b.at(j)+k*diff); 
				if (!ok) break; 
			}
			if (ok) ans.push_back({diff, b.at(i)}); 
			if (ans.size() == 10000) check = 1; 
			if (check) break; 
		}
		if (check) break; 
	}

	sort(ans.begin(), ans.end()); 

	for (vector<int>& i : ans) {
		cout << i.at(1) << " " << i.at(0) << "\n"; 
	}

	if (ans.size() == 0) cout << "NONE" << "\n"; 

	return 0; 
}
