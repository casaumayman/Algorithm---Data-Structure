#include<bits/stdc++.h>
using namespace std;
int n,a[11];
int main()
{
	a[1]=1;
	a[2]=2;
	a[3]=3;
	a[4]=1;
	a[5]=2;
	a[6]=3;
	a[7]=1;
	a[8]=2;
	a[9]=3;
	cin>>n;
	if (n%10==0) cout<<4;
	else cout<<a[n%10];
	return 0;
}
