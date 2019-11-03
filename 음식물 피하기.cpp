#include <iostream>
#include <algorithm>
using namespace std;

int map[101][101],n, m, q;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool visit[101][101];

int dfs(int x, int y) {
	visit[y][x] = 1;
	int t = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
			if (map[ny][nx] == 1 && !visit[ny][nx]) {
				visit[ny][nx] = 1;
				t += dfs(nx, ny);
			}
		}
	}
	return t;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++) {
		int a, b; 
		cin >> a >> b;
		map[a][b] = 1;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			if (map[i][k] == 1 && !visit[i][k]) {
				res = max(res,dfs(k, i));
			}
		}
	}
	cout << res << "\n";
}