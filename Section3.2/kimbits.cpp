/*
ID: s3yoonpark
LANG: C++
PROB: kimbits
*/ 

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

const int mxN = 31; 
int N, L, I; 

int strcnt(string& x) {
	int res = 0; 
	for (char i : x) {
		if (i == '1') ++res; 
	}
	return res; 
}

string solve() {
	string ans = ""; 
	vector<string> fi; 
	vector<string> se[mxN+1]; 
	int a = N/2; 
	int b = N-a; 
	for (int i = 0; i < (1<<a); ++i) {
		if (__builtin_popcount(i) <= L) {
			string tmp = ""; 
			for (int k = a-1; k >= 0; --k) {
				tmp += ((1<<k) & i) ? '1' : '0'; 
			}
			fi.push_back(tmp); 
		}
	}
	for (int i = 0; i < (1<<b); ++i) {
		int cnt = __builtin_popcount(i); 
		if (cnt <= L) {
			string tmp = ""; 
			for (int k = b-1; k >= 0; --k) {
				tmp += (1<<k) & i ? '1' : '0'; 
			}
			for (int j = 0; j <= L-cnt; ++j) {
				se[j].push_back(tmp); 
			}
		}
	}
	for (int j = 0; j <= mxN; ++j) sort(se[j].begin(), se[j].end()); 
	for (string& x : fi) {
		int cnt = strcnt(x); 
		if (I > (int)se[cnt].size()) {
			I -= (int)se[cnt].size(); 
		} else {
			ans += x; 
			ans += se[cnt][I-1]; 
			return ans; 
		}
	}

	return ans; 
}

int main() {
	ios_base::sync_with_stdio(0) ;
	cin.tie(0); 
	//freopen("kimbits.in", "r", stdin); 
	//freopen("kimbits.out", "w" ,stdout); 

	cin >> N >> L >> I; 
	cout << solve() << '\n'; 
	
	return 0; 
}
