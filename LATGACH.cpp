#include<bits/stdc++.h>
using namespace std;
string f[101];
int T,n;
string cong(string a,string b)
{
	int nho=0,t;
	string s="";
	while (a.length()!=b.length()) b='0'+b;
	for (int i=a.length()-1;i>=0;i--)
	{
		t=(a[i]-'0')+(b[i]-'0')+nho;
		nho=0;
		if (t>9)
		{
			nho=1;
			t-=10;
		}
		s=char(t+'0')+s;
	}
	if (nho) s='1'+s;
	return s;
}
void Process()
{
	cin>>n;
	f[1]="1";
	f[2]="2";
	for (int i=3;i<=n;i++)
		f[i]=cong(f[i-1],f[i-2]);
	cout<<f[n]<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>T;
	while (T--) Process();
	//cout<<cong("999","5");
	return 0;
}
