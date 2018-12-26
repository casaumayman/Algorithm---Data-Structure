#include<bits/stdc++.h>
using namespace std;
int T,n,a;
int chia(int a)
{
	int dem=0;
	while (a%2==0)
	{
		dem++;
		a/=2;
	}
	return dem;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while (T--)
	{
		cin>>n;
		int t=0;
		for (int i=1;i<=n;i++)
		{
			cin>>a;
			t+=chia(a);
		}
		if (t%2==0) cout<<"Alan\n";
		else cout<<"Charlie\n";
	}
	return 0;
}
