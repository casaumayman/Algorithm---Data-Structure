#include<bits/stdc++.h>
using namespace std;
int n,a[21];
int mins(int a[],int l)
{
	int m=101,ms=l;
	for (int i=l;i<=n;i++)
		if (a[i]<m)
		{
			m=a[i];
			ms=i;
		}
	return ms;
}
int main()
{
	cin>>n;
	int i,j;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<n;i++)
	{
		j=mins(a,i);
		if (j!=i) swap(a[i],a[j]);
		for (int k=1;k<=n;k++)
			if (k==i || k==j) cout<<"["<<a[k]<<"] ";
			else cout<<a[k]<<" ";
		cout<<"\n";
	}
	return 0;
}
