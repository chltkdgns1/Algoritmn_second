#include <iostream>
#include <algorithm>
using namespace std;
class Len {
public:
	int a, b;
};
Len len[1001];
int total;
bool cmp(const Len &a, const Len &b) {
	if (a.a == b.a) return a.b < b.b;
	else return a.a < b.a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) cin >> len[i].a >> len[i].b;
		sort(len, len + m, cmp);
		cout << endl;
		for (int i = 0; i < m; i++) {
			cout << len[i].a << " " << len[i].b << endl;
		}
		cout << endl;
		int check_index = 0;
		for (int i = 0; i < m; i++) {
			if (i == 0) {
				check_index = len[i].a;
				total++;
			}
			else {
				if (check_index < len[i].a) {
					check_index = len[i].a;
					total++;
				}
				else if (check_index == len[i].a) {
					if (check_index < len[i].b) {
						total++;
						check_index = len[i].a + 1;
					}
				}
				else {
					if (check_index < len[i].b) {
						total++;
						check_index++;
					}
				}
			}
		}
		for (int i = 0; i < m; i++) len[i].a = len[i].b = 0;
		cout << total << endl;
		total = 0;
	}
	system("pause");
}