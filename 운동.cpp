#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987564321
using namespace std;

typedef long long ll;
ll dis[401][401];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int v, e; cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		for (int k = 1; k <= v; k++) {
			if (i == k) dis[i][k] = 0;
			else dis[i][k] = INF;
		}
	}
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		dis[a][b] = c;
	}


	for (int i = 1; i <= v; i++) {
		for (int k = 1; k <= v; k++) {
			for (int d = 1; d <= v; d++) {
				if (dis[k][d] > dis[k][i] + dis[i][d]) {
					dis[k][d] = dis[k][i] + dis[i][d];
				}
			}
		}
	}

	ll res = INF;
	for (int i = 1; i <= v; i++) {
		for (int k = 1; k <= v; k++) {
			if (i == k) continue;
			res = min(res, dis[i][k] + dis[k][i]);
		}
	}
	if (res == INF) cout << -1 << "\n";
	else cout << res << "\n";
}