#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
#define INF 9876543210
ll dp[17][(1 << 16)];
int map[17][17];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= 16; i++) {
		for (int k = 0; k < (1 << 16); k++) dp[i][k] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			cin >> map[i][k];
		}
	}
	dp[1][1] = 0;
	// 각자의 시작 위치
	for (int k = 0; k < (1 << n); k++) {
		for (int i = 1; i <= n; i++) {
			if (k == (1 << n) - 1) {
				if (!map[i][1]) dp[i][k] = INF;
				else dp[i][k] += map[i][1];
			}
			else {
				if (dp[i][k] != INF) {
					for (int z = 1; z < n; z++) {
						int d = 1 << z;
						if (k == (k | d) || !map[i][z + 1]) continue;
						else {
							if (dp[z + 1][k | d] > dp[i][k] + map[i][z + 1]) {
								dp[z + 1][k | d] = dp[i][k] + map[i][z + 1];
							}
						}
					}
				}
			}
		}
	}
	ll res = INF;
	for (int i = 2; i <= n; i++) {
		if (res > dp[i][(1 << n) - 1]) res = dp[i][(1 << n) - 1];
	}
	cout << res << "\n";
}