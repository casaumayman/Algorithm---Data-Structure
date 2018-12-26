#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],tree[400001];
void Create(int k,int l,int r)
{
	if (l==r)
	{
		tree[k]=a[l];
		return;
	}
	int m=(l+r)/2;
	Create(k*2,l,m);
	Create(k*2+1,m+1,r);
	tree[k]=min(tree[k*2],tree[k*2+1]);
}
void Input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	Create(1,1,n);
}
int getmin(int k,int u,int v,int l,int r)
{
	if (u>r || v<l) return 1000000009;
	if (u>=l && v<=r) return tree[k];
	int m=(u+v)/2;
	return min(getmin(k*2,u,m,l,r),getmin(k*2+1,m+1,v,l,r));
}
void Process()
{
	Input();
	int p,r;
	for (int i=1;i<=m;i++)
	{
		cin>>p>>r;
		cout<<getmin(1,1,n,p,r)<<"\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}
