/* 
ID: s3yoonpark
LANG: C++ 
PROB: combo
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int farmer[3], master[3]; 
int n; 

bool valid(vector<int> lst) {
	// try farmer ones first 
	bool b1=0, b2=0, b3=0; 
	b1 = (abs(lst[0]-farmer[0]) <= 2) || (n - abs(lst[0]-farmer[0]) <= 2); 
	b2 = (abs(lst[1]-farmer[1]) <= 2) || (n - abs(lst[1]-farmer[1]) <= 2); 
	b3 = (abs(lst[2]-farmer[2]) <= 2) || (n - abs(lst[2]-farmer[2]) <= 2); 
	if (b1 && b2 && b3) return 1; 
	b1 = (abs(lst[0]-master[0]) <= 2) || (n - abs(lst[0]-master[0]) <= 2); 
	b2 = (abs(lst[1]-master[1]) <= 2) || (n - abs(lst[1]-master[1]) <= 2); 
	b3 = (abs(lst[2]-master[2]) <= 2) || (n - abs(lst[2]-master[2]) <= 2); 
	if (b1 && b2 && b3) return 1; 
	return 0; 
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	ifstream cin("combo.in"); 
	ofstream cout("combo.out"); 
	

	// one thing to be wary of is that the lock is circular, so 50 is right next to 1  
	
	cin >> n; 

	for (int i = 0; i < 3; ++i) {
		cin >> farmer[i]; 
	}

	for (int i = 0; i < 3; ++i) {
		cin >> master[i]; 
	}


	// brute forcing all combinations
	
	int cnt = 0; 

	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			for (int c = 1; c <= n; ++c) {
				if (valid({a,b,c})) {
					++cnt; 
				}
			}
		}	
	}

	cout << cnt << "\n"; 


	return 0; 
}
