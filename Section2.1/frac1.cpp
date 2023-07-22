/*
ID: s3yoonpark
LANG: C++ 
PROB: frac1
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int N; 

struct f {
	int p; 
	int q; 
	double val; 
};
typedef struct f f; 
vector<f> lst; 
bool check[161][161];

bool cmp(const f& a, const f& b) {
	return a.val < b.val; 
}

int main() {
	ifstream cin("frac1.in"); 
	ofstream cout("frac1.out"); 

	cin >> N; 	
	
	for (int denominator = 1; denominator <= N; ++denominator) {
		for (int numerator = 0; numerator <= denominator; ++numerator) {
			f tmp; 
			tmp.p = numerator / gcd(numerator, denominator); 
			tmp.q = denominator / gcd(numerator, denominator); 
			tmp.val = (double)tmp.p / tmp.q; 
			if (!check[tmp.p][tmp.q]) {
				check[tmp.p][tmp.q] = 1; 
				lst.push_back(tmp); 
			}
		}
	}	

	sort(lst.begin(), lst.end(), cmp); 

	for (f i : lst) {
		cout << i.p << '/' << i.q << '\n'; 
	}


	return 0; 
}
