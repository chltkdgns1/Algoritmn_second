#include <iostream>
#include <queue>
using namespace std;

int map[101][101][101];
bool check[101][101][101];
int m, n, h;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
class Data {
public:
	int x, y, h;
};
Data d;
queue <Data> q;
void bfs() {
	while (!q.empty()) {
		int x1, y1, h1;
		x1 = q.front().x;
		y1 = q.front().y;
		h1 = q.front().h;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			int nh = h1 + dh[i];
			if (nx >= 0 && ny >= 0 && nh >= 0 && nx < m && ny < n && nh < h) {
				if (map[nh][ny][nx] == 0 && check[nh][ny][nx] == false) {
					check[nh][ny][nx] = true;
					map[nh][ny][nx] = map[h1][y1][x1] + 1;
					d.h = nh, d.x = nx, d.y = ny;
					q.push(d);
				}
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					d.h = i, d.y = j, d.x = k;
					q.push(d);
					check[i][j][k] = true;
				}
			}
		}
	}
	bfs();
	int max = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (max < map[i][j][k]) max = map[i][j][k];
				if (map[i][j][k] == 0) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	cout << max - 1 << endl;
}