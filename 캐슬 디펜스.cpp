#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 987654321
using namespace std;

int map[16][16];
int temp[16][16];
bool visit[16][16];
int dist1[16][16];
int dist2[16][16];
int dist3[16][16];
int n, m, d;
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };

class Data {
public:
	int x, y, d;
};

bool cmp(const Data &a, const Data &b) {
	return a.x < b.x;
}

int simulation(int a, int b, int c) { // 각각 궁수들의 위치 좌표
	int kill = 0;
	while (1) {
		vector <Data> s1, s2, s3;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				Data de;
				de.x = k, de.y = i;
				if (dist1[i][k] && map[i][k]) {
					de.d = dist1[i][k];
					if (s1.empty()) s1.push_back(de);
					else if (s1.back().d > dist1[i][k]) {
						while (!s1.empty()) s1.pop_back();
						s1.push_back(de);
					}
					else s1.push_back(de);
				}
				if (dist2[i][k] && map[i][k]) {
					de.d = dist2[i][k];
					if (s2.empty()) s2.push_back(de);
					else if (s2.back().d > dist2[i][k]) {
						while (!s2.empty()) s2.pop_back();
						s2.push_back(de);
					}
					else s2.push_back(de);
				}
				if (dist3[i][k] && map[i][k]) {
					de.d = dist3[i][k];
					if (s3.empty()) s3.push_back(de);
					else if (s3.back().d > dist3[i][k]) {
						while (!s3.empty()) s3.pop_back();
						s3.push_back(de);
					}
					else s3.push_back(de);
				}
			}
		}

		sort(s1.begin(), s1.end(), cmp);
		sort(s2.begin(), s2.end(), cmp);
		sort(s3.begin(), s3.end(), cmp);
		
		if (!s1.empty()) { map[s1[0].y][s1[0].x] = 0; kill++; }
		if (!s2.empty() && map[s2[0].y][s2[0].x]) { map[s2[0].y][s2[0].x] = 0, kill++; }
		if (!s3.empty() && map[s3[0].y][s3[0].x]) { map[s3[0].y][s3[0].x] = 0, kill++; }

		int check_cnt = 0; // 적들이 더 이상 남아있는지 확인하면서 성아래로 이동
		for (int i = n - 1; i >= 0; i--) {
			for (int k = 0; k < m; k++) {
				if (map[i][k] ) {
					map[i][k] = 0;
					if (i + 1 != n) {
						map[i + 1][k] = 1;
						check_cnt++;
					}
				}
			}
		}
		if (!check_cnt) break;
	}
	return kill;
}

bool check(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}

void bfs(int x, int y, int dist[16][16]) {
	visit[y - 1][x] = 1; // 이 이유는 성벽에서 1보타 위에있는 지점부터 시작
	dist[y - 1][x] = 1; // 대신 거리도 1부터 시작함
	queue <pair<int, int>> q;
	q.push({ x,y - 1 });
	int cnt = 0;
	while (!q.empty()) {
		int len = q.size();
		if (cnt == d - 1) return;
		for (int i = 0; i < len; i++) {
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ax = nx + dx[i];
				int ay = ny + dy[i];
				if (check(ax, ay)) {
					if (!visit[ay][ax]) {
						visit[ay][ax] = 1;
						dist[ay][ax] = dist[ny][nx] + 1;
						q.push({ ax,ay });
					}
				}
			}
		}
		cnt++;
	}
	memset(visit, 0, sizeof(visit));
}

void initArray() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			dist1[i][k] = 0, dist2[i][k] = 0, dist3[i][k] = 0;
			map[i][k] = temp[i][k];
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			temp[i][k] = map[i][k];
		}
	}
	int max = 0;
	for (int k = 0; k < m; k++) {
		for (int z = k + 1; z < m; z++) {
			for (int q = z + 1; q < m; q++) {
				bfs(k, n, dist1); bfs(z, n, dist2); bfs(q, n, dist3);
				int s = simulation(k, z, q);
				if (max < s) max = s;
				initArray();
			}
		}
	}
	cout << max << "\n";
	system("pause");
}