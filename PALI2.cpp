#include<bits/stdc++.h>
const long long Mod=1000000007;
using namespace std;
int Pow[2001],hash1[2001],hash2[2001],n;
char s[2001];
void nhap()
{
	cin>>n;
	Pow[0]=1;
	hash1[0]=1;
	hash2[n+1]=1;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		Pow[i]=Pow[i-1]*26 % Mod;
		hash1[i]=(hash1[i-1]*26+s[i]-'a') % Mod;
	}
	for (int i=n;i>=1;i--)
	{
		hash2[i]=(hash2[i+1]*26+s[i]-'a')%Mod;\
	}
}
int gethash(int i,int j)
{
	return (hash[i]-hash[j-1]*Pow[i-j+1]+Mod*Mod) % Mod;
}
void Process()
{
	int i=1;
}
int main()
{
	nhap();
	return 0;
}
