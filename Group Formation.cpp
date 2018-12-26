#include<bits/stdc++.h>
using namespace std;
struct stu
{
	string Name;
	int grade;
} st[100001];
bool cmp(stu a,stu b)
{
	return (a.Name<b.Name);
}
int n,m,a,b,f,s,t;
struct par
{
	int f,s,t,st;
} cha[100001];
int root(int v)
{
	return (cha[v].st==-1)?v:(cha[v].st=root(cha[v].st));
}
int tong(par a)
{
	return a.f+a.s+a.t;
}
void merge(int x,int y)
{
	if ((x=root(x))==(y=root(y))) return;
	if (tong(cha[root(x)])<tong(cha[root(y)])) swap(x,y);
	cha[x].f+=cha[y].f;
	cha[x].s+=cha[y].s;
	cha[x].t+=cha[y].t;
	cha[y].st=x;
}
void Input()
{
	cin>>n>>m>>a>>b>>f>>s>>t;
	for (int i=1;i<=n;i++)
	{
		cin>>st[i].Name>>st[i].grade;
		cha[i].st
	}
	sort(st+1,st+n+1,cmp);
	int x,y;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y;
	}
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	return 0;
}

