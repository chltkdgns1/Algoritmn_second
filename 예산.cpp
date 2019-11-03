#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> v, int n) {
	int answer = 0;
	int t = v.size();
	sort(v.begin(), v.end());
	for (auto a : v) {
		if (a > (n / t)) return n / t;
		else {
			n -= a;
			t--;
		}
	}
	return v.back();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	vector <int> v;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	solution(v, m);
}