#include<bits/stdc++.h>
using namespace std;
int T,m,n;
vector<int> a[10001];
int dem[10001];
bool seen[10001];
void Input()
{
	cin>>n>>m;
	int u,v;
	for (int i=1;i<=n;i++)
	{
		a[i].clear();
		dem[i]=0;
		seen[i]=false;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v;
		dem[v]++;
		a[u].push_back(v);
	}
}
void Process()
{
	Input();
	int id=n,u,v;
	vector <int> tt;
	bool multi_way=false,imposible=false;
	queue <int> que;
	while (id)
	{
		if (!multi_way && que.size()>1) multi_way=true;
		for (int i=1;i<=n;i++)
			if (!dem[i]) que.push(i);
		if (que.empty()) imposible=true;
		while (!que.empty())
		{
			u=que.front();
			que.pop();
			seen[u]=true;
			id--;
			tt.push_back(u);
			for (v=0;v<a[u].size();v++)
			{
				if (seen[a[u][v]])
				{
					imposible=true;
					break;
				}
				dem[a[u][v]]--;
			}
			if (imposible) break;
		}
		if (imposible) break;
	}
	if (imposible || id) cout<<tt.size()<<"\n";
	else if (multi_way) cout<<"missing hints\n";
	else
	{
		for (int i=0;i<tt.size();i++) cout<<tt[i]<<" ";
		cout<<"\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>T;
	while (T--) Process();
	return 0;
}
