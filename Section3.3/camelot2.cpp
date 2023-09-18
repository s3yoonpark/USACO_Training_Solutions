/*
ID: s3yoonpark
LANG: C++
PROB: camelot
*/

#include <iostream> 
#include <cstring> 
#include <queue> 
using namespace std;

const int mxR = 30, mxC = 26; 

int R, C; 

int king[2]; 
int di[mxR][mxC][mxR][mxC]; 
// di[a][b][c][d] = # moves for a knight from (a, b) to get to (c, d)

int dx[8] = {1,2,2,1,-1,-2,-2,-1}; 
int dy[8] = {2,1,-1,-2,-2,-1,1,2}; 

int sum[mxR][mxC]; 
int ans[mxR][mxC];

struct Knight {
	int x, y; 
	int dist[mxR][mxC]; 
	bool vis[mxR][mxC]; 
	void upd() {
		for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                dist[i][j] = di[y][x][i][j]; 
            }
        }
	}
};
vector<Knight> v; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("camelot.in", "r", stdin); 
    freopen("camelot.out", "w", stdout); 

    cin >> R >> C; 

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            // origin 
            bool vis[mxR][mxC]; memset(vis, 0, sizeof(vis)); 
            for (int y = 0; y < R; ++y) {
                for (int x = 0; x < C; ++x) {
                    di[i][j][y][x] = 0x3f3f3f3f;
                }
            }
            di[i][j][i][j] = 0; 
            priority_queue<vector<int>> q; 
            q.push({0, i, j}); 
            while (!q.empty()) {
                int y = q.top()[1]; 
                int x = q.top()[2]; 
                q.pop(); 
                if (vis[y][x]) continue; 
                vis[y][x] = 1; 
                for (int c = 0; c < 8; ++c) {
                    int b = y + dy[c]; 
                    int a = x + dx[c]; 
                    if (!(b>=0&&b<R&&a>=0&&a<C)) continue; 
                    if (di[i][j][y][x] + 1 < di[i][j][b][a]) {
                        di[i][j][b][a] = di[i][j][y][x] + 1; 
                        q.push({-di[i][j][b][a], b, a}); 
                    }
                }
            }
        }
    }

    char tx; int ty;  
	cin >> tx >> ty; 
	king[0] = --ty; king[1] = tx-'A'; 

	while (cin >> tx >> ty) {
		// cout << "DONE" << '\n' << '\n'; 
		Knight t; 	
		t.y = --ty; 
		t.x = tx-'A'; 
		t.upd(); 

		// for (int i = 0; i < R; ++i) {
		// 	for (int j = 0; j < C; ++j) {
		// 		cout << t.dist[i][j] << ' ';
		// 	}
		// 	cout << '\n'; 
		// }

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				sum[i][j] += t.dist[i][j]; 
			}
		}
		v.push_back(t); 
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
						ans[i][j] = min(ans[i][j], (sum[i][j] - k.dist[i][j]) + k.dist[a][b] + abs(a - king[0]) + abs(b - king[1]) + di[a][b][i][j]); 
					}
				}
			}
			res = min(res, ans[i][j]); 
		}
	}

	// for (int i = 0; i < R; ++i) {
	// 	for (int j = 0; j < C; ++j) {
	// 		cout << ans[i][j] << ' ';
	// 	}
	// 	cout << '\n'; 
	// }
	
	cout << res << '\n'; 

    return 0; 
}