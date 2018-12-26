#include<bits/stdc++.h>
using namespace std;
vector<int> lab;
int cha(int i)
{
	if (lab[i]<0) return i;
	lab[i]=cha(lab[i]);
	return lab[i];
}	
bool sameSet(int u,int v)
{
	return (cha(u)==cha(v));
}
bool merge(int u,int v)
{		
    int x=cha(u);
    int y=cha(v);
	if (x==y) return false;
	if (lab[x]>lab[y]) swap(x,y);
	lab[x]+=lab[y];
	lab[y]=x;
	return true;
}	
char a[1515][1515];	
int dis[1515][1515];
pair<int,int> sortDis[1515*1515],swan[7];
int m,n;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void init() 
{
    cin>>m>>n;
    for (int i=1;i<=m;i++) cin>>a[i]+1;
    int nSwan=0;
    for (int i=1;i<=m;i++) 
		for (int j=1;j<=n;j++) 
			if (a[i][j]=='L') swan[++nSwan]=make_pair(i,j);
}
bool inside(int x,int y) 
{
	if (x<1 || x>m || y<1 || y>n) return (false);	
    return true;
}
void bfs() 
{	
    memset(dis,-1,sizeof dis);	
    queue<pair<int,int> > q;
    for (int i=1;i<=m;i++) 
		for (int j=1;j<=n;j++) if (a[i][j]!='X') 
		{
        	dis[i][j]=0;
        	q.push(make_pair(i,j));
    	}
    int nVst=0;
    while (!q.empty()) 
	{
        int ux=q.front().first;
        int uy=q.front().second;
        q.pop();
        sortDis[++nVst]=make_pair(ux,uy);
        for (int i=0;i<4;i++) 
			if (inside(ux+dx[i],uy+dy[i])) 
			{
            	int vx=ux+dx[i];
            	int vy=uy+dy[i];
            	if (dis[vx][vy]<0) 
				{
                	dis[vx][vy]=dis[ux][uy]+1;
                	q.push(make_pair(vx,vy));
            	}
			}
    }
}
int cellID(int x,int y) 
{	
    return ((x-1)*n+y);
}
void process() 
{
	lab.assign(m*n+1,-1);	
    int j=1;
    int sta=cellID(swan[1].first,swan[1].second);	
    int fin=cellID(swan[2].first,swan[2].second);
    for (int i=0;i<=1515*1515;i++) 
	{
        while (j<=m*n && dis[sortDis[j].first][sortDis[j].second]<=i) 
		{
            int x=sortDis[j].first;
            int y=sortDis[j].second;
            for (int k=0;k<4;k++) if (inside(x+dx[k],y+dy[k]) && dis[x+dx[k]][y+dy[k]]<=i)
                merge(cellID(x,y),cellID(x+dx[k],y+dy[k]));
            j++;
        }
        if (sameSet(sta,fin)) {
            cout<<i;
            return;
        }
    }	
}
int main() 
{
    init();
    bfs();
    process();
    return 0;	
}
