#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		ll n; cin >> n;
		if (!n) break;
		priority_queue <pair<int,int>> q;
		set <ll> s;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			q.push({ -a,i });
		}
		long long res = 0;
		while (!q.empty()) {
			ll d = -q.top().first;
			int r = q.top().second;
			q.pop();
			if (s.empty()) res = max(res, n*d);
			else {
				auto a = s.upper_bound(r);
				if (a == s.end()) {
					a--; res = max(res, (n - 1 - (*a)) * d);
				}
				else if (a == s.begin()) {
					res = max(res, (*a)*d);
				}
				else {
					auto c = a; a--;
					res = max(res, ((*c) - (*a) - 1)*d);
				}
			}
			s.insert(r);
		}
		cout << res << "\n";
	}
}