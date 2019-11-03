#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
vector <pair<int, int>> v;
double dp[513][513];
int n;
double cal(int a,int b) {
	return sqrt((v[a].first - v[b].first)*(v[a].first - v[b].first)+
		(v[a].second - v[b].second)*(v[a].second - v[b].second));
}
double solve(int a,int b) {
	if (a == n - 1 || b == n - 1) {
		if (a != n - 1) return cal(a, n - 1);
		if (b != n - 1) return cal(b, n - 1);
	}
	double &ref = dp[a][b];
	if (ref != -1) return ref;
	ref = 987654321;

	int m = max(a, b) + 1;
	ref = min(ref, solve(a, m) + cal(b, m));
	ref = min(ref, solve(m, b) + cal(a, m));
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int c, d; cin >> c >>  d;
			v.push_back({ c,d });
		}
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) dp[i][k] = -1;
		}
	
		cout << solve(0, 0) << "\n";
		v.clear();
	}
}