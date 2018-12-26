#include<bits/stdc++.h>
using namespace std;
long long f[26][26],n,k,T;
void Process()
{	
	f[0][0]=1;
	for (int i=1;i<=25;i++)
		for (int j=1;j<=25;j++) f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
	cin>>T;
	while (T--)
	{
		cin>>n>>k;
		cout<<f[n][k]<<"\n";
	}
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

