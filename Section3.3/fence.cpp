/*
ID: s3yoonpark
LANG: C++
PROB: fence
*/ 

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

const int mxF = 1024; 
const int mxN = 500; 
int F; 
int matrix[mxN+1][mxN+1]; 
int edges[mxN+1]; 
vector<int> eulerian; 

void dfs(int node) {
	for (int j = 1; j <= 500; ++j) {
		while (matrix[node][j]) {
			--matrix[node][j]; 
			--matrix[j][node]; 
			dfs(j); 
		}
	}
	eulerian.push_back(node); 
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	freopen("fence.in", "r", stdin); 
	freopen("fence.out", "w", stdout); 

	cin >> F; 	
	for (int i = 0; i < F; ++i) {
		int a, b; 			
		cin >> a >> b; 
		++matrix[a][b]; 
		++matrix[b][a]; 
		++edges[a];
		++edges[b]; 
	}

	bool tour = 0; 
	for (int i = 1; i <= 500 && !tour; ++i) {
		// assume it's a tour 
		if (edges[i]%2 == 1) {
			dfs(i); 
			tour = 1; 
		}
	}

	if (!tour) dfs(1); 
	reverse(eulerian.begin(), eulerian.end()); 
	for (int v : eulerian) cout << v << '\n'; 

	return 0; 
}
