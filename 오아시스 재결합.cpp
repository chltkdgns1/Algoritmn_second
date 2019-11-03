#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector <pair<ll ,ll >> s;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (s.empty()) s.push_back({ a,1 });
		else {
			while (!s.empty() && s.back().first < a) {
				res += s.back().second;
				s.pop_back();
			}
			if (!s.empty() && s.back().first > a) res++;
			else if (!s.empty() && s.back().first == a) {
				res += s.back().second;
				s.back().second++;
				if (s.size() != 1) res++;
				continue;
			}
			s.push_back({ a,1 });
		}
	}
	cout << res << "\n";
}