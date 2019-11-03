#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int>> v[1001];
int d[1001];

void distra(int start) {
	d[start] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (d[cur] < cost) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dis = v[cur][i].second;
			if (d[next] > next_dis + cost) {
				d[next] = next_dis + cost;
				pq.push({ -d[next], next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	int a, b;
	cin >> a >> b;
	for(int i=1;i<=n;i++) d[i] = 1e9;
	distra(a);
	cout << d[b] << "\n";
}