#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int map[11][11];
int dp[11][1 << 10];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) cin >> map[i][k];
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < (1 << n); k++) dp[i][k] = INF;
	}
	dp[1][0] = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int k = 1; k <= n; k++) {
			if (dp[k][i] != INF) {
				for (int z = 0; z < n; z++) {
					if (!map[k][z + 1]) continue;
					if (!(i & (1 << z))) {
						dp[z + 1][i | (1 << z)] = min(dp[z + 1][i | (1 << z)], dp[k][i] + map[k][z + 1]);
					}
				}
			}
		}
	}
	cout << dp[1][(1 << n) - 1] << "\n";
}