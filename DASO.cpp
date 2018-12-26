#include<bits/stdc++.h>
using namespace std;
int n,a[30001],f[30001],maxs;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	f[1]=1;
	f[2]=2;
	for (int i=3;i<=n;i++)
	{
		if (a[i]==a[i-1]+a[i-2]) f[i]=f[i-1]+1;
		else f[i]=2;
		maxs=max(maxs,f[i]);
	}
	if (maxs<3) cout<<-1; else cout<<maxs;
	return 0;
}
