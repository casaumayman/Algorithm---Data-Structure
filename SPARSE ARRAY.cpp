#include<bits/stdc++.h>
using namespace std;
class Trie
{
public:
	Trie *foot[3];
	int dem;
	Trie()
	{
		foot[1]=foot[0]=foot[2]=NULL;
		dem=0;
	}
	void Insert(string s)
	{
		Trie *t=this;
		int ind;
		int c;
		for (int i=0;i<s.size();i++)
		{
			c=s[i]-'a';
			for (int j=1;j<=3;j++)
			{
				ind=c%3;
				c/=3;
				if (t->foot[ind]==NULL)
					t->foot[ind]=new Trie();
				t=t->foot[ind];
			}
		}
		t->dem++;
	}
	int count(string s)
	{
		Trie *t=this;
		int ind;
		int c;
		for (int i=0;i<s.size();i++)
		{
			c=s[i]-'a';
			for (int j=1;j<=3;j++)
			{
				ind=c%3;
				c/=3;
				if (t->foot[ind]==NULL) return 0;
				t=t->foot[ind];
			}
		}
		return t->dem;
	}
} trie;
int n,q;
string s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		trie.Insert(s);
	}
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>s;
		cout<<trie.count(s)<<"\n";
	}
	return 0;
}
