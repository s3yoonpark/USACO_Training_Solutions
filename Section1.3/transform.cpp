/*
ID: s3yoonpark
LANG: C++
PROB: transform
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int n; 
char before[10][10]; 
char after[10][10]; 
char temp[10][10];


void rotate() {
	// rotate temp by clockwise 90 degrees 
	char t[10][10]; 

	int x = n-1; 
	int y = 0; 
		
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			t[i][j] = temp[i+x-j][y]; 			
		}
		--x; 
		++y; 
	}
	memcpy(temp, t, sizeof(t)); 
	return; 
}

bool eqa() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (temp[i][j] != after[i][j]) return 0; 
		}
	}
	return 1;
}

void reflect() {
	char t[10][10]; 	
	int y = n-1; 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			t[i][j] = temp[i][y-j]; 
		}
	}
	memcpy(temp, t, sizeof(t)); 
	return; 
}



int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	ifstream cin("transform.in"); 
	ofstream cout("transform.out"); 
	
	cin >> n; 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> before[i][j]; 
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> after[i][j]; 
		}
	}
	memcpy(temp, before, sizeof(before)); 	
	for (int i = 1; i <= 3; ++i) {
		rotate(); 
		if (eqa()) {
			cout << i << "\n"; 
			return 0; 
		}
	}	

	memcpy(temp, before, sizeof(before)); 

	if (eqa()) {
		cout << 6 << "\n"; 
		return 0; 
	}

	reflect(); 
	if (eqa()) {
		cout << 4 << "\n"; 
		return 0; 
	}
	for (int i = 1; i <= 3; ++i) {
		rotate(); 
		if (eqa()) {
			cout << 5 << "\n"; 
			return 0; 
		}
	}

	cout << 7 << "\n"; 

	return 0; 
}
