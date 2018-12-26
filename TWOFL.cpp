#include<bits/stdc++.h>
using namespace std;
int m,n,a[2001][2001],sl[4000001];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1},coun,maxs;
set <pair<int,int> > ma;
set <pair<int,int> >::iterator it;
bool visited[2001][2001];
bool check(int i,int j)
{
	bool c1,c2;
	c1=(i>=1 && i<=m);
	c2=(j>=1 && j<=n);
	return (c1 && c2);
}
void Input()
{
	cin>>m>>n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			sl[a[i][j]]++;
		}
	int x,y;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
		{
			x=a[i][j];
			if (check(i,j+1))
			{
				y=a[i][j+1];
				if (x>y) swap(x,y);
				if (x!=y) ma.insert(make_pair(x,y));
			}
			if (check(i+1,j))
			{
				y=a[i+1][j];
				if (x>y) swap(x,y);
				if (x!=y) ma.insert(make_pair(x,y));
			}
		}
}
void submit(int u,int v,int i,int j)
{
	coun++;
	visited[i][j]=true;
	int x,y;
	for (int k=0;k<4;k++)
		if (check(i+di[k],j+dj[k]))
		{
			x=i+di[k];
			y=j+dj[k];
			if (!visited[x][y])
			{
				if (a[x][y]!=u && a[x][y]!=v) continue;
				visited[x][y]=true;
				submit(u,v,x,y);
			}
		}
}
void Process()
{
	Input();
	int u,v;
	if (ma.empty())
	{
		cout<<m*n;
		return;
	}
	for (it=ma.begin();it!=ma.end();it++)
	{
		memset(visited,false,sizeof(bool)*2001*2001);
		u=(*it).first;
		v=(*it).second;
		if (sl[u]+sl[v]<=maxs) continue;
		coun=0;
		for (int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
				if ((a[i][j]==u || a[i][j]==v) && !visited[i][j])
				{
					coun=0;
					submit(u,v,i,j);
					maxs=max(maxs,coun);
				}
	}
	cout<<maxs;
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

