#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define INF 987654321
using namespace std;
double map[17][17];
double dp[17][1 << 16];
vector <pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int k = 0; k < v.size(); k++) {
			int x = v[i].first, y = v[i].second;
			int nx = v[k].first, ny = v[k].second;
			map[i + 1][k + 1] = sqrt((x - nx)*(x - nx) + (y - ny)*(y - ny));
		}
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
						if (dp[z + 1][i | (1 << z)] > dp[k][i] + map[k][z + 1]) {
							dp[z + 1][i | (1 << z)] = dp[k][i] + map[k][z + 1];
						}
					}
				}
			}
		}
	}
	printf("%.6lf\n", dp[1][(1 << n) - 1]);
}