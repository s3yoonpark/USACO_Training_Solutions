/*
ID: s3yoonpark
LANG: C++ 
TASK: gift1
*/


#include <bits/stdc++.h> 

using namespace std; 

int main() {
	ifstream fin("gift1.in"); 
	ofstream fout("gift1.out"); 
	int n; 
	fin >> n; 
	vector<string> lst (n); 
	vector<int> bank (n); 
	for (string& i : lst) fin >> i; 
	for (int i = 0; i < n; ++i) {
		string giver; 
		fin >> giver; 
		int money, num; 
		fin >> money >> num; 
		if (num == 0) continue; 
		auto it = find(lst.begin(), lst.end(), giver); 
		int index = it - lst.begin(); 
		bank[index] -= money; 
		int remainder = money - num * (money/num); 
		bank[index] += remainder; 
		for (int j = 0; j < num; ++j) {
			string recipient; 
			fin >> recipient; 
			auto t_it = find(lst.begin(), lst.end(), recipient); 
			int t_index = t_it - lst.begin(); 
			bank[t_index] += (money / num); 
		}
	}
	for (int i = 0; i < n; ++i) {
		fout << lst[i] << " " << bank[i] << "\n"; 
	}

	return 0; 
}
