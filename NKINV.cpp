#include<bits/stdc++.h>
using namespace std;
struct ele
{
	int val,pos;
	
} a[60001];
int bit[60001],n,dem,b[60001];
bool cmp(ele a,ele b)
{
	if (a.val==b.val) return (a.pos<b.pos);
	return (a.val<b.val);
}
void update(int x)
{
	for (int i=x;i>=1;i-=i&-i)
		bit[i]++;
}
int getsum(int x)
{
	int t=0;
	for (int i=x;i<=n;i+=i&-i)
		t+=bit[i];
	return t;
}
void Process()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].val;
		a[i].pos=i;
	}
	sort(a+1,a+n+1,cmp);
	int c=0;
	a[0].val=INT_MIN;
	for (int i=1;i<=n;i++)
	{
		if (a[i].val==a[i-1].val) b[a[i].pos]=c;
		else b[a[i].pos]=++c;
	}
	for (int i=1;i<=n;i++)
	{
		dem+=getsum(b[i]+1);
		if (b[i]!=1) update(b[i]);
	}
	cout<<dem;
}
int main()
{
	Process();
	return 0;
}
