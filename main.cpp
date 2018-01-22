#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define ll long long int
#define pi pair<int, int>
#define vi vector<int>
#define maxn int(1e6)
using namespace std;

struct element //Used for custom defined data type
{
	int val;
};

/*element combine (element, element); // Used to combine 2 elements in query/update for segment tree.

struct seg_tree
{
	element st[4*maxn];
	void build(int, int, int);
	void update(int, int, int, int, int, element);
	element query(int, int, int, int, int);
};*/

/*struct BIT
{
	ll ft[maxn+10];
	int LSOne(int);
	void update(int, ll);
	ll query(int);
};*/

int main()
{
	return 0;
}

/*element combine(element a, element b)
{
	if (a.val == -1)
		return b;
	else if (b.val == -1)
		return a;
	element new1;
	new1.val = a.val+b.val;
	return new1;
}

void seg_tree::build(int a, int b, int index)
{
	if (a == b)
	{
		st[index].val = 0; //Change it as appropriate
	}
	else
	{
		build(a, (a+b)/2, 2*index);
		build((a+b)/2+1, b, 2*index+1);
		st[index].val = 0;
	}
}

void seg_tree::update(int a, int b, int l, int r, int index, element x)
{
	if (a > r or b < l)
		return;
	if (l <= a and b <= r)
	{
		st[index] = combine(st[index], x);
	}
	else
	{
		update(a, (a+b)/2, l, r, 2*index, x);
		update((a+b)/2+1, b, l, r, 2*index+1, x);
		st[index] = combine(st[2*index], st[2*index+1]);
	}
}

element seg_tree::query(int a, int b, int l, int r, int index)
{
	if (a > r or b < l)
	{
		element new1;
		new1.val = -1;
		return new1;
	}
	if (l <= a and b <= r)
		return st[index];
	else
	{
		element t1 = query(a, (a+b)/2, l, r, 2*index);
		element t2 = query((a+b)/2+1, b, l, r, 2*index+1);
		return (combine(t1, t2));
	}
}*/

/*int BIT::LSOne(int n)
{
	return (n&-n);
}

void BIT::update(int index, ll val)
{
	ft[index] += val;
	index += LSOne(index);
	while (index <= maxn)
	{
		ft[index] += val;
		index += LSOne(index);
	}
}

ll BIT::query(int index)
{
	if (index <= 0)
		return 0ll;
	ll ans = ft[index];
	index -= LSOne(index);
	while (index > 0)
	{
		ans += ft[index];
		index -= LSOne(index);
	}
	return ans;
}*/
