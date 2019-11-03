#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;

vector <int> v, e;
int d[4],a[4],n;
int cal(int a, int b, int d) {
	switch (d) {
	case 0 :
		return a + b;
		break;
	case 1:
		return a - b;
		break;
	case 2:
		return a * b;
		break;
	case 3:
		return a / b;
		break;
	}
}
int res1 = -INF, res2 = INF;
void go(int index,int data) {
	if (n == index) {
		if (res1 < data) res1 = data;
		if (res2 > data) res2 = data;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (a[i] < d[i]) {
			a[i]++;
			go(index + 1,cal(data,v[index],i));
			a[i]--;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		d[i] = a;
	}
	go(1,v[0]);
	cout << res1 << "\n";
	cout << res2 << "\n";
}