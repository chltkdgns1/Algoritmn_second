#include <iostream>
#include <algorithm>
using namespace std;

class peo {
public:
	int x, y;
};
peo p[100];
bool cmp(const peo &a, const peo &b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << p[i].x << " " << p[i].y << "\n";
	}
	system("pause");
}