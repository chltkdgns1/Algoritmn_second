#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

char map[101][101];
bool visit[101][101];
int a, b, c, d;
int n, m;
int dx[4] = { 0,0,1,-1 },dy[4] = { 1,-1,0,0 };
bool dfs2(int x, int y) {
	if (map[y][x] == 'H') return false;
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if (!visit[ny][nx] && map[ny][nx] != '#') {
				if (dfs2(nx,ny) == false) {
					return false;
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