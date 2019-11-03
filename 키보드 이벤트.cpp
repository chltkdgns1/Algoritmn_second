#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Data {
public:
	int a, b;
	char c;
};
vector <Data> v;
bool cmp(const Data &a, const Data&b) {
	if (a.b == b.b) return a.a < b.a;
	else return a.b < b.b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		Data d; cin >> d.a >> d.b >> d.c;
		v.push_back(d);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].c;
	}
	cout << "\n";
}