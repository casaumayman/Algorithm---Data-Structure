#include<bits/stdc++.h>
using namespace std;
bool KT(int a)
{
	if (a<2) return false;
	for (int i=2;i<a;i++)
		if (a%i==0) return false;
	return true;
}
int main()
{
	int n;
	cin>>n;
	for (int i=2;i<=n;i++) 
		if (KT(i)) cout<<i<<" ";
	return 0;
}
