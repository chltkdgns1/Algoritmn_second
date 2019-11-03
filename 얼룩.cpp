#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

bool check[10001];
int a, b, c;

class d {
public:
	int x, y;
	d(int x,int y) :x(x),y(y) {}
};

bool cmp(const d&a, const d&b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int res = 987654321;
void dfs(int index,vector <d> v,int cnt,int get) {
	if (get == c) {
		res = cnt < res ? cnt : res;
		return;
	}
	int x = v[index].x, y = v[index].y;
	int cr = 1, get_cr = 0;
	int get_index = 987654321;
	for (int i = 2; i >= 0; i--) {
		cr--;
		vector <int> e;
		for (int k = index; k < v.size(); k++) {
			if (check[k]) continue;
			if (v[k].x >= x && v[k].x <= x + 2) {
				if (v[k].y >= y + cr && v[k].y <= y + i) {
					e.push_back(k);
					check[k] = 1;
					get_cr++;
				}
				else {
					get_index = get_index > k ? k : get_index;
				}
			}
			else {
				get_index = get_index > k ? k : get_index;
				break;
			}
		}
		dfs(get_index, v, cnt + 1, get_cr + get);
		get_cr = 0;
		for (int i = 0; i < e.size(); i++) check[e[i]] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(check, 0, sizeof(check));
		cin >> a >> b >> c; // y x 
		vector <d> v;
		for (int i = 0; i < c; i++) {
			int x, y; cin >> x >> y;
			v.push_back(d{ x,y});
		}
		sort(v.begin(), v.end(), cmp);
		dfs(0, v, 0, 0);
		cout << res << "\n";
	}
}