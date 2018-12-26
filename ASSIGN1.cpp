#include<bits/stdc++.h>
using namespace std;
int a[201][201],MatchX[201],MatchY[201],trace[201],n,maxs;
void Input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]>maxs) maxs=a[i][j];
		}
}
int FindPatch(int x,int val)
{
	queue <int> que;
	que.push(x);
	memset(trace,0,sizeof trace);
	int u;
	while (!que.empty())
	{
		u=que.front();
		que.pop();
		for (int v=1;v<=n;v++)
			if (a[u][v]<=val && !trace[v])
			{
				trace[v]=u;
				if (!MatchY[v]) return v;
				que.push(MatchY[v]);
			}
	}
	return 0;
}
void Enlarge(int f)
{
	int next,x;
	while (f)
	{
		x=trace[f];
		next=MatchX[x];
		MatchX[x]=f;
		MatchY[f]=x;
		f=next;
	}
}
bool check(int val)
{
	memset(MatchX,0,sizeof MatchX);
	memset(MatchY,0,sizeof MatchY);
	int v;
	for (int u=1;u<=n;u++)
		if (!MatchX[u])
		{
			v=FindPatch(u,val);
			if (v) Enlarge(v);
		}
	for (int u=1;u<=n;u++)
		if (!MatchX[u]) return false;
	return true;
}
void Process()
{
	Input();
	int i=0,j=maxs,mid;
	while (i<j)
	{
		mid=(i+j)/2;
		if (check(mid)) j=mid;
		else i=mid+1;
	}
	cout<<i;
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

