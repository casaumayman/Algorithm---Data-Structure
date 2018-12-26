#include<bits/stdc++.h>
using namespace std;
int n,f[1001];
struct point
{
	int d,c;
} a[1001];
bool cmp(point a,point b)
{
		if (a.c==b.c) return (a.d<b.d);
		return (a.c<b.c);
}
void Process()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i].d>>a[i].c;
	sort(a+1,a+n+1,cmp);
	f[1]=1;
	int maxs=1;
	for (int i=2;i<=n;i++)
	{
		f[i]=1;
		for (int j=1;j<=i-1;j++)
			if (a[j].c<a[i].d) f[i]=max(f[j]+1,f[i]);
		maxs=max(maxs,f[i]);
	}
	cout<<maxs;
//	for (int i=1;i<=n;i++) cout<<a[i].d<<" "<<a[i].c<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
