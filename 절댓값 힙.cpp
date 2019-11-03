#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;
typedef pair<int, int> par;
struct cmp {
	bool operator()(par a, par b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	}
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,a; cin >> n;
	priority_queue < par,vector<par>,cmp> q;
	while (n--) {
		cin >> a;
		if (!a) {
			if (q.empty()) cout << 0 << "\n";
			else {
				cout << q.top().second << "\n";
				q.pop();
			}
		}
		else q.push({ abs(a),a });
	}
}