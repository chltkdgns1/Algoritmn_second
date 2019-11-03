#include <iostream>
#include <math.h>
using namespace std;
double len(int a, int b, int c, int d) {
	return sqrt((a - c)*(a - c) + (b - d)*(b - d));
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;
	double a = x, b = y + (double)(h / 2);
	double c = x + w, d = y + (double)(h / 2);
	int cnt = 0;
	for (int i = 0; i < p; i++) {
		int q, r; cin >> q >> r;
		if (x <= q && y<=r && q<=x+w && r<=y+h) cnt++;
		else if (len(a, b, q, r) <= double(h / 2)) cnt++;
		else if (len(c, d, q, r) <= double(h / 2)) cnt++;
	}
	cout << cnt << "\n";
}