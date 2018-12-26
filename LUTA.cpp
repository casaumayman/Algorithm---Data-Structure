#include<bits/stdc++.h>
using namespace std;
int n;
long long c;
struct baitap
{
	int a,b;
	bool operator < (const baitap &x) const
	{
		if (a==x.a) return (b>x.b);
		else return (a<x.a);
	}
} bt[100001];
int main()
{
	cin>>n>>c;
	for (int i=1;i<=n;i++) cin>>bt[i].a>>bt[i].b;
	sort(bt+1,bt+n+1);
	int i=1;
	while (c>=bt[i].a && i<=n)
	{
		c+=(long long)bt[i].b;
		i++;
	}
	cout<<i-1;
	return 0;
}
