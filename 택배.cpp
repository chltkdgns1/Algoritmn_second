#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class trans {
public:
	int first, end, things;
};
trans t[10000];
queue <int> q;
bool cmp(const trans &a, const trans &b) {
	if (a.first == b.first) return a.end < b.end;
	else return a.first < b.first;
}
int main() {
	int n, c, m;
	int total = 0;
	cin >> n >> c >> m;
	for (int i = 0; i < m; i++) cin>>t[i].first>>t[i].end>>t[i].things;
	sort(t, t + m, cmp);
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << t[i].first << " " << t[i].end << " " << t[i].things << endl;
	}
	cout << endl;
	int q_index = t[0].first;
	for (int i = 0; i < m; i++) {
		if (q_index != t[i].first) {
			total += q.front();
			c += q.front();
			q.pop();
			q_index = t[i].first;
		}
		if (c >= t[i].things) {
			q.push(t[i].things);
			c -= t[i].things;
		}
		else {
			q.push(c);
			c = 0;
		}
	}
	while (!q.empty()) {
		total += q.front();
		q.pop();
	}
	cout << total << endl;
	system("pause");
}