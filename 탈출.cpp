#include <iostream>
#include <queue>
using namespace std;

char map[51][51];
bool check_w[51][51];
bool check_s[51][51];
queue <pair<int, int>> w;
queue <pair<int, int>> s;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;
int key;
void bfs(int xpos,int ypos) {
	s.push({ xpos,ypos });
	check_s[ypos][xpos] = true;
	int cnt = 1;
	while (1) {
		int len_w = w.size(), len_s = s.size();
		if (len_s == 0) return;
		for (int i = 0; i < len_w; i++) {
			int x1 = w.front().first;
			int y1 = w.front().second;
			w.pop();
			for (int i = 0; i < 4; i++) {
				int x = x1 + dx[i];
				int y = y1 + dy[i];
				if (x >= 0 && y >= 0 && x < m && y < n) {
					if (map[y][x] != 'X' && map[y][x] != 'D' && check_w[y][x] == false) {
						check_w[y][x] = true;
						map[y][x] = '*';
						w.push({ x,y });
					}
				}
			}
		}
		for (int i = 0; i < len_s; i++) {
			int x1 = s.front().first;
			int y1 = s.front().second;
			s.pop();
			for (int i = 0; i < 4; i++) {
				int x = x1 + dx[i];
				int y = y1 + dy[i];
				if (x >= 0 && y >= 0 && x < m && y < n) {
					if (map[y][x] == 'D') {
						key = cnt;
						return;
					}
					if (map[y][x] =='.' && check_s[y][x] == false ) {
						check_s[y][x] = true;
						s.push({ x,y });
					}
				}
			}
		}
		cnt++;
	}
}
int main() {
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '*') {
				check_w[i][j] = true;
				w.push({ j,i });
			}
			if (map[i][j] == 'S') { x = j, y = i; }
		}
	}
	bfs(x, y);
	if (key) cout << key << endl;
	else cout << "KAKTUS" << endl;
}