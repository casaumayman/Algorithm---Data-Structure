#include<bits/stdc++.h>
using namespace std;
long long n,s,a[101],res,f[101][1001];
void Process()
{
	cin>>n>>s;
	int maxs;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]>maxs) maxs=a[i];
	}
	while (s>1000)
	{
		res++;
		s-=maxs;
	}
	for (int i=1;i<=s;i++) f[0][i]=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=s;j++)
			if (a[i]<=j) f[i][j]=min(f[i-1][j],f[i][j-a[i]]+1);
			else f[i][j]=f[i-1][j];
	}
	cout<<res+f[n][s];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}

