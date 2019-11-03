#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

#define inf 10000000000
typedef long long ll;
vector<vector<int>> v;
vector<vector<ll>> dp;
int n, m, d;

ll solve(int a, int b) {
	if (a >= n) return 0;

	ll &ref = dp[a][b];
	if (ref) return ref;

	int q , w;
	
	ref = -inf;
	for (int i = a + 1; i <= a + d; i++) {

		q = (b - d + i - a < 0 ? 0 : b - d);
		w = (b + d - (i - a) >= m ? m - 1 : b + d);

		for (int k = q; k <= w; k++) {
			if (i - a + abs(k - b) <= d) {
				if (i <= n - 1) {
					ref = max(ref, solve(i, k) + v[i][k] * v[a][b]);
				}
			}
		}
	}
	if (ref == -inf) ref = 0;
	return ref;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	 cin >> n >> m >> d;

	v.resize(n + 1);
	dp.resize(n + 1);

	for (int i = 0; i < n; i++) dp[i].resize(m);
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			int a; cin >> a;
			v[i].push_back(a);
		}
	}

	ll res = -inf;

	for (int i = 0; i < m; i++) {
		res = max(res, solve(0, i));
	}
	cout << res << "\n";
}