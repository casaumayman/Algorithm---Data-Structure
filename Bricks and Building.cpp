#include<bits/stdc++.h>
using namespace std;
int n,q,k,b[100001];
void thuchien(int a)
{
	for (int i=1;i<=sqrt(a);i++)
		if (a%i==0)
		{
			b[i]++;
			b[a/i]++;
		}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	int x;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		thuchien(x);
	}
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>k;
		cout<<b[k]<<"\n";
	}
	return 0;
}
