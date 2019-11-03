#include <iostream>
using namespace std;

int arr[101][101],brr[101][101];
int n, k, a, b;
void cal() {
	for (int i = 0; i < n; i++) {
		for (int q = 0; q < b; q++) {
			int t = 0;
			for (int z = 0; z < k; z++) {
				t += arr[i][z] * brr[z][q];
			}
			cout << t << " ";
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < k; z++) {
			cin >> arr[i][z];
		}
	}
	cin >> a >> b;
	for (int q = 0; q < a; q++) {
		for (int z = 0; z < b; z++) {
			cin >> brr[q][z];
		}
	}
	cal();
}