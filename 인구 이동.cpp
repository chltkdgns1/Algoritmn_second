#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
int map[51][51];
int visit[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, r, l;
int dfs(int x, int y,int check) {
	visit[y][x] = check;
	int length = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (!visit[ny][nx] && (abs(map[y][x] - map[ny][nx]) >= l
				&& abs(map[y][x] - map[ny][nx]) <= r)) {
				length += dfs(nx,ny, check);
			}
		}
	}
	return length;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> map[i][k];
		}
	}
	int check = 1, key_cnt = 0;
	for (int a = 0; a < 2000; a++) {
		int br_cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				if (!visit[i][k]) {
					if (dfs(k, i, check) >= 2) {
						br_cnt++;
						int total = 0, cnt = 0;
						for (int y = 0; y < n; y++) {
							for (int x = 0; x < n; x++) {
								if (visit[y][x] == check) {
									total += map[y][x];
									cnt++;
								}
							}
						}
						total /= cnt;
						for (int y = 0; y < n; y++) {
							for (int x = 0; x < n; x++) {
								if (visit[y][x] == check) {
									map[y][x] = total;
								}
							}
						}
					}
					check++;
				}
			}
		}
		key_cnt++;
		if (!br_cnt) break;
		memset(visit, 0, sizeof(visit));
	}
	cout << key_cnt - 1 << "\n";
}