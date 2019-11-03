#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	stack <int> s;
	while (n--) {
		int a; cin >> a;
		if (!a) s.pop();
		else s.push(a);
	}
	int t = 0;
	while (!s.empty()) {
		t += s.top();
		s.pop();
	}
	cout << t << "\n";
}