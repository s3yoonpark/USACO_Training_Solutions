/*
ID: s3yoonpark
LANG: C++
PROB: namenum
*/ 

#include <bits/stdc++.h> 

using namespace std; 

unordered_set<string> s;

unordered_map<int,string> mp;

int cnt = 0; 

ifstream fin("namenum.in"); 
ofstream fout("namenum.out"); 

void process(string& n, int ind, string temp) {
	if (ind == n.length()) {
		if (s.count(temp)) {
			fout << temp << "\n"; 
			++cnt; 
		}
		return; 
	}

	int t = n[ind] - '0'; 

	for (char& i : mp[t]) {
		process(n, ind+1, temp+i); 
	}
	return; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	mp[2] = "ABC"; 
	mp[3] = "DEF"; 
	mp[4] = "GHI"; 
	mp[5] = "JKL"; 
	mp[6] = "MNO"; 
	mp[7] = "PRS"; 
	mp[8] = "TUV"; 
	mp[9] = "WXY"; 

	fstream f; 
   	f.open("dict.txt"); 	
	string temp;
	while (getline(f, temp)) {
		s.insert(temp); 
	}
	f.close(); 


	string n; 
	fin >> n; 

	process(n, 0, "");	

	if (!cnt) fout << "NONE" << "\n"; 

	return 0; 
}
