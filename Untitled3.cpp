#include<bits/stdc++.h>
using namespace std;
int f[251][51],n,m,a[251];
int main()
{
	cin>>m>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) f[i][0]=1;
	for (int j=1;j<=m;j++)
	{
		for (int i=1;i<=n;i++)
		{
			if (j>=a[i]) f[i][j]+=f[i-1][j]+f[i][j-a[i]];
			else f[i][j]=f[i-1][j];
			//cout<<f[i][j]<<" ";
		}
		//cout<<"\n";
	}
	cout<<f[n][m];
	return 0;
}
