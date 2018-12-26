#include<bits/stdc++.h>
using namespace std;
int n,a[60001],b[60000],f[60001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<n;i++)
	{
		cin>>b[i];
	}
	f[1]=a[1];
	for (int i=2;i<=n;i++)
		f[i]=min(b[i-1]+f[i-2],f[i-1]+a[i]);
	cout<<f[n];
	return 0;
}
