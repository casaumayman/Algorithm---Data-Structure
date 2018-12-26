#include<bits/stdc++.h>
using namespace std;
int n=30;
string acc,pass;
map <string,bool> m;
int main()
{
	freopen("C:\\Users\\ADMIN\\Desktop\\ACC.INP","r",stdin);
	for (int i=1;i<=n;i++)
	{
		getline(cin,acc);
		if (m[acc]) cout<<i<<": "<<acc<<"\n";
		else m[acc]=true;
		getline(cin,pass);
	}
	return 0;
}
