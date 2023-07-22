/*
ID: s3yoonpark
LANG: C++
PROB: preface
*/ 

#include <bits/stdc++.h> 
using namespace std; 

int N; 

string digits[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 
string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; 
string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; 
string thousands[4] = {"", "M", "MM", "MMM"}; 
char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}; 
int counter[26]; 

string convert(int i) {
	return thousands[i/1000] + hundreds[(i%1000)/100] + tens[(i%100)/10] + digits[i%10]; 
}

int main() {
	ifstream cin("preface.in"); 
	ofstream cout("preface.out"); 
	cin >> N; 	
	for (int i = 1; i <= N; ++i) {
		for (char c : convert(i)) {
			++counter[c-'A']; 
		}	
	}
	for (int i = 0; i < 7; ++i) {
		if (counter[roman[i]-'A']) {
			cout << roman[i] << ' ' << counter[roman[i]-'A'] << '\n'; 
		}
	}


	return 0; 
}
