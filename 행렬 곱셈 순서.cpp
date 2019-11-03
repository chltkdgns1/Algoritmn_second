#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <pair<int, int>> v;
ll dp[501][501];
ll cal(int a, int b) {
	return v[a].first*v[a].second*v[b].second;
}
ll solve(int a,int b) {
	if (a == b) return 0;
	if (a + 1 == b) {
		return cal(a, b);
	}
	ll & ref = dp[a][b];
	if (ref) return ref;
	ref = 987654321321;
	for (int i = a ; i < b; i++) {
		ref = min(ref,solve(a, i) + solve(i + 1, b) + v[a].first*v[i].second*v[b].second);
	}
	return ref;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	cout << solve(0, n - 1) << "\n";
}