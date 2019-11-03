#include <iostream>
#include <vector>
using namespace std;
int map[101][101];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int n, m;
bool check(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}
void air(int x, int y) {
	map[y][x] = -1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(nx, ny) && !map[ny][nx]) air(nx, ny);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k]) cnt++;
		}
	}
	if (!cnt) { cout << 0; return 0;}
	int t = 0;
	while (1) {
		t++;
		vector <pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				if (!i || i == n - 1 || !k || k == n - 1) {
					if (!map[i][k]) air(k, i);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				if (map[i][k] == 1) {
					int cnt = 0;
					for (int z = 0; z < 4; z++) {
						int x = k + dx[z];
						int y = i + dy[z];
						if (check(x, y) && map[y][x] == -1) cnt++;
					}
					if (cnt >= 2) v.push_back({ k,i });
				}
			}
		}
		for (int i = 0; i < v.size(); i++) map[v[i].second][v[i].first] = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				if (map[i][k] == 1) cnt++;
				if (map[i][k] == -1) map[i][k] = 0;
			}
		}
		if (!cnt) break;
	}
	cout << t << "\n";
}