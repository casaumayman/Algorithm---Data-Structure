#include<bits/stdc++.h>
using namespace std;
int main()
{
	string n;
	int a=0;
	cin>>n;
	for (int i=0;i<n.size();i++) a+=n[i]-48;
	if (a%9==0) cout<<"YES"; else cout<<"NO";
	return 0;
}
