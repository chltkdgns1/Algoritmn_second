#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

vector <pair<int, int>> v[501];
int dist[501]; // 어느 한 정점에서부터의 각 정점의 거리
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[1] = 0;
	bool br = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int z = 0; z < v[k].size(); z++) {
				int y = v[k][z].first;
				if (dist[k] != INF && dist[y] > dist[k] + v[k][z].second) {
					dist[y] = dist[k] + v[k][z].second;
					if (i == n) {
						br = 1;
						break;
					}
				}
			}
		}
	}
	if (br) { cout << -1 << "\n"; return 0; }
	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF) cout << -1<<"\n";
		else cout << dist[i] << "\n";
	}
}