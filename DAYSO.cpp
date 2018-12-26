#include<bits/stdc++.h>
using namespace std;
int n;
long long maxs,a[1001],f[1001];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	f[3]=maxs=a[1]+a[2]+a[3];
	for (int i=4;i<=n;i++)
	{
		f[i]=a[i]+a[i-1]+a[i-2];
		f[i]=max(f[i],f[i]+f[i-3]);
		maxs=max(maxs,f[i]);
	}
	cout<<maxs;
	return 0;
}
