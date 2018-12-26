#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
bool visited[101][101];
bool check(int a,int b)
{
	return ((a>=1 && a<=m) && (b>=1 && b<=n));
}
void Process()
{
	cin>>n>>m>>x;
	int u,v,res=0,a,b;
	for (int i=1;i<=x;i++)
	{
		cin>>u>>v;
		if (!visited[u][v])
		{
			visited[u][v]=true;
			res++;
		}
		for (int k=0;k<4;k++)
		{
			a=u+di[k];
			b=v+dj[k];
			if (!check(a,b)) continue;
			if (!visited[a][b])
			{
				visited[a][b]=true;
				res++;
			}
		}
	}
	cout<<res;
//	for (int i=1;i<=m;i++)
//	{
//		for (int j=1;j<=n;j++) cout<<visited[i][j]<<" ";
//		cout<<"\n";
//	}
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

