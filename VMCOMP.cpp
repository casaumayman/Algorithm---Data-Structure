#include<bits/stdc++.h>
using namespace std;
long long sum[100001];
bool check[100001];
struct cmp
{
	bool operator() (int a,int b)
	{
		if (sum[a]==sum[b]) return (a<b);
		return (sum[a]<sum[b]);
	}
};
set <int, cmp> heap;
vector <pair<int,long long> > a[100001];
int n,m,s,dem;
void Process()
{
	cin>>n>>m>>s;
	int x,y;
	long long z;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));
	}
	for (int i=1;i<=n;i++)
	{
		long long z=0;
		for (int j=0;j<a[i].size();j++)
		{
			z+=a[i][j].second;
		}
		sum[i]=z;
		heap.insert(i);
	}
	int i,u;
	while (!heap.empty())
	{
		i=*heap.begin();
		//cout<<sum[i]<<" "<<i<<"\n";
		if (sum[i]>=s) break;
		heap.erase(i);
		check[i]=true;
		for (int j=0;j<a[i].size();j++)
		{
			u=a[i][j].first;
			if (check[u]) continue;
			heap.erase(u);
			sum[u]-=a[i][j].second;
			heap.insert(u);
		}
	}
	if (heap.empty())
	{
		cout<<-1;
		return;
	}
	cout<<heap.size()<<"\n";
	for (int i=1;i<=n;i++)
		if (!check[i]) cout<<i<<" ";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	Process();
	return 0;
} 
