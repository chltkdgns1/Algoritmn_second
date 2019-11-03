#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int>> v[1001];
int d[1001];
int e[1001];
void dtra(int s) {
	d[s] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (d[cur] < cost) continue;
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++) d[i] = 1e9;
		dtra(i);
		e[i] = d[x];
	}
	for (int i = 1; i <= n; i++) d[i] = 1e9;
	dtra(x);
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[i] + e[i])  max = d[i] + e[i];
	}
	cout << max << "\n";
}