#include<bits/stdc++.h>
using namespace std;
int m,n,a[101][101],b[101][101];
int main()
{
	cin>>m>>n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			b[i][j]=max(b[i-1][j],b[i][j-1])+a[i][j];
	cout<<b[m][n];
	return 0;
}
