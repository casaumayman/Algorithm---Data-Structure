#include<bits/stdc++.h>
using namespace std;
int cha[30001],con[30001],n,m;
vector <int> a[30001];
stack <int> st;
bool visited[30001];
int root(int i)
{
	if (cha[i]!=i) cha[i]=root(cha[i]);
	return cha[i];
}
void dfs(int u)
{
	visited[u]=true;
	cha[u]=u;
	st.push(u);
	int v;
	for (int k=0;k<a[u].size();k++) if (visited[a[u][k]])
	{
		v=a[u][k];
		v=root(con[v]);
		while (st.top()!=v)
		{
			cha[root(st.top())]=v;
			st.pop();
		}
	}
	for (int k=0;k<a[u].size();k++) if (!visited[a[u][k]])
	{
		v=a[u][k];
		con[u]=v;
		dfs(v);
	}
	if (st.top()==u) st.pop();
}
void Input()
{
	cin>>n>>m;
	int u,v;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}
void Process()
{
	Input();
	if (m==0)
	{
		cout<<1;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!visited[i]) dfs(i);
	for (int i=1;i<=n;i++) con[i]=0;
	int maxs=0,u;
	for (int i=1;i<=n;i++)
	{
		u=root(i);
		con[u]++;
		if (con[u]>maxs) maxs=con[u];
	}
	cout<<maxs+1;
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

