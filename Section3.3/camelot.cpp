#include <iostream> 
#include <queue> 
#include <vector> 
#include <cstring> 
using namespace std;

const int mxR = 30, mxC = 26; 
int R, C; 
int king[2]; 
int sum[mxR][mxC]; 
int ans[mxR][mxC];
int di[mxR][mxC][mxR][mxC]; 

int dx[8] = {1,2,2,1,-1,-2,-2,-1}; 
int dy[8] = {2,1,-1,-2,-2,-1,1,2}; 

struct Knight {
	int x, y; 
	int dist[mxR][mxC]; 
	bool vis[mxR][mxC]; 
	void upd() {
		memset(vis, 0, sizeof(vis)); 
		memset(dist, 0x3f, sizeof(dist)); 
		dist[y][x] = 0; 
		priority_queue<vector<int>> q; 
		q.push({0, y, x});  
		while (!q.empty()) {
			int b = q.top()[1]; 
			int a = q.top()[2]; 
			q.pop(); 
			if (vis[b][a]) continue; 
			vis[b][a] = 1; 
			for (int i = 0; i < 8; ++i) {
				int c = dx[i] + a; 
				int d = dy[i] + b; 
				if (!(c>=0&&c<C&&d>=0&&d<R)) continue; 
				if (dist[b][a] + 1 < dist[d][c]) {
					dist[d][c] = dist[b][a]+1; 
					q.push({-dist[d][c], d, c}); 
				}
			}
		}
	}
};
vector<Knight> v; 

void init() {
	for (int i = 0; i < mxR; ++i) {
		for (int j = 0; j < mxC; ++j) {
			// origin 
			bool vis[mxR][mxC]; 	
			memset(vis, 0, sizeof(vis)); 
			priority_queue<vector<int>> q; 
			q.push({0, 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	freopen("camelot.in", "r", stdin); 
	freopen("camelot.out", "w", stdout); 

	cin >> R >> C; 
	init(); 
	exit(0); 
	char tx; int ty;  
	cin >> tx >> ty; 
	king[0] = --ty; king[1] = tx-'A'; 

	while (cin >> tx >> ty) {
		cout << "DONE" << '\n' << '\n'; 
		Knight t; 	
		t.y = --ty; 
		t.x = tx-'A'; 
		t.upd(); 

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << t.dist[i][j] << ' ';
			}
			cout << '\n'; 
		}

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				sum[i][j] += t.dist[i][j]; 
			}
		}
		v.push_back(t); 
	}

	cout << "sum" << '\n'; 
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << sum[i][j] << ' ';
		}
		cout << '\n'; 
	}
	
	memcpy(ans, sum, sizeof(sum)); 
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			ans[i][j] += abs(i - king[0]) + abs(j - king[1]); 
		}		
	}
	
	int res = 0x3f3f3f3f; 
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			// gathering spot 
			// rotate through each knight, and consider it to guarantee to pick up spot for the king 
			for (Knight& k : v) {
				for (int a = 0; a < R; ++a) {
					for (int b = 0; b < C; ++b) {
						ans[i][j] = min(ans[i][j], (sum[i][j] - k.dist[i][j]) + k.dist[a][b] + abs(a - king[0]) + abs(b - king[1])); 
					}
				}
			}
			res = min(res, ans[i][j]); 
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n'; 
	}
	
	cout << res << '\n'; 

	return 0; 
}
