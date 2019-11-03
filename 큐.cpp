#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	queue <int> q;
	int n, b;
	cin >> n;
	while (n--) {
		string a;
		cin >> a ;
		if (a == "push") {
			cin >> b;
			q.push(b);
		}
		else if (a == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (a == "size") {
			cout << q.size() << "\n";
		}
		else if (a == "empty") {
			if (q.empty())cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (a == "front") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
	}
}