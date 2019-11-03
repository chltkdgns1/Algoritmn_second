#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 9876543210
using namespace std;
vector <pair<int, int>> v[101];
int d[101];
long long dp[101];
bool cycle[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, s, e, m; cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++) cin >> d[i];
	for (int i = 0; i < n; i++) dp[i] = INF;
	dp[s] = -d[s];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			for (int z = 0; z < v[k].size(); z++) {
				int y = v[k][z].first;
				int cost = v[k][z].second;
				if (dp[k] != INF && dp[y] > dp[k] + cost - d[y]) {
					if (i == n - 1) cycle[k] = 1, cnt++;
					else dp[y] = dp[k] + cost - d[y];
				}
			}
		}
	}
	if (dp[e] == INF) cout << "gg" << "\n";
	else {
		int c = 0, index = -1;
		for (int i = 0; i < n; i++) {
			if (cycle[i]) {
				queue <int> q;
				bool visit[101];
				memset(visit, 0, sizeof(visit));
				q.push(i);
				visit[i] = 1;
				while (!q.empty()) {
					int node = q.front();
					if (node == e) {
						cout << "Gee" << "\n";
						return 0;
					}				
					q.pop();
					for (int i = 0; i < v[node].size(); i++) {
						int y = v[node][i].first;
						if (!visit[y]) {
							visit[y] = 1;
							q.push(y);
						}
					}
				}
			}
		}
		cout << -dp[e] << "\n";
	}
}