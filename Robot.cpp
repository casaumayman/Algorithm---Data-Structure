#include<bits/stdc++.h>
using namespace std;
int n;
int huong(int x,int y,int a,int b)
{
	if (a==x+1 && b==y) return 1;
	if (a==x && b==y+1) return 0;
	if (a==x && b==y-1) return 2;
	return 3;
}
int main()
{
	int x1,y1,x2,y2,h1,h2,dem=0;
	cin>>n;
	cin>>x1>>y1>>x2>>y2;
	h1=huong(x1,y1,x2,y2);
	x1=x2;
	y1=y2;
	for (int i=3;i<=n;i++)
	{
		cin>>x2>>y2;
		h2=huong(x1,y1,x2,y2);
		if (h2==h1+1 || (h2==0 && h1==3)) dem++;
		h1=h2;
		x1=x2;
		y1=y2;
	}
	cout<<dem;
	return 0;
}
