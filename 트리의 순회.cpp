#include <iostream>
using namespace std;
int arr[100001],brr[100001],n;
void pre(int start,int end,int left,int right) {
	if (start > end || left > right) return;
	cout << brr[right] << " ";
	int root = arr[brr[right]];
	pre(start, root - 1, left, left + root - start - 1);
	pre(root + 1, end, left + root - start, right - 1);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int index;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		arr[a] = i; // 중위순회
	}
	for (int i = 1; i <= n; i++) cin >> brr[i]; // 후위순회
	pre(1, n, 1, n);
}