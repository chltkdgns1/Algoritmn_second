#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
long long arr[10000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}
	long long left, right, middle;
	left = 0, right = max;
	int check = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += arr[i] / middle;
		if (cnt == k) {
			left = middle + 1;
		}
		else if (cnt > k) left = middle + 1;
		else if (cnt < k) right = middle - 1;	
	}
	cout << left - 1<< endl;
}