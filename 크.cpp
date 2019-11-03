#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
int n, m, h;
int map[1001][1001][4];
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
bool visit[1001][1001];
int wt[1001][1001];

set <pair<int, int>> s;
priority_queue < pair<int, pair<int, int>>> q;

bool check(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> h;
	int d;
	for (int i = 0; i <= n; i++) {
		for (int k = 0; k < m; k++) {
			wt[i][k] = h;
			cin >> d;
			if (!i) map[i][k][0] = d;
			else if (i == n) map[i - 1][k][2] = d;
			else map[i][k][0] = d,map[i - 1][k][2] = d;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= m; k++) {
			cin >> d;
			if (!k) map[i][k][3] = d;
			else if (k == m) map[i][k - 1][1] = d;
			else map[i][k - 1][1] = d,map[i][k][3] = d;	
		}
	}
	for (int i = 0; i < n; i++) { // 세로
		for (int z = 0; z < 4; z++) {
			int x = m - 1 + dx[z], xx = 0 + dx[z];
			int y = i + dy[z];
			int w = map[i][m - 1][z], ww = map[i][0][z];
			if (!check(x, y) && w != -1) {
				s.insert({ m - 1,i });
				int &r = wt[i][m - 1];
				r = min(r, w);
			}
			if (!check(xx, y) && ww != -1) {
				s.insert({ 0 ,i });
				int &r = wt[i][0];
				r = min(r, ww);
			}
		}
	}
	for (int k = 0; k < m; k++) { // 가로
		for (int z = 0; z < 4; z++) {
			int x = k + dx[z];
			int y = n - 1 + dy[z], yy = 0 + dy[z];
			int w = map[n - 1][k][z], ww = map[0][k][z];
			if (!check(x, y) && w != -1) {
				int &r = wt[n - 1][k];
				r = min(r, w);
				s.insert({ k ,n - 1 });
			}
			if (!check(x, yy) && ww != -1) {
				int &r = wt[0][k];
				r = min(r, ww);
				s.insert({ k ,0});
			}
		}
	}
	for (auto a : s) {
		int c = a.first, d = a.second;
		q.push({ -wt[d][c],{c,d} });
	}

	while (!q.empty()) {
		int wh = -q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		visit[y][x] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (check(nx, ny) && !visit[ny][nx] && map[y][x][i] != -1) {
				if (wh <= map[y][x][i] && map[y][x][i] < wt[ny][nx]) {
					wt[ny][nx] = map[y][x][i];
					q.push({ -wt[ny][nx],{nx,ny} });
				}
				else if (wh > map[y][x][i]) {
					wt[ny][nx] = wh;
					q.push({ -wt[ny][nx],{nx,ny} });
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			res += wt[i][k];
		}
	}
	cout << res << "\n";
}