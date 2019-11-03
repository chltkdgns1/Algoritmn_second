#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

pair <int,vector<int>> arr[1000001];
vector <int> c;
vector <pair<int, vector<int>>> v;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	set <int> s;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		c.push_back(a);
		s.insert(a);
		arr[a].first++;
		arr[a].second.push_back(i);
	}
	for (auto a : s) v.push_back(arr[a]);
	sort(v.begin(), v.end());

	system("pause");
}