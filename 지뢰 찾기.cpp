#include <iostream>
using namespace std;

char map[1001][1001], res[1001][1001];

int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
int dy[8] = { 1,-1,0,0,1,1,-1,-1 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> map[i];

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (map[i][k] != '.') res[i][k] = '*';
			else {
				int s = 0;
				for (int z = 0; z < 8; z++) {
					int x = k + dx[z];
					int y = i + dy[z];
					if (x >= 0 && x < n && y >= 0 && y < n) {
						char a = map[y][x];
						if (a != '.') s += a - 48;
					}
				}
				if (s < 10) res[i][k] = s + 48;
				else res[i][k] = 'M';
			}
		}
	}

	for (int i = 0; i < n; i++) cout << res[i] << "\n";
}