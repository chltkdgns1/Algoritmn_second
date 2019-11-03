#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define SIZE 53
using namespace std;

vector <int> v[SIZE];
int c[SIZE][SIZE];
int f[SIZE][SIZE];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b; int d;
		cin >> a >> b >> d;
		int s, t;
		if (a >= 'A' && a <= 'Z') s = a - 'A';
		else s = a - 'a' + 26;
		if (b >= 'A'&& b <= 'Z') t = b - 'A';
		else t = b - 'a' + 26;

		v[s].push_back(t);
		v[t].push_back(s);
		c[s][t] += d;
		c[t][s] += d;
	}

	int sink = 'Z' - 'A' , source = 0, maxflow = 0;
	while (1) {
		int prev[SIZE];
		memset(prev, -1, sizeof(prev));

		queue <int> q;
		q.push(0);

		while (!q.empty()) {
			int d = q.front();
			q.pop();

			for (auto a : v[d]) {
				if (prev[a] != -1) continue;

				if (c[d][a] - f[d][a] > 0) {
					prev[a] = d;

					if (a == sink) break;
					q.push(a);
				}
			}
		}

		if (prev[sink] == -1) break;

		int flow = 987654321;
		for (int i = sink; i != source; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}

		for (int i = sink; i != source; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}

		maxflow += flow;
	}
	cout << maxflow << "\n";
}