#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
typedef pair <int,int> chuoi;
vector <chuoi> kq;
bool visited[100001],vao[100001];
int DFS(int u)
{
	visited[u]=true;
	if (!visited[a[u]]) return DFS(a[u]);
	return a[u];
}
void Input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		vao[a[i]]=true;
	}
	for (int i=1;i<=n;i++)
		if (!vao[i]) kq.push_back(chuoi(i,DFS(i)));
	for (int i=1;i<=n;i++)
		if (!visited[i]) kq.push_back(chuoi(i,DFS(i)));
	if (kq.size()==1)
	{
		if (kq[0].first==kq[0].second) cout<<0;
		else
		{
			cout<<1<<"\n";
			cout<<kq[0].second<<" "<<kq[0].first;
		}
	}
	else
	{
		cout<<kq.size()<<"\n";
		for (int i=0;i<kq.size()-1;i++)
			cout<<kq[i].second<<" "<<kq[i+1].first<<"\n";
		cout<<kq[kq.size()-1].second<<" "<<kq[0].first;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Input();
	return 0;
}

