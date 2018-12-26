#include<bits/stdc++.h>
using namespace std;
struct ele
{
	int dinh,chiphi,dodai;
};
struct cmp
{
	bool operator() (ele a,ele b)
	{
		if (a.dodai==b.dodai)
			return (a.chiphi>b.chiphi);
		return (a.dodai>b.dodai);
	}
};
int min_long;
ele make_ele(int i,int j,int k)
{
	ele t;
	t.dinh=i;
	t.dodai=j;
	t.chiphi=k;
	return t;
}
vector <ele> a[101];
int T,K,n,m;
void Input()
{
	cin>>K>>n>>m;
	min_long=INT_MAX;
	int u,v,l,t;
	for (int i=1;i<=n;i++) a[i].clear();
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>l>>t;
		a[u].push_back(make_ele(v,l,t));
	}
}
void dijkstra()
{
	priority_queue <ele, vector <ele>, cmp> heap;
	heap.push(make_ele(1,0,0));
	int u,money,dai;
	while (!heap.empty())
	{
		u=heap.top().dinh;
		dai=heap.top().dodai;
		money=heap.top().chiphi;
		heap.pop();
		if (u==n)
		{
			min_long=dai;
			return;
		}
		for (int i=0;i<a[u].size();i++)
		{
			if (money+a[u][i].chiphi>K) continue;
			heap.push(make_ele(a[u][i].dinh,a[u][i].dodai+dai,a[u][i].chiphi+money));
		}
	}
}
void Process()
{
	Input();
	dijkstra();
	if (min_long==INT_MAX) cout<<"-1\n";
	else cout<<min_long<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	cin>>T;
	while (T--) Process();
	return 0;
}
