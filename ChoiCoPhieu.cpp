#include<bits/stdc++.h>
using namespace std;
int T,n,a[50001],r[50001],maxs;
void Input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	maxs=n;
	r[n]=n;
	for (int i=n-1;i>=1;i--)
		if (a[i]>a[maxs])
		{
			r[i]=i;
			maxs=i;
		}
		else r[i]=maxs;
}
void Process()
{
	long long i=1,res=0,t;
	while (i<=n)
	{
		if (i==r[i])
		{
			i++;
			continue;
		}
		t=0;
		for (int j=i;j<r[i];j++)
		{
			t+=a[j];
		}
		res+=((r[i]-i)*(long long)a[r[i]])-t;
		i=r[i]+1;
	}
	cout<<res<<"\n";
}
int main()
{
	cin>>T;
	while (T--)
	{
		Input();
		Process();
	}
	return 0;
}
