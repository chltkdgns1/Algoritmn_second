#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[15000];
bool _arr[15000];
int binarySearch(int number) {
	int first = 0;
	int end = n - 1;
	int middle;
	while (first<=end) {
		middle = (first + end) / 2;
		if (arr[middle] == number) {
			if (_arr[middle] == true) return -1;
			return middle;
		}
		else if (arr[middle] < number) first = middle + 1;
		else end = middle - 1;
	}
	return -1;
}
int main() {
	int cnt = 0;
	int index;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i] >= m) continue;
		if ((index = binarySearch(m - arr[i])) != -1) {
			cout << index << endl;
			_arr[i] = _arr[index] = true;
			cnt++;
		}
	}
	cout << cnt << endl;
	system("pause");
}

/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	vector <int> armor(n);
	for (int i = 0; i < n; i++)
		cin >> armor[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (armor[i] + armor[j] == m)
				cnt++;
		}
	}
	cout << cnt <<'\n';
}


*/