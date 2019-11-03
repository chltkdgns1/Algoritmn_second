#include <iostream>
#include <algorithm>
using namespace std;
int val[10002]; // 무게
int happy[10002]; // 만족도
int MaxVal[10002]; // dp배열
int n, m;
int main()
{
	int ct = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int v, c, k;
		cin >> v >> c >> k;
		int tot = 0;
		int flag = 1;
		for (int i = 1; tot < k&&flag; i *= 2)
		{
			tot += i;
			if (tot >= k)
			{
				tot -= i;
				i = k - tot;
				flag = 0;
			}
			val[ct] = v * i;
			happy[ct] = c * i;
			ct++;
		}
	}
	for (int i = 0; i < ct; ++i)
	{
		for (int j = m; j >= val[i]; j--)
			MaxVal[j] = max(MaxVal[j], MaxVal[j - val[i]] + happy[i]);
	}
	cout << MaxVal[m];
}