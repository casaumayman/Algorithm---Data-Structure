#include<bits/stdc++.h>
using namespace std;
int m,n;
int h[100001],f[400001],t[400001];
int nhap()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>h[i];
}
void init(int k,int l,int r)
{
	if (l==r)
	{
		f[k]=h[l];
		return;
	}
	int m=(l+r)/2;
	init(k*2,l,m);
	init(k*2+1,m+1,r);
	f[k]=max(f[k*2],f[k*2+1]);
}
void update(int k,int l,int r,int u,int v,int x)
{
	if (t[k])
	{
		f[k]=t[k];
		t[k*2]=t[k];
		t[k*2+1]=t[k];
		t[k]=0;
	}
	if (u>r || v<l) return;
	if (u<=l && v>=r)
	{
		t[k]=x;
		f[k]=t[k];
		return;
	}
	int m=(l+r)/2;
	update(k*2,l,m,u,v,x);
	update(k*2+1,m+1,r,u,v,x);
	f[k]=max(f[k*2],f[k*2+1]);
}
int get(int k,int l,int r,int u,int v)
{
	if (t[k])
	{
		f[k]=t[k];
		t[k*2]=t[k];
		t[k*2+1]=t[k];
		t[k]=0;
	}
	if (u>r || v<l) return -999999999;
	if (u<=l && v>=r) return f[k];
	int m=(l+r)/2;
	return max(get(k*2,l,m,u,v),get(k*2+1,m+1,r,u,v));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	nhap();
	init(1,1,n);
	int p,l;
	for (int i=1;i<=m;i++)
	{
		cin>>p>>l;
		int maxs=get(1,1,n,p,p+l-1);
		cout<<maxs+1<<"\n";
		update(1,1,n,p,p+l-1,maxs+1);
	}
	return 0;
}
