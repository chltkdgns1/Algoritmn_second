#include <iostream>
using namespace std;

int map[101][101];
char t_m[101][101];
int dx[8] = { 0,0,1,-1,1,1,-1,-1}, dy[8] = { 1,-1,0,0,1,-1,1,-1};
int n;
bool check(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t_m[i];
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (t_m[i][k] != '#') map[i][k] = t_m[i][k] - 48;
			else map[i][k] = t_m[i][k];
		}
	}

	if (n == 1 || n == 2) {
		cout << 0 << "\n";
		return 0;
	}
	if (map[0][0]) map[1][1] = -1;
	else map[1][1] = 0;
	if (map[0][n - 1]) map[1][n - 2] = -1;
	else map[1][n - 2] = 0;
	if (map[n - 1][0]) map[n - 2][1] =  -1;
	else map[n - 2][1] = 0;
	if (map[n - 1][n - 1]) map[n - 2][n - 2] = -1;
	else map[n - 2][n - 2] = 0;

	for (int k = 0; k < n; k++) { // x 방향
		int cnt = 0, cnt2 = 0;
		for (int z = 0; z < 8; z++) {
			int nx = k + dx[z];
			int ny = 0 + dy[z];
			int my = n - 1 + dy[z];
			if (check(nx, ny)) {
				if (map[ny][nx] == -1) cnt++;
			}
			if (check(nx, my)) {
				if (map[my][nx] == -1) cnt2++;
			}
		}
		if (map[0][k] - cnt > 0 && map[1][k + 1] == 35) map[1][k + 1] = -1;
		if (map[n - 1][k] - cnt2 > 0 && map[n - 2][k + 1] == 35) map[n - 2][k + 1] = -1;
	}

	for (int k = 0; k < n; k++) { // y 방향
		int cnt = 0, cnt2 = 0;
		for (int z = 0; z < 8; z++) {
			int nx = 0 + dx[z];
			int ny = k + dy[z];
			int mx = n - 1 + dx[z];
			if (check(nx, ny)) {
				if (map[ny][nx] == -1) cnt++;
			}
			if (check(mx, ny)) {
				if (map[ny][mx] == -1) cnt2++;
			}
		}
		if (map[k][0] - cnt > 0 && map[k + 1][1] == 35) map[k + 1][1] = -1;
		if (map[k][n - 1] - cnt2 > 0 && map[k + 1][n - 2] == 35) map[k + 1][n - 2] = -1;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (map[i][k] == -1) cnt++;
		}
	}
	if (n == 3) cout << cnt << "\n";
	else cout << cnt + (n - 4)*(n - 4) << "\n";
}

