#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[51][51];
int dis[51][51];
int n, k;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool visit[51][51];
queue <pair<int, int>> q;
vector <pair<int, int>> v;

void bfs() {
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (map[ny][nx] != 1 && !visit[ny][nx]) {
						visit[ny][nx] = 1;
						dis[ny][nx] = dis[y][x] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	while (!q.empty())q.pop();
}

int d[11], max1 = 987654321;
void dfs(int index,int e) {
	if (e == k) {
		for (int i = 0; i < n; i++) {
			for (int z = 0; z < n; z++) {
				visit[i][z] = 0;
				if (map[i][z] == 0) dis[i][z] = -1;
				else dis[i][z] = 0;
			}
		}
		for (int i = 0; i < index; i++) {
			if (d[i]) {
				q.push({ v[i].first,v[i].second });
				visit[v[i].second][v[i].first] = 1;
			}
		}
		bfs();
		int data = 0;
		for (int i = 0; i < n; i++) {
			for (int z = 0; z < n; z++) {
				if (dis[i][z] == -1) return;
				if (data < dis[i][z]) data = dis[i][z];
			}
		}
		if (data < max1) max1 = data;
		return;
	}
	if (index == v.size()) return;

	d[index] = 1;
	dfs(index + 1, e + 1);
	d[index] = 0;
	dfs(index + 1, e);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n; z++) {
			cin >> map[i][z];
			if (map[i][z] == 2) {
				v.push_back({ z,i });
			}
		}
	}
	dfs(0, 0);
	if (max1 == 987654321) cout << -1 << "\n";
	else cout << max1 << "\n";
}