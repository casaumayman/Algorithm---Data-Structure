#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
bool visited[100001],instack[100001];
int cha[100001],num[100001],res[100001];
stack <int> st;
int root(int i)
{
	if (cha[i]!=i) cha[i]=root(cha[i]);
	return cha[i];
}
void Input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		cha[i]=i;
		num[i]=1;
	}
	memset(res,-1,sizeof(int)*(n+1));
}
void DFS(int u)
{
	//cout<<u<<"\n";
	visited[u]=true;
	instack[u]=true;
	st.push(u);
	int v;
	if (instack[a[u]])
	{
		v=root(a[u]);
		while (st.top()!=v)
		{
			cha[st.top()]=v;
			st.pop();
			num[v]++;
		}
	}
	else if (!visited[a[u]])
		{
			DFS(a[u]);
		}
	//if (visited[a[u]] and a[u]!=u) num[u]=num[a[u]]+1;
	instack[u]=false;
	if (st.top()==u) st.pop();
}
int kq(int i)
{
	if (res[i]!=-1) return res[i];
	if (i==a[i])
	{
		res[i]=1;
		return res[i];
	}
	if (root(i)!=root(a[i]))
	{
		res[i]=kq(a[i])+1;
		return res[i];
	}
	if (root(i)==root(a[i])) 
	{
		res[i]=num[root(i)];
		return res[i];
	}
}
void Process()
{
	Input();
//	DFS(5);
	for (int i=1;i<=n;i++)
		if (!visited[i]) DFS(i);
	for (int i=1;i<=n;i++)
	{
		cout<<kq(i)<<"\n";
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

