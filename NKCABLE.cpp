#include<bits/stdc++.h>
using namespace std;
int a[25000],f[25001],n;
int main()
{
	cin>>n;
	for (int i=1;i<n;i++) cin>>a[i];
	f[2]=a[1];
	f[3]=a[1]+a[2];
	//cout<<f[2]<<" "<<f[3]<<" ";
	for (int i=4;i<=n;i++)
	{
		f[i]=min(f[i-2],f[i-1])+a[i-1];
		//cout<<f[i]<<" ";
	}
	cout<<f[n];
	return 0;
}
