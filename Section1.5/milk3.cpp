/*
ID: s3yoonpark
LANG: C++ 
PROB: milk3
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int capacity[3]; 
int state[3]; 
vector<int> ans; 
unordered_map<string, bool> mp; 

void dfs() {
	string s = ""; 
	for (int i = 0; i < 3; ++i) s += to_string(state[i]) + " "; 
	if (mp.find(s) != mp.end()) return; 
	mp[s] = true; 


	if (state[0] == 0) {
		ans.push_back(state[2]); 
	}
	for (int i = 0; i < 3; ++i) {
		// sender 
		if (state[i] == 0) continue; // if you have 0 money, what you gonna send??? :skull: 
		for (int j = 0; j < 3; ++j) {
			// recipient 
			if (i == j) continue; // how you gonna give to the same person :skull: 
			if (state[j] == capacity[j]) continue; // how you gonna give to a person with full money? :skull: 
												   
			int t1 = state[i], t2 = state[j]; 
			state[i] -= min(t1, (capacity[j] - state[j])); 
			state[j] += min(t1, (capacity[j] - state[j])); 
			dfs(); 
			state[i] = t1; 
			state[j] = t2; 
		}
	}

	return; 
}

int main() {
	ifstream cin("milk3.in"); 
	ofstream cout("milk3.out"); 

	for (int i = 0; i < 3; ++i) cin >> capacity[i]; 	
	
	// dfs stopping when it counters a state it has already reached 
	state[2] = capacity[2]; 	
	dfs(); 	
	sort(ans.begin(), ans.end());	
	for (int i = 0; i < ans.size()-1; ++i) cout << ans[i] << " "; 
	cout << ans[ans.size()-1] << "\n"; 

	return 0;
}
