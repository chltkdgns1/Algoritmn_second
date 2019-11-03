#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[10001];
bool visit[10001];
int a, b, n;
int bfs(int s) {
	visit[s] = 1;
	queue <int> q;
	q.push(s);
	int cnt = 0;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int e = q.front();
			q.pop();
			if (e != b && !arr[e]) {visit[e] = 1; continue;}
			if (e == b || !(abs(e - b) % arr[e])) return ++cnt;
			for (int i = e; i >= 1; i -= arr[e]) {
				if (!visit[i]) {
					visit[i] = 1;
					q.push(i);
				}
			}
			for (int i = e; i <= n; i += arr[e]) {
				if (!visit[i]) {
					visit[i] = 1;
					q.push(i);
				}
			}
		}
		cnt++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> a >> b;
	cout << bfs(a) << "\n";
}