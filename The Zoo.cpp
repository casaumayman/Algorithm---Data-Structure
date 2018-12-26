#include<bits/stdc++.h>
using namespace std;
long long n,m,ho,dadieu;
int main()
{
	cin>>n>>m;
	if (n%2==1)
	{
		cout<<"IMPOSSIBLE";
		return 0;
	}
	long long sl=n/2;
	ho=4*sl;
	dadieu=ho-m;
	if (dadieu%2==1)
	{
		cout<<"IMPOSSIBLE";
		return 0;
	}
	dadieu/=2;
	ho=sl-dadieu;
	if (ho<0 || dadieu<0)
	{
		cout<<"IMPOSSIBLE";
		return 0;
	}
	cout<<ho<<" "<<dadieu;
	return 0;
}
