/*
ID: s3yoonpark
LANG: C++
PROB: milk2
*/

#include <bits/stdc++.h> 

using namespace std; 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	ifstream cin("milk2.in"); 
	ofstream cout("milk2.out"); 

	bool check[1000001]; 
	memset(check, false, 1000001); 
	int n; 
	cin >> n; 
		
	int start, end; 	
	int m = 0; 
	int a = 1000001; 
	for (int i = 0; i < n; ++i) {
		cin >> start >> end; 
		m = max(m, end); 
		a = min(a, start); 	
		for (int j = start; j < end; ++j) {
			check[j] = 1; 
		} 
	}

	int ans1 = 0; int ans2 = 0; 
	int tcnt = 0; 
	int tcnt2 = 0; 
	for (int i = a; i < m; ++i) {
		if (check[i]) {
			++tcnt; 
		} else {
			if (tcnt) {
				ans1 = max(ans1, tcnt); 	
				tcnt = 0; 
			}
		}

		if (!check[i]) {
			++tcnt2; 
		} else {
			if (tcnt2) {
				ans2 = max(ans2, tcnt2); 
				tcnt2 = 0; 
			}
		}
	}
	ans1 = max(ans1, tcnt); 
	ans2= max(ans2, tcnt2); 
	cout << ans1 << " " << ans2 << "\n"; 


	return 0; 
}
