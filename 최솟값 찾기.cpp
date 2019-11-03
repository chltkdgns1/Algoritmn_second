#include <iostream>
#include <deque>
using namespace std;
const int MAX = 5000000;
int arr[MAX];
deque<pair<int, int>> dq; //value, idx
int main(void){	
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);//cin ����ӵ� ���
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		//dq���� �ִ� L���� ���� ����
		if (!dq.empty() && dq.front().second <= i - L)
			dq.pop_front();

		//arr[i]�� �� ������ ���� ū ����
		while (!dq.empty() && dq.back().first > arr[i])
			dq.pop_back();

		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << " ";
	}
	cout << "\n";
	return 0;
}