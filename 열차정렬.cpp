#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int lis(int here, vector<int> vc)
{
	vector<int> lis;
	int plis = 1;
	lis.push_back(vc[here]);
	int i;
	for (i = here + 1; i < n; i++)
		if (lis[0] < vc[i])
		{
			lis.push_back(vc[i]);
			plis++;
			i++;
			break;
		}
	for (i; i < n; i++)
	{
		if (lis[0] > vc[i])
			continue;
		if (lis.back() < vc[i])
		{
			lis.push_back(vc[i]);
			plis++;
		}
		else
		{
			auto it = lower_bound(lis.begin() + 1, lis.end(), vc[i]) - (lis.begin());
			lis[it] = vc[i];
		}
	}
	return plis;
}

int getLds(vector<int> lds, int start, int end, int target)
{
	int mid;
	while (start < end)
	{
		mid = (start + end) / 2;

		if (lds[mid] > target)
			start = mid + 1;
		else
			end = mid;
	}
	return end + 1;
}
int lds(int here, vector<int> vc)
{
	vector<int> lds;
	int plds = 1;
	lds.push_back(vc[here]);
	int i = 0;
	for (i = here + 1; i < n; i++)
		if (lds[0] > vc[i])
		{
			lds.push_back(vc[i]);
			plds++;
			i++;
			break;
		}
	for (i; i < n; i++)
	{
		if (lds[0] < vc[i])
			continue;
		if (lds.back() > vc[i])
		{
			lds.push_back(vc[i]);
			plds++;
		}
		else
		{
			int pos = getLds(lds, 1, plds, vc[i]);
			lds[pos - 1] = vc[i];
		}
	}
	return plds;
}
int main()
{
	scanf("%d", &n);
	vector<int> vc(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vc[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int cntLis = lis(i, vc);
		int cntLds = lds(i, vc);
		ans = max(ans, cntLis + cntLds - 1);
	}
	printf("%d", ans);
	return 0;
}


