#include <iostream>
using namespace std;

int arr[10];
int main() {
	for (int i = 0; i < 10; i++) cin >> arr[i];
	int a = 0, b = 0, s, index = -1 ,e = -1;
	for (int i = 0; i < 10; i++) {
		cin >> s;
		if (arr[i] < s) b += 3 ,index = i,e = s;
		else if (arr[i] == s) a++, b++;
		else a += 3,index = i, e = s;
	}
	cout << a << " " << b << "\n";
	if (e == -1 && index == -1) {
		cout << "D" << "\n";
		return 0;
	}
	if (a > b) cout << "A" << "\n";
	else if (a < b) cout << "B" << "\n";
	else {
		if (arr[index] < e) cout << "B" << "\n";
		else if (arr[index] > e) cout << "A" << "\n";
		else cout << "D" << "\n";
	}
}