/* 
ID: s3yoonpark
LANG: C++ 
TASK: friday
*/ 

#include <bits/stdc++.h> 

using namespace std; 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	ifstream fin("friday.in"); 
	ofstream fout("friday.out"); 
	
	vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  
	vector<int> lst (7, 0); 
	int n; 
	fin >> n; 

	int day = 2; 
	int year = 1900; 
	for (int i = 0; i < n; ++i) {
		bool leap = 0; 
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				leap = 1; 
			}
		} else {
			if (year % 4 == 0) {
				leap = 1; 
			}
		}

		if (leap) {
			month[2] = 29; 
		} else {
			month[2] = 28; 
		}
		
		for (int j = 1; j <= 12; ++j) {
			day += 12; 
			day %= 7; 
			++lst[day]; 	
			day += (month[j]-13+1); 
			day %= 7; 
		}
		++year; 
	}
	
	for (int i = 0; i < lst.size(); ++i) {
		if (i == 6) {
			fout << lst[i]; 
			continue; 
		}
		fout << lst[i] << " "; 
	}
	fout << "\n"; 

	return 0; 
}
