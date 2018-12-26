#include<bits/stdc++.h>
using namespace std;
int n;
char a[501][501];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
bool visited[501][501];
int kq;
void dfs(int x,int y)
{
	visited[x][y]=true;
	kq++;
	int u,v;
	//cout<<x<<" "<<y<<"\n";
	for (int k=0;k<4;k++)
	{
		u=x+di[k];
		v=y+dj[k];
		if (u>=1 && u<=n && v>=1 && v<=n && !visited[u][v] && a[u][v]=='1')
			dfs(u,v);
	}
}
void Process()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	int coun=0;
	int maxs=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]=='1' && !visited[i][j]) 
			{
				coun++;
				kq=0;
				dfs(i,j);
				maxs=max(maxs,kq);
			}
	cout<<coun<<" "<<maxs;
}
int main()
{
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}

