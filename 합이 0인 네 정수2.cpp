#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a[4000], b[4000], c[4000], d[4000];
vector <int> v;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) v.push_back(c[i] + d[j]);
	}
	sort(v.begin(), v.end());
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long data = a[i] + b[j];
			long long low = lower_bound(v.begin(), v.end(), -data) - v.begin();
			long long upper = upper_bound(v.begin(), v.end(), -data) - v.begin();
			if (-data == v[low]) {
				cnt += upper - low;
			}
		}
	}
	cout << cnt << endl;
}