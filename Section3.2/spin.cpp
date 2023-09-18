/*
ID: s3yoonpark
LANG: C++
PROB: spin
*/ 

#include <iostream> 
#include <cassert> 
using namespace std;

int speed[5]; 
bool pos[5][360]; 

int main() {
	//ios_base::sync_with_stdio(0); 
	//cin.tie(0); 

	//freopen("spin.in", "r", stdin); 
	//freopen("spin.out", "w", stdout); 

	for (int i = 0; i < 5; ++i) {
		cin >> speed[i]; 	
		speed[i] %= 360; 
		int num; 
		cin >> num;
		while (num--) {
			int angle, extent; 
			cin >> angle >> extent; 
			for (int j = angle; j <= angle + extent; ++j) {
				pos[i][j%360] = 1; 
			}
		}
	}
	bool found = 0; 
	int A = 0, B = 0, C = 0, D = 0, E = 0; 
	// base case t = 0 
	for (int t = 0; t < 360 && !found; ++t) {
		cout << t << ' ' << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << '\n'; 
		for (int i = 0; i < 360 && !found; ++i) {
			if (pos[0][(i+A)%360] && pos[1][(i+B)%360] && pos[2][(i+C)%360] && pos[3][(i+D)%360] && pos[4][(i+E)%360]) {
				// matches 
				found = 1; 
				cout << i << '\n'; 
				cout << t << '\n'; 
			}	
		}
		A += speed[0]; A %= 360; 
		B += speed[1]; B %= 360; 
		C += speed[2]; C %= 360; 
		D += speed[3]; D %= 360; 
		E += speed[4]; E %= 360; 
	}
	if (!found) cout << "none" << '\n'; 

	return 0; 
}
