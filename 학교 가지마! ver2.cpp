#include <iostream>
#include <cstring>
#include <math.h>
#include <queue>
using namespace std;

char map[101][101];
bool visit[101][101];
int a, b, c, d;
int n, m;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool dfs2(int x, int y) {
	queue <pair<int, int>> q;
	q.push({ x,y });
	visit[y][x] = 1;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = nx + dx[i];
			int y = ny + dy[i];
			if (0 <= x && x < m && 0 <= y && y < n) {
				if (map[y][x] != '#' && !visit[y][x]) {
					if (map[y][x] == 'H') return false;
					q.push({ x,y });
					visit[y][x] = 1;
				}
			}
		}
	}
	return true;
}

int dfs() {
	if (dfs2(b, a) == true) {
		return 0;
	}
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (map[i][k] == '.') {
				map[i][k] = '#';
				if (dfs2(b, a) == true) {
					return 1;
				}
				memset(visit, 0, sizeof(visit));
				map[i][k] = '.';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (map[i][k] == '.') {
				map[i][k] = '#';
				for (int i = 0; i < n; i++) {
					for (int k = 0; k < m; k++) {
						if (map[i][k] == '.') {
							map[i][k] = '#';
							if (dfs2(b, a) == true) {
								return 2;
							}
							memset(visit, 0, sizeof(visit));
							map[i][k] = '.';
						}
					}
				}
				map[i][k] = '.';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (map[i][k] == '.') {
				map[i][k] = '#';
				for (int i = 0; i < n; i++) {
					for (int k = 0; k < m; k++) {
						if (map[i][k] == '.') {
							map[i][k] = '#';
							for (int i = 0; i < n; i++) {
								for (int k = 0; k < m; k++) {
									if (map[i][k] == '.') {
										map[i][k] = '#';
										if (dfs2(b, a) == true) {
											return 3;
										}
										memset(visit, 0, sizeof(visit));
										map[i][k] = '.';
									}
								}
							}
							map[i][k] = '.';
						}
					}
				}
				map[i][k] = '.';
			}
		}
	}
	return 4;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k] == 'K') a = i, b = k;
			else if (map[i][k] == 'H') c = i, d = k;
		}
	}
	if (abs(a - c) + abs(b - d) == 1) {
		cout << -1 << "\n";
		return 0;
	}
	cout << dfs() << "\n";
}