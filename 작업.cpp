#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[10001];
int d[10001];
int cost[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		cost[i] = a;
		for (int k = 0; k < b; k++) {
			int c; cin >> c;
			v[c].push_back(i);
			d[i]++;
		}
	}
	priority_queue <pair<int,int>> q;
	for (int i = 1; i <= n; i++) {
		if (!d[i]) q.push({-cost[i],i});
	}

	int t = 0;
	while (1) {
		int len = q.size();
		if (!len) break;
		for (int i = 0; i < len; i++) {
			int s = q.top().second;
			int co = -q.top().first;
			if(t < co) t = co;
			q.pop();
			for (int i = 0; i < v[s].size(); i++) {
				int y = v[s][i];
				d[y]--;
				if (!d[y]) q.push({-(co + cost[y]),y});
			}
		}
	}
	cout << t << "\n";
}