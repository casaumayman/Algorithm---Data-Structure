#include<bits/stdc++.h>
using namespace std;
const int BASE=1000003;
int dx[6],dy[6],n,k,m,t,q,cach[3001][3001],buoc[3001][3001];
struct tien
{
	int sin;
	int kore;
	tien(int a,int b)
	{
		sin=a;
		kore=b;
	}
};
void nhap()
{
	cin>>m>>n>>t>>k;
	char c;
	int u,v;
	for (int i=1;i<=k;i++)
	{
		cin>>c>>u>>v;
		if (c=='L')
		{
			dx[i]=-u;
			dy[i]=v;
		}
		else
		{
			dy[i]=-v;
			dx[i]=u;
		}
	}
}
void BFS()
{
	queue <tien> que;
	que.push(tien(m,n));
	buoc[m][n]=0;
	cach[m][n]=1;
	int x,y,u,v;
	while (!que.empty())
	{
		x=que.front().sin;
		y=que.front().kore;
		que.pop();
		if (buoc[x][y]>t) continue;
		for (int i=1;i<=k;i++)
		{
			u=x+dx[i];
			v=y+dy[i];
			if (u<0 || v<0) continue;
			if (buoc[u][v]==buoc[x][y]+1)
				cach[u][v]=(cach[x][y]%BASE+cach[u][v]%BASE)%BASE;
			if (!buoc[u][v] && (u!=m || v!=n))
			{
				buoc[u][v]=buoc[x][y]+1;
				cach[u][v]=cach[x][y]%BASE;
				que.push(tien(u,v));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	nhap();
	BFS();
	cin>>q;
	int x,y;
	while (q--)
	{
		cin>>x>>y;
		if (buoc[x][y]>t || !cach[x][y]) cout<<-1<<" "<<-1<<"\n";
		else cout<<buoc[x][y]<<" "<<cach[x][y]<<"\n";
	}
	return 0;
}
