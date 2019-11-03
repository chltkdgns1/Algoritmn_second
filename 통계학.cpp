#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int arr[500001];
int e[8002];
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n , max = 0, cnt = 0;
	cin >> n;
	long long t = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		e[arr[i] + 4000]++;
		int num = e[arr[i] + 4000];
		if (max < num) { 
			max = num;
			cnt = 0;
		}
		else if (max == num) cnt++;
		t += arr[i];
	}

	double d = (double)t / n;
	d = round(d); 
	cout << d << "\n";
	
	sort(arr, arr + n);
	cout << arr[n / 2] << "\n";
	
	int c = 0;
	for (int i = 0; i <= 8000; i++) {
		if (max == e[i]) {
			c++;
			if (!cnt) {
				cout << i - 4000 << "\n";
				break;
			}
			if (c == 2 ) {
				cout << i - 4000 << "\n";
				break;
			}
		}
	}

	cout << arr[n - 1] - arr[0] << "\n";

}