#include<bits/stdc++.h>
using namespace std;
long long n,t;
int main()
{
	cin>>n;
	while (n)
	{
		t+=n%10;
		n/=10;
	}
	cout<<t;
	return 0;
	
}
