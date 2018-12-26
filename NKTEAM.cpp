#include<bits/stdc++.h>
using namespace std;
struct TS
{
	int a,b,c;
} ts[100001];
int n,b[100001];
bool cmp(TS a,TS b)
{
	return a.a<b.a;
}
void Input()
{
	cin>>n;
	int x;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		ts[x].a=i;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		ts[x].b=i;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		ts[x].c=i;
	}
	sort(ts+1,ts+n+1,cmp);
}
int gets(int vt)
{
	int f=100001;
	while (vt>0)
	{
		f=min(b[vt],f);
		vt-=vt&(-vt);
	}
	return f;
}
void updates(int vt,int gt)
{
	while (vt<=n)
	{
		b[vt]=min(b[vt],gt);
		vt+=vt&(-vt);
	}
}
void Process()
{
	Input();
	int dem=0;
	for (int i=1;i<=n;i++) b[i]=100001;
	for (int i=1;i<=n;i++)
	{
		if (gets(ts[i].b)>ts[i].c) dem++;
		updates(ts[i].b,ts[i].c);
	}
	cout<<dem;
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

