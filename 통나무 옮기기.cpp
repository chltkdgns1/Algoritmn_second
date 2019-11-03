#include <iostream>
#include <queue>
using namespace std;
char map[51][51];
bool visit[51][51][2],state2;
int x2 , y2 ,dx[8] = { 0,0,1,-1,1,1,-1,-1 },dy[8] = { 1,-1,0,0,1,-1,1,-1 },n;

bool check(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < n) return true;
	return false;
}

bool posCheck(int x, int y,bool s) {
	if (!s) { // 가로 
		if (map[y][x - 1] != '1' && map[y][x] != '1' && map[y][x + 1] != '1') return true;
	} 
	else { // 세로
		if (map[y - 1][x] != '1' && map[y][x] != '1' && map[y + 1][x] != '1') return true;
	}
	return false;
}

bool cycleCheck(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[ny][nx] == '1') {
			return false;
		}
		if (!check(nx, ny)) {
			return false;
		}
	}
	return true;
}

void bfs(int x,int y,bool state) {

	visit[y][x][state] = 1;
	queue < pair<pair<int, int>, bool>> q;
	q.push({ { x,y }, state });
	int cnt = 0;
	while (1) {

		int len = q.size();
		if (!len) break;

		for (int i = 0; i < len; i++) {	

			int nx = q.front().first.first;
			int ny = q.front().first.second;
			bool st = q.front().second;	
			q.pop();

			if (nx == x2 && ny == y2 && st == state2) {
				cout << cnt << "\n";
				return;
			}
			for (int k = 0; k < 4; k++) {

				int x = nx + dx[k];
				int y = ny + dy[k];
				if (!st) {

					if (dx[k]) {

						if (!visit[y][x][st] && check(x + dx[k], y) && posCheck(x,y,st)) {
							visit[y][x][st] = 1;
							q.push({ {x,y} ,st });
						}
					}
					else {

						if (!visit[y][x][st] && check(x, y) && posCheck(x, y, st)) {
							visit[y][x][st] = 1;
							q.push({ {x,y} ,st });
						}

					}
				}

				else { 
					if (dy[k]) {

						if (!visit[y][x][st] && check(x, y + dy[k]) && posCheck(x, y, st)) {
							visit[y][x][st] = 1;
							q.push({ {x,y} ,st });
						}

					}
					else {

						if (!visit[y][x][st] && check(x, y)) {

							if (posCheck(x, y,st)) {
								visit[y][x][st] = 1;
								q.push({ {x,y} ,st });
							}
						}
					}
				}
			}

			if (cycleCheck(nx, ny)) {
				st ^= 1;
				if (!visit[ny][nx][st]) {
					visit[ny][nx][st] = 1;
					q.push({ { nx,ny },st });
				}
			}
		}
		cnt++;
	}
	cout << 0 << "\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int a = 0, b = 0, c = 0, d = 0;
	int x1 = 0, y1 = 0;
	bool br1 = 0, br2 = 0, state1 = 0;

	for (int i = 0; i < n; i++) {	

		for (int k = 0; k < n; k++) {			
			cin >> map[i][k];	

			if (map[i][k] == 'B') {
				x1 += k, y1 += i;	
				if (!br1) a = k, b = i, br1 = 1;

				else {
					if (a == k) state1 = 1; // 세로
					else state1 = 0; // 가로
				}

			}
			else if (map[i][k] == 'E') {

				x2 += k, y2 += i;

				if (!br2) c = k, d = i,br2=1;

				else {
					if (c == k) state2 = 1;
					else state2 = 0;
				}
			}
		}
	}	
	x1 /= 3; y1 /= 3;
	x2 /= 3; y2 /= 3;
	bfs(x1,y1,state1);
}