#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
int n;
struct edge
{
	int x1,x2,y;
	bool open;
};
struct Node
{
	int slphu,length;
} t[5*30001];
edge make(int a,int b,int c,bool k)
{
	edge t;
	t.y=a;
	t.x1=b;
	t.x2=c;
	t.open=k;
	return t;
}
void update(int k,int l,int r,int u,int v,bool type)
{
	if (r<u || l>v) return;
	if (u<=l && r<=v)
	{
		if (type)
		{
			t[k].slphu++;
			t[k].length=(r-l+1);
		}
		else
		{
			t[k].slphu--;
			if (t[k].slphu==0)
				t[k].length=t[k*2].length+t[k*2+1].length;
		}
		return;
	}
	int mid=(l+r)/2;
	update(k*2,l,mid,u,v,type);
	update(k*2+1,mid+1,r,u,v,type);
	if (t[k].slphu==0)
		t[k].length=t[k*2].length+t[k*2+1].length;
}
bool cmp(edge a,edge b)
{
	if (a.y==b.y) return (a.x1<b.x1);
	else return (a.y<b.y);
}
vector <edge> a;
void Input()
{
	cin>>n;
	int x,y,u,v;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y>>u>>v;
		a.push_back(make(y,x,u,true));
		a.push_back(make(v,x,u,false));
	}
	sort(a.begin(),a.end(),cmp);
}
void Process()
{
	Input();
	int64 area=0;
	update(1,0,30000,a[0].x1,a[0].x2-1,a[0].open);
	for (int i=1;i<a.size();i++)
	{
		area+=(a[i].y-a[i-1].y)*(int64)t[1].length;
		update(1,0,30000,a[i].x1,a[i].x2-1,a[i].open);
	}
	cout<<area;
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

