#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector <int> v(10001), e[10001];

int dp[10001][2];
int solve(int s, bool r , int p) {
	int &ref = dp[s][r];
	if (ref != -1) return ref;

	ref = 0;
	if (r) ref = v[s];

	for (auto a : e[s]) {
		if (a == p) continue;

		int q = 0;
		if (!r) q = max(q, solve(a, 1, s));
		q = max(q, solve(a, 0, s));
		ref += q;
	}
	return ref;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i + 1];
	
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	int res = 0;
	res = max(res, solve(1, 0,-1));
	res = max(res, solve(1, 1,-1));

	cout << max(solve(1, 0, -1), solve(1, 1, -1)) << "\n";
}