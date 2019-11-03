#include <iostream>
#include <string>
#include <map>
#include <math.h>
using namespace std;

map <string, double> m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	m["A+"] = 4.3, m["A0"] = 4.0, m["A-"] = 3.7;
	m["B+"] = 3.3, m["B0"] = 3.0, m["B-"] = 2.7;
	m["C+"] = 2.3, m["C0"] = 2.0, m["C-"] = 1.7;
	m["D+"] = 1.3, m["D0"] = 1.0, m["D-"] = 0.7;
	m["F"] = 0.0;
	double s = 0; int t = 0;
	for (int i = 0; i < n; i++) {
		string a, b; int c;
		cin >> a >> c >> b;
		t += c;
		s += m[b] * double(c);
	}
	printf("%.2lf", round((s / t) * 100) / 100);
}