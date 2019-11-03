#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];
int main() {
	while (1) {
		for (int i = 0; i < 3; i++) cin >> arr[i];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
		sort(arr, arr + 3);
		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}