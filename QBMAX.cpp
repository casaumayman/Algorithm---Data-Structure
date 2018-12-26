#include<bits/stdc++.h>
using namespace std;
int n,a[101][101],f[101][101],m;
int maxs(int j,int i)
{
	if (j==1) return max(f[j][i-1],f[j+1][i-1]);
	if (j==m) return max(f[j-1][i-1],f[j][i-1]);
	return max(max(f[j-1][i-1],f[j][i-1]),f[j+1][i-1]);
}
void Process()
{
	cin>>m>>n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
	for (int i=1;i<=m;i++)
		f[i][1]=a[i][1];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[j][i]=maxs(j,i)+a[j][i];
	int maxx=INT_MIN;
	for (int i=1;i<=m;i++)
		if (f[i][n]>maxx) maxx=f[i][n];
	cout<<maxx;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}
