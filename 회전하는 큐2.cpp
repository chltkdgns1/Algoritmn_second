#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
list <int> arr;
vector <int> v;
int checkQue() {
	list <int>::iterator it;
	int key = 0;
	for (int i = 0; i < v.size(); i++) {
		int cnt = 0;
		for (it = arr.begin(); it != arr.end(); it++) {
			cnt++;
			if (v[i] == *it) break;
		}
		if (cnt - 1 < arr.size() + 1 - cnt) {
			key += cnt - 1;
			for (int i = 0; i < cnt - 1; i++) {
				arr.push_back(arr.front());
				arr.pop_front();
			}
			arr.pop_front();
		}
		else {
			key += arr.size() + 1 - cnt;
			for (int i = 0; i < arr.size() + 1 - cnt; i++) {
				arr.push_front(arr.back());
				arr.pop_back();
			}
			arr.pop_front();
		}
	}
	return key;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) arr.push_back(i + 1);
	for (int i = 0; i < m; i++) { int a; cin >> a; v.push_back(a); }
	cout<<checkQue()<<"\n";
}