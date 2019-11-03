#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[201][201];
vector <int> v;
int solve(int a, int b) {
	if (a == b) return 0;
	int &ref = dp[a][b];
	if (ref != -1) return ref;
	ref = 987654321;
	for (int i = a; i < b; i++) {
		int d = v[a] == v[i + 1] ? 0 : 1;
		ref = min(ref, solve(a, i) + solve(i + 1,b) + d);
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (v.empty()) v.push_back(a);
		else if (v.back() == a) continue;
		else v.push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, v.size() - 1) << "\n";
}