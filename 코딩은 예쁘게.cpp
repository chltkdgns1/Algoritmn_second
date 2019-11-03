#include <iostream>
using namespace std;

int b[1002], a[1002], t[1002], n, ans;
int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%d", &b[i]);

	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &a[i]);
		t[i] = b[i] - a[i];
	}

	for (int i = 1; i <= n; ++i) {
		if (t[i] >= 0) {
			if (t[i - 1] < 0) ans += abs(t[i - 1]);
			else if (t[i - 1] >= t[i]) ans += t[i - 1] - t[i];
		}
		else {
			if (t[i - 1] > 0) ans += t[i - 1];
			else if (t[i - 1] <= t[i]) ans += abs(t[i - 1]) - abs(t[i]);
		}
		t[i - 1] = t[i];
	}
	printf("%d\n", ans);
	system("pause");
}