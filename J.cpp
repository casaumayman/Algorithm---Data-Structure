#include<bits/stdc++.h>
using namespace std;
string x,y;
int dem;
void Process()
{
	cin>>x>>y;
	string s="";
	if (x.size()<y.size())
	{
		for (int k=1;k<=y.size()-x.size();k++) s.push_back('0');
		x=s+x;
	}
	if (y.size()<x.size())
	{
		for (int k=1;k<=x.size()-y.size();k++) s.push_back('0');
		y=s+y;
	}
	int i=0;
	while (x[i]=='0' && y[i]=='0') i++;
	while (x[i]==y[i] && i<x.size()) i++;
	dem=x.size()-i;
}
int main()
{
	//freopen("C:\\Users\\ADMIN\\Desktop\\test.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	cout<<dem;
	return 0;
}
