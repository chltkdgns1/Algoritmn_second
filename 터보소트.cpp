#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector <pair<int, int>> v;
vector <int> tree;

void update(int i, int diff){
	while (i <= tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i){
	int ans = 0;
	while (i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	tree.resize(n + 1);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		v[i].first = a, v[i].second = i;
		update(i, 1);
	}
	sort(v.begin(), v.end());
	int c = n; bool ch = 0;
	if ((n % 2)) c++, ch = 1;
	for (int i = 1; i <= c / 2; i++) {
		cout<<sum(i) - 1<<"\n";
		update(v[i].second, -1);// 왼쪽 비트를 제거
		if (ch && i == c / 2) break;
		cout << abs((n - i + 1) - (v[n - i + 1].second + qurey(v[n - i + 1].second))) << "\n";
		update(v[n - i + 1].second + 1, 0);
	}
	system("pause");
}