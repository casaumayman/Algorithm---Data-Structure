#include<bits/stdc++.h>
using namespace std;
int n,a[50001],p;
int maxs;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>p;
	int x;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		a[i]=a[i-1]+x;
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (a[j]-a[i-1]>=p)
				if (j-i+1>maxs) maxs=j-i+1;
	cout<<(maxs?maxs:-1);
	return 0;
	
}
