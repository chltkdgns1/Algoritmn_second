#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
vector <pair<int, int>> v[501];
int d[501];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, w; cin >> n >> m >> w;
		int a, b, c;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}
		for (int i = 0; i < w; i++) {
			cin >> a >> b >> c;
			v[a].push_back({ b,-c });
		}
		fill(d + 1, d + n + 1, INF);
		bool flag = 0;
		d[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int z = 1; z <= n; z++) {
				for (int k = 0; k < v[z].size(); k++) {
					int next = v[z][k].first;
					int dis = v[z][k].second;
					if (d[z] != INF && d[next] > d[z] + dis) {
						d[next] = d[z] + dis;
						if (i == n) {
							flag = 1;
							break;
						}
					}
				}
			}
		}
		if (flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		for (int i = 1; i <= n; i++) v[i].clear();
	}
}