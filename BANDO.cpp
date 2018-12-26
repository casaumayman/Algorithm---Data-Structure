#include<bits/stdc++.h>
using namespace std;
int n,a[1001][1001];
struct kq
{
	int maxs,mins;
} f[1001][1001];
void lech(int i,int j)
{
	int mins1=min(f[i-1][j].mins,a[i][j]);
	int maxs1=max(f[i-1][j].maxs,a[i][j]);
	int mins2=min(f[i][j-1].mins,a[i][j]);
	int maxs2=max(f[i][j-1].maxs,a[i][j]);
	if ((maxs1-mins1)<(maxs2-mins2))
	{
		f[i][j].maxs=max(f[i-1][j].maxs,a[i][j]);
		f[i][j].mins=min(f[i-1][j].mins,a[i][j]);
	}
	else
	{
		f[i][j].maxs=max(f[i][j-1].maxs,a[i][j]);
		f[i][j].mins=min(f[i][j-1].mins,a[i][j]);
	}
}
void Process()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
	f[1][1].mins=f[1][1].maxs=a[1][1];
	for (int i=2;i<=n;i++)
	{
		f[1][i].maxs=max(f[1][i-1].maxs,a[1][i]);
		f[1][i].mins=min(f[1][i-1].mins,a[1][i]);
		f[i][1].maxs=max(f[i-1][1].maxs,a[i][1]);
		f[i][1].mins=min(f[i-1][1].mins,a[i][1]);
	}
	for (int i=2;i<=n;i++)
		for (int j=2;j<=n;j++)
		{
			lech(i,j);
		}
	cout<<f[n][n].maxs-f[n][n].mins;
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}

