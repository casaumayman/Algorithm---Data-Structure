#include<bits/stdc++.h>
using namespace std;
long long n;
int rev(int x)
{
	int s=0;
	while (x)
	{
		s=s*10+(x%10);
		x/=10;
	}
	return s+2;
}
int main()
{
	cin>>n;
	int x=1;
	if (n<=82)
		for (long long i=2;i<=n;i++) x=rev(x);
	else
	{
		x=3;
		for (long long i=2;i<=((n-83)%81+1);i++) x=rev(x);
	}
	//for (int i=2;i<=n;i++) x=rev(x);
	cout<<x;
	return 0;
}
