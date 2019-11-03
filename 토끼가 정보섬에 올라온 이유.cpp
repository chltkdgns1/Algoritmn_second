#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

queue <pair<int, int>> q;
char map[1001][1001];
int dis[1001][1001];
int n, m, dx[3] = { 1,1,1 }, dy[3] = { 0,1,-1 }, max1 = -2;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 3; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if ((map[ny][nx] == '.' || map[ny][nx] == 'O') && dis[y][x] > dis[ny][nx]){
					dis[ny][nx] = dis[y][x];
					if (map[ny][nx] == 'O' && max1 < dis[y][x]) max1 = dis[y][x];
					q.push({ nx,ny });
				}
				else if (map[ny][nx] == 'C' && dis[y][x] + 1 > dis[ny][nx]) {
					dis[ny][nx] = dis[y][x] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(dis, -2, sizeof(dis));
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k] == 'R') q.push({ k,i }), dis[i][k] = 0;
		}
	}
	bfs();
	if (max1 == -2) cout << -1 << "\n";
	else cout << max1 << "\n";
}