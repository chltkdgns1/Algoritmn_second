#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <pair<int, int>> v;
vector <pair<int, int>> p; // ¸ñÇ¥
char map[6][6];
bool check[6][6];
int dis[6][6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int result;
bool canGo(int x, int y) {
	if (x >= 0 && y >= 0 && x < 5 && y < 5) return true;
	return false;
}
void bfs(int x, int y) {
	check[y][x] = 1;
	queue <pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = nx + dx[i];
			int y = ny + dy[i];
			if (canGo(x,y)) {
				if (!check[y][x] && map[y][x] == '.') {
					check[y][x] = 1;
					q.push({ x,y });
					dis[y][x] = dis[ny][nx] + 1;
				}
			}
		}
	}
}
bool moveCheck(int x,int y) {
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (canGo(nx, ny)) {
			if (map[ny][nx] == '*') {
				p.push_back({ nx,ny });
				return true;
			}
		}
	}
	return false;
}
void firstCheck(int x, int y) {
	int min = 1e6, a, b,idx;
	for (int i = 0; i < v.size(); i++) {
		if (i) {
			for (int k = 0; k < 4; k++) {
				int x = v[i].first + dx[k];
				int y = v[i].second + dy[k];
				if (canGo(x, y) && map[y][x] != '*') {
					if (min > dis[y][x]) {
						min = dis[y][x];
						a = x, b = y;
						idx = i;
					}
				}
			}
		}
	}
	result += min;
	map[y][x] = '.';
	map[b][a] = '*';
	p.push_back({ a,b });
	p.push_back({ v[idx].first,v[idx].second});
}
void shorCourse(int x,int y) {
	int min = 1e6, a, b, idx;
	for (int i = 0; i < p.size(); i++) {

		for (int k = 0; k < 4; k++) {
			int x = p[i].first + dx[k];
			int y = p[i].second + dy[k];
			if (canGo(x, y) && map[y][x] != '*') {
				if (min > dis[y][x]) {
					min = dis[y][x];
					a = x, b = y;
				}
			}
		}
	}
	result += min;
	map[y][x] = '.';
	map[b][a] = '*';
	p.push_back({a,b});
	return;
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') v.push_back({ j,i });
		}
	}
	if (v.size() == 1) { cout << 0; return 0; }
	
	for (int i = 0; i < v.size(); i++) {

		int x = v[i].first, y = v[i].second;

		if (!moveCheck(x, y)) {

			bfs(x, y);
			if (!i) firstCheck(x, y);
			else shorCourse(x,y);



			cout << "\n";
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					cout << map[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					dis[i][j] = 0; 
					check[i][j] = 0;
				}
			}

		}
	}
	cout << result << "\n";
	system("pause");
}