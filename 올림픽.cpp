#include <iostream>
using namespace std;
class medal {
public:
	int g, s, b, n;
	medal() { g = 0, s = 0, b = 0, n = 0; }
};
medal arr[1000];
int s_gold[1000];
int s_silver[1000];
int main() {
	int n, k, cnt = 0;
	int g_cnt = 0, s_cnt = 0;
	int index;
	cin >> n >> k;
	index = k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].n >> arr[i].g >> arr[i].s >> arr[i].b;
		if (k == arr[i].n) {
			index = i + 1;
		}
	}
	k = index;
	for (int i = 0; i < n; i++) {
		if (arr[k - 1].g < arr[i].g && i != k - 1) cnt++;
		else if (arr[k - 1].g == arr[i].g && i != k - 1) {
			s_gold[g_cnt] = i;
			g_cnt++;
		}
	}
	for (int i = 0; i < g_cnt; i++) {
		if (arr[k - 1].s < arr[s_gold[i]].s && k - 1 != s_gold[i]) cnt++;	
		else if (arr[k - 1].s == arr[s_gold[i]].s && k - 1 != s_gold[i]) {
			s_silver[s_cnt] = s_gold[i];
			s_cnt++;
		}
	}
	for (int i = 0; i < s_cnt; i++) {
		if (arr[k - 1].b < arr[s_silver[i]].b && k - 1 != s_silver[i]) cnt++;
	}
	cout << cnt + 1 << endl;
}