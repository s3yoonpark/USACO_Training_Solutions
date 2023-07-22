/*
ID: s3yoonpark
LANG: C++
PROB: ttwo
*/ 


#include <bits/stdc++.h>
using namespace std;

struct info {
	int x, y, dir; 
}; 
typedef struct info info; 

// 0 north 
// 1 east 
// 2 south 
// 3 west 

int cnt; 
bool found; 
char board[10][10]; 
info farmer; 
info modelFarmer; 
vector<info> cows; 
vector<info> modelCows; 

bool equal(const info& a, const info& b) {
	return (a.x == b.x && a.y == b.y && a.dir == b.dir); 
}

bool equal2(const vector<info>& a, const vector<info>& b) {
	for (int i = 0; i < a.size(); ++i) {
		if (!equal(a[i], b[i])) return false; 
	}
	return true; 
}

void update(info& a) {
	if (a.dir == 0) {
		if (a.y-1 < 0) {
			++a.dir; 
			a.dir %= 4;
			return; 
		}
		if (board[a.y-1][a.x] == '*') {
			// obstacle 
			++a.dir; 
			a.dir %= 4;
		} else {
			--a.y; 
		}
	} else if (a.dir == 1) {
		if (a.x+1 > 9) {
			++a.dir; 
			a.dir %= 4; 
			return; 
		}
		if (board[a.y][a.x+1] == '*') {
			++a.dir; 
			a.dir %= 4; 
		} else {
			++a.x; 
		}
	} else if (a.dir == 2) {
		if (a.y+1 > 9) {
			++a.dir; 
			a.dir %= 4; 
			return; 
		}
		if (board[a.y+1][a.x] == '*') {
			++a.dir; 
			a.dir %= 4;
		} else {
			++a.y; 
		}
	} else if (a.dir == 3) {
		if (a.x-1 < 0) {
			++a.dir; 
			a.dir %= 4;
			return; 
		}
		if (board[a.y][a.x-1] == '*') {
			++a.dir; 
			a.dir %= 4;
		} else {
			--a.x; 
		}
	}
	return;
}


int main() {
	ifstream cin("ttwo.in"); 
	ofstream cout("ttwo.out"); 

	cnt = 0; 
	found = 0; 
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> board[i][j]; 
			if (board[i][j] == 'C') {
				info tmp; 
				tmp.x = j; 
				tmp.y = i; 
				tmp.dir = 0; 
				cows.push_back(tmp); 	
				modelCows.push_back(tmp); 
				board[i][j] = '.'; 
			} else if (board[i][j] == 'F') {
				farmer.x = j; 
				farmer.y = i; 
				farmer.dir = 0; 
				modelFarmer.x = j; 
				modelFarmer.y = i; 
				modelFarmer.dir = 0; 
				board[i][j] = '.'; // denoting that it is empty 
			}
		}
	}	
	while (1) {
		++cnt; 
		// update farmer pos first 
		update(farmer); 
		for (auto& cow : cows) {
			update(cow); 
			if (cow.x == farmer.x && cow.y == farmer.y) {
				cout << cnt << '\n'; 
				found = 1; 	
				break; 
			}
		}		
		if (found) break; 
		if (cnt > 160000) {
			cout << 0 << '\n'; 
			break; 
		}
	}
		
	return 0; 
}
