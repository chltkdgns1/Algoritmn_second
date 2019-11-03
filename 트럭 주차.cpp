#include <iostream>
using namespace std;
int arr[101];
int main() {
	int a, b, c;
	int begin, end;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		cin >> begin >> end;
		for (int j = begin + 1; j <= end; j++) arr[j]++;
	}
	int sum = 0;
	for (int i = 0; i <= 100; i++) {
		if (arr[i] == 1) sum += a * arr[i];
		else if (arr[i] == 2) sum += b * arr[i];
		else if(arr[i] == 3) sum += c * arr[i];
	}
	cout << sum << endl;
}