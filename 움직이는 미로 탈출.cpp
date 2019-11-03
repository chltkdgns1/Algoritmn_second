#include <iostream>
#include <queue>
using namespace std;

char map[9][9];
int dx[8] = { 1,-1,0,0,1,1,-1,-1};
int dy[8] = { 0,0,1,-1,1,-1,1,-1};
bool visit[200][9][9];

void bfs(int x, int y) {
	visit[0][y][x] = 1;
	queue <pair<int,pair<int, int>>> q;
	q.push({ 0,{ x,y } });
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int nx = q.front().second.first;
			int ny = q.front().second.second;
			int c = q.front().first;
			q.pop();
			if (map[ny][nx] == '#') {
				visit[c][ny][nx] = 0;
				continue;
			}
			if (nx == 7 && ny == 0) {
				cout << 1 << "\n";
				return;
			}
			for (int i = 0; i < 8; i++) {
				int x = nx + dx[i];
				int y = ny + dy[i];
				if (x >= 0 && x < 8 && y >= 0 && y < 8) {
					if (!visit[c][y][x] && map[y][x] != '#') {
						visit[c][y][x] = 1;
						q.push({ c,{ x,y } });
					}
				}
			}
			visit[c + 1][ny][nx] = 1;
			q.push({ c + 1,{ nx,ny } });
		}
		for (int i = 7; i >=0; i--) {
			for (int k = 0; k < 8; k++) {
				if (map[i][k] == '#') {
					map[i][k] = '.';
					if (i + 1 < 8) {
						map[i + 1][k] = '#';
					}
				}
			}
		}
	}
	cout << 0 << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 8; i++) {
		for (int k = 0; k < 8; k++) {
			cin >> map[i][k];
		}
	}
	bfs(0, 7);
}