#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
	int r;
	cin>>a>>b;
	while (b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	cout<<a;
	return 0;
}
