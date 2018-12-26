#include<bits/stdc++.h>
using namespace std;
int const oo=INT_MAX;
int n,k,a[100001],c[101],mins[100001][101];
int f[100001][101];
void Input()
{
	cin>>n>>k;
	int x;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++) mins[i][j]=oo;
	for (int i=1;i<=n;i++) cin>>x,a[i]=a[i-1]+x;
	for (int i=1;i<=k;i++) cin>>x,c[i]=c[i-1]+x;
	for (int i=1;i<=n;i++) f[0][0]=0,mins[i][0]=0;
	for (int i=1;i<=k;i++) f[0][i]=oo,mins[0][i]=oo;
}
void Process()
{
	Input();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			if (i<c[j]) f[i][j]=oo;
			else
			{
				f[i][j]=mins[i-(c[j]-c[j-1])][j-1]+(a[i]-a[i-(c[j]-c[j-1])]);
				mins[i][j]=min(f[i][j],mins[i-1][j]);
			}
	cout<<mins[n][k];
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

