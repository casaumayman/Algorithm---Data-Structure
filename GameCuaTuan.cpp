#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long mods;
map <int,int> dem;
void Input()
{
	cin>>n;
	int maxs=0,t;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		t=++dem[a[i]];
		if (t>maxs)
		{
			maxs=t;
			mods=a[i];
		}
	}
}
void Process()
{
	long long res=0;
	for (int i=1;i<=n;i++)
		if (a[i]<mods) res+=mods-a[i];
		else res+=a[i]-mods;
	cout<<res;
}
int main()
{
	Input();
	Process();
	return 0;
}
