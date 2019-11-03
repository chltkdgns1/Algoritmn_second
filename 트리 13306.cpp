#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v(200010);
vector <pair<int, int>> q;
vector <bool> ans;

int find(int x) {
	if (v[x] == x) {
		return x;
	}
	else {
		return v[x] =  find(v[x]);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	v[1] = 1;
	for (int i = 1; i <= n - 1; i++) {
		int a; cin >> a;
		v[i + 1] = a;
	}
	for (int i = 0; i < n - 1 + m; i++) {
		int a, b, c;
		cin >> a;
		if (!a) {
			cin >> b; 
			q.push_back({ -v[b],b });
			v[b] = b;
		}
		else {
			cin >> b >> c;
			q.push_back({ b,c });
		}
	}
	for (int i = q.size() - 1; i >= 0; i--) {
		if (q[i].first < 0) v[q[i].second] = -q[i].first;	
		else {
			if (find(q[i].first) == find(q[i].second)) ans.push_back(1);
			else ans.push_back(0);
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i]) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}