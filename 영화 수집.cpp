#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
ll query(vector<ll> &tree, int i)
{
	ll ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(vector<ll> &tree, int i, ll diff)
{
	while (i < tree.size())
	{
		tree[i] += diff;
		i += (i & -i);
	}
}
int main()
{
	int tCase;
	scanf("%d", &tCase);
	while (tCase--)
	{
		vector<ll> tree(200002);
		vector<int> floor(200002);
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			floor[i] = n - i + 1;
			update(tree, i, 1);
		}
		int next = n + 1;
		while (m--)
		{
			int val;
			scanf("%d", &val);
			printf("%lld ", query(tree, 200001) - query(tree, floor[val]));
			update(tree, floor[val], -1);
			floor[val] = next++;
			update(tree, floor[val], 1);
		}
		printf("\n");
	}
	return 0;
}

