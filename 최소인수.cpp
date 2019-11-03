#include <iostream>
typedef long long ll;
#define MAX 100000000
using namespace std;
bool arr[MAX + 1];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	arr[1] = 1;
	for (int i = 2; i*i <= MAX; i++) {
		if (!arr[i]) {
			int k = 2;
			while (i*k <= MAX) {
				arr[i*k] = 1;
				k++;
			}
		}
	}
	ll n, p;
	cin >> n >> p;
	ll cnt = 0, p_mul = 0, key = 0;
	while (n != cnt) {
		p_mul++;
		if (p_mul * p > 1000000000) break;
		if (p_mul < p) { // 경우를 만족했을 때
			if (arr[p_mul]) {
				key = p_mul;
				cnt++;
			}
		}
		else {
			if (!arr[p_mul]) {
				key = p_mul;
				cnt++;
			}
		}
	}
	cout << key * p << "\n";
}
