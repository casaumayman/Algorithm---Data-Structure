#include<bits/stdc++.h>
using namespace std;
struct trie
{
	int end;
	trie *c[26];
} *root;
int maxs,t;
int toint(char a)
{
	return a-'a';
}
trie *Create()
{
	trie *t=new trie;
	t->end=0;
	for (int i=0;i<26;i++) t->c[i]=NULL;
	return t; 
}
void Insert(string s)
{
	trie *p=root,*q;
	for (int i=0;i<s.length();i++)
	{
		if (p->c[toint(s[i])]==NULL)
		{
			q=Create();
			p->c[toint(s[i])]=q;
		}
		else q=p->c[toint(s[i])];
		p=p->c[toint(s[i])];
	}
	(p->end)++;
}
void dfs(trie *p,int value)
{
	bool empt=true;
	for (int i=0;i<26;i++)
		if (p->c[i])
		{
			empt=false;
			dfs(p->c[i],value+(p->end));
		}
	if (empt) maxs=max(maxs,value+(p->end));
}
string s;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	root=Create();
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		Insert(s);
	}
	dfs(root,0);
	cout<<maxs;
	return 0;
}
