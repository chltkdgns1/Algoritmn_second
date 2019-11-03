#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;
ll dis[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	stack <ll> s;
	ll t = 0;
	for (int i = 0; i < n - 1; i++) cin >> dis[i];
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (i == n - 1) {
			t += s.top()* dis[i - 1];
			break;
		}
		if (s.empty()) s.push(a);
		else {
			t += dis[i - 1] * s.top();
			if (s.top() > a) s.push(a);
				
		}
	}
	cout << t << "\n";
}