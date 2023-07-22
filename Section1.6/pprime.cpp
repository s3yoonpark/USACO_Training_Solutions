/*
ID: s3yoonpark
LANG: C++ 
PROB: pprime
*/ 

#include <bits/stdc++.h> 

using namespace std; 


const int mxN = 100000000; 
bool prime[mxN+1]; 
int A, B; 
set<int> s; 

bool valid(string n) {
	string temp = n; 
	reverse(temp.begin(), temp.end()); 
	return n == temp; 
}

void gen() {
	for (int i = 2; i <= B; ++i) {
		if (prime[i]) {
			if (i >= A) {
				if (valid(to_string(i))) s.insert(i); 
			}
			for (int j = i*2; j <= B; j += i) {
				prime[j] = 0; 
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	ifstream cin("pprime.in"); 
	ofstream cout("pprime.out"); 
	memset(prime, 1, sizeof(prime)); 
	cin >> A >> B; 	
	gen(); 
	for (int i : s) cout << i << "\n"; 

	return 0; 
}
