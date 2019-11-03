#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> v;
int n;
int dp[1500001];
int solve(int t) {
	if (t >= n) return 0;
	int &res = dp[t];
	if (res) return res;

	if(t + v[t].first <= n) res = max(res, solve(t + v[t].first) + v[t].second);
	if(t + 1 <= n) res = max(res, solve(t + 1));
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	cout << solve(0) << "\n";
}