/*
huynhhuytuan
huy
*/
#include<bits/stdc++.h>
using namespace std;
string a,b;
long long hashB,hashA[1000001],Pow[1000001];
void Input()
{
	cin>>a>>b;
	for (int i=0;i<b.length();i++) hashB=(hashB*31+b[i]-'a');
	hashA[0]=a[0]-'a';
	for (int i=1;i<a.length();i++) hashA[i]=(hashA[i-1]*31+a[i]-'a');
	Pow[0]=1;
	for (int i=1;i<=a.length();i++) Pow[i]=(Pow[i-1]*31);
}
long long getHash(int i,int j)
{
	return (hashA[j]-hashA[i-1]*Pow[j-i+1]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Input();
	//cout<<hashB<<"\n";
	for (int i=0;i<a.length()-b.length()+1;i++) //cout<<hashA[i]<<" ";
		if (getHash(i,i+b.length()-1)==hashB) cout<<i+1<<" ";
	return 0;
}
