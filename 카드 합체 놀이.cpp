#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	priority_queue <ll> pq;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		pq.push(-a);
	}
	for (int i = 0; i < m; i++) {
		ll a = -pq.top(),b;
		pq.pop();
		b = -pq.top(); pq.pop();
		pq.push(-a - b);
		pq.push(-a - b);
	}
	ll t = 0;
	while (!pq.empty()) {
		t += -pq.top();
		pq.pop();
	}
	cout << t << "\n";
}

/*
#include <string.h>
#include<iostream>
#include <algorithm>
#include<stdio.h>

using namespace std;

long long card_score[1001];

long long  get_min_score(long long  card, long long  fusion)
{
	long long  min , sub_min;
	long long  *adress_min=0, *adress_sub=0;
	long long  sum=0;

	for (int i = 0; i < fusion;i++) {
		adress_min = min_element(card_score + 1, card_score + card+1);
		min = *adress_min;
		*adress_min = 9223372036854775807;
		adress_sub = min_element(card_score + 1, card_score + card+1);
		*adress_min = *adress_sub = min + *adress_sub;
	}
	for (int i = 1; i <= card; i++)
		sum += card_score[i];

	return sum;
}

int main(void)
{
	long long card, fusion;

	scanf("%lld %lld", &card, &fusion);
	for (long long  j = 1; j <= card; j++)
		scanf("%d", &card_score[j]);

	printf("%lld", get_min_score(card, fusion));
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
long long arr[1001];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) {
		sort(arr, arr + n);
		arr[0] = arr[0] + arr[1];
		arr[1] = arr[0];
	}
	long long total = 0;
	for (int i = 0; i < n; i++) total += arr[i];
	cout << total << "\n";
}


*/