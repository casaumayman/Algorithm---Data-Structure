#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
	cin>>T;
	int u,v;
	while (T--)
	{
		cin>>n;
		for (int i=sqrt(n);i>=1;i--)
			if (n%(i*i)==0)
			{
				 cout<<i<<" "<<n/(i*i)<<"\n";
				 break;
			}
	}
	return 0;
}
