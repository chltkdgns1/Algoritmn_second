#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define inf 10000000000
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, d; cin >> n >> m >> d;

	vector<vector<int>> v(n + 1);
	vector<vector<ll>> dp(n + 1);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) dp[i].push_back(-inf);
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			int a; cin >> a;
			v[i].push_back(a);
		}
	}

	int q, w;
	for (int i = 0; i < m; i++) dp[0][i] = 0;
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < m; k++) {
			q = k - d < 0 ? 0 : k - d;
			w = k + d >= m ? m - 1 : k + d;
			for (int z = 1; z <= d; z++) {
				if (i - z >= 0) {
					for (int x = q; x <= w; x++) {
						if (z + abs(k - x) <= d) {
							dp[i][k] = max(dp[i][k], dp[i - z][x] +
								v[i][k] * v[i - z][x]);
						}
					}
				}
				else break;
			}
		}
	}
	ll res = -inf;
	for (int i = 0; i < m; i++) res = max(res, dp[n - 1][i]);
	cout << res << "\n";
}