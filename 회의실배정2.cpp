#include <iostream>
#include <algorithm>
using namespace std;
class Time {
public:
	long long s, e;
};
Time arr[100000];
bool cmp(const Time &a, const Time&b) {
	if (a.e == b.e) {
		return a.s < b.s;
	}
	else {
		return a.e < b.e;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].s >> arr[i].e;
	sort(arr, arr + n,cmp);
	long long t_s = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (t_s <= arr[i].s) {
			t_s = arr[i].e;
			cnt++;
		 }
	}
	cout << cnt << endl;
}