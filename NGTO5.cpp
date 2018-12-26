#include<bits/stdc++.h>
using namespace std;
int dem[100001],T,n;
bool KT(int x)
{
	if (x<2) return false;
	if (x==2) return true;
	if (x%2==0) return false;
	for (int i=3;i<=sqrt(x);i+=2)
		if (x%i==0) return false;
	return true;
}
bool KTU(int a,int b)
{
	int r;
	while (b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return (a==1);
}
int main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;
		int t=0;
		for (int i=1;i<=n;i++)
			if (KTU(i,n)) t++;
		if (KT(t)) cout<<"TRUE\n";
		else cout<<"FALSE\n";
	}
	return 0;
}
