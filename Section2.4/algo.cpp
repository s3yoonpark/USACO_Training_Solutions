#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6; 
const int n = 100; 
const int x = 1; 
int distance[n+1]; 
bool processed[n+1]; 
priority_queue<pair<int,int>> qu; 

int main() {
	// dijkstra
	// time complexity: O(E * logV)
	for (int i = 1; i <= n; ++i) distance[i] = INF; 	
	distance[x] = 0; 
	qu.push({0, x}); 
	while (!qu.empty()) {
		int a = q.top().second; qu.pop(); // the node is popped 
		if (processed[a]) continue; 
		processed[a] = true; 
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;  
			if (distance[a]+w < distance[b]) {
				distance[b] = distance[a] + w; 
				qu.push({-distance[b], b}); 
			}
		}
	}
	
	// bellman-ford 
	// time complextiy: O(E * V) 
	for (int i = 1; i <= n; ++i) distance[i] = INF; 
	distance[x] = 0; 
	for (int i = 1; i <= n-1; ++i) {
		for (auto e : edges) {
			int a, b, w; 
			tie(a, b, w) = e; 
			distance[b] = min(distance[b], distance[a]+w); 
		}
	}

	// Floyd-Warshall 
	// time complexity: O(V ^ 3) 
	
	// initialising values 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) distance[i][j] = 0; 
			else if (adj[i][j]) distance[i][j] = adj[i][j]; 
			else distance[i][j] = INF; 
		}
	}
	// calculating shortest distances 
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]); 
			}
		}
	}

	return 0; 
}
