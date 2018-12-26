#include<bits/stdc++.h>
using namespace std;
int m,n,k;
bool a[100001],b[100001],c[100001];
void Process()
{
	int x,dema=0;
	cin>>m>>n>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>x;
		if (!a[x])
		{
			dema++;
			a[x]=true;
		}
	}
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		b[x]=true;
	}
	int demc=0,length=0,maxs=0;
	for (int i=1;i<=k;i++)
	{
		cin>>x;
		if (b[x])
		{
			if (demc==dema) maxs=max(length,maxs);
			length=0;
			demc=0;
			memset(c,false,sizeof(bool)*100001);
		}
		else
		{
			length++;
			if (a[x] && !c[x])
			{
				demc++;
				c[x]=true;
			}
		}
		//cout<<demc<<" ";
	}
	if (demc==dema) maxs=max(length,maxs);
	cout<<maxs;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
