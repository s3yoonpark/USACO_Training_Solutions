/* 
ID: s3yoonpark
LANG: C++
PROB: agrinet
*/ 

#include <bits/stdc++.h> 
using namespace std;

const int mxN = 100; 
int N; 
int matrix[mxN][mxN]; 
int cLink[mxN], cSize[mxN]; 
vector<vector<int>> edges; 
int ans; 


int cFind(int x) {
	while (x != cLink[x]) { x = cLink[x]; }
	return x; 
}

bool same(int a, int b) {
	return cFind(a) == cFind(b); 
}

void unite(int a, int b) {
	a = cFind(a); 
	b = cFind(b); 
	if (cSize[a] < cSize[b]) swap(a, b); 
	cSize[a] += cSize[b]; 
	cLink[b] = a; 
	return; 
}

int main() {
	freopen("agrinet.in", "r", stdin); 
	freopen("agrinet.out", "w", stdout); 
	// kruskal's algorithm 
	cin >> N; 	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j]; 
			edges.push_back({matrix[i][j], i, j}); 
		}
	}
	sort(edges.begin(), edges.end()); 
	for (int i = 0; i < N; ++i) cLink[i] = i; 
	for (int i = 0; i < N; ++i) cSize[i] = 1; 
	for (vector<int>& i : edges) {
		if (!same(i[1], i[2])) {
			unite(i[1], i[2]); 
			ans += i[0]; 
		}
	}
	cout << ans << '\n'; 

	return 0; 
}
