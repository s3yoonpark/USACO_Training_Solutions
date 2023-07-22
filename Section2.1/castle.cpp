/*
ID: s3yoonpark
LANG: C++
PROB: castle
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int M, N; 
int grid[50][50]; 
bool vis[50][50]; 
int t; 
int num, lroom; 

void floodfill(int i, int j) {
	if (i < 0 || i > N-1 || j < 0 || j > M-1) return; 	
	if (vis[i][j]) return; 
	//cout << i << ' ' << j << ' ' << grid[i][j] << '\n'; 
	vis[i][j] = 1; 
	++t; 
	if (!(grid[i][j] & (1 << 1))) {
		//cout << i << ' ' << j << ' ' << "north" << '\n'; 
		floodfill(i-1, j); 
	}
	if (!(grid[i][j] & (1 << 2))) {
		//cout << i << ' ' << j << ' ' << "east" << '\n'; 
		floodfill(i, j+1); 
	}
	if (!(grid[i][j] & (1 << 3))) {
		//cout << i << ' ' << j << ' ' << "south" << '\n'; 
		floodfill(i+1, j); 
	}
	if (!(grid[i][j] & (1 << 0))) {
		//cout << i << ' ' << j << ' ' << "west" << '\n'; 
		floodfill(i, j-1); 
	}
	return; 	
}

void eval() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!vis[i][j]) {
				//cout << "here" << '\n'; 
				++num; 
				t = 0; 
				floodfill(i, j); 
				//cout << '\n' << '\n'; 
				lroom = max(lroom ,t); 
			}
		}
	}
	return; 
}

int main() {

	ifstream cin("castle.in");
	ofstream cout("castle.out"); 

	cin >> M >> N; 
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> grid[i][j]; 
		}
	}
	eval(); 
	cout << num << '\n'; 
	cout << lroom << '\n'; 

	// brute force 
	int pos = 0; 
	int x=-1, y=-1; char dir = ' ';
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k <= 3; ++k) {
				if (grid[i][j] & (1 << k)) {
					grid[i][j] ^= (1<<k); // toggle it off
										  // i also have to toggle the opposite walls off 
					if (k == 0) {
						if (j-1 >= 0) grid[i][j-1] ^= (1<<2); 
					} else if (k == 1) {
						if (i-1 >= 0) grid[i-1][j] ^= (1<<3); 	
					} else if (k == 2) {
						if (j+1 <= M-1) grid[i][j+1] ^= (1<<0); 
					} else if (k == 3) {
						if (i+1 <= N-1) grid[i+1][j] ^= (1<<1); 
					}
					num=0;
					lroom=0;
					memset(vis, 0, sizeof(vis)); 
					eval(); 
					if (pos <= lroom) {
						//cout << lroom << ' ' << i+1 << ' ' << j+1 << '\n'; 
						if (pos == lroom) {
							if (!(y < j+1)) {
								if (y == j+1) {
									// check south 
									if (!(x > i+1)) {
										if (x == i+1) {
											if (dir == 'E') {
												pos = lroom; 
												x = i+1; 
												y = j+1; 
												if (k == 0) dir = 'W';
												else if (k == 1) dir = 'N';
												else if (k == 2) dir = 'E'; 
												else if (k == 3) dir = 'S'; 
											}	
										} else {
											pos = lroom; 
											x = i+1; 
											y = j+1; 
											if (k == 0) dir = 'W';
											else if (k == 1) dir = 'N';
											else if (k == 2) dir = 'E'; 
											else if (k == 3) dir = 'S'; 
										}
								}
								} else {
									pos = lroom; 
									x = i+1; 
									y = j+1; 
									if (k == 0) dir = 'W';
									else if (k == 1) dir = 'N';
									else if (k == 2) dir = 'E'; 
									else if (k == 3) dir = 'S'; 
								}
							}
						} else {
							pos = lroom;
							x = i+1; 
							y = j+1;
							if (k == 0) dir = 'W';
							else if (k == 1) dir = 'N';
							else if (k == 2) dir = 'E'; 
							else if (k == 3) dir = 'S'; 
						}
						//cout << pos << '\n'; 
						//cout << x << ' ' << y << ' ' << dir << '\n'; 
					}		
					grid[i][j] ^= (1<<k); 
					if (k == 0) {
						if (j-1 >= 0) grid[i][j-1] ^= (1<<2); 
					} else if (k == 1) {
						if (i-1 >= 0) grid[i-1][j] ^= (1<<3); 	
					} else if (k == 2) {
						if (j+1 <= M-1) grid[i][j+1] ^= (1<<0); 
					} else if (k == 3) {
						if (i+1 <= N-1) grid[i+1][j] ^= (1<<1); 
					}
				}
			}
		}
	}

	cout << pos << '\n'; 
	cout << x << ' ' << y << ' ' << dir << '\n'; 

	return 0; 

}
