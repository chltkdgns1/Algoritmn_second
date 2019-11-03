#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int map[21][21];
vector <pair<int, int>> black;
vector <pair<int, int>> white;
bool visit[4][21][21];
int dx[8] = { 0,0,-1,1,1,-1,-1,1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

int vic;
pair <int, int> res;

bool check(int x, int y) {
	if (x >= 0 && x <= 18 && y >= 0 && y <= 18) return true;
	else return false;
}
void dfs(int x, int y, int dir, int col, int st, int s_x, int s_y) {
	bool br = 0;
	for (int i = 0; i < 8; i++) {
		int k;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (i % 2 == 1) k = i - 1;
		else k = i;
		if (check(nx, ny)) {
			if (dir * 2 == k && !visit[dir][ny][nx] && map[ny][nx] == col) {
				visit[dir][ny][nx] = 1;
				br = 1;
				dfs(nx, ny, dir, col, st + 1, s_x, s_y);
			}
		}
	}
	if (!br) {
		if (st == 5) {
			vic = col;
			if (x < s_x) res.first = x, res.second = y;
			else if(x > s_x) res.first = s_x, res.second = s_y;
			else {
				if (s_y < y) res.first = s_x, res.second = s_y;
				else res.first = x, res.second = y;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 19; i++) {
		for (int k = 0; k < 19; k++) {
			cin >> map[i][k];
			if (map[i][k] == 1) black.push_back({ k,i });
			else if (map[i][k] == 2) white.push_back({ k,i });
		}
	}
	for (int i = 0; i < black.size(); i++) {
		int x = black[i].first;
		int y = black[i].second;
		for (int z = 0; z < 4; z++) {
			visit[z][y][x] = 1;
			dfs(x, y, z, 1, 1, x, y);
			if (vic) {
				cout << vic << "\n";
				cout << res.second + 1 << " " << res.first + 1 << "\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < white.size(); i++) {
		int x = white[i].first;
		int y = white[i].second;
		for (int z = 0; z < 4; z++) {
			visit[z][y][x] = 1;
			dfs(x, y, z, 2, 1, x, y);
			if (vic) {
				cout << vic << "\n";
				cout << res.second + 1 << " " << res.first + 1 << "\n";
				return 0;
			}
		}
	}
	cout << 0 << "\n";
}