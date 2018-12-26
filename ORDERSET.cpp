#include<bits/stdc++.h>
#define BASE 1000000000
using namespace std;
int tree_size;
class Trie
{
	private:
		Trie *foot[4];
		int dem;
	public:	
		Trie()
		{
			for (int i=0;i<4;i++) foot[i]=NULL;
			dem=0;
		}
	private:
		bool SEARCH(int x)
		{
			Trie *t=this;
			int ind;
			for (int i=30;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				if (t->foot[ind]==NULL || t->foot[ind]->dem==0) return false;
				t=t->foot[ind];
			}
			return true;
		}
	public:
		void INSERT(int x)
		{
			if (!SEARCH(x)) tree_size++;
			else return;
			Trie *t=this;
			int ind;
			for (int i=30;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				if (!t->foot[ind]) t->foot[ind]=new Trie();
				t->foot[ind]->dem++;
				t=t->foot[ind];
			}
		}
		void DELETE(int x)
		{
			//cout<<SEARCH(x)<<"\n";
			if (!SEARCH(x)) return;
			tree_size--;
			Trie *t=this;
			int ind;
			for (int i=30;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				t->foot[ind]->dem--;
				t=t->foot[ind];
			}
		}
		int KQUERY(int k)
		{
			if (k>tree_size) return -1;
			Trie *t=this;
			int ind,sum=0,tong=0;
			for (int i=30;i>=0;i-=2)
			{
				for (ind=0;ind<4;ind++)
				{
					if (t->foot[ind]!=NULL) sum+=t->foot[ind]->dem;
					if (sum>=k) break;
				}
				tong=(tong<<2)|ind;
				//cout<<sum<<"\n";
				sum-=t->foot[ind]->dem;
				t=t->foot[ind];
			}
			return tong;
		}
		int COUNT(int k)
		{
			Trie *t=this;
			int ind,sum=0;
			ind=(k>>30)&3;
			for (int i=0;i<ind;i++)
				if (t->foot[i]) sum+=t->foot[i]->dem;
			if (t->foot[ind]==NULL || t->foot[ind]->dem==0) return sum;
			t=t->foot[ind];
			for (int i=28;i>=0;i-=2)
			{
				ind=(k>>i)&3;
				for (int u=0;u<ind;u++)
					if (t->foot[u]) sum+=t->foot[u]->dem;
				if (!t->foot[ind] || t->foot[ind]->dem==0) break;
				t=t->foot[ind];
			}
			return sum;
		}
};
int main()
{
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Trie tree;
	int n,x,u;
	char c;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%c",&c);
		switch (c)
		{
			case 'I':
				scanf("%d",&x);
				tree.INSERT(x+BASE);
				break;
			case 'D':
				scanf("%d",&x);
				tree.DELETE(x+BASE);
				break;
			case 'K':
				scanf("%d",&x);
				if (x>tree_size) printf("invalid\n");
				else printf("%d\n",tree.KQUERY(x)-BASE);
				break;
			case 'C':
				scanf("%d",&x);
				printf("%d\n",tree.COUNT(x+BASE));
				break;
		}
	}
	return 0;
}

