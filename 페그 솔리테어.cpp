#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
char map[6][10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int min1 = 1e9, min2 = 1e9;
bool lineCheck(int x, int y) {
	if (x>=0 && x<9 && y>=0 && y<5) return true;
	return false;
}
void dfs(int xpos, int ypos,int pin,int move) {
	for (int i = 0; i < 4; i++) {
		int x = xpos + dx[i], y = ypos + dy[i];
		if (lineCheck(x,y) && map[y][x] == 'o') {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (lineCheck(nx,ny) && map[ny][nx] == '.') {
				map[ypos][xpos] = map[y][x] = '.';
				map[ny][nx] = 'o';
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 9; j++) {
						if (map[i][j] == 'o') {
							dfs(j, i, pin - 1, move + 1);
						}
					}
				}
				map[ypos][xpos] = map[y][x] = 'o';
				map[ny][nx] = '.';
			}
		}
	}
	if (min1 > pin) {
		min1 = pin;
		min2 = move;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int n = 0;
		vector <pair<int, int>> v;
		for (int i = 0; i < 5; i++) {
			cin >> map[i];
			for (int j = 0; j < 9; j++) {
				if (map[i][j] == 'o') {
					v.push_back({ j,i });
					n++;
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			dfs(v[i].first, v[i].second, n,0);
		}
		cout << min1 << " " << min2 << "\n";
		min1 = min2 = 1e9;
	}
}