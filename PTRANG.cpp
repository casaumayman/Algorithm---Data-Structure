#include<bits/stdc++.h>
using namespace std;
int f[6001],w[6001],n,l;
void Input()
{
	cin>>n>>l;
	for (int i=1;i<=n;i++)
	{
		cin>>w[i];
		w[i]+=w[i-1];
	}
}
void Process()
{
	Input();
	for (int i=1;i<=n;i++)
	{
		f[i]=INT_MAX;
		for (int j=i-1;j>=0;j--)
		{
			if (w[i]-w[j]>l) break;
			f[i]=min(f[i],max(f[j],l-(w[i]-w[j])));
		}
	}
	cout<<f[n];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
