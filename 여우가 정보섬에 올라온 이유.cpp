#include <iostream>
#include <algorithm>
using namespace std;

long long res;

class xypos {
public:
	int x, y, index;
};

xypos xy[200001];

bool cmp(const xypos &a, const xypos&b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool cmp2(const xypos &a, const xypos&b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y > b.y;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> xy[i].x >> xy[i].y;
	}
	sort(xy, xy + n, cmp);
	for (int i = 0; i < n; i++) xy[i].index = i;
	sort(xy, xy + n, cmp2);

	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) {
			if (xy[i].x < xy[k].x) {
				res = (res + xy[k].index - xy[i].index - 1) % (1000000007);
			}
		}
	}
	cout << res << "\n";
	system("pause");
	// y축을 기준으로 첫번째 별에서 x 축보다 좌표값이 큰 별 2개 택해서
	// 개수 세주면됨
}