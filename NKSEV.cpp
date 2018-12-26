#include<bits/stdc++.h>
using namespace std;
class Trie
{
	public:
		bool last;
		Trie* a[26];
	Trie()
	{
		this->last=false;
		for (int i=0;i<26;i++) this->a[i]=NULL;
	}
	void add(string s)
	{
		Trie *t=this;
		for (int i=0;i<s.size();i++)
		{
			if (t->a[s[i]-'a']!=NULL) t=t->a[s[i]-'a'];
			else
			{
				t->a[s[i]-'a']=new Trie();
				t=t->a[s[i]-'a'];
			}
		}
		t->last=true;
	}
};
int f[300001],n;
string s;
Trie root;
void Input()
{
	string tmp;
	cin>>s>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>tmp;
		root.add(tmp);
	}
	n=s.size();
	f[n]=1;
}
void Process()
{
	Input();
	Trie *p;
	int t;
	for (int i=n-1;i>=0;i--)
	{
		p=&root;
		for (int j=i;j<n;j++)
		{
			t=s[j]-'a';
			if (p->a[t]==NULL) break;
			p=p->a[t];
			if (p->last) f[i]+=f[j+1];
		}
		f[i]%=1337377;
	}
	cout<<f[0];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUTT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}

