#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v, r;
int arr[1000001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i >= 0; i--) {
		while (!v.empty() && arr[i] >= v.back()) v.pop_back();
		if (!v.empty()) r.push_back(v.back());
		else r.push_back(-1);
		v.push_back(arr[i]);
	}
	for (int i = n - 1; i >= 0; i--) cout << r[i] << " ";
}