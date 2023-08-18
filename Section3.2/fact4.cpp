/*
ID: s3yoonpark
LANG: C++
PROB: fact4
*/ 

#include <iostream> 
using namespace std;

int N; 
int n2, n5; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	freopen("fact4.in", "r", stdin); 
	freopen("fact4.out", "w", stdout); 
	
	cin >> N; 
	int prod = 1; 
	for (int i = 1; i <= N; ++i) {
		int j = i; 
		while (j % 2 == 0) {
			j /= 2;
			++n2; 
		}
		while (j % 5 == 0) {
			j /= 5; 
			++n5; 	
		}
		prod *= j;
		prod %= 10; 
	}
	for (int i = 0; i < abs(n5-n2); ++i) {
		prod *= 2; 
		prod %= 10; 
	}

	cout << prod << '\n'; 

	return 0; 
}
