/*
ID: s3yoonpark
LANG: C++
PROB: spin
*/ 

#include <iostream> 
#include <vector> 
using namespace std;

struct Wedge {
	int angle; 	
	int extent; 
};
typedef struct Wedge Wedge; 


vector<vector<Wedge>> wheels (5, vector<Wedge>()); 		
int speed[5]; 
int ans = INT_MAX; 

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	//freopen("spin.in", "r", stdin); 
	//freopen("spin.out", "w", stdout); 
	
	for (int i = 0; i < 5; ++i) {
		cin >> speed[i]; 
		int numWedge; 
		cin >> numWedge; 
		for (int j = 0; j < numWedge; ++j) {
			Wedge t; 
			cin >> t.angle >> t.extent; 
			wheels[i].push_back(t); 
		}
	}
	for (Wedge& a : wheels[0]) {
		for (Wedge& b : wheels[1]) {
			for (Wedge& c : wheels[2]) {
				for (Wedge& d : wheels[3]) {
					for (Wedge& e : wheels[4]) {
						// a b c d e find the minimum time 
						int tAns; 
						

					}
				}
			}
		}
	}

	return 0; 
}
