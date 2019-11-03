
#include <iostream>
using namespace std;

char arr[500000];
int temp_arr[500000];
int indexs ;

int main() {
	int n, k;
	int place = 0;
	int big;
	cin >> n >> k;
	cin >> arr;
	for (int i = 0; i < n; i++) temp_arr[i] = arr[i];
	while (k > 0) {
		int del_cnt = 0;
		char temp = 0;
		int i;

		for (i = indexs; i <= k + indexs; i++) {
			if (arr[i] == '9') {
				big = i;
				break;
			}
			if (temp < arr[i]) {
				temp = arr[i];
				big = i;
			}
		}
		indexs = big;
		for (int i = place; i < indexs; i++) {
			arr[i] = '*';
			del_cnt++;
		}
		indexs++; // 가장 큰 값 다음으로 탐색하기 위한 증가.
		place = indexs; // 지우기 위한 위치 설정
		k -= del_cnt; // 지운 개수 뺀 남은 지울 개수.
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == '*') continue;
		printf("%c",arr[i]);
	}
	cout << "\n";
}

/*
#include<stdio.h>
#include<queue>
using namespace std;
int n, k;
char str[500001];
deque<char> q;
void push(char x) {
	while (!q.empty() && q.back()<x) q.pop_back();
	q.push_back(x);
}
int main() {
	scanf("%d %d %s", &n, &k, str);
	for (int i = 0; i<k; i++) push(str[i]);
	for (int i = k; i<n; i++) {
		push(str[i]);
		printf("%c", q.front());
		q.pop_front();
	}
	return 0;
}

*/
