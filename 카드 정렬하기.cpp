#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	priority_queue <int> q;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		q.push(-a);
	}

	int res = 0;

	while (q.size() != 1) {
		int a = -q.top(); q.pop();
		int b = -q.top(); q.pop();
		res += a + b;
		q.push(-a -b);
	}
	cout << res << "\n";
}