#include<bits/stdc++.h>
using namespace std;
int n;
long long maxs,a[1001],f[1001];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	f[3]=a[3]+a[1]+a[2];
	for (int i=4;i<=n;i++)
	{
		f[i]=a[i]+a[i-1]+a[i-2];
		for (int j=i-4;j>=3;j--) f[i]=max(f[i],f[i]+f[j]);
		maxs=max(maxs,f[i]);
	}
	cout<<maxs;
	return 0;
}
