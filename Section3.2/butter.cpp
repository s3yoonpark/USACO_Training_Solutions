/*
ID: s3yoonpark
LANG: C++
PROB: butter
*/ 

#include <iostream> 
#include <vector> 
#include <queue>
#include <cstring> 
#include <cmath> 
using namespace std;

int N, P, C; 
int cow[501]; 
vector<pair<int, int>> adj[801]; 
int dist[801]; 
bool processed[801]; 
int ans = pow(2,31) - 1; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	freopen("butter.in", "r", stdin); 
	freopen("butter.out", "w", stdout); 
	
	cin >> N >> P >> C; 
	for (int i = 1; i <= N; ++i) {
		cin >> cow[i]; 
	}
	for (int i = 0; i < C; ++i) {
		int a, b, w; 
		cin >> a >> b >> w; 
		adj[a].push_back(make_pair(b, w)); 
		adj[b].push_back(make_pair(a, w)); 
	}
	for (int i = 1; i <= P; ++i) {
		memset(dist, 0x3f, sizeof(dist)); 
		memset(processed, 0, sizeof(processed)); 
		priority_queue<pair<int,int>> q; 	
		q.push(make_pair(0, i)); 
		dist[i] = 0; 		
		while (!q.empty()) {
			int a = q.top().second; q.pop(); 			
			if (processed[a]) continue; 
			processed[a] = 1; 
			for (auto& e : adj[a]) {
				int w = e.second; 
				int b = e.first; 
				if (dist[a] + w < dist[b]) {
					dist[b] = dist[a] + w; 		
					q.push(make_pair(-dist[b], b)); 
				}
			}
		}
		int t = 0; 
		for (int i = 1; i <= N; ++i) {
			t += dist[cow[i]]; 
		}
		ans = min(ans, t); 
	}
	cout << ans << '\n'; 

	return 0; 
}
