#include<bits/stdc++.h>
using namespace std;
struct node
{
	int i,j,k,pos,type;
} a[230001];
int n,q,bit[230001],b[200001];
int getsum(int i)
{
	int t=0;
	for (i=i;i>=1;i-=i&(-i)) t+=bit[i];
	return t;
}
void update(int i)
{
	for (i=i;i<=n;i+=i&(-i)) bit[i]++;
}
bool cmp(node a,node b)
{
	if (a.k==b.k) return (a.type<b.type);
	return (a.k>b.k);
}
void XL()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].k;
		a[i].i=a[i].j=i;
		a[i].type=1;
	}
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>a[i+n].i>>a[i+n].j>>a[i+n].k;
		a[i+n].pos=i;
		a[i+n].type=0;
	}
	sort(a+1,a+n+q+1,cmp);
	for (int i=1;i<=n+q;i++)
	{
		if (a[i].type) update(i);
		else b[a[i].pos]=getsum(a[i].j)-getsum(a[i].i-1);
	}
	for (int i=1;i<=q;i++) cout<<b[i]<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	XL();
	return 0;
}
