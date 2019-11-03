#include <iostream>
#include <queue>
using namespace std;
int map[101][101];
int distances[101];
bool check[101];
int n, a, b, m, key;
void bfs(int number) {
	queue <int> q;
	q.push(number);
	check[number] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (map[x][i] == 1 && check[i] == false) {
				if (i == b) {
					key = distances[x] + 1;
					return;
				}
				check[i] = true;
				q.push(i);
				distances[i] = distances[x] + 1;
			}
		}
	}
}
int main() {
	int x, y;
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	bfs(a);
	if (key == 0) cout << -1 << endl;
	else cout << key << endl;
}