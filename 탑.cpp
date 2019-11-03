#include <iostream>
#include <vector>
using namespace std;
vector <int> a;
class Data {
public:
	int x, index;
};
vector <Data> b;
int main() {
	Data d;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		a.push_back(c);
	}
	for (int i = 0; i < a.size(); i++) {
		d.x = a[i], d.index = i + 1;
		if (b.empty()) {
			b.push_back(d);
			cout << "0 ";
		}
		else {
			while (!b.empty() && b.back().x <= a[i]) b.pop_back();
			if(!b.size()) cout << "0 ";
			else cout << b.back().index << " ";
			b.push_back(d);
		}
	}
}