#include<bits/stdc++.h>
using namespace std;
struct ask
{
	int start,end;
} a[10001];
int n;
int tree[30000*4];
bool cmp(ask a,ask b)
{
	if (a.start==b.start)
		return (a.end<b.end);
	return (a.start<b.start);
}
void update(int k,int l,int r,int i,int x)
{
	if (l>i || r<i) return;
	if (tree[k]<x) tree[k]=x;
	if (l==r)
	{
		return;
	}
	int m=(l+r)/2;
	update(k*2,l,m,i,x);
	update(k*2+1,m+1,r,i,x);
}
int getmax(int k,int l,int r,int u,int v)
{
	if (l>v || r<u) return INT_MIN;
	if (l>=u && r<=v) return tree[k];
	int m=(l+r)/2;
	return max(getmax(k*2,l,m,u,v),getmax(k*2+1,m+1,r,u,v));
}
void Process()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i].start>>a[i].end;
	sort(a+1,a+n+1,cmp);
	int maxi,maxs=INT_MIN;
	for (int i=1;i<=n;i++)
	{
		maxi=getmax(1,0,30000,0,a[i].start);
		if (maxi+(a[i].end-a[i].start)>maxs) maxs=maxi+(a[i].end-a[i].start);
		update(1,0,30000,a[i].end,maxi+(a[i].end-a[i].start));
		//cout<<maxi<<" ";
	}
	//cout<<getmax(1,1,n,0,4);
	cout<<maxs;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
