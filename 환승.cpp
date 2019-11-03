#include <iostream>
#include <vector>
#include <queue>
#define HYPER 10000
using namespace std;

vector <int> v[110001];
bool visit[110001];
int n;
void bfs(int s) {
	visit[s] = 1;
	int min = 987654321;
	queue <pair<int, int>> q;
	q.push({ -1,s });
	while (!q.empty()) {
		int dis = q.front().first;
		int s = q.front().second;
		if (s == n) {
			if (min > dis) min = dis;
			continue;
		}
		q.pop();
		for (int i = 0; i < v[s].size(); i++) {
			int y = v[s][i];
			if (!visit[y]) {
				if (y > HYPER) q.push({ dis,y });
				else q.push({ dis + 1 ,y });
			}
		}
	}
	if (min == 987654321) cout << -1 << "\n";
	else cout << min << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m, c;
	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++) {
		for (int k = 0; k < m; k++) {
			int a; cin >> a;
			v[HYPER + i].push_back(a);
			v[a].push_back(HYPER + i);
		}
	}
	bfs(1);
	system("pause");
}