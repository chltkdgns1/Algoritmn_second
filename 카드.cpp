#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

long long arr[1000001];
map <long long, int> m;
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	long long number;
	map <long long, int>::iterator iter;
	int max = 1;
	long long data = 0;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		iter = m.find(arr[i]);
		if (iter == m.end()) {
			m.insert({ arr[i], 1 });
			if (data == 0) {
				data = arr[i];
			}
		}
		else if (iter != m.end()) {
			(*iter).second++;
			if (max < (*iter).second) {
				max = (*iter).second;
				data = (*iter).first;
			}
 		}
	}
	cout << data << "\n";
}