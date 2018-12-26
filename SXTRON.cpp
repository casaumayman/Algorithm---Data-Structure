#include<bits/stdc++.h>
using namespace std;
int n,m,a[21],b[21];
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	a[n+1]=b[m+1]=999;
	int i=1,j=1;
	while (i<=n || j<=m)
	{
		if (a[i]<=b[j])
		{
			cout<<"b"<<i<<" ";
			i++;
		}
		else
		{
			cout<<"c"<<j<<" ";
			j++;
		}
	}
	return 0;
}
