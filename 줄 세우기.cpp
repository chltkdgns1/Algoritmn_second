#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <int> v[32001];
int dir[32001];
int main() {
	queue <int> q,p;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	cin >> a >> b;
	int max = 0;
	for (int i = 0; i < b; i++) {
		int c, d;
		cin >> c >> d;
		v[c].push_back(d);
		dir[d]++;
	}
	for (int i = 1; i <= a; i++) {
		if (!dir[i]) q.push(i);
	}
	while (!q.empty()) {
		int n = q.front();
		p.push(n);
		q.pop();
		for (int i = 0; i < v[n].size(); i++) {
			int y = v[n][i];
			dir[y]--;
			if (!dir[y]) q.push(y);
		}
	}
	while (!p.empty()) {
		cout << p.front() << " ";
		p.pop();
	}
}