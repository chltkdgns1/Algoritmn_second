#include <iostream>
using namespace std;
int dx[4] = { 0,1,0,-1 },dy[4] = { 1,0,-1,0 };
int map[1001][1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b,res; cin >> a >> b >>res;
	if (res > a*b) { cout << 0; return 0;}
	map[1][1] = 1;
	int x = 1, y = 1,dir = 0;
	int cnt = 1;
	while (cnt < res) {
		cnt++;
		x += dx[dir], y += dy[dir];
		if ((x < 1 || x > a || y < 1 || y > b) || map[y][x]) {
			x -= dx[dir], y -= dy[dir];
			dir++;
			dir %= 4;
			x += dx[dir], y += dy[dir];
		}
		map[y][x] = cnt;
	}
	cout << x << " " << y << "\n";
}