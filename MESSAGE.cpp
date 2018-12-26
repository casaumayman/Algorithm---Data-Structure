#include<bits/stdc++.h>
using namespace std;
int n,m,res;
bool visited[801],check[801],kq[801];
vector <int> a[801];
int cha[801];
int root(int i)
{
	if (i!=cha[i]) cha[i]=root(cha[i]);
	return cha[i];
}
stack <int> st;
void Input()
{
	cin>>n>>m;
	int u,v;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v;
		a[u].push_back(v);
	}
	for (int i=1;i<=n;i++) cha[i]=i;
}
void DFS(int u)
{
	visited[u]=true;
	check[u]=true;
	st.push(u);
	int v;
	for (int i=0;i<a[u].size();i++)
		if (check[a[u][i]])
		{
			v=root(a[u][i]);
			while (st.top()!=v)
			{
				cha[st.top()]=v;
				st.pop();
			}
		}
	for (int i=0;i<a[u].size();i++)
		if (!visited[a[u][i]]) DFS(a[u][i]);
	check[u]=false;
	if (st.top()==u) st.pop();
}
void Process()
{
	Input();
	for (int i=1;i<=n;i++)
		if (!visited[i]) DFS(i);
	for (int i=1;i<=n;i++) 
		if (cha[i]==i) kq[i]=true;
	for (int i=1;i<=n;i++)
		for (int j=0;j<a[i].size();j++)
			if (root(i)!=root(a[i][j])) kq[root(a[i][j])]=false;
	for (int i=1;i<=n;i++)
		if (kq[i]) res++;
	cout<<res;
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

