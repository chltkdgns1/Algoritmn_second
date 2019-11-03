#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int>> s[20001];
int d[20001];
void dijkstra(int start) {
	d[start] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int node = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		if (d[node] < dis) continue;
		for (int i = 0; i < s[node].size(); i++) {
			int next_node = s[node][i].first;
			int next_distance = s[node][i].second + dis;
			if (next_distance < d[next_node]) {
				d[next_node] = next_distance;
				pq.push(make_pair(-next_distance, next_node));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v, e, start;
	cin >> v >> e >> start;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		s[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= v; i++) d[i] = 1e9;
	dijkstra(start);
	for (int i = 1; i <= v; i++) {
		if (d[i] != 1e9) printf("%d\n", d[i]);
		else printf("INF\n");
	}
}