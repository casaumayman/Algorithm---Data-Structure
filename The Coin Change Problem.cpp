#include<bits/stdc++.h>
using namespace std;
int n,m,a[251];
long long f[51][251];
int main()
{
	cin>>m>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) f[0][i]=1;
	for (int j=1;j<=m;j++)
	{
		for (int i=1;i<=n;i++)
		{
			if (j>=a[i]) f[j][i]=f[j][i-1]+f[j-a[i]][i];
			else f[j][i]=f[j][i-1];
			cout<<f[j][i]<<" ";
		}
		cout<<"\n";
	}
	//cout<<f[m][n];
	return 0;
}
