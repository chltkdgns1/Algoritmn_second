#include <iostream>
#include <algorithm>
using namespace std;

class xy {
public:
	int x, y;
};
xy pos[100000];

bool cmp(const xy &a, const xy&b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pos[i].x >> pos[i].y;
	}
	sort(pos, pos + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << pos[i].x << " " << pos[i].y << "\n";
	}
}