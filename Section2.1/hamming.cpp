/* 
ID: s3yoonpark
LANG: C++
PROB: hamming
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int N, B, D; 
int cap; 
vector<int> lst; 

int dist(int a, int b) {
	int res = 0; 
	for (int k = 0; k < B; ++k) {
		bool b1 = a & (1<<k); 
		bool b2 = b & (1<<k); 
		if (b1 != b2) ++res; 
	}
	return res; 
}

int main() {
	ifstream cin("hamming.in"); 
	ofstream cout("hamming.out"); 
	
	cin >> N >> B >> D; 
	cap = pow(2, B) - 1; 	

	for (int i = 0; i <= cap; ++i) {
		bool ok = 1; 
		for (int j : lst) {
			if (dist(i, j) < D) {
				ok = 0; 
				break; 
			}
		}
		if (ok) {
			lst.push_back(i); 
		}
		if (lst.size() == N) break; 
	}

	for (int i = 0; i < lst.size(); ++i) {
		string tmp; 	
		if (i % 10 == 9) tmp = "\n"; 
		else if (i == lst.size()-1) tmp = '\n'; 
		else tmp = " "; 
		cout << lst[i] << tmp;  
	}

	return 0; 
}
