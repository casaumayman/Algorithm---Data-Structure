#include<bits/stdc++.h>
using namespace std;
struct Node
{
	bool cong,tru,end;
	Node* c[26];
} *trie;
int n;
bool res=true;
string s;
vector <string> vec;
Node *CreateNode()
{
	Node *p=new Node;
	p->cong=false;
	p->tru=false;
	p->end=false;
	for (int i=0;i<26;i++) p->c[i]=NULL;
	return p;
}
int chr(char c)
{
	return (c-'a');
}
void Insert(string s,bool cong)
{
	Node *p=trie;
	for (int i=0;i<s.size();i++)
	{
		if (!p->c[chr(s[i])])
		{
			p->c[chr(s[i])]=CreateNode();
			if (cong) p->c[chr(s[i])]->cong=true;
			else p->c[chr(s[i])]->tru=true;
		}
		else
		{
			if (cong) p->c[chr(s[i])]->cong=true;
			else p->c[chr(s[i])]->tru=true;
		}
		p=p->c[chr(s[i])];
	}
	if (!cong) p->end=true;
}
void Input()
{
	cin>>n;
	char c;
	while (n--)
	{
		cin>>c;
		cin>>s;
		Insert(s,(c=='+'));
	}
}
bool checkend(Node* p)
{
	if (p->end && p->cong) return true;
	return false;
}
void dfs(Node* p)
{
	if (checkend(p))
	{
		res=false;
		return;
	}
	for (int i=0;i<26;i++)
	{
		if (p->c[i]==NULL) continue;
		if (p->c[i]->tru)
		{
			s+=i+'a';
			if (p->c[i]->cong)
				dfs(p->c[i]);
			else
				vec.push_back(s);
			s.erase(s.end()-1);
		}
	}
}
void Process()
{
	trie=CreateNode();
	Input();
	for (int i=0;i<26;i++)
	{
		if (trie->c[i]==NULL) continue;
		s="";
		if (trie->c[i]->tru)
		{
			s+=i+'a';
			if (trie->c[i]->cong) dfs(trie->c[i]);
			else vec.push_back(s);
		}
	}
	if (vec.empty() || !res) cout<<-1;
	else
	{
		cout<<vec.size()<<"\n";
		for (int i=0;i<vec.size();i++) cout<<vec[i]<<"\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}
