#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector <pair<int, int>> v;
int dp[301][301];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x, y; cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	memset(dp, -1, sizeof(dp));
	dp[x][y] = 0;
	int max = 0;
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].first;
		int b = v[i].second;
		for (int k = 0; k <= x; k++) {
			for (int z = 0; z <= y; z++) {
				if (dp[k][z] != -1) {
					if (k - a >= 0 && z - b >= 0) {
						if (dp[k - a][z - b] < dp[k][z] + 1) {
							dp[k - a][z - b] = dp[k][z] + 1;
							if (max < dp[k][z] + 1) max = dp[k][z] + 1;
						}
					}
				}
			}
		}
	}
	cout << max << "\n";
}