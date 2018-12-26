#include<bits/stdc++.h>
using namespace std;
const long long oo=1e9;
long long a[501][501],b[501][501];
int n,k;
long long min(long long a,long long b,long long c)
{
	long long mins;
	if (a<b) mins=a; else mins=b;
	if (mins>c) mins=c;
	return mins;
}
void Process()
{
	cin>>n>>k;
	int d,c;
	for (int i=1;i<=k;i++)
	{
		cin>>d>>c;
		a[d][c]=b[d][c]=oo;
	}
	a[1][1]=b[1][n]=0;
	for (int i=2;i<=n;i++)
	{
		if (!a[1][i]) a[1][i]=a[1][i-1]+1;
		if (!a[i][1]) a[i][1]=a[i-1][1]+1;
		if (!b[1][n-i+1]) b[1][n-i+1]=b[1][n-i+2]+1;
		if (!b[i][n]) b[i][n]=b[i-1][n]+1;
	}
	for (int i=2;i<=n;i++)
		for (int j=2;j<=n;j++)
			if (!a[i][j]) a[i][j]=min(a[i-1][j-1],a[i-1][j],a[i][j-1])+1;
	for (int i=2;i<=n;i++)
		for (int j=n-1;j>=1;j--)
			if (!b[i][j]) b[i][j]=min(b[i-1][j+1],b[i-1][j],b[i][j+1])+1;
	long long res=oo;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			//cout<<b[i][j]<<" ";
			res=min(res,max(a[i][j],b[i][j]));
		}
		//cout<<"\n";
	}
	cout<<res;
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

