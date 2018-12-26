#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string a,b,s,res="";
void submit(int k,int i,int j)
{
	if (k==a.size()+b.size())
	{
		cout<<res;
		exit(0);
	}
	if (s[k]==a[i])
	{
		res+='1';
		submit(k+1,i+1,j);
	}
	if (s[k]==b[j])
	{
		res+='2';
		submit(k+1,i,j+1);
	}
	res.erase(res.end()-1);
}
void Process()
{
	cin>>a>>b>>s;
	n=a.size();
	m=b.size();
	k=s.size();
	submit(0,0,0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}

