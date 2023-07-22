/*
ID: s3yoonpark
LANG: C++
PROB: lamps
*/ 

#include <bits/stdc++.h>
using namespace std;

//ifstream fin("lamps.in"); 
//ofstream fout("lamps.out"); 

int N, C;
int state[10000]; 
int tmp[10000]; 
bool possible; 
vector<string> ans; 


// 0 off 
// 1 on
// -1 unsure

int main() {
	ifstream cin("lamps.in"); 
	ofstream cout("lamps.out"); 
	memset(state, -1, sizeof(state)); 
	cin >> N >> C; 	
	int on; 
	cin >> on; 
	while (on != -1) {
		state[on-1] = 1; 	
		cin >> on; 
	}
	int off; 
	cin >> off; 
	while (off != -1) {
		state[off-1] = 0; 
		cin >> off; 
	}

	//for (int i = 0; i < N; ++i) {
		//cout << i+1 << ' ' << state[i] << '\n'; 
	//}
	
	for (int a = 0; a <= 1; ++a) {
		for (int b = 0; b <= 1; ++b) {
			for (int c = 0; c <= 1; ++c) {
				for (int d = 0; d <= 1; ++d) {
					for (int i = 0; i < N; ++i) tmp[i] = 1;
					int sum = a+b+c+d; 
					if (sum <= C && sum%2 == C%2) {
						if (a) {
							for (int i = 0; i < N; ++i) {
								if (tmp[i]) tmp[i] = 0; 
								else tmp[i] = 1; 
							}
						}	
						if (b) {
							for (int i = 0; i < N; i+=2) {
								if (tmp[i]) tmp[i] = 0; 
								else tmp[i] = 1; 
							}
						}
						if (c) {
							for (int i = 1; i < N; i+=2) {
								if (tmp[i]) tmp[i] = 0; 
								else tmp[i] = 1; 
							}
						}
						if (d) {
							for (int i = 0; i < N; i+=3) {
								if (tmp[i]) tmp[i] = 0; 
								else tmp[i] = 1; 
							}
						}
						// check
						bool ok = 1; 
						for (int i = 0; i < N && ok; ++i) {
							if (state[i] == -1) continue; 
							if (tmp[i] != state[i]) ok = 0; 
						}
						if (ok) {
							string t; 
							possible = 1; 
							for (int i = 0; i < N; ++i) {
								t += (char)(tmp[i]+'0'); 
							} 
							ans.push_back(t); 
						}
					}
				}
			}
		}
	}

	if (!possible) cout << "IMPOSSIBLE" << '\n'; 
	sort(ans.begin(), ans.end()); 
	for (string& s : ans) {
		cout << s << '\n'; 
	}

	return 0; 
}
