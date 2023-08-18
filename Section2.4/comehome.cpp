/*
ID: s3yoonpark
LANG: C++ 
PROB: comehome
*/ 

#include <bits/stdc++.h> 
using namespace std;

const int mxN = 52; 
const int INF = 1e7 + 1;
int P;
int dist[mxN][mxN]; 
bool cowCheck[mxN]; 
char ansLetter; 
int ansNum = INF; 

int convert(char c) {
	if ('a' <= c && 'z' >= c) {
		return c - 'a'; 
	}
	if ('A' <= c && 'Z' >= c) {
		return c - 'A' + 26; 
	}
	return -1; 
}

char lettify(int n) {
	if (0 <= n && 25 >= n) {
		return n + 'a'; 
	}
	if (26 <= n && 51 >= n) {
		return n + 'A' - 26; 
	}
}

int main() {
	freopen("comehome.in", "r", stdin); 
	freopen("comehome.out", "w", stdout); 
	memset(dist, 0x3f, sizeof(dist)); 
	cin >> P; 	
	for (int i = 0; i < P; ++i) {
		char a, b; int w; 	
		cin >> a >> b >> w; 
		dist[convert(a)][convert(b)] = min(dist[convert(a)][convert(b)], w); 
		dist[convert(b)][convert(a)] = min(dist[convert(b)][convert(a)], w); 
		if ('A' <= a && 'Z' > a) {
			cowCheck[convert(a)] = 1; 
		}
		if ('A' <= b && 'Z' > b) {
			cowCheck[convert(b)] = 1; 
		}
	}

	int distance[mxN]; 
	bool processed[mxN]; 
	memset(processed, 0, sizeof(processed)); 
	for (int i = 0; i < mxN; ++i) distance[i] = INF; 
	priority_queue<pair<int,int>> q; 
	q.push({0, 51}); 
	distance[51] = 0; 
	while (!q.empty()) {
		int a = q.top().second; q.pop(); 
		if (processed[a]) continue; 
		processed[a] = 1; 
		for (int i = 0; i < mxN; ++i) {
			if (dist[a][i]) {
				if (distance[a] + dist[a][i] < distance[i]) {
					distance[i] = distance[a] + dist[a][i]; 
					q.push({-distance[i], i}); 
				}
			}
		}
	}
	for (int i = 0; i < mxN; ++i) {
		if (cowCheck[i]) {
			if (distance[i] < ansNum) {
				ansNum = distance[i]; 
				ansLetter = lettify(i); 
			}
		}
	}

	cout << ansLetter << ' ' << ansNum << '\n'; 	

	return 0; 
}
