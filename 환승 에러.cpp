#include <iostream>
#include <vector>
#include <queue>
#define HYPER 10000
#define INF 987654321
using namespace std;
vector <int> v[110001];
int d[110001];
int n;
void bfs(int s) {
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (int i = 0; i < v[s].size(); i++) {
			int y = v[s][i];
			if (y > n && d[y] > d[s]) {
				d[y] = d[s];
				q.push(y);
			}
			else if(y <= n && d[y] > d[s] + 1){
				d[y] = d[s] + 1;
				q.push(y);
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m, c;
	cin >> n >> m >> c;
	for (int i = 1; i <= n + c; i++) d[i] = INF;
	d[1] = 1;
	for (int i = 1; i <= c; i++) {
		for (int k = 0; k < m; k++) {
			int a; cin >> a;
			v[n + i].push_back(a);
			v[a].push_back(n+ i);
		}
	}
	bfs(1);
	if (d[n] == INF) cout << -1 << "\n";
	else cout << d[n] << "\n";
}