#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, a;
	queue <int> q;
	cin >> n;
	for (int i = 1; i <= n; i++) q.push(i);
	for (int i = 1; i <= n; i++) {
		cout << q.front() << " ";
		if (i == n) break;
		q.pop();
		q.push(q.front());
		q.pop();
	}
}