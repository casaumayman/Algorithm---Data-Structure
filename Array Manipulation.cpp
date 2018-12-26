#include<bits/stdc++.h>
using namespace std;
int n,m;
struct point
{
	bool open;
	int pos;
	long long value;
};
vector <point> query;
point make_point(int pos,bool op,long long val)
{
	point t;
	t.pos=pos;
	t.open=op;
	t.value=val;
	return t;
}
bool cmp(point a,point b)
{
	if (a.pos==b.pos) return (a.open<b.open);
	return (a.pos<b.pos);
}
void Process()
{
	cin>>n>>m;
	int x,y,z;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		query.push_back(make_point(x,true,z));
		query.push_back(make_point(y+1,false,z));
	}
	sort(query.begin(),query.end(),cmp);
	long long maxs=INT_MIN,sum=0;
	for (int i=0;i<query.size();i++)
	{
		if (query[i].open) sum+=query[i].value;
		else sum-=query[i].value;
		maxs=max(sum,maxs);
	}
	cout<<maxs;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
