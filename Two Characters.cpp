#include<bits/stdc++.h>
using namespace std;
string s;
int dem[26];
bool kt(char a,char b)
{
	bool chr;
	int i=0;
	while (s[i]!=a && s[i]!=b) i++;
	chr=(s[i]==a)?true:false;
	for (i=i+1;i<s.length();i++)
	{
		if (s[i]==a && chr) return false;
		if (s[i]==b && !chr) return false;
		if (s[i]==a) chr=true;
		if (s[i]==b) chr=false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	cin>>s;
	int maxs=0;
	for (int i=0;i<s.length();i++) dem[s[i]-'a']++;
	for (char x='a';x<='z'-1;x++)
		if (dem[x-'a'])
			for (char y=x+1;y<='z';y++)
				if (dem[y-'a'])
					if (kt(x,y) && dem[x-'a']+dem[y-'a']>maxs) maxs=dem[x-'a']+dem[y-'a'];
	cout<<maxs;
	return 0; 
}
