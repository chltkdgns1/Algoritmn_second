#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

vector <pair<int, int>> v;
double dp[513];
int a;


double cal(int a, int b) {
	return sqrt((v[a].first - v[b].first)*(v[a].first - v[b].first) +
		(v[a].second - v[b].second)*(v[a].second - v[b].second));
}

double checkCal(int *d) {
	int s = a;
	double t = 0;
	for (int i = a - 1; i >= 1; i--) {
		if (!d[i]) {
			t += cal(s, i);
			s = i;
		}
	}
	return t;
}

double solve(int s, int *d) {
	double &ref = dp[s];
	if (ref) return ref;
	ref = 987654;

	for (int i = s + 1; i < a; i++) {
		d[i] = 1;
		ref = min(ref, solve(i, d) + cal(s, i));
		d[i] = 0;
	}
	ref = min(ref, cal(s, a) + checkCal(d));
	return ref;

}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> a;
		v.push_back({ -1,-1 });
		for (int i = 0; i < a; i++) {
			int c, d; cin >> c >> d;
			v.push_back({ c,d });
		}
		int d[513];
		memset(d, 0, sizeof(d));
		cout << solve(1, d) << "\n";
		v.clear();
	}
	system("pause");
}