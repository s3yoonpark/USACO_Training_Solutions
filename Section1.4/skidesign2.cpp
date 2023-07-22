/* 
ID: s3yoonpark
LANG: C++ 
PROB: skidesign
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int N; int hills[1001]; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	cin >> N; 
	for (int i = 1; i <= N; ++i) {
		cin >> hills[i]; 
	}
	sort(hills, hills+N+1); 
	
	int cost = 0; 

	while (hills[N]-hills[1] > 17) {
		int dist = hills[N]-hills[1]-17; 
		int f=dist/2, s=dist/2; 
		if (f+s < dist) ++s; 
		if (hills[2]-hills[1] > hills[N]-hills[N-1]) swap(f, s); 
		hills[1] += f; 
		hills[N] -= s; 
		cost += f*f + s*s; 
		sort(hills, hills+N+1); 
	}
	
	cout << cost << "\n"; 

	return 0; 
}
