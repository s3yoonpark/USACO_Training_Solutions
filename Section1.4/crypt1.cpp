/* 
ID: s3yoonpark
LANG: C++ 
PROB: crypt1
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 

	ifstream cin("crypt1.in"); 
	ofstream cout("crypt1.out"); 
	
	int n; 
	cin >> n; 
	vector<int> lst (n); 
	for (int& i : lst) cin >> i; 

	// abc * de 
	int cnt = 0; 
	
	for (int a : lst) {
		if (a == 0) continue; 
		for (int b : lst) {
			for (int c : lst) {
				int m = 100 * a + 10 * b + c; 

				for (int d : lst) {
					if (d == 0) continue; 
					if ((m * d) >= 1000) continue; 
					int prod1 = (m*d); 
					bool check1 = 1; 
					for (char x : to_string(prod1)) {
						int temp = x - '0'; 
						check1 = (find(lst.begin(), lst.end(), temp) != lst.end()); 
						if (!check1) break; 
					}
					if (!check1) continue; 
					for (int e : lst) {
						if ((m * e) >= 1000) continue; 

						int prod2 = m*e; 
						bool check2 = 1;
						for (char x : to_string(prod2)) {
							int temp = x - '0'; 
							check2 = (find(lst.begin(), lst.end(), temp) != lst.end()); 
							if (!check2) break; 
						}
						if (!check2) continue;

						int prod3 = (m*e) + (m*10*d); 		
						bool check3 = 1; 
						for (char x : to_string(prod3)) {
							int temp = x - '0'; 
							check3 = (find(lst.begin(), lst.end(), temp) != lst.end()); 
							if (!check3) break; 
						}
						if (check3) {
							++cnt; 
						}
					}
				}
			}
		}
	}

	cout << cnt << "\n"; 

	return 0; 
}
