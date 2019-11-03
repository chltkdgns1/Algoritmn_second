#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll sum(vector<ll> &tree, int i)
{
	ll ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i); // 최하위 비트 지우기 
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
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	vector<ll> arr(n + 1);
	vector<ll> tree(n + 1);

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		update(tree, i, arr[i]);
	}

	m += k;

	while (m--)
	{
		int num;
		scanf("%d", &num);

		if (num == 1)
		{
			int index;
			ll val;
			scanf("%d %lld", &index, &val);

			ll diff = val - arr[index];
			arr[index] = val;

			update(tree, index, diff);
		}

		else if (num == 2)
		{
			int left, right;
			scanf("%d %d", &left, &right);

			printf("%lld\n", sum(tree, right) - sum(tree, left - 1));
		}
	}

	return 0;
}
