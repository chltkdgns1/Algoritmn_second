#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
vector <int> v, e;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		int a, b;
		cin >> a >> b;
		if (!a && !b) break;
		if (a - b < b) b = a - b;
		ll c = 1;
		for (int i = 0; i < b; i++) {
			v.push_back(a);
			a -= 1;
		}
		int t = b;
		for (int i = 0; i < t; i++) {
			e.push_back(b);
			b -= 1;
		}
		for (int i = 0; i < v.size(); i++) {
			for (int k = 0; k < e.size(); k++) {
				if (e[k] != 1 && v[i] % e[k] == 0 ) {
					v[i] /= e[k];
					e[k] = 1;
				}
			}
		}
		ll d = 1;
		for (int i = 0; i < e.size(); i++) {
			if (e[i] != 1) d *= e[i];
		}
		for (int i = 0; i < v.size(); i++) c *= v[i];
		cout << c / d << "\n";
		v.clear(), e.clear();
	}
}