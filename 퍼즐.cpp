#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
string map;
string collect = "123456780";

int dr[4] = { -3,3,-1,1 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
unordered_set <string> s;
void bfs(int x, string map) {
	queue <pair<int,string>> q;
	q.push({ x,map });
	int cnt = 0;
	while (1) {
		int len = q.size();
		if (!len) break;
		for (int i = 0; i < len; i++) {
			int nx = q.front().first;
			string t = q.front().second;
			if (t == collect) {
				cout << cnt << "\n";
				return;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ax = (nx % 3) + dx[i];
				int ay = (nx / 3) + dy[i];
				int dy = nx + dr[i];
				string w = t;
				if (ax >= 0 && ax < 3 && ay >= 0 && ay < 3) {
					swap(w[dy], w[nx]);
					if (s.find(w) == s.end()) {
						s.insert(w);
						q.push({ dy,w });
					}
				}
			}
		}
		cnt++;
	}
	cout << -1 << "\n";
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int idx;
	for (int i = 0; i < 9; i++) {
		int a; cin >> a;
		if (!a) idx = i;
		map += a + 48;
	}
	s.insert(map);
	bfs(idx, map);
}