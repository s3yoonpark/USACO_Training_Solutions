/*
ID: s3yoonpark
LANG: C++ 
PROB: milk
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int n, m; 
vector<pair<int,int>> lst; 

bool cmp(const pair<int,int>& x, const pair<int,int>& y) {
	if (x.first == y.first) {
		return x.second < y.second;
	} else {
		return x.first < y.first; 
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	ifstream cin("milk.in"); 
	ofstream cout("milk.out"); 

	cin >> n >> m; 
	for (int i = 0; i < m; ++i) {
		int p, a; 
		cin >> p >> a; 
		lst.push_back(make_pair(p, a)); 
	}	
	sort(lst.begin(), lst.end(), cmp); 

	int ans = 0; 
	for (pair<int,int>& i : lst) {
		if (i.second > n) {
			ans += n * i.first; 
			break; 
		}
		ans += i.second * i.first; 
		n -= i.second; 
	}
	cout << ans << "\n"; 

	return 0; 
}
