#include<bits/stdc++.h>
using namespace std;
long long L,R,T;
int main()
{
	cin>>T;
	while (T--)
	{
		cin>>L>>R;
		cout<<(long long)sqrtl(R)-(long long)sqrtl(L-1)<<"\n";
	}
	return 0;
}
