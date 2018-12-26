#include<bits/stdc++.h>
#define REP for(int i=1;i<=m;i++) for (int j=1;j<=n;j++)
using namespace std;
int n,m,a[1001][1001],f[1001][1001];
int min3(int a,int b,int c)
{
	return min(min(a,b),c);
}
void Process()
{
	cin>>m>>n;
	REP cin>>a[i][j];
	for (int i=0;i<=m;i++) f[i][1]=1;
	for (int i=0;i<=n;i++) f[1][i]=1;
	REP if (a[i][j]==a[i-1][j] &&
	a[i][j]==a[i][j-1] &&
	a[i][j]==a[i-1][j-1]) f[i][j]=min3(f[i-1][j],f[i][j-1],f[i-1][j-1])+1;
	else f[i][j]=1;
	int maxs=0;
	REP if (f[i][j]>maxs) maxs=f[i][j];
	cout<<maxs;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
