#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
int n, m;
char map[110][110];
bool check[110][110]; // 초기화
set <char> key; // 초기화
int txt; // 초기화 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int br_cnt; // 다 돌아왔는데도 아무것도 없다면 탈출할 변수
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
			if (x >= 0 && y >= 0 && x < m && y < n) {
				if (!check[y][x]) {
					if (map[y][x] == '.') {
						check[y][x] = 1;
						q.push({ x,y });
					}
					if (map[y][x] >= 97 && map[y][x] <= 122) {
						check[y][x] = 1;
						key.insert(map[y][x]);
						map[y][x] = '.';
						q.push({ x,y });
						br_cnt++;
					}
					if (map[y][x] == '$') {
						map[y][x] = '.';
						check[y][x] = 1;
						q.push({ x,y });
						txt++;
					}
					if (map[y][x] >= 65 && map[y][x] <= 90) {
						char c = map[y][x] + 32;
						if (key.find(c) != key.end()) {
							map[y][x] = '.';
							check[y][x] = 1;
							q.push({ x,y });
						}
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector <pair<int, int>> v;
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> map[i];
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) key.insert(s[i]);
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				if (!i || i == n - 1 || !k || k == m - 1) {
					if (map[i][k] >= 97 && map[i][k] <= 122) {
						key.insert(map[i][k]);
						map[i][k] = '.';
						v.push_back({ k,i });
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				if (!i || i == n - 1 || !k || k == m - 1) {
					if (map[i][k] == '.') v.push_back({ k,i });
					if (map[i][k] >= 65 && map[i][k] <= 90) {
						char c = map[i][k] + 32;
						if (key.find(c) != key.end()) {
							map[i][k] = '.';
							v.push_back({ k,i });
						}
					}
					if (map[i][k] == '$') {
						map[i][k] = '.';
						txt++;
						v.push_back({ k,i });
					}
				}
			}
		}
		while (1) {
			for (int i = 0; i < v.size(); i++) {
				bfs(v[i].first, v[i].second);
			}
			memset(check, 0, sizeof(check));
			if (!br_cnt) break;
			br_cnt = 0;
		}
		cout << txt << "\n";
		txt = 0;
		br_cnt = 0;
		key.clear();
	}
}