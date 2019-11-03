#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[301][301];
int dis[301][301];
vector <pair<int, int>> v[301];
int n, m, k;
int dfs(int s,int cnt) {
	if (cnt == m && s != n) return -987654321;
	int &res = dp[cnt][s];
	if (res != -1) return res;
	res = 0;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i].first;
		int d = v[s][i].second;
		int t = dfs(y, cnt + 1) + d;
		res = max(res, t);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a < b && dis[a][b] < c) {
			dis[a][b] = c;
			v[a].push_back({ b,c });
		}
	}
	for (int i = 0; i <= m; i++) {
		for (int k = 1; k <= n; k++) dp[i][k] = -1;
	}
	cout<<dfs(1, 1)<<"\n";
}