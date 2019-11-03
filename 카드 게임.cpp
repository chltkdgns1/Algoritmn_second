#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[1001][1001];
vector <int> v;
int solve(int s, int e,int cnt) {
	if (s > e) return 0;
	if (dp[s][e] != -1) return dp[s][e];
	int &res = dp[s][e];
	res = 0;
	if (!(cnt % 2)) res = max(solve(s + 1, e, cnt + 1) + v[s],solve(s,e - 1,cnt + 1) + v[e]);
	else res = min(solve(s + 1, e, cnt + 1), solve(s, e - 1, cnt + 1));
	return dp[s][e];
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; v.push_back(a);
		}
		memset(dp, -1, sizeof(dp));
		cout << solve(0, n - 1, 0) << "\n";
		v.clear();
	}
}