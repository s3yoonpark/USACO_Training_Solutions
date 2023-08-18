/*
ID: s3yoonpark
LANG: C++
PROB: cowtour 
*/ 

#include <bits/stdc++.h> 
using namespace std;

const int mxN = 150;
const int INF = 200000; 
int N; 
pair<int,int> pastures[mxN]; 
bool matrix[mxN][mxN]; 
int groupID[mxN]; 
bool visited[mxN]; 
int groupNum; 
double maxDiameter[mxN]; 
double groupDiameter[mxN]; 

void assignID(int node) {
	groupID[node] = groupNum; 
	visited[node] = 1; 
	for (int i = 0; i < N; ++i) {
		if (matrix[node][i] && !visited[i]) {
			assignID(i); 
		}
	}	
	return; 
}

double dist(int a, int b) {
	return sqrt(pow(pastures[a].first - pastures[b].first, 2) + pow(pastures[a].second - pastures[b].second, 2)); 
}

double calculate(int node) {
	double maxD = 0; 
	double distance[mxN]; 
	bool processed[mxN]; 
	memset(processed, 0, sizeof(processed)); 
	for (int i = 0; i < N; ++i) distance[i] = INF; 
	priority_queue<pair<double,int>> q; 
	distance[node] = 0; 
	q.push({0, node}); 
	while (!q.empty()) {
		int a = q.top().second; q.pop(); 	
		if (processed[a]) continue; 
		processed[a] = 1; 
		for (int i = 0; i < N; ++i) {
			if (matrix[a][i]) {
				int b = i; 
				double w = dist(a, b); 
				if (distance[a] + w < distance[b]) {
					distance[b] = distance[a] + w; 
					q.push({-distance[b], b}); 
				}
			}
		}
		maxD = max(maxD, distance[a]); 
	}
	return maxD; 
}

int main() {
	freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
	cin >> N; 
	for (int i = 0; i < N; ++i) {
		cin >> pastures[i].first >> pastures[i].second; 
	}
	for (int i = 0; i < N; ++i) {
		string s; 
		cin >> s; 
		for (int j = 0; j < N; ++j) {
			matrix[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			assignID(i); 
			++groupNum; 
		}
	}
	for (int i = 0; i < N; ++i) {
		double diameter = calculate(i); 
		groupDiameter[groupID[i]] = max(groupDiameter[groupID[i]], diameter); 
		maxDiameter[i] = diameter; 
	}
	double ans = INF; 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (groupID[i] == groupID[j]) {
				continue; 
			}
			ans = min(ans, max(max(groupDiameter[groupID[i]], groupDiameter[groupID[j]]), maxDiameter[i] + dist(i, j) + maxDiameter[j])); 
		}
	}
	printf("%0.6f\n", ans); 


	return 0; 
}
