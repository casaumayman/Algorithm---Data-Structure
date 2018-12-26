#include<bits/stdc++.h>
using namespace std;
int n;
long long f[200001];
int main()
{
	cin>>n;
	long long x,maxs;
	f[0]=maxs=-999999999;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		f[i]=max(x,f[i-1]+x);
		maxs=max(f[i],maxs);
	}
	cout<<maxs;
	return 0;
}
