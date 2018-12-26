#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001];
int main()
{
	cin>>n>>m;
	long long t=0,f=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (m>=f+a[i])
		{
			t += f+a[i];
			f = 0;
		}
		else
		{
			t += m;
			if (f >= m) f = a[i];
			else f = a[i] - (m - f);
		}
		//cout<<t<<" "<<f<<"\n";
	}
	t += min(f,m);
	cout<<t;
	return 0;
}
/*
5 2
5 4 3 2 1
*/
