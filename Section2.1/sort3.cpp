/* 
ID: s3yoonpark
LANG: C++ 
PROB: sort3
*/ 

#include <bits/stdc++.h> 

using namespace std; 

const int mxN = 1000; 
int ar[mxN]; 
int model[mxN]; 
int N; 

int main() {
	ifstream cin("sort3.in"); 
	ofstream cout("sort3.out"); 
	
	cin >> N; 
	for (int i = 0; i < N; ++i) {
		cin >> ar[i]; 
	}	
	memcpy(model, ar, sizeof(ar)); 
	sort(model, model+N); 

	int ans = 0; 
	for (int i = 0; i < N; ++i) {
		if (ar[i] == model[i]) continue; // correctly placed
		// brute force each option and rate them 
		int score = 0; 
		int opti, optj; 
		for (int j = 0; j < N; ++j) {
			if (i == j) continue; // how you gonna switch the same one :skull: 
			if (model[j] == ar[j]) continue; 
			int tscore; 
			bool t1 = model[j] == ar[i];
			bool t2 = model[i] == ar[j]; 
			if (t1 && t2) {
				tscore = 3; 	
			}
			else if (t1 != t2) {
				//if (t1) tscore = 1; 
				//if (t2) tscore = 2; 
				tscore = 1; 
			}
			else if (!t1 && !t2) {
				tscore = 0; 
			}
			if (score < tscore) {
				score = tscore; 
				opti = i; 
				optj = j; 
			}
		}
		//cout << score << ' ' <<  opti << ' ' << optj << '\n'; 
		swap(ar[opti], ar[optj]); 
		++ans; 
		--i; 
	}
	
	//cout << "here" << '\n'; 
	//for (int i = 0; i < N; ++i) {
		//cout << ar[i] << '\n'; 
	//}
	//cout << "here" << '\n'; 
	cout << ans << '\n'; 

	return 0; 
}
