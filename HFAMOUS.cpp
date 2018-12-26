#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int id,val;
};
Node make(int a,int b)
{
	Node t;
	t.id=a;
	t.val=b;
	return t;
}
struct cmp
{
	bool operator() (Node a,Node b)
	{
		return (a.val>b.val);
	}
};
int dem[100001],n,m,k,spt;
vector <int> a[100001];
priority_queue <Node,vector<Node>,cmp> heap;
void Input()
{
	int u,v;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v;
		dem[u]++;
		dem[v]++;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	spt=n;
	for (int i=1;i<=n;i++)
		heap.push(make(i,dem[i]));
}
void Process()
{
	Node t;
	while (!heap.empty() && heap.top().val<k)
	{
		t=heap.top();
		heap.pop();
		if (dem[t.id]==-1) continue;
		spt--;
		//cout<<t.id<<" "<<t.val<<"\n";
		dem[t.id]=-1;
		for (int i=0;i<a[t.id].size();i++)
			if (dem[a[t.id][i]]>-1)
				heap.push(make(a[t.id][i],--dem[a[t.id][i]]));
	}
}
void Output()
{
	cout<<spt<<"\n";
	if (spt)
		for (int i=1;i<=n;i++)
			if (dem[i]>-1) cout<<i<<" ";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Input();
	if (k<=0)
	{
		cout<<n<<"\n";
		for (int i=1;i<=n;i++) cout<<i<<" ";
		return 0;
	}
	Process();
	Output();
	return 0;
}
    
