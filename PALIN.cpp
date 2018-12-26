#include<bits/stdc++.h>
using namespace std;
string s="";
int n;
bool *f1,*f,*f2,kt[10001];
int q,l;
void sinh()
{
	for (int i=1;i<=10000;i++)
	{
		s+='a';
		//l[i]=i;
	}
}
void Process()
{
	cin>>s;
	n=s.length();
	f=new bool[n];
	f1=new bool[n];
	f2=new bool[n];
	for (int i=0;i<n;i++) f1[i]=f2[i]=true;
	for (int j=2;j<=n;j++)
	{
		for (int i=0;i<=n-j;i++)
		{
			if (s[i]==s[i+j-1] && f2[i+1])
			{
				kt[j]=true;
				f[i]=true;
			}
			else f[i]=false;
		}
		f2=f1;
		f1=f;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(NULL);
	//sinh();
	Process();
	//int t=0;
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>l;
		cout<<kt[l]<<"\n";
	}
	return 0;
}
