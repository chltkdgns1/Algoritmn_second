#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 200000000
using namespace std;

vector <pair<int, int>> v[801];
int d[801];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next_cur = v[cur][i].first;
			int next_cost = v[cur][i].second + cost;
			if (d[next_cur] > next_cost) {
				d[next_cur] = next_cost;
				pq.push({ -next_cost,next_cur });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	int a, b;
	long long a_cnt = 0, b_cnt = 0;
	cin >> a >> b;
	for (int i = 1; i <= n; i++) d[i] = INF;
	dijkstra(a);
	a_cnt += d[1] + d[b];
	b_cnt += d[b] + d[n];
	for (int i = 1; i <= n; i++) d[i] = INF;
	dijkstra(b);
	b_cnt += d[1];
	a_cnt += d[n];
	long long key;
	if ((key = min(a_cnt,b_cnt)) < INF) cout << key << "\n";
	else cout << -1 << "\n";
}