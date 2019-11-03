#include <stdio.h>
#include <algorithm>
using namespace std;

int n, nn;
int ab[16000000], cd[16000000];
int a[4000], b[4000], c[4000], d[4000];


int main() {
	scanf("%d", &n);
	nn = n * n;

	for (int i = 0; i < n; ++i)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ab[n*i + j] = -(a[i] + b[j]);
			cd[n*i + j] = c[i] + d[j];
		}
	}

	sort(cd, cd + nn);

	int left = 0, right = nn;
	long long ans = 0;

	for (int i = 0; i < nn; ++i) {

		while (left < right) {
			int mid = (left + right) / 2;

			if (ab[i] > cd[mid])
				left = mid + 1;
			else
				right = mid;
		}

		int lo = right;
		//int lo2 = lower_bound(cd, cd + nn, ab[i]) - cd;

		left = 0, right = nn;

		while (left < right) {
			int mid = (left + right) / 2;

			if (ab[i] >= cd[mid])
				left = mid + 1;
			else
				right = mid;
		}

		int hi = right;
		//int hi2 = upper_bound(cd, cd + nn, ab[i]) - cd;

		ans += (long long)(hi - lo);

		left = 0, right = nn;
	}

	printf("%lld", ans);

	return 0;
}
