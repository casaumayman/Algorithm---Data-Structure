#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
long long f[100001],maxs=-999999999;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=3;i<=n;i++)
	{
		long long k=(long long)a[i]+a[i-1]+a[i-2];
		f[i]=max(k,k+f[i-3]);
		maxs=max(f[i],maxs);
	}
	cout<<maxs;
	return 0;
}
